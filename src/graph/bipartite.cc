// Check if a graph is bipartite. The graph is given as
// adjacency lists and must be undirected
bool isBipartite(const vvi &G) {
    // Keep track of group of vertices
    vi group(sz(G), -1);
    // Iterate over connected components
    REP(i, sz(G)) {
        if (group[i] != -1)
            continue;
        // Go over vertices in connected component
        // using BFS
        queue<ll> q; q.push(i); group[i] = 0;
        while (!q.empty()) {
            ll c = q.front();
            q.pop();
            for (ll e : G[c]) {
                if (group[c] == group[e])
                    return false;
                if (group[e] != -1)
                    continue;
                group[e] = 1 - group[c];
                q.push(e);
            }
        }
    }
    return true;
}