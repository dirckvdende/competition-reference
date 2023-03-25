vi allCombs(ll n, ll m) {
    if (m >= n)
        return {~(~0LL << n)};
    if (m <= 0)
        return {0};
    // Prepend both 0 and 1
    vi z = allCombs(n - 1, m);
    vi o = allCombs(n - 1, m - 1);
    for (ll i : o)
        z.pb(i | (1LL << (n - 1)));
    return z;
}