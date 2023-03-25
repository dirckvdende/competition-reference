// + = add          - = subtract
// * = multiply     / = divide
// n = number
struct Node { char type; vi children; ll val; };

// Implements a parser of simple expressions: sums and
// products. Output is put in "out", where children are
// indices of other nodes. Use read() to parse input.
// Assumes that the input is a valid expression. The
// last node in the list is the root node
struct Parser {
    ll i = -1;
    const string &inp;
    vector<Node> out;
    Parser(const string &inp) : inp(inp) { }
    char cur() const { return inp[i]; }
    void next() { i++; while (inp[i] == ' ') i++; }
    void read() { next(); readSum(); }
    void readSum() {
        readProd();
        ll a = sz(out) - 1;
        while (cur() == '+' || cur() == '-') {
            char c = cur();
            next(), readProd();
            ll b = sz(out) - 1;
            out.pb({c, {a, b}}), a = sz(out) - 1;
        }
    }
    void readProd() {
        readElem();
        ll a = sz(out) - 1;
        while (cur() == '*' || cur() == '/') {
            char c = cur();
            next(), readElem();
            ll b = sz(out) - 1;
            out.pb({c, {a, b}}), a = sz(out) - 1;
        }
    }
    // Only reads numbers
    void readElem() {
        if (cur() == '(') {
            // Skip '(' and corresponding ')'
            return next(), readSum(), next();
        }
        ll n = 0;
        while ('0' <= cur() && cur() <= '9')
            n *= 10, n += cur() - '0', next();
        out.pb({'n', {}, n});
    }
    // Evaluate expression
    ll eval(ll i = -1) {
        if (i == -1)
            i = sz(out) - 1;
        if (out[i].type == 'n')
            return out[i].val;
        ll a = eval(out[i].children[0]);
        ll b = eval(out[i].children[1]);
        switch (out[i].type) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            default: throw exception();
        }
    }
};