// This function can be used to keep track of the
// rolling hash of a string. Only use this if most of
// the strings to check for will not match!
struct RollingHash {
    // ip is the inverse of p mod M
    static const ll p = 1031, ip = 28802816,
    M = 33554467;
    // Keep track of hash, string and p^n mod M
    ll H; deque<char> q; vi ppow;
    RollingHash() : H(0), ppow({1}) { }
    // Check equality of strings, first using hash and
    // then using stored characters
    bool operator==(const RollingHash &other) {
        if (H != other.H)
            return false;
        if (sz(q) != sz(other.q))
            return false;
        auto itA = q.begin();
        auto itB = other.q.begin();
        for (; itA != q.end(); itA++, itB++)
            if (*itA != *itB)
                return false;
        return true;
    }
    void pup() { ppow.pb(ppow.back() * p % M); }
    // Append to end of string
    void push_back(char c) {
        H += c * ppow.back(), H %= M;
        pup(), q.push_back(c);
    }
    // Remove front end of string
    void pop_back() {
        ppow.pop_back();
        H -= q.back() * ppow.back(), H %= M;
        if (H < 0) H += M;
        q.pop_back();
    }
    // Add to front of string
    void push_front(char c) {
        H = c + p * H, H %= M;
        pup(), q.push_front(c);
    }
    // Remove from front of string
    void pop_front() {
        H = ip * (H - q.front()), H %= M;
        if (H < 0) H += M;
        ppow.pop_back(), q.pop_front();
    }
};