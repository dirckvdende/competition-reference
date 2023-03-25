// Multiply an n by m maxtrix with an m by k matrix.
// Matrices should be indexed with [row][column]
vvi matmul(const vvi &a, const vvi &b) {
    vvi ret(sz(a), vi(sz(b[0]), 0));
    REP(i,sz(a)) REP(j,sz(b[0])) {
        ll c = 0;
        REP(k,b.size())
            c += a[i][k] * b[k][j];
        ret[i][j] = c;
    }
    return ret;
}