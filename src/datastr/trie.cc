// Trie data structure, can store strings efficiently.
// Is empty as initialization. Note that strings can be
// deleted, but this is not recommended. Change the
// base to the lowest ASCII char that should be
// accepted and amt to the amount of accepted chars.
struct Trie {
    const char base = 'a';
    const ll amt = 26;
    vvi children = {vi(amt, -1)};
    vi leaves = {0};
    bool find(const string &s) {
        ll node = 0;
        for (char c : s) {
            node = children[node][c - base];
            if (node < 0)
                return false;
        }
        return leaves[node];
    }
    void insert(const string &s) {
        ll node = 0;
        for (char c : s) {
            if (children[node][c - base] < 0) {
                children[node][c - base] =
                sz(children);
                leaves.pb(0);
                children.pb(vi(amt, -1));
            }
            node = children[node][c - base];
        }
        leaves[node] = 1;
    }
    void erase(const string &s) {
        ll node = 0;
        for (char c : s) {
            if (children[node][c - base] < 0)
                return;
            node = children[node][c - base];
        }
        leaves[node] = 0;
    }
};