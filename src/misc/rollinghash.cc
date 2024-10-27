// Cached prime powers
static vi ppow = {1};
// This can be used to keep track of the rolling hash
// of a string. Access the hash using H. If you want to
// keep track of the contained string, use a deque
struct RollingHash {
    // ip is the inverse of p mod M. Different primes
    // can be found earlier in the reference!
    static const ll p = 8125343,
    ip = 34789068517540942, M = 36028797018963971;
    // Keep track of hash and string size
    ll H, size;
    RollingHash() : H(0), size(0) { }
    // Update cached prime powers
    void pup() {
        while (size >= sz(ppow))
            ppow.pb(modMul(ppow.back(), p, M));
    }
    void norm(ll &c) { c %= M; if (c < 0) c += M; }
    // Append to end of string
    void push_back(ll c) {
        norm(c);
        H += modMul(c, ppow[size], M); norm(H);
        size++; pup();
    }
    // Remove front end of string
    void pop_back(ll c) {
        norm(c);
        H -= modMul(c, ppow[size - 1], M); norm(H);
        size--;
    }
    // Add to front of string
    void push_front(ll c) {
        norm(c);
        H = c + modMul(p, H, M); norm(H);
        size++; pup();
    }
    // Remove from front of string
    void pop_front(ll c) {
        H = modMul(ip, H - c, M);
        size--;
    }
};