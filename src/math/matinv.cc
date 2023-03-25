typedef vector<ld> vd;
typedef vector<vd> vvd;

// Computes the inverse of a matrix using Gaussian
// elimination. Assumes the matrix is invertable
// (det != 0) and square. Modifies the input matrix!
vvd inv(vvd &a) {
    // Start with identity matrix
    vvd res(sz(a), vd(sz(a)));
    REP(i, sz(a)) REP(j, sz(a))
        res[i][j] = i == j ? 1.0 : 0.0;
    REP(i, sz(a)) {
        // Move row with non-zero at [i] to front
        ll j = i;
        while (a[j][i] == 0)
            j++;
        if (i != j)
            swap(a[i], a[j]), swap(res[i], res[j]);
        // Divide row by value at [i]
        ld v = a[i][i];
        REP(j, sz(a))
            a[i][j] /= v, res[i][j] /= v;
        // Subtract row from other rows (if needed)
        REP(j, sz(a)) {
            if (i == j)
                continue;
            ld p = a[j][i];
            REP(k, sz(a))
                a[j][k] -= p * a[i][k],
                res[j][k] -= p * res[i][k];
        }
    }
    return res;
}