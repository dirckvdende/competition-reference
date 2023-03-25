// Segment tree, which supports updating a value and
// finding the sum of an interval [start, end]
struct SegmentTree {
    vi nodes;
    ll n;
    SegmentTree(vi &src) : nodes(vi(2 * sz(src), 0)),
    n(sz(src)) {
        REP(i, n)
            nodes[n + i] = src[i];
        for (ll i = n - 1; i > 0; i--)
            nodes[i] = nodes[i << 1] +
            nodes[i << 1 | 1];
    }
    void update(ll i, ll val) {
        nodes[i + n] = val, i += n;
        for (ll j = i; j > 1; j >>= 1)
            nodes[j >> 1] = nodes[j] + nodes[j ^ 1];
    }
    ll getSum(ll start, ll end) {
        ll r = 0; end++;
        for (start += n, end += n; start < end;
        start >>= 1, end >>= 1) {
            if (start & 1)
                r += nodes[start++];
            if (end & 1)
                r += nodes[--end];
        }
        return r;
    }
};