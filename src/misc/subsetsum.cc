// Determines if there is a subset of x that sums up to
// T
bool subsetSum(vi x, ll T) {
    if (T == 0)
        return true;
    // Subset sums of first n items
    vi opt = {0};
    unordered_set<ll> found = {0};
    for (ll v : x) {
        ll s = sz(opt);
        REP(i, s) {
            ll c = opt[i] + v;
            if (c == T)
                return true;
            if (found.find(c) == found.end())
                opt.pb(c), found.insert(c);
        }
    }
    return false;
}