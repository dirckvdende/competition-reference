// Since C++ can return negative numbers, for checking
// if two numbers are congruent mod n, we need this
bool modEq(ll a, ll b, ll n) {
    ll aa = a % n, bb = b % n;
    return aa == bb || aa == bb + n || aa + n == b;
}