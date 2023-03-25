// Disjoint Set Union structure, is initialized as n
// disjoint singletons. Implements combine and find
// operations
struct DisjointUnion {
    // Stores pointer to parent in the tree, or -1 if
    // the current node is the top node
    // (representative)
    vi prev;
    DisjointUnion(ll n) : prev(vi(n, -1)) { }
    ll find(ll x) {
        if (prev[x] < 0)
            return x;
        // This is an optimization to make find faster
        // on consecutive runs
        return prev[x] = find(prev[x]);
    }
    void combine(ll x, ll y) {
        if ((x = find(x)) == (y = find(y)))
            return;
        if (prev[x] > prev[y])
            swap(x, y);
        prev[x] += prev[y];
        prev[y] = x;
    }
};