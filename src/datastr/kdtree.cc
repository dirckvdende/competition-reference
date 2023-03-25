// Implements a k-d tree, change dimension based on
// needed. All points inserted must be of size k.
// Supports search and insert operations. Deletion can
// be added by marking points as unused
struct KDTree {
    // Change dimension here
    const ll k = 2;
    // Stores point data and children
    vvi points; vii ch; ll root = -1;
    // Helper insert function, given are the root node
    // of the current subtree and the current dimension
    ll insert(const vi &p, ll i, ll d) {
        // If there is no root, a new node needs to be
        // created
        if (i == -1) {
            points.pb(p);
            ch.pb({-1, -1});
            return sz(points) - 1;
        }
        // Check left or right in current dimension
        if (p[d] < points[i][d]) {
            ll c = insert(p, ch[i].x, (d + 1) % k);
            ch[i].x = c;
        } else {
            ll c = insert(p, ch[i].y, (d + 1) % k);
            ch[i].y = c;
        }
        return i;
    }
    // Insert a point
    void insert(const vi &p) {
        root = insert(p, root, 0);
    }
    // Search function, given are the root node of the
    // current subtree and the current dimension
    bool search(const vi &p, ll i = -2, ll d = 0) {
        if (i == -2)
            i = root;
        if (i == -1)
            return false;
        if (p == points[i])
            return true;
        // Search is done in the same way as insert
        if (p[d] < points[i][d])
            return search(p, ch[i].x, (d + 1) % k);
        return search(p, ch[i].y, (d + 1) % k);
    }
};