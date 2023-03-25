vi fact(ll n) {
    vi r;
    for (ll k = 2; n > 1 && k * k <= n; k++)
        while (n % k == 0)
            n /= k, r.pb(k);
    if (n > 1)
        r.pb(n);
    return r;
}