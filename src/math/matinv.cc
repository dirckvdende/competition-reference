// Calculates the inverse of a matrix. The input matrix
// is modified to store the result! Assumes matrix is
// square and invertable (det != 0)!
void inv(vvd &a) {
    ll n = sz(a);
    REP(i, n) REP(j, n)
        a[i].pb(i == j ? 1.0 : 0.0);
    gauss(a);
    REP(i, n)
        a[i] = vd(a[i].begin() + n, a[i].end());
}