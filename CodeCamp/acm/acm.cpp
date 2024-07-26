#include <bits/stdc++.h>

using namespace std;

#define name "acm"
#define el  "\n"
#define fi  first
#define se  second
#define BIT(x, i) ((x) & (1 << (i)))
#define MASK(x) (1 << (x))
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define FORE(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORDE(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using vi = vector<int>;

template<class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; };
template<class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; };

/// Author: tinhnopro
// end of template

const int MAXN = 3e4 + 11, MAX = 1e6 + 11;
//const int MOD = 1e9 + 7;
//const int INF = 1e9 + 11; const ll INFF = 1e18 + 11;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int s[MAXN][15], n;
ll g[MASK(11) + 1], f[MASK(11) + 1];

void process(void) {
    cin >> n;
    FORE(i, 1, n) FORE(j, 1, 11) cin >> s[i][j];
    FORE(i, 1, n) {
        memset(f, 0, sizeof f);
        FOR(t, 1, MASK(11)) {
            int j = __builtin_ffs(t);
            f[t] = f[t ^ MASK(j - 1)] + s[i][j];
            maximize(g[t], f[t]);
        }
    }
    ll ans = 0;
    FOR(t1, 0, MASK(11)) {
        FOR(t2, t1 + 1, MASK(11)) if (!(t1 & t2)) {
//            cout << g[t1] << " " << g[t2] << "\n";
            int t3 = (MASK(11) - 1) ^ t1 ^ t2;
//            cout << t1 << " " << " " << t2 << " " << t3 << " " << MASK(11) << el;
            ll res = g[t1] + g[t2] + g[t3];
            maximize(ans, res);
        }
    }
    cout << ans;
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
