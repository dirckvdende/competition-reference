// Return the longest common subsequence in two strings
// Returns just one if there are multiple
string longestCommon(const string &A, const string &B)
{
    // [first i of A][first j of B] = (max, last chars
    // in A and B)
    vector<vector<pair<ll, ii>>> dp(sz(A) + 1,
    vector<pair<ll, ii>>(sz(B) + 1));
    REP(i, sz(A) + 1) REP(j, sz(B) + 1) {
        dp[i][j] = {0, {-1, -1}};
        if (i == 0 || j == 0)
            continue;
        if (dp[i - 1][j].x > dp[i][j].x)
            dp[i][j] = dp[i - 1][j];
        if (dp[i][j - 1].x > dp[i][j].x)
            dp[i][j] = dp[i][j - 1];
        if (dp[i - 1][j - 1].x + 1 > dp[i][j].x &&
        A[i - 1] == B[j - 1])
            dp[i][j] = {dp[i - 1][j - 1].x + 1,
            {i - 1, j - 1}};
    }
    // Reconstruct string from "last char" entries
    string rec = "";
    ll i = sz(A), j = sz(B);
    while (i >= 0 && j >= 0) {
        pair<ll, ii> entry = dp[i][j];
        rec.pb(A[entry.y.x]);
        i = entry.y.x, j = entry.y.y;
    }
    reverse(all(rec));
    return rec;
}