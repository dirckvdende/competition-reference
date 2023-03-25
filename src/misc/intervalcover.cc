// Check if a collection of intervals covers a specific
// interval. WARNING: Modifies the input
bool intervalCover(vii &vals, ii val) {
    sort(all(vals));
    ll mx = val.x;
    for (ii v : vals) {
        if (v.y <= val.x)
            continue;
        if (v.x > mx)
            return false;
        mx = max(v.y, mx);
    }
    return mx >= val.y;
}