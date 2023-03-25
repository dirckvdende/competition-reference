// Returns the coloring of the vertices in the order
// the vertices are given. May produce better results
// depending on the ordering of the vertices. The input
// graph is given as adjacency lists. The graph should
// be undirected
vi greedyColoring(const vvi &G) {
    vi color(sz(G), -1);
    // Maximum number of colors is sz(G)
    vi used(sz(G), 0);
    REP(i, sz(G)) {
        // Mark neighbour colors as unavailable
        for (ll e : G[i])
            if (color[e] != -1)
                used[color[e]] = 1;
        // Pick first available color
        ll c = 0;
        while (used[c]) c++;
        color[i] = c;
        // Mark neighbour colors as available
        for (ll e : G[i])
            if (color[e] != -1)
                used[color[e]] = 0;
    }
    return color;
}