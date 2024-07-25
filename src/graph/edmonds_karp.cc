// Checks if there is a path from s to t in the
// residual graph given by its edges. Uses prev to
// store path
bool bfs(const vvi &Gr, const vvi &edges, ll s, ll t,
vi &prev) {
    // Keep track of done vertices
    vi done(sz(prev), 0);
    // Add source vertex to queue
    queue<ll> q;
    q.push(s), done[s] = 1, prev[s] = -1;
    // BFS, consider edges with weight >0
    while (!q.empty()) {
        ll cur = q.front();
        q.pop();
        for (ll v : edges[cur]) {
            if (!done[v] && Gr[cur][v] > 0) {
                prev[v] = cur;
                if (v == t)
                    return true;
                q.push(v), done[v] = 1;
            }
        }
    }
    return false;
}

// Returns maximum flow from source s to sink t in
// graph G and the residual graph as an adjacency
// matrix. The graph should also be given as an
// adjacency matrix
pair<ll, vvi> maxFlow(const vvi &G, ll s, ll t) {
    vvi Gr = G;
    vi prev(sz(G), 0);
    ll mx = 0;
    // Also store original graph as adjacency list
    vvi edges(sz(G));
    REP(i, sz(G)) REP(j, sz(G))
        if (G[i][j] != 0)
            edges[i].pb(j), edges[j].pb(i);
    // Augment flow while there is a path from source
    // to sink
    while (bfs(Gr, edges, s, t, prev)) {
        // Find minimum residual capacity of edges
        // along the path found by BFS
        ll flow = LLONG_MAX, v;
        for (v = t; v != s; v = prev[v])
            flow = min(flow, Gr[prev[v]][v]);
        // Update residual capacities of the edges and
        // reverse edges along the path
        for (v = t; v != s; v = prev[v]) {
            Gr[prev[v]][v] -= flow;
            Gr[v][prev[v]] += flow;
        }
        mx += flow;
    }
    return {mx, Gr};
}