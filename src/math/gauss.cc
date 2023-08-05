const ld EPS = 1e-12;
typedef vector<ld> vd;
typedef vector<vd> vvd;

// Perform gaussian elimination on a matrix, which does
// not have to be square. The input matrix is modified!
// Returns the determinant of the matrix if it's square
ld gauss(vvd &a) {
    ll n = sz(a), m = sz(a[0]); // n rows, m columns
    ld det = 1.0;
    // Loop over pivot index
    REP(i, min(n, m)) {
        // Search for row where i'th column is non-zero
        ll j = i;
        for (; j < n; j++)
            if (abs(a[j][i]) > EPS) {
                if (i != j)
                    swap(a[i], a[j]), det *= -1.0;
                break;
            }
        // No pivot in this column
        if (j == n) {
            det = 0.0;
            continue;
        }
        // Reduce such that 1 is in the pivot column
        ld d = a[i][i];
        det *= d;
        REP(j, m)
            a[i][j] /= d;
        // Subtract row from all other rows
        REP(j, n)
            if (i != j) {
                ld d = a[j][i];
                REP(k, m)
                    a[j][k] -= d * a[i][k];
            }
    }
    return det;
}