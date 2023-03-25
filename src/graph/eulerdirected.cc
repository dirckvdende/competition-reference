// The graph G is given as an adjacency list
bool hasEulerCycle(const vvi &G) {
    // Check if there is one strongly connected
    // component
    if (sz(components(G)) != 1)
        return false;
    // Check if all vertices have equal in and out
    // degrees
    vi indeg(sz(G), 0), outdeg(sz(G), 0);
    REP(i, sz(G)) for (ll e : G[i])
        indeg[e]++, outdeg[i]++;
    REP(i, sz(G))
        if (indeg[i] != outdeg[i])
            return false;
    return true;
}