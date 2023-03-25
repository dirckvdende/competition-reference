// Executes Prim's algorithm on a graph G, represented
// by adjacency lists. Returns the total length of the
// MST and the edges that make it up.
// WARNING: The graph needs to be undirected and
// connected and thus contain (v1, v2) if it contains
// the edge (v2, v1)!
pair<ll, vii> prim(const vector<vii> &G) {
    vi done(sz(G), 0);
    done[0] = 1;
    vii edges;
    ll len = 0;
    set<pair<ll, ii>> q;
    // Find connections of first node
    for (ii c : G[0])
        q.insert({c.y, {0, c.x}});
    while (!q.empty()) {
        // Retrieve edge with lowest length, and check
        // if node has been marked as done
        pair<ll, ii> cur = *q.begin();
        q.erase(q.begin());
        if (done[cur.y.y])
            continue;
        // Mark this node as done
        edges.pb(cur.y);
        done[cur.y.y] = 1;
        len += cur.x;
        // Add all connections of the new node
        for (ii c : G[cur.y.y])
            if (!done[c.x])
                q.insert({c.y, {cur.y.y, c.x}});
    }
    return {len, edges};
}