// Implements the sparse table data structure, the
// input list has to be given at construction.
struct SparseTable {
    // Lookup table
    vvi data;
    SparseTable(const vi &inp) {
        // Precompute the data table
        ll K = 0, k = sz(inp);
        while (k > 0)
            k /= 2, K++;
        data = vvi(K + 1, vi(sz(inp)));
        data[0] = inp;
        rep(i, 1, K + 1)
            REP(j, sz(inp) - (1LL << i) + 1)
                // min() can be replaced with a
                // different function
                data[i][j] = min(data[i - 1][j],
                data[i - 1][j + (1LL << (i - 1))]);
    }
    // Searches for interval minimum in [l, r)
    ll query(ll l, ll r) {
        if (r <= l)
            return LLONG_MAX;
        ll p = -1, d = r - l;
        while (d > 0)
            d /= 2, p++;
        return min(data[p][l],
        data[p][r - (1LL << p)]);
    }
};