namespace std {
    template<class T>
    struct hash<vector<T>> {
        hash<T> ht; hash<size_t> h;
        size_t operator()(const vector<T> &v) const {
            size_t out = 0;
            for (const T &i : v)
                out = h(out ^ ht(i));
            return out;
        }
    };
    template<class T, class S>
    struct hash<pair<T, S>> {
        hash<T> ht; hash<S> hs; hash<size_t> h;
        size_t operator()(const pair<T, S> &p) const {
            return h(ht(p.x) ^ h(hs(p.y)));
        }
    };
}