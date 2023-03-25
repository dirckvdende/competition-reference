// Calculates n choose k. Returns double because of
// large numbers, see function below for long longs
ld binom(ll n, ll k) {
    if (k > n)
        return 0.0;
    ld r = 1.0;
    REP(i, n - k)
        r *= ld(n - i) / ld(n - k - i);
    return r;
}
// This variant is slower than the above
ll binom(ll n, ll k) {
    if (k > n)
        return 0;
    ll r = 1;
    REP(i, n - k)
        r *= i + k + 1;
    REP(i, n - k)
        r /= i + 1;
    return r;
}