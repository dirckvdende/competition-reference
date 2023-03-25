// Determines reachable nodes with a maximum distance
// Input are the graph, the starting node and the
// maximum distance. Returns the set of reachable
// nodes. Set the maximum distance very high to
// determine connected subgraph. Assumes that all
// distances in the graph are either 0 or 1!
vi reachable(const vector<vii> &G, ll s, ll M) {
    // Keeps track of nodes that are reachable
    vi reach(sz(G), 0);
    reach[s] = 1;
    // Create queues for current and next distance
    // steps
    queue<ll> cur, next;
    cur.push(s);
    // Loop over all possible distance steps
    REP(m, M + 1) {
        if (cur.empty())
            break;
        while (!cur.empty()) {
            ll v = cur.front();
            cur.pop();
            reach[v] = 1;
            for (const ii &e : G[v]) {
                if (reach[e.x])
                    continue;
                if (e.y)
                    next.push(e.x);
                else
                    cur.push(e.x);
            }
        }
        cur = next;
    }
    return reach;
}