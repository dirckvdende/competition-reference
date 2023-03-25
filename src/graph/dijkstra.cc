// Calculates the shortest path from the starting
// points to any other point. Returns the distance to
// any point, and the previous nodes in the shortest
// path. The graph input G represents the list of
// points, each containing a list of connections to
// other points, these are pairs: the other point and
// the distance. Returns LLONG_MAX if a point is not
// reachable
pair<vi, vi> dijkstra(const vector<vii> &G, ll s) {
    vi dist(sz(G), LLONG_MAX), pr(sz(G), -1);
    dist[s] = 0;
    // (Ordered) set so that the point with lowest
    // distance will be handled first
    set<ii> Q;
    Q.insert({dist[s], s});
    // While there are points not visited (or other
    // points are not reachable)
    while (!Q.empty()) {
        // Vertex with shortest distance
        ll v = Q.begin()->y;
        Q.erase(Q.begin());
        // Go over all connections from this point
        for (const ii &e : G[v])
            if (dist[v] + e.y < dist[e.x]) {
                Q.erase({dist[e.x], e.x});
                dist[e.x] = dist[v] + e.y;
                Q.insert({dist[e.x], e.x});
                pr[e.x] = v;
            }
    }
    return {dist, pr};
}