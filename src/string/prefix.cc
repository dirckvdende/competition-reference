// Returns the length of the shortest word in a list
// that is a prefix of a given string. If no prefix was
// found returns -1
ll shortestPrefix(const string &s, const vector<string>
&list) {
    Trie trie;
    for (const string &i : list)
        trie.insert(i);
    ll node = 0;
    REP(i, sz(s)) {
        node = trie.children[node][s[i] - trie.base];
        if (node == -1)
            return -1;
        if (trie.leaves[node])
            return i + 1;
    }
    return -1;
}