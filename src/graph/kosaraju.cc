// Visits a node and then its neighbours, given the
// out-list, L and done
void visit(const vvi &G, vi &L, vi &done, ll i) {
    if (done[i])
        return;
    done[i] = 1;
    for (ll e : G[i])
        if (!done[e])
            visit(G, L, done, e);
    L.pb(i);
}

// Assign a node to a component
void assign(const vvi &Gr, vi &comp, ll i, ll root) {
    if (comp[i] != -1)
        return;
    comp[i] = root;
    for (ll e : Gr[i])
        assign(Gr, comp, e, root);
}

// The graph G is represented as adjacency lists
vvi components(const vvi &G) {
    // Construct reverse graph (for in-neighbours)
    vvi Gr(sz(G));
    REP(i, sz(G)) for (ll e : G[i])
        Gr[e].pb(i);
    vi done(sz(G), 0);
    vi L;
    REP(i, sz(G))
        visit(G, L, done, i);
    reverse(all(L));
    // Component represented by root vertex
    vi comp(sz(G), -1);
    REP(i, sz(G))
        assign(Gr, comp, L[i], L[i]);
    // Construct components
    vvi compList(sz(G));
    REP(i, sz(G))
        compList[comp[i]].pb(i);
    vvi out;
    for (const vi &l : compList)
        if (!l.empty())
            out.pb(l);
    return out;
}