// Calculates determiniant recursively. Assumes matrix
// is square
ll subdet(const vvi &m, vector<bool> &d, ll i) {
    if (i >= m.size())
        return 1;
    ll r = 0, c = 0;
    REP (j,m.size()) if (d[j]) {
        d[j] = false;
        r += m[i][j] * subdet(m, d, i + 1)
        * (++c % 2 * 2 - 1);
        d[j] = true;
    }
      return r;
}
ll det(const vvi &m) {
    vector<bool> d(m.size(), true);
    return subdet(m, d, 0);
}