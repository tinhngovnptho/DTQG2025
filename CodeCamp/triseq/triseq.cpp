#include <bits/stdc++.h>

using namespace std;

#define name "triseq"
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
using pii = pair<int, int>;
using vi = vector<int>;

template<class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; };
template<class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; };

/// Author: tinhnopro
// end of template

//const int MAXN = 5e5 + 11, MAX = 1e6 + 11;
//const int MOD = 1e9 + 7;
//const int INF = 1e9 + 11; const ll INFF = 1e18 + 11;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};


#define int ll

int n, t, a[100];
ll f[25][25][25][25], d = 0;

ll calc(int i, int min1, int min2, int maxx) {
    if (i > n) {
        return f[i][min1][min2][maxx] = (min1 + min2 > maxx);
    }
    if (f[i][min1][min2][maxx] != -1) return f[i][min1][min2][maxx];
    ll cnt = 0;
    FORE(v, 1, n) {
        int nmin1 = min1, nmin2 = min2;
        if (minimize(nmin1, v)) nmin2 = min1;
        else minimize(nmin2, v);
        cnt += calc(i + 1, nmin1, nmin2, max(maxx, v));
    }
    return f[i][min1][min2][maxx] = cnt;
}

void order_to_config(int i, int min1, int min2, int maxx) {
    if (i > n) {
        return ;
    }
    FORE(v, 1, n) {
        int nmin1 = min1, nmin2 = min2;
        if (minimize(nmin1, v)) nmin2 = min1;
        else minimize(nmin2, v);
        if (t > f[i + 1][nmin1][nmin2][max(v, maxx)]) {
            t -= f[i + 1][nmin1][nmin2][max(v, maxx)];
        } else {
//            cout << t << ": ";
            cout << v << " ";
            order_to_config(i + 1, nmin1, nmin2, max(v, maxx));
            break;
        }
    }
}

void config_to_order(int i, int min1, int min2, int maxx) {
    if (i > n) {
        return ;
    }
    FORE(v, 1, n) {
        int nmin1 = min1, nmin2 = min2;
        if (minimize(nmin1, v)) nmin2 = min1;
        else minimize(nmin2, v);
        if (v < a[i]) d += f[i + 1][nmin1][nmin2][max(v, maxx)];
        else {
            config_to_order(i + 1, nmin1, nmin2, max(v, maxx));
            break;
        }
    }
}


void process(void) {
    cin >> n >> t;
    FORE(i, 1, n) cin >> a[i];
    memset(f, -1, sizeof f);
    calc(1, n + 1, n + 1, 0);
    cout << f[1][n + 1][n + 1][0] << el;
    order_to_config(1, n + 1, n + 1, 0);
    cout << el;
    config_to_order(1, n + 1, n + 1, 0);
    cout << d + 1;
}

signed main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
	}
//	int t; cin >> t; while(t--)
	process();
	return 0;
}
