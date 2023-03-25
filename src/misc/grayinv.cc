ll grayInv(ll g) {
    ll n = 0;
    while (g != 0)
        n ^= g, g >>= 1;
    return n;
}