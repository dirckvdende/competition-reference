// Sort by the number of occurences of each possible
// number in the list. Can also be used with a set if
// bounds are unknown, but likely quicksort is faster.
// Parameters are the list, the min and the max.
void countSort(vi &list, ll m, ll M) {
    vi occ(M - m + 1, 0);
    // Counts number of occurences
    for (ll &i : list)
        occ[i - m]++;
    // Remake list in correct order
    ll c = 0, i = 0;
    vi res;
    while (i < sz(occ)) {
        res.pb(i + m);
        c++;
        if (c >= occ[i])
            c = 0, i++;
    }
    list = res;
}