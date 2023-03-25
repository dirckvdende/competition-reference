// Check if the number n is prime
bool isPrime(ll n) {
    // Miller-Rabin only works for odd numbers
    if (n < 2 || n % 2 == 0)
        return n == 2;
    // Determine s > 0 and d odd > 0 such that
    // n - 1 = 2^s * d
    ll d = n - 1, s = 0;
    while (d % 2 == 0)
        d /= 2, s++;
    // This list needs to be extended for numbers >2^64
    for (ll a : {2, 3, 7, 11, 13, 17, 19, 23, 29, 31,
    37}) {
        if (n == a)
            return true;
        ll x = modPower(a, d, n);
        REP(i, s) {
            ll y = (x * x) % n;
            if (y == 1 && x != 1 && x != n - 1)
                return false;
            x = y;
        }
        if (x != 1)
            return false;
    }
    return true;
}