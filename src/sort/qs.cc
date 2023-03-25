// Partition part a list using the last element as a
// pivot. All lower elements will be left to the pivot
// and higher elements will be to the right. The
// (final) index of the pivot if returned.
ll partition(vi &v, ll start, ll end) {
    ll pivot = v[end];
    ll i = start - 1;
    rep(j, start, end)
        if (v[j] < pivot)
            i++, swap(v[i], v[j]);
    swap(v[i + 1], v[end]);
    return i + 1;
}

// Sort a list by recursively partitioning
void quickSort(vi &v, ll start = 0, ll end = -1) {
    if (end == -1)
        end = sz(v) - 1;
    if (start >= end)
        return;
    ll pi = partition(v, start, end);
    quickSort(v, start, pi - 1);
    quickSort(v, pi + 1, end);
}