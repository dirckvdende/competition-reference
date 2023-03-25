// Used to determine the power of a number x^p,
// modulo another number n, without doing all of
// the powers
ll modPower(ll x, ll p, ll n) {
    ll res = 1;
    while (p > 0) {
        if (p % 2 == 1)
            res = res * x % n;
        res = res * res % n;
        p /= 2;
    }
    return res;
}