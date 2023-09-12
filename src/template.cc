#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define x first
#define y second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define REP(i, b) rep(i, 0LL, b)
#ifdef DEBUG
    #define DBG(x) cerr << __LINE__ << ": " << #x \
    << " = " << (x) << endl
#else
    #define DBG(x) ((void)(x))
#endif

template <class T> ostream &operator<<(ostream &os,
const vector<T> &v) {
    os << '[';
    for (const T &i : v) os << i << ", ";
    return os << ']' << endl;
}
template <class T, class S> ostream &operator<<(ostream
&os, const pair<T, S> &v) {
    return os << '{' << v.x << ", " << v.y << '}';
}

void run() {
}

int main() {
    // No automatic flushing before cin
    cin.tie(NULL);
    // Mixed C/C++ IO
    ios_base::sync_with_stdio(false);
    // Enough for double precision
    cout.precision(20);
    run();
    return 0;
}