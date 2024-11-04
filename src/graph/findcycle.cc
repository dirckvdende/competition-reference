// Returns {} if no cycle is found
vi findCycle(const vvi &G) {
    vector<bool> done(sz(G), false);
    vector<bool> in_path(sz(G), false); vi path;
    // DFS is used to detect path looping back on
    // itself
    function<bool(ll, ll)> dfs = [&](ll i, ll prev) {
        if (done[i])
            return false;
        path.pb(i); in_path[i] = done[i] = true;
        // NOTE: Remove if-statement for directed graph
        for (ll e : G[i]) if (e != prev) {
            if (!done[e] && dfs(e, i))
                return true;
            if (in_path[e]) {
                // Add duplicate node for removal
                path.pb(e);
                return true;
            }
        }
        path.pop_back(); in_path[i] = false;
        return false;
    };
    // For every point not yet visited start a DFS
    REP(i, sz(G)) {
        if (done[i] || !dfs(i, -1))
            continue;
        // Reconstruct path from duplicate node
        ll start = 1;
        while (path[start - 1] != path.back())
            start++;
        return vi(path.begin() + start, path.end());
    }
    return {};
}