// The graph G is given as an adjacency list
bool hasEulerCycle(const vvi &G) {
    // Check if there is one connected component
    DisjointUnion dsu(sz(G));
    REP(i, sz(G)) for (ll e : G[i])
        dsu.combine(i, e);
    ll c = dsu.find(0);
    REP(i, sz(G))
        if (dsu.find(i) != c)
            return false;
    // Check if all vertices have even degree
    REP(i, sz(G))
        if (sz(G[i]) % 2 != 0)
            return false;
    return true;
}