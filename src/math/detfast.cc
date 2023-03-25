typedef vector<ld> vd;
typedef vector<vd> vvd;

// Calculates the determinant using Gaussian
// elimination. Modifies the original matrix!
ld det(vvd &a) {
    ld m = 1.0;
    // Put matrix in row echelon form
    REP(i, sz(a)) {
        // Find row where [i] is not zero
        ld j = i;
        while (j < sz(a) && a[j][i] == 0.0)
            j++;
        if (j == sz(a))
            return 0.0;
        if (i != j)
            swap(a[i], a[j]), m *= -1.0;
        // Divide row by value at [i]
        ld v = a[i][i];
        m *= v;
        REP(j, sz(a))
            a[i][j] /= v;
        // Subtract row from other rows (if needed)
        REP(j, sz(a)) {
            if (i == j)
                continue;
            ld p = a[j][i];
            REP(k, sz(a))
                a[j][k] -= p * a[i][k];
        }
    }
    // Calculate product of diagonal
    REP(i, sz(a))
        m *= a[i][i];
    return m;
}