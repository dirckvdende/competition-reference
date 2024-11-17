// Special pair hashing
struct DinicHash {
    hash<ll> h;
    size_t operator()(const ii &p) const {
        return h(p.x + (p.y << 31));
    }
};
// Object to run Dinic's algorithm
struct Dinic {
    // Size of the graph
    ll n;
    // Adjacency lists, with both forward and backward
    // edges included
    vvi adj;
    // Total and residual capacity
    unordered_map<ii, ll, DinicHash> cap, res;
    // Current level of each node
    vi level;
    // Source and sink nodes
    ll s, t;
    // Visited nodes by DFS in `findPath` function, and
    // pruned nodes is DFS that lead to dead ends
    vector<bool> visited, pruned;
    // Input the graph as an adjacency list
    Dinic(const vector<vii> &G, ll s, ll t) : n(sz(G)),
    adj(n), s(s), t(t), visited(n), pruned(n) {
        // For performance: determine approx. number of
        // entries in hash tables
        ll tot = 0;
        REP(i, n) tot += sz(G[i]);
        cap.reserve(tot * 2); res.reserve(tot * 2);
        // Construct adjacency lists, set capacities
        REP(i, n)
            for (const ii &e : G[i]) {
                if (cap.find({i, e.x}) == cap.end()) {
                    cap[{i, e.x}] = cap[{e.x, i}] =
                    res[{i, e.x}] = res[{e.x, i}] = 0;
                    adj[i].pb(e.x), adj[e.x].pb(i);
                }
                cap[{i, e.x}] += e.y;
            }
    }
    // Find the levels of all nodes, given residual
    // graph
    void findLevels() {
        level = vi(n, -1);
        queue<ll> q; q.push(s); level[s] = 0;
        while (!q.empty()) {
            ll i = q.front(); q.pop();
            for (ll e : adj[i])
                if (cap[{i, e}] > res[{i, e}] &&
                level[e] == -1)
                    level[e] = level[i] + 1, q.push(e);
        }
    }
    // Checks if an edge is in the current level graph
    bool inLevel(const ii &e) {
        return cap[e] > res[e] && level[e.x] <
        level[e.y];
    }
    // Find a blocking path using DFS, returns max-flow
    // of path if it exists, otherwise 0
    ll findPath(ll i, vi &path, ll flow) {
        visited[i] = true;
        path.pb(i);
        if (i == t)
            return flow;
        for (ll e : adj[i]) {
            if (inLevel({i, e}) && !visited[e] &&
            !pruned[e]) {
                ll r = findPath(e, path, min(flow,
                cap[{i, e}] - res[{i, e}]));
                if (r > 0)
                    return r;
            }
        }
        pruned[i] = true;
        path.pop_back();
        return 0;
    }
    // Find the maximum flow of the graph. NOTE: This
    // function can only be called once!
    ll maxFlow() {
        ll flow = 0;
        while (true) {
            findLevels();
            if (level[t] == -1)
                break;
            vi path; ll r;
            fill(all(pruned), false);
            fill(all(visited), false);
            while ((r = findPath(s, path, LLONG_MAX)))
            {
                REP(i, sz(path) - 1) {
                    res[{path[i], path[i + 1]}] += r;
                    res[{path[i + 1], path[i]}] -= r;
                }
                flow += r;
                path.clear();
                fill(all(visited), false);
            }
        }
        return flow;
    }
};