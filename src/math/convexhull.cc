// Square distance between two points
ll sqDist(ii a, ii b) {
    return (a.x - b.x) * (a.x - b.x) +
    (a.y - b.y) * (a.y - b.y);
}

// Determine orientation of two points w.r.t. another
int orient(ii p, ii q, ii r) {
    ll val = (q.y - p.y) * (r.x - q.x) -
    (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

// Determines the points that make up the convex hull.
// Returns empty list if convex hull doesn't exist.
// WARNING: Makes changes to the points list!
vii convexHull(vii &points) {
    // Find bottom-most point (left in case of a tie)
    ii ym = points[0]; ll yi = 0;
    REP(i, sz(points)) {
        ii point = points[i];
        if (ii{point.y, point.x} < ii{ym.y, ym.x})
            ym = point, yi = i;
    }
    swap(points[0], points[yi]);
    ii p0 = points[0];
    // Sort by orientation w.r.t. first point, is case
    // of tie pick closest first
    sort(all(points), [&](ii &a, ii &b) -> int {
        int o = orient(p0, a, b);
        if (o == 0)
            return sqDist(p0, a) < sqDist(p0, b);
        return o == 2;
    });
    // Remove some points that are on the same line
    ll m = 1;
    rep(i, 1, sz(points)) {
        while (i < sz(points) - 1 && orient(p0,
        points[i], points[i + 1]) == 0)
            i++;
        points[m] = points[i], m++;
    }
    if (m < 3)
        return {};
    // Process points and keep track of stack
    vii s = {points[0], points[1], points[2]};
    rep(i, 3, m) {
        while (sz(s) > 1 && orient(s[sz(s) - 2],
        s.back(), points[i]) != 2)
            s.pop_back();
        s.pb(points[i]);
    }
    return s;
}