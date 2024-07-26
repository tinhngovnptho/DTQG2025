#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define BIT(x, i) ((x) & (1 << (i)))
#define MASK(x) (1 << (x))
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define FORE(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORDE(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define file(name) if (fopen(name".inp", "r")) { freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout); }

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;

template<class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; };
template<class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; };

/// Author: tinhnopro
// end of template

const int MAXN = 5e3 + 11, MAX = 1e6 + 11;
//const int MOD = 1e9 + 7;
//const int INF = 1e9 + 11; const ll INFF = 1e18 + 11;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int n;
ll a[MAXN], b[MAXN], tmp[MAXN];
ll  ans = 0;

namespace Sub1 {
    void solve() {
        FORE(i, 1, n) ans += a[i] * b[i];
        ll res;
        FORE(l, 1, n) FORE(r, l, n) {
            res = 0;
            FORE(i, l, r) a[i] = b[l + r - i] - a[i];
            FORE(i, 1, n) res += a[i] * b[i];
            maximize(ans, res);
//            cout << l << " " << r << " " << ans << "\n";
            FORE(i, l, r) a[i] = tmp[i];
        }
        cout << ans << "\n";
    }
}

namespace Sub2 {
    ll sumPrefix[MAXN], f[MAXN][MAXN];
    void solve() {
        FORE(i, 1, n) sumPrefix[i] = sumPrefix[i - 1] + a[i] * b[i];
        FORE(i, 1, n) ans += a[i] * b[i];
        ll res, tmp = ans;
        memset(f, 0, sizeof f);
        FORE(len, 1, n) {
            FORE(l, 1, n) {
                int r = l + len - 1;
                f[l][r] = f[l + 1][r - 1] + b[l] * b[r];
            }
        }
//        FORE(l, 1, n) FORE(r, l, n) cout << l << " " << r << " " << f[l][r] << "\n";

        FORE(l,  1, n) FORE(r, l, n) {
            res = tmp + 2 * (f[l][r] - sumPrefix[r] + sumPrefix[l - 1]);
            maximize(ans, res);
        }
        cout << ans;
    }
}

void process(void) {
    cin >> n;
    FORE(i, 1, n) {
        cin >> a[i];
        tmp[i] = a[i];
    }
    FORE(i, 1, n) cin >> b[i];
    if (n <= 100) return void(Sub1::solve());
    return void(Sub2::solve());
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	file("LROP");
//	int t; cin >> t; while(t--)
	process();
	return 0;
}
