const ld EPS = 1e-12;
typedef vector<ld> vd;
typedef vector<vd> vvd;

// Determine solution of a linear system of equations
// of the form Ax = b, where the input is the matrix A
// with an extra column that is b. Returns empty vector
// when there is no solution or for infinite number of
// solutions. Modifies input matrix!
vd gauss(vvd &a) {
    ll n = sz(a), m = sz(a[0]) - 1;
    vi w(m, -1);
    // Current column and row
    ll c = 0, r = 0;
    // Result vector
    vd res(n, 0.0);
    while (c < m && r < n) {
        ll s = r;
        rep(i, r, n)
            if (abs(a[i][c]) > abs(a[s][c]))
                s = i;
        if (abs(a[s][c]) < EPS) {
            c++;
            continue;
        }
        rep(i, c, m + 1)
            swap(a[s][i], a[r][i]);
        w[c] = r;
        REP(i, n) {
            if (i != r) {
                ld cur = a[i][c] / a[r][c];
                rep(j, c, m + 1)
                    a[i][j] -= a[r][j] * cur;
            }
        }
        c++, r++;
    }
    REP(i, m)
        if (w[i] != -1)
            res[i] = a[w[i]][m] / a[w[i]][i];
    REP(i, n) {
        ld sm = 0;
        REP(j, m)
            sm += res[j] * a[i][j];
        if (abs(sm - a[i][m]) > EPS)
            return {};
    }
    // To get one of the solutions, remove this loop:
    REP(i, m)
        if (w[i] == -1)
            return {};
    return res;
}