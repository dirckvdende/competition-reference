// Used to determine the power of a number x^p,
// modulo another number n, without doing all of
// the powers
ll modPower(ll x, ll p, ll n) {
    ll res = 1;
    x %= n;
    while (p > 0) {
        // For large modulo (>2^31) use modMul instead
        if (p % 2 == 1)
            res = res * x % n;
        x = x * x % n;
        p /= 2;
    }
    return res;
}