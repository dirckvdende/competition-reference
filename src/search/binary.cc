// Perform binary search on interval [start, end]
// f should evaluate to false for lower values and
// to true for higher values. Returns the lowest value
// for which f is true
ll binarySearch(ll start, ll end) {
    while (start < end) {
        ll mid = (start + end) / 2;
        if (f(mid))
            end = mid;
        else
            start = mid + 1;
    }
    return start;
}