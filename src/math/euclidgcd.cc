// Euclidean algorithm to find numbers t, s such
// that as + bt = gcd(a, b). Here s and t are the
// smallest such numbers possible. The function
// returns the gcd(a, b). The s and t may have the
// wrong sign!
ll euclidGcd(ll a, ll b, ll &s, ll &t) {
    ll r = b, rr = a;
    s = 0, t = 1;
    ll ss = 1, tt = 0;
    while (rr != 0) {
        ll q = r / rr;
        r -= q * rr; swap(r, rr);
        s -= q * ss; swap(s, ss);
        t -= q * tt; swap(t, tt);
    }
    return r;
}