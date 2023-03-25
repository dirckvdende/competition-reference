// The tree should be given as a DIRECTED graph, with
// node 0 the root, the graph is given as an adjacency
// list
vi maxIndep(const vvi &G) {
    // Create list in the right order (children first)
    vi nodes;
    queue<ll> q; q.push(0);
    while (!q.empty()) {
        ll c = q.front();
        q.pop();
        nodes.pb(c);
        for (ll e : G[c])
            q.push(e);
    }
    reverse(all(nodes));
    // Max indep set size given that current node is/is
    // not included
    vi A(sz(G), 0), B(sz(G), 0);
    for (ll c : nodes) {
        A[c] = 1;
        // A[c] = sum(B[e] for e children)
        for (ll e : G[c])
            A[c] += B[e];
        // B[c] = sum(max(A[e], B[e]) for e children)
        for (ll e : G[c]) {
            if (A[e] > B[e])
                B[c] += A[e];
            else
                B[c] += B[e];
        }
    }
    // Construct max indep set
    // queue: (node, can be included)
    queue<ii> v; v.push({0, 1});
    vi res;
    while (!v.empty()) {
        ii c = v.front();
        v.pop();
        // Include or do not include
        if (c.y && A[c.x] > B[c.x]) {
            res.pb(c.x);
            for (ll e : G[c.x])
                v.push({e, 0});
        } else {
            for (ll e : G[c.x])
                v.push({e, 1});
        }
    }
    return res;
}