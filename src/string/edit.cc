ll editDistance(const string &src, const string &dst) {
    vvi dp(sz(src) + 1, vi(sz(dst) + 1, 0));
    REP(i, sz(src) + 1) REP(j, sz(dst) + 1) {
        if (i == 0)
            dp[i][j] = j;
        else if (j == 0)
            dp[i][j] = i;
        else if (src[i - 1] == dst[j - 1])
            dp[i][j] = dp[i - 1][j - 1];
        else
            dp[i][j] = 1 + min(dp[i][j - 1], min(
            dp[i - 1][j], dp[i - 1][j - 1]));
    }
    return dp[sz(src)][sz(dst)];
}