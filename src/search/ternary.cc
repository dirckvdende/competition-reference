// Perform ternary search on interval [start, end]
// This will find the maximum M of a function f
ll ternarySearch(ll start, ll end) {
    while (start < end) {
        ll l = start + (end - start) / 3;
        ll r = end - (end - start) / 3;
        if (f(l) < f(r))
            start = l;
        else
            end = r;
    }
    return start;
}