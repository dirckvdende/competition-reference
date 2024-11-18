// Segment tree for associative operations, stored as
// a tree. Parent of i: i >> 1; Children of i: i << 1
// and i << 1 | 1. Implementation uses ints, but this
// can be adapted
struct SegmentTree {
    vi nodes; ll n;
    // Change operation here, can be any associative
    // operation. Does not need to be commutative!
    ll op(ll a, ll b) { return a + b; }
    // Identity value of operation
    ll id = 0;
    SegmentTree(const vi &src) : nodes(2 * sz(src)),
    n(sz(src)) {
        REP(i, n) nodes[n + i] = src[i];
        for (ll i = n - 1; i > 0; i--)
            nodes[i] = op(nodes[i << 1],
            nodes[i << 1 | 1]);
    }
    // Update a value in the tree (replaces value)
    void update(ll i, ll val) {
        i += n; nodes[i] = val;
        for (ll j = i; j > 1; j >>= 1) {
            // Left and right child, correctly ordered
            ll l = j, r = j ^ 1; if (l > r) swap(l, r);
            nodes[j >> 1] = op(nodes[l], nodes[r]);
        }
    }
    // Get accumulated value over [start, end]
    ll get(ll start, ll end) {
        // Accumulate over start and end, and combine
        ll rs = id, re = id;
        end++; start += n, end += n;
        for (; start < end; start >>= 1, end >>= 1) {
            if (start & 1)
                rs = op(rs, nodes[start++]);
            if (end & 1)
                re = op(nodes[--end], re);
        }
        return op(rs, re);
    }
};