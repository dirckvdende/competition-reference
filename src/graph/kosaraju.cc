// The graph G is represented as adjacency lists
vvi components(const vvi &G) {
    // Construct reverse graph (for in-neighbours)
    vvi Gr(sz(G));
    REP(i, sz(G)) for (ll e : G[i])
        Gr[e].pb(i);
    vector<bool> done(sz(G), false);
    vi L;
    function<void(ll)> visit = [&](ll i) {
        if (done[i])
            return;
        done[i] = true;
        for (ll e : G[i])
            visit(e);
        L.pb(i);
    };
    // Component represented by root vertex
    vi comp(sz(G), -1);
    function<void(ll, ll)> assign = [&](ll i, ll root) {
        if (comp[i] != -1)
            return;
        comp[i] = root;
        for (ll e : Gr[i])
            assign(e, root);
    };
    REP(i, sz(G))
        visit(i);
    reverse(all(L));
    REP(i, sz(L))
        assign(L[i], L[i]);
    // Construct component lists
    vvi compList(sz(G));
    REP(i, sz(G))
        compList[comp[i]].pb(i);
    // Remove empty components
    vvi out;
    for (const vi &l : compList)
        if (!l.empty())
            out.pb(l);
    return out;
}