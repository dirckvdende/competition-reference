bool dfs(ll i, const vector<vii> &G, vi &done, vi &rec)
{
    if (!done[i]) {
        done[i] = rec[i] = 1;
        for (ii e : G[i]) {
            if (!done[e.x] && dfs(e.x, G, done, rec))
                return true;
            else if (rec[e.x])
                return true;
        }
    }
    rec[i] = 0;
    return false;
}

bool hasCycle(const vector<vii> &G) {
    vi done(sz(G), 0), rec(sz(G), 0);
    REP(i, sz(G))
        if (!done[i] && dfs(i, G, done, rec))
            return true;
    return false;
}