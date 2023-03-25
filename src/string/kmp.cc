// Calculate the preprocessing pattern table for KMP
// This table works for finding a pattern in any string
vi kmpTable(const string &pat) {
    vi T(sz(pat) + 1, -1);
    ll pos = 1, cnd = 0;
    while (pos < sz(pat)) {
        if (pat[pos] == pat[cnd]) {
            T[pos] = T[cnd];
        } else {
            T[pos] = cnd;
            while (cnd >= 0 && pat[pos] != pat[cnd])
                cnd = T[cnd];
        }
        pos++, cnd++;
    }
    T[pos] = cnd;
    return T;
}

// Returns the first position at which the pattern
// occurs, or -1 if the pattern does not occur
// Function can be modified to return a list of indices
ll kmp(const string &str, const string &pat) {
    ll j = 0, k = 0;
    vi T = kmpTable(pat);
    while (j < sz(str)) {
        if (pat[k] == str[j]) {
            j++, k++;
            if (k == sz(pat)) {
                return j - k;
                // In case we need multiple occurences:
                k = T[k];
            }
        } else {
            k = T[k];
            if (k < 0)
                j++, k++;
        }
    }
    return -1;
}