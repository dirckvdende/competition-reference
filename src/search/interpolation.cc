// Returns the index of the found element, or -1 if it
// wasn't found
ll interpolationSearch(const vi &a, ll x) {
    ll start = 0, end = sz(a) - 1;
    while (start <= end && a[start] <= x &&
    x <= a[end]) {
        if (start == end)
            return a[start] == x ? start : -1;
        ll pos = start + (end - start) * (x - a[start])
            / (a[end] - a[start]);
        if (a[pos] == x)
            return pos;
        if (a[pos] < x)
            start = pos + 1;
        else
            end = pos - 1;
    }
    return -1;
}