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

const int MAXN = 100, MAX = 1e6 + 11;
const int MOD = 998244353;
//const int INF = 1e9 + 11; const ll INFF = 1e18 + 11;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int n, c[MAXN][MAXN], f[MAXN][MAXN];
pii d[MAXN];

void process(void) {
    cin >> n;
    FORE(i, 1, 2 * n) {
        cin >> d[i].fi;
        if (i > n) d[i].se = 1;
    }
    FORE(i, 1, n) FORE(j, 1, n) cin >> c[i][j];
    sort(d + 1, d + 2 * n +  1);
//    FORE(i, 1, 2 * n) cout << d[i].fi << " ";
    int res = 0;
    while (next_permutation(d + 1, d + 2 * n + 1)) {
        memset(f, 0, sizeof f);
        FORE(i, 1, 2 * n) {
            if (d[i].se == 0) {
                FORE(j, 1, n) f[d[i].fi][j] = d[i].fi;
            } else {
                FORE(j, 1, n) f[j][d[i].fi] = d[i].fi;
            }
        }
        bool check = 1;
        FORE(i, 1, n) {
            FORE(j, 1, n) if (c[i][j] != f[i][j]) {
                check = 0;
                break;
            }
            if (check == 0) break;
        }
        if (check) res++;
    }
    cout << res % MOD;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	file("paint");
//	int t; cin >> t; while(t--)
	process();
	return 0;
}
