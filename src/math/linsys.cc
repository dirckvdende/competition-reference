// Solve a linear system of equations Ax = b. If there
// no or multiple solutions, an empty vector is
// returned. The input matrix is modified!
vd linsys(vvd &a, const vd &b) {
    // Put vector b on the right side of matrix A
    REP(i, sz(b))
        a[i].pb(b[i]);
    gauss(a);
    // No solutions:
    REP(i, sz(a)) {
        bool allZero = true;
        REP(j, sz(a[i]) - 1)
            if (abs(a[i][j]) > EPS) {
                allZero = false;
                break;
            }
        if (allZero && abs(a[i].back()) > EPS)
            return {};
    }
    // Multiple solutions: (independent coordinates can
    // still be found)
    if (sz(a) < sz(a[0]) - 1)
        return {};
    REP(i, sz(a[0]) - 1)
        if (abs(a[i][i] - 1.0) > EPS)
            return {};
    // Return right column (modified b)
    vd out;
    REP(i, sz(a))
        out.pb(a[i].back());
    return out;
}