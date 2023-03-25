ll invMerge(vi &A, ll lo, ll mid, ll hi) {
    ll i = lo, j = mid + 1, k = 0, r = 0;
    vi B(hi - lo + 1, 0);
    while (i <= mid && j <= hi) {
        if (A[i] <= A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++], r += (mid + 1) - i;
    }
    while (i <= mid) B[k++] = A[i++];
    while (j <= hi) B[k++] = A[j++];
    rep(x,lo,hi + 1) A[x] = B[x - lo];
    return r;
}

// Also sorts the array (using mergesort)
ll inversions(vi &A, ll lo = 0, ll hi = -1) {
    if (hi == -1) hi = sz(A) - 1;
    ll r = 0;
    if (lo < hi) {
        ll mid = (lo + hi) / 2;
        r += inversions(A, lo, mid);
        r += inversions(A, mid + 1, hi);
        r += invMerge(A, lo, mid, hi);
    }
    return r;
}