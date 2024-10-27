// Determines x * y % n without risking overflow issues
// x, y and n need to be in the range [0, n)
ll modMul(ll x, ll y, ll n) {
    ll step = (1ll << 61) / n;
    ll res = 0;
    while (y > 0) {
        res = (res + x * (y % step)) % n;
        x = (x * step) % n;
        y /= step;
    }
    return res;
}