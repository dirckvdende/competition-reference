// Executes Kruskal's algorithm on a graph G,
// represented by adjacency lists. Returns the total
// length of the MST and the edges that make it up.
// WARNING: The graph needs to be undirected and
// connected and thus contain (v1, v2) if it contains
// the edge (v2, v1)!
pair<ll, vii> kruskal(const vector<vii> &G) {
    // Each node is in a different group initially
    DisjointUnion dsu(sz(G));
    // Gather edges: length, (v1, v2)
    vector<pair<ll, ii>> edges;
    REP(i, sz(G)) REP(j, sz(G[i]))
        if (i < G[i][j].x)
            edges.pb({G[i][j].y, {i, G[i][j].x}});
    sort(all(edges));
    vii mst;
    ll len = 0;
    for (auto &e : edges) {
        if (dsu.find(e.y.x) != dsu.find(e.y.y)) {
            mst.pb(e.y);
            dsu.combine(e.y.x, e.y.y);
            len += e.x;
        }
    }
    return {len, mst};
}