ll phi(ll n) {
    ll res = n;
    for (ll p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            res -= res / p;
        }
    }
    // If n is prime itself
    if (n > 1)
        res -= res / n;
    return res;
}