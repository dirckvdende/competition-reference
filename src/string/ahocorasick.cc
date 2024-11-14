// NOTE: Duplicate patterns will be ignored!
// NOTE: Doesn't allow for adding patterns after
// construction!
struct AhoCorasick {
    // Base character offset and character range
    const char base; const ll range;
    // Standard trie links, and (parent node, char
    // index)
    vvi trie; vii parent;
    // Blue and green edges, accepted word index or -1
    vi blue, green; vi accepted;
    AhoCorasick(const vector<string> &pat, char base,
    char end) : base(base), range(ll(end) - base + 1) {
        addNode(); // Add root node
        createTrie(pat); createBlue(); createGreen();
    }
    // Add empty node to the automaton and return index
    ll addNode() {
        accepted.pb(-1); trie.pb(vi(range, -1));
        blue.pb(-1); green.pb(-1); parent.pb({-1, -1});
        return sz(blue) - 1;
    }
    // Construct trie and mark accepted patterns
    void createTrie(const vector<string> &pat) {
        REP(i, sz(pat)) {
            ll j = 0;
            for (char c : pat[i]) {
                if (trie[j][c - base] == -1) {
                    ll v = addNode();
                    parent[v] = {j, c - base};
                    trie[j][c - base] = v;
                }
                j = trie[j][c - base];
            }
            accepted[j] = i;
        }
    }
    // Create blue edges to longest strict suffix
    // Uses BFS and blue edges of parent
    void createBlue() {
        queue<ll> q; q.push(0);
        while (!q.empty()) {
            ll cur = q.front(); q.pop();
            REP(i, range)
                if (trie[cur][i] != -1)
                    q.push(trie[cur][i]);
            if (parent[cur].x <= 0) {
                blue[cur] = 0;
                continue;
            }
            // Char that points at current node
            ll c = parent[cur].y;
            // Follow blue edge of parent from current
            // node
            ll p = blue[parent[cur].x];
            while (p > 0 && trie[p][c] == -1)
                p = blue[p];
            blue[cur] = trie[p][c] == -1 ? 0 :
            trie[p][c];
        }
    }
    // Create green edges to longest accepted suffix
    // Uses BFS and blue edges
    void createGreen() {
        queue<ll> q; q.push(0);
        while (!q.empty()) {
            ll cur = q.front(); q.pop();
            REP(i, range)
                if (trie[cur][i] != -1)
                    q.push(trie[cur][i]);
            if (blue[cur] == -1)
                continue;
            if (accepted[blue[cur]] != -1)
                green[cur] = blue[cur];
            else
                green[cur] = green[blue[cur]];
        }
    }
    // Returns a list of (end index, pat. index)
    vii match(const string &s) {
        ll cur = 0; vii out;
        REP(i, sz(s)) {
            ll c = ll(s[i]) - base;
            // Move to next node
            if (cur > 0 && trie[cur][c] == -1)
                cur = blue[cur];
            if (trie[cur][c] == -1)
                cur = 0;
            else
                cur = trie[cur][c];
            // NOTE: Option to return only longest
            // match per index
            #if ONLY_LONGEST_SUFFIX
                if (accepted[cur] != -1)
                    out.pb({i, accepted[cur]});
                else if (green[cur] != -1)
                    out.pb({i, accepted[green[cur]]});
            #else
                if (accepted[cur] != -1)
                    out.pb({i, accepted[cur]});
                ll j = cur;
                while (green[j] != -1) {
                    // green[j] points to next accepted
                    // suffix
                    j = green[j];
                    out.pb({i, accepted[j]});
                }
            #endif
        }
        return out;
    }
};