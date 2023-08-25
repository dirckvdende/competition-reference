// Find x such that a * x = b (mod n)
// Solution exists iff gcd(a, n) divides b
ll modSys(ll a, ll b, ll n) {
    ll s, t;
    ll g = euclidGcd(a, n, s, t);
    assert(b % g == 0);
    ll res = s * (b / g);
    return res < 0 ? res + n : res;
}
// Determines the inverse of a mod n
ll modInv(ll a, ll n) {
    return modSys(a, 1, n);
}