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

const int MAXN = 5e5 + 11, MAX = 1e6 + 11;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 11; const ll INFF = 1e18 + 11;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int n, q, a[MAXN];
int dp[MAXN];

int Mul(int a, int b) {
    ll d = 1LL * a * b;
    return d % MOD;
}

void process(void) {
    cin >> n >> q;
    FORE(i, 1, n) cin >> a[i];
    a[0] = a[n + 1] = -INF;
    while (q--) {
        int x;
        cin >> x;
        memset(dp, 0, sizeof dp);
        dp[x] = 1;
        int pos_L = x - 1, pos_R = x + 1;
        while (pos_L > 0 || pos_R <= n) {
            if (a[pos_L] < a[pos_R]) {
                dp[pos_R] = dp[x];
                x = pos_R;
                pos_R++;
            } else if (a[pos_L] > a[pos_R]) {
                dp[pos_L] = dp[x];
                x = pos_L;
                pos_L--;
            } else {
                dp[pos_R] = Mul(2, dp[x]);
                x = pos_R;
                pos_R++;
            }
        }
        cout << dp[x] << "\n";
    }
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	file("NOCTURNE");
//	int t; cin >> t; while(t--)
	process();
	return 0;
}
