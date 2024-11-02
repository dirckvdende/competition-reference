// Perform depth-first search on a directed graph,
// marking nodes as visited on the way
void dfs(ll i, vi &out, const vvi &Gr,
vector<bool> &done) {
    done[i] = true;
    // Visit ancestor nodes first
    for (ll e : Gr[i]) if (!done[e])
        dfs(e, out, Gr, done);
    out.pb(i);
}

// Finds a topological ordering on a graph G. This
// function assumes that such an ordering exists!
vi toposort(const vvi &G) {
    // Construct reverse graph
    vvi Gr(sz(G));
    REP(i, sz(G)) for (ll e : G[i])
        Gr[e].pb(i);
    // Run DFS for each node without descendents
    vi out; vector<bool> done(sz(G), false);
    REP(i, sz(G)) if (G[i].empty() && !done[i])
        dfs(i, out, Gr, done);
    return out;
}