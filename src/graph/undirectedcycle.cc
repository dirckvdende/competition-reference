// Note that the lengths in the graph are not used
bool hasCycle(const vector<vii> &G) {
    // Find number of connected components by going
    // over edges and joining
    DisjointUnion dsu(sz(G));
    ll C = sz(G), E = 0;
    REP(i, sz(G)) for (ii e : G[i]) {
        if (dsu.find(i) != dsu.find(e.x))
            dsu.combine(i, e.x), C--;
        E++;
    }
    return E + C != sz(G);
}