// Find a stable matching that is best for group A and
// worst for group B. The preference lists are given
// as a list of indices, from most to least preferred.
// It returns a list of indices, the item from group
// A that each item from group B is matched to
vi stableMatching(const vvi &prefA, const vvi &prefB) {
    ll n = sz(prefA);
    // All items are marked as free
    vi freeA(n, 1), freeB(n, 1); ll matched = 0;
    vi match(n);
    // Assign each item from A to an item from B
    while (matched < n) {
        // Pick first free item from list A
        ll a = 0;
        while (!freeA[a]) a++;
        // Go over items from B
        for (ll i = 0; i < n && freeA[a]; i++) {
            ll b = prefA[a][i];
            // If free: assign, otherwise check if it
            // is a better alternative to current
            // assignment
            if (freeB[b]) {
                freeA[a] = freeB[b] = 0;
                match[b] = a;
                matched++;
            } else {
                ll old = match[b];
                // Check if a is preferred over old
                bool pref = false;
                REP(i, n) {
                    if (prefB[b][i] == a) {
                        pref = true; break;
                    } else if (prefB[b][i] == old) {
                        break;
                    }
                }
                if (pref) {
                    match[b] = a;
                    freeA[a] = 0, freeA[old] = 1;
                }
            }
        }
    }
    return match;
}