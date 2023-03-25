// Determines a Eulerian cycle in a graph G, where G is
// given by adjacency lists. Input is the starting
// vertex of the cycle. This function assumes that a
// Eulerian cycle exists
vi eulerCycle(const vvi &G, ll start = 0) {
    // Store edges in a set for quick removal
    set<ii> edges;
    REP(i, sz(G)) for (ll e : G[i])
        edges.insert({i, e});
    // Number of edges from each vertex
    vi deg;
    REP(i, sz(G))
        deg.pb(sz(G[i]));
    // Current path and final result
    vi path, res;
    path.pb(0);
    ll cur = start;
    while (!path.empty()) {
        // Continue current circuit of backtrack
        if (deg[cur] > 0) {
            path.pb(cur);
            ll nxt = edges.lower_bound({cur, 0})->y;
            edges.erase({cur, nxt}), deg[cur]--;
            // For directed graphs, remove this line:
            edges.erase({nxt, cur}), deg[nxt]--;
            cur = nxt;
        } else {
            res.pb(cur);
            cur = path.back();
            path.pop_back();
        }
    }
    reverse(all(res));
    return res;
}