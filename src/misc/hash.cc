// Basic implementation of rolling hash, but without
// the extra functionality of adding and removing items
// easily
struct vihash {
    size_t operator()(const vi &v) const {
        static const ll p = 1031;
        static const ll M = 33554467;
        ll pw = 1;
        ll r = 0;
        for (const ll &i : v) {
            r += (i % M) * pw;
            r %= M;
            pw *= p, pw %= M;
        }
        return static_cast<size_t>(r);
    }
};