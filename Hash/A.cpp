#include <bits/stdc++.h>

using namespace std;

#define name "A"
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

const int MAXN = 1e6 + 11;
const ll MOD = 1e9 + 7;
const ll base = 31;
//const int INF = 1e9 + 11; const ll INFF = 1e18 + 11;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

ll POW[MAXN], hashT[MAXN];
string a, b;

ll getHash(int l, int r) {
    return (hashT[r] - hashT[l - 1] * POW[r - l + 1] + MOD * MOD) % MOD;
}

void process(void) {
    cin >> a >> b;
    int n = a.size(), m = b.size();
    a = " " + a;
    b = " " + b;
    ll hashP = 0;
    FORE(i, 1, n) hashP = (hashP * base + a[i] - 'a' + 1) % MOD;
    POW[0] = 1;
    FORE(i, 1, m) {
        POW[i]  = (POW[i - 1] * base) % MOD;
        hashT[i] = (hashT[i - 1] * base + b[i] - 'a' + 1) % MOD;
    }
    vector<int> pos;
    FORE(i, 1, m - n + 1) if (hashP == getHash(i, i + n - 1)) pos.push_back(i);
    cout << pos.size() << el;
    FOR(i, 0, pos.size()) cout << pos[i] << " ";
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
