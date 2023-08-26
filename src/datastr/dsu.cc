// A disjoint union data structure, initialized as
// singletons. The structure also keeps track of set
// sizes and set sums. The values of all elements are
// initialized at 0
struct DisjointUnion {
    // Parent node, sum of nodes, number of nodes
    vi prev, sums, sizes;
    DisjointUnion(ll n) : prev(n, -1), sums(n, 0),
    sizes(n, 1) { }
    // Find a representative of the 
    ll find(ll x) {
        if (prev[x] < 0)
            return x;
        return prev[x] = find(prev[x]);
    }
    // Combine two sets, the root of the largest set
    // becomes the new root
    void combine(ll x, ll y) {
        if ((x = find(x)) == (y = find(y)))
            return;
        if (sizes[x] < sizes[y])
            swap(x, y);
        prev[y] = x;
        sizes[x] += sizes[y];
        sums[x] += sums[y];
    }
    // Get the size of the set that x is contained in
    ll size(ll x) {
        return sizes[find(x)];
    }
    // Update the value of the set that x is contained
    // in by adding v
    void update(ll x, ll v) {
        sums[find(x)] += v;
    }
    // Get the sum of the values of elements of the set
    // that x is contained in
    ll sum(ll x) {
        return sums[find(x)];
    }
};