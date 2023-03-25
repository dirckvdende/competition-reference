const ll INF = 1LL << 32;

// Find the minimum cost matching given a cost matrix,
// returns the total cost and matching pairs
pair<ll, vii> hungarian(const vvi &A) {
    ll n = sz(A), m = sz(A[0]);
    vi u(n + 1), v(m + 1), p(m + 1), way(m + 1);
    rep(i, 1, n + 1) {
        p[0] = i;
        ll j0 = 0;
        vi minv(m + 1, INF), used(m + 1, 0);
        while (p[j0] != 0) {
            used[j0] = 1;
            ll i0 = p[j0], delta = INF, j1;
            rep(j, 1, m + 1) {
                if (!used[j]) {
                    ll cur = A[i0 - 1][j - 1] - u[i0]
                    - v[j];
                    if (cur < minv[j])
                        minv[j] = cur, way[j] = j0;
                    if (minv[j] < delta)
                        delta = minv[j], j1 = j;
                }
            }
            REP(j, m + 1) {
                if (used[j])
                    u[p[j]] += delta, v[j] -= delta;
                else
                    minv[j] -= delta;
            }
            j0 = j1;
        }
        while (j0) {
            ll j1 = way[j0];
            p[j0] = p[j1], j0 = j1;
        }
    }
    vii res;
    rep(i, 1, m + 1)
        res.pb({p[i] - 1, i - 1});
    return {-v[0], res};
}