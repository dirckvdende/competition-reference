// Calculates determinant using Gaussian elimination.
// The input matrix is modified! Assumes matrix is
// square!
ld det(vvd &a) {
    gauss(a);
    ld out = 1.0;
    REP(i, sz(a))
        out *= a[i][i];
    return out;
}