// Data structure for all operations needed for the
// Aho-Corasick algorithm
struct AhoCorasick {
    // Store list of patterns separately
    vector<string> patt;
    const unsigned char base; const ll maxChars;
    // Output function: used to check if current state
    // accepts prefix strings
    vvi out;
    // Failure function, goto function
    vi f; vvi g;
    // Append an empty state
    void add() {
        out.pb({});
        f.pb(-1);
        g.pb(vi(maxChars + 1, -1));
    }
    // Construct trie from multiple patterns. Give the
    // min and max character as parameters.
    AhoCorasick(const vector<string> &patt, unsigned
    char mn = 'a', unsigned char mx = 'z') :
    patt(patt), base(mn), maxChars(mx - mn + 1) {
        // Add initial state
        add();
        // Step 1: Construct goto function, which is to
        // construct a Trie
        REP(i, sz(patt)) {
            const string &word = patt[i];
            ll cur = 0;
            REP(j, sz(word)) {
                ll ch = word[j] - base;
                if (g[cur][ch] == -1)
                    g[cur][ch] = sz(out), add();
                cur = g[cur][ch];
            }
            // Mark current state as accepting for this
            // specific word
            out[cur].pb(i);
        }
        // All characters that do not have an edge from
        // the root will get a goto to the root
        REP(ch, maxChars)
            if (g[0][ch] == -1)
                g[0][ch] = 0;
        // Step 2: Build failure function
        // Failure function is calculated in using BFS
        queue<ll> q;
        // Iterate over possible single-character
        // inputs
        REP(ch, maxChars)
            if (g[0][ch] != 0)
                f[g[0][ch]] = 0, q.push(g[0][ch]);
        // This vector is used to keep track of double
        // merge values:
        vector<bool> merged(sz(patt), false);
        // Use queue to iterate over states using BFS
        while (!q.empty()) {
            ll cur = q.front(); q.pop();
            // Determine failure function if goto
            // function is not defined for character
            REP(ch, maxChars + 1) if (g[cur][ch] != -1)
            {
                // Find failure state of removed state
                ll fail = f[cur];
                // Find the deepest node labeled by
                // proper suffix of string from root to
                // current state
                while (g[fail][ch] == -1)
                    fail = f[fail];
                fail = g[fail][ch];
                f[g[cur][ch]] = fail;
                // Merge output values:
                // Step A: Mark all values that are
                // already in output value
                for (ll v : out[g[cur][ch]])
                    merged[v] = true;
                // Step B: Add values for out[fail]
                // that have not yet been added
                for (ll v : out[fail])
                    if (!merged[v])
                        out[g[cur][ch]].pb(v);
                // Step C: Unmark all values for next
                // iteration
                for (ll v : out[g[cur][ch]])
                    merged[v] = false;
                // Insert child node to queue
                q.push(g[cur][ch]);
            }
        }
    }
    // Find the next state in the automaton given
    // current state and input
    ll nextState(ll cur, char c) {
        ll res = cur;
        // Use failure function if goto is not defined
        while (g[res][c - base] == -1)
            res = f[res];
        return g[res][c - base];
    }
    // Find stored patterns in a string. Returns a
    // vector where every entry contains all starting
    // positions of one of the pattern words.
    vvi find(const string &txt) {
        ll cur = 0;
        vvi res(sz(patt), vi{});
        // Simulate automaton, looping over all chars
        REP(i, sz(txt)) {
            cur = nextState(cur, txt[i]);
            // No match found in this state:
            for (ll j : out[cur])
                res[j].pb(i - sz(patt[j]) + 1);
        }
        return res;
    }
};