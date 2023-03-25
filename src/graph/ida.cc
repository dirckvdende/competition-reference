// Fill the heuristic function in here:
ll h(ll i);

// Search function, returns minimum or -1 if
// destination was found, LLONG_MAX if no path was
// found
ll search(const vector<vii> &G, ll s, ll t, vi &path,
ll g, ll bound) {
    ll cur = path.back();
    ll f = g + h(cur);
    if (f > bound)
        return f;
    if (cur == t)
        return -1;
    ll mn = LLONG_MAX;
    // Go over neighbours
    for (ii e : G[cur]) {
        bool inPath = false;
        for (ll p : path) if (p == e.x) {
            inPath = true;
            break;
        }
        if (inPath)
            continue;
        path.pb(e.x);
        ll c = search(G, s, t, path, g + e.y, bound);
        if (c == -1)
            return -1;
        if (c < mn)
            mn = c;
        path.pop_back();
    }
    return mn;
}

// The input graph G can be directed, and is given as
// adjacency lists, s is the start node, t the
// destination. If no shortest path exists, returns
// empty vector
vi idaStar(const vector<vii> &G, ll s, ll t)
{
    ll bound = h(s);
    vi path = {s};
    // Search until no extra nodes can be reached
    while (bound != LLONG_MAX) {
        ll c = search(G, s, t, path, 0, bound);
        if (c == -1)
            // Here, "bound" will be the distance from
            // s to t
            return path;
        bound = c;
    }
    return {};
}