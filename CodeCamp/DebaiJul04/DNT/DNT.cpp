#include <bits/stdc++.h>

using namespace std;

#define name "DNT"
#define el  "\n"
#define ll  long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi  first
#define se  second
#define BIT(x, i) ((x) & (1 << (i)))
#define MASK(x) (1LL << (x))
#define ON_BIT(x, i) ((x) | (1LL << (i)))
#define OFF_BIT(x, i) ((x) & ~(1LL << (i)))
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define FORE(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORDE(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)

template<class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; };
template<class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; };

/// Author: tinhnopro
// end of template

const int MAXN = 1e6 + 11;
//const int MOD = 1e9 + 7;
//const int INF = 1e9 + 11; const ll INF = (ll) 1e18 + 11;
//const int BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int n, q, prefixF[MAXN];
vector<int> f;
bool a[MAXN];

void process(void) {
    cin >> n >> q;
    FORE(i, 1, n) {
        cin >> a[i];
    }
    int cnt = 0;
    FORDE(i, n, 1) {
        if (a[i] == 0) cnt++;
        else f.push_back(cnt);
    }
    int m = f.size();
    f.push_back(0);
    reverse(ALL(f));
    prefixF[1] = f[1];
    FORE(i, 2, m) prefixF[i] = prefixF[i - 1] + f[i];
    while (q--) {
        int k; cin >> k;
        int ans = n + 1;
        FORE(d, 1, min(m, k)) {
            cout << d << ": ";
            int res = prefixF[m] - prefixF[d];
            int x = k - d;

            res -= (m - d) * x;
            minimize(ans, res);
        }
        cout << ans << el;
    }
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
