// Longest increasing subsequence of vector v
ll longestIncreasing(const vi &v) {
    // d[i] = lowest number that subsequence of length
    // i can end in
    vi d(sz(v) + 1, LLONG_MAX);
    d[0] = LLONG_MIN;
    ll r = 0;
    for (ll val : v) {
        ll i = upper_bound(all(d), val) - d.begin();
        // Change to <= for longest non-decreasing
        if (d[i - 1] <= val && val <= d[i]) {
            if (d[i] == LLONG_MAX)
                r++;
            d[i] = val;
        }
    }
    return r;
}