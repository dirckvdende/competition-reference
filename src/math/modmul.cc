// Determines x * y % n without risking overflow issues
ll modMul(ll x, ll y, ll n) {
    ll res = 0;
    while (y > 0) {
        if (y % 2 == 1)
            res = (res + x) % n;
        x = (x * 2) % n;
        y /= 2;
    }
    return res;
}