// Implementation of an unbalanced interval tree that
// supports inserting intervals and finding point
// matches
struct IntervalTree {
    // List of intervals, maximum values of nodes,
    // children, and root node
    vii vals; vi mx; vii ch; ll root = -1;
    // Insert interval into tree
    void insert(ii val) {
        // Keep track of parent node and which side the
        // child node is
        ll parent = -1, node = root;
        bool side = true;
        // Traverse the tree
        while (node != -1) {
            parent = node;
            // Update maximum
            if (val.y > mx[node])
                mx[node] = val.y;
            // Insert left or right
            if (val.x < vals[node].x)
                node = ch[node].x, side = true;
            else
                node = ch[node].y, side = false;
        }
        if (parent == -1)
            root = 0;
        else
            (side ? ch[parent].x : ch[parent].y) =
            sz(vals);
        vals.pb(val), mx.pb(val.y), ch.pb({-1, -1});
    }
    // Retrieve all overlapping intervals with given
    // point
    vii search(ll val) {
        if (root == -1)
            return {};
        vii res;
        queue<ll> q; q.push(root);
        while (!q.empty()) {
            ll node = q.front();
            q.pop();
            // Current node interval contains point
            if (vals[node].x <= val && val <=
            vals[node].y)
                res.pb(vals[node]);
            // Search left node
            if (ch[node].x != -1 && val <=
            mx[ch[node].x])
                q.push(ch[node].x);
            // Search right node
            if (ch[node].y != -1 && val >=
            vals[node].x)
                q.push(ch[node].y);
        }
        return res;
    }
};