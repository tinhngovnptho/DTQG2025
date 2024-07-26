#include <bits/stdc++.h>

using namespace std;

#define name "d4triples"
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

const int MAXN = 1e3 + 11, MAX = 1e6 + 11;
//const int MOD = 1e9 + 7;
//const int INF = 1e9 + 11; const ll INFF = 1e18 + 11;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

char a[MAXN][MAXN];
int n, m, c[MAXN][3], r[MAXN][3];

void process(void) {
    cin >> n >> m;
    FORE(i, 1, n) FORE(j, 1, m) cin >> a[i][j];
    // let c[i][x] is numbers of color x in row i
    FORE(i, 1, n) FOR(j, 0, 3) c[i][j] = 0;
    FORE(i, 1, m) FOR(j, 0, 3) r[i][j] = 0;
    FORE(i, 1, n) {
        FORE(j, 1, m) c[i][a[i][j] - '0']++;
    }
    FORE(i, 1, m) {
        FORE(j, 1, n) r[i][a[j][i] - '0']++;
    }
    ll res = 0;
    FORE(i, 1, n) FORE(j, 1, m) {
        if (a[i][j] == '1') {
            res += 1LL * c[i][2] * r[j][2];
        } else if (a[i][j] == '2') {
            res += 1LL * c[i][1] * r[j][1];
        }
    }
    cout << res << el;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
	}
	int t; cin >> t; while(t--)
	process();
	return 0;
}
