// Calculates the k shortest paths from source s to
// sink t in an undirected weighted graph G, given as
// adjacency lists
vvi kShortest(const vector<vii> &G, ll s, ll t, ll k) {
    // P contains all found paths
    vvi P;
    // Number of paths found to a certain node
    vi count(sz(G), 0);
    // Heap to store apths to nodes with given lengths.
    // Unlike in normal Dijkstra the entire path needs
    // to be stored
    set<pair<ll, vi>> Q;
    Q.insert({0, {s}});
    while (!Q.empty() && count[t] < k) {
        pair<ll, vi> p = *Q.begin();
        ll u = p.y.back();
        Q.erase(Q.begin()), count[u]++;
        // Save paths to sink node
        if (u == t)
            P.pb(p.y);
        // Go over neighbours and add lengths and paths
        // to the heap
        if (count[u] < k) for (ii e : G[u]) {
            pair<ll, vi> pe = p;
            pe.x += e.y, pe.y.pb(e.x);
            Q.insert(pe);
        }
    }
    return P;
}