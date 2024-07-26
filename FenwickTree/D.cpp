#include <bits/stdc++.h>

using namespace std;

#define name "D"
#define el  "\n"
#define fi  first
#define se  second
#define BIT(x, i) ((x) & (1 << (i)))
#define MASK(x) (1 << (x))
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define FORE(ti, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORDE(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;

template<class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; };
template<class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; };

/// Author: tinhnopro
// end of template

const int MAXN = 5e5 + 11, MAX = 1e6 + 11;
const int MOD = 1e9 + 7;
//const int INF = 1e9 + 11; const ll INFF = 1e18 + 11;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int n, a[MAXN];
pii bit[MAXN];

#define node(i) ((i) & (-i))

void add(int &a, int &b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void update(int x, pii v) {
    for (; x <= n; x += node(x))
        if (bit[x].fi < v.fi) bit[x] = v;
        else if (bit[x].fi == v.fi) add(bit[x].se, v.se);
}

pii Get(int x) {
    pii res = {0, 1};
    for (; x; x -= node(x))
        if (bit[x].fi > res.fi) res = bit[x];
        else if (bit[x].fi == res.fi) add(res.se, bit[x].se);
    return res;
}

void Compress(void) {
    vector<int> v(a + 1, a + n + 1);
    sort(ALL(v));
    v.resize(unique(ALL(v)) - v.begin());
    FORE(i, 1, n) a[i] = lower_bound(ALL(v), a[i]) - v.begin() + 1;
}


void process(void) {
    cin >> n;
    FORE(i, 1, n) cin >> a[i];
    Compress();
    FORE(i, 1, n) {
        pii tmp = Get(a[i] - 1);
        tmp.fi++;
        update(a[i], tmp);
    }
    cout << Get(n).se;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
	}
//	int t; cin >> t; while(t--)
	process();
	return 0;
}
