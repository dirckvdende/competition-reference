// Returns the maximum value (v) that can be put in a
// knapsack of capacity W with weights (wt)
ll knapsack(int W, vi &wt, vi &v) {
    ll n = sz(wt);
    vvi K(n + 1, vi(W + 1));
    REP(i, n + 1) REP(w, W + 1) {
        if (i == 0 || w == 0)
            K[i][w] = 0;
        else if (wt[i - 1] <= w)
            K[i][w] = max(v[i - 1]
            + K[i - 1][w - wt[i - 1]],
            K[i - 1][w]);
        else
            K[i][w] = K[i - 1][w];
    }
    return K[n][W];
}