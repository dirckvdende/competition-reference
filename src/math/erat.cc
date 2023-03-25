// Returns the list of all primes that are lower than n
// using a sieve of Eratosthenes.
vi primeSieve(ll n) {
    vi primes(n + 1, 1);
    for (ll p = 2; p * p <= n; p++)
        if (primes[p])
            for (ll i = p * p; i <= n; i += p)
                primes[i] = 0;
    vi primeList;
    rep(i, 2, n + 1)
        if (primes[i])
            primeList.pb(i);
    return primeList;
}