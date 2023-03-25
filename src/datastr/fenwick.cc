// Implements a fenwick tree, use prefixSum to get the
// sum of the first i elements, use update to change a
// value (adds v to the entry)
struct Fenwick {
    vi data;
    Fenwick(ll n) : data(n + 1, 0) { }
    ll prefixSum(ll i) {
        ll sm = 0;
        i++;
        while (i > 0)
            sm += data[i], i = i - (i & (-i));
        return sm;
    }
    void update(ll i, ll v) {
        i++;
        while (i < sz(data))
            data[i] += v, i = i + (i & (-i));
    }
};