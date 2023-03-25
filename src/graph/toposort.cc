// Perform depth-first search on a directed graph,
// marking nodes as visited on the way
void dfs(ll i, vi &out, const vector<vii> &Gr,
vi &done) {
    done[i] = 1;
    for (ii e : Gr[i])
        if (!done[e.x])
            dfs(e.x, out, Gr, done);
    out.pb(i);
}

// Finds a topological ordering on a graph G. This
// function assumes that such an ordering exists!
// Note that the lengths of the edges in G are not
// used.
vi toposort(const vector<vii> &G) {
    // Construct reverse graph
    vector<vii> Gr(sz(G), vii{});
    REP(i, sz(G))
        for (ii e : G[i])
            Gr[e.x].pb({i, e.y});
    vi out, done(sz(G), 0);
    REP(i, sz(G))
        if (G[i].empty() && !done[i])
            dfs(i, out, Gr, done);
    return out;
}