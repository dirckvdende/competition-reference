// Standard input/output: reads until whitespace!
cin >> var; cout << expr << endl;
// Read up to next line ending
getline(cin, str);
// Enable/disable fixed point display
cout << fixed << val; cout << defaultfloat << val;
// Throws exception when condition is not met
assert(expr);

// Sort using iterators from low to high
bool lt(T &a, T &b);
sort(begin, end, lt);
// Reverse using iterators
reverse(begin, end);
// Iterator operations
prev(it, n = 1), next(it, n = 1);
// Swaps values
swap(a, b);
// Unordered uses hashtable, otherwise binary tree
(unordered_)(multi)[set|map] obj;
obj.insert(item), obj.erase(item),
obj.lower_bound(item), obj.equal_range(item);
// Amortized constant time insert
vector<T> v;
v.pb(), v.pop_back();
// Reference to a string, no copies performed
string_view sv;
// constants
LLONG_MAX, INT_MAX;

// Lambda expressions + examples
[captures](params) specs {body}
[](int x) -> int { return -x; }
[&]() -> string { return s + "!"; }

// Complex numbers
complex<ld> num;
