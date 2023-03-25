ll kthComb(ll n, ll m, ll k) {
    if (m >= n)
        return ~(~0LL << n);
    if (m <= 0)
        return 0;
    // Zeros first, then ones
    ll s = binom(n - 1, m);
    if (k < s)
        return nthComb(n - 1, m, k);
    return nthComb(n - 1, m - 1, k - s) |
    (1LL << (n - 1));
}