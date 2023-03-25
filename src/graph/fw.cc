// Has as input the graph distances represented using
// an adjacency matrix. This matrix is then modified to
// reflect minimal path distances between nodes. When
// there is no connection between nodes, this should be
// represented with LLONG_MAX
void floydWarshall(vvi &d) {
    REP(k, sz(d)) REP(i, sz(d)) REP(j, sz(d))
        if (d[i][j] > d[i][k] + d[k][j]
        && LLONG_MAX - d[i][k] > d[k][j])
            d[i][j] = d[i][k] + d[k][j];
}