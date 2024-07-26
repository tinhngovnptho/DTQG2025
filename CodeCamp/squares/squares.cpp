#include <bits/stdc++.h>

using namespace std;

#define name "squares"
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

int m, n, k, d[1001][1001], l[1001][1001];
vector<pii> v;

void sub12() {
    ll cnt = 0;
    FORE(r, 1, min(m, n) - 1) {
        FORE(x, 1, m - r) FORE(y, 1, n - r) FORE(a, 0, r - 1) {
            int xa = x, ya = y + a;
            int xb = x + a, yb = y + r;
            int xc = x + r, yc = y + r - a;
            int xd = x + r - a, yd = y;
            if (d[xa][ya] || d[xb][yb] || d[xc][yc] || d[xd][yd]) continue;
            cnt++;
        }
    }
    cout << cnt;
}

void sub3() {
    ll cnt = 0;
    FORE(r, 1, min(m, n) - 1) cnt += 1LL * r * (m - r) * (n - r);
    cout << cnt;
}

bool in_range(int x, int y, int r) {
    return x > 0 && x <= m - r && y > 0 && y <= n - r;
}

void subfull() {
    ll cnt = 0;
    FORE(r, 1, min(m, n) - 1) cnt += 1LL * r * (m - r) * (n - r);
    for (pii u : v) {
        FORE(r, 1, min(m, n) - 1) FORE(a, 0, r - 1) {
            // delete A
            int x = u.fi, y = u.se - a;
            if (in_range(x, y, r)) {
                cnt--;
//                cout << u.fi << " A " << u.se << el;
            }
            // delete B
            x = u.fi - a; y = u.se - r;
            int xa = x, ya = y + a;
            if (in_range(x, y, r) && d[xa][ya] == 0) {
                cnt--;
//                cout << u.fi << " B " << u.se << el;
            }
            // delete C
            x = u.fi - r; y = u.se - (r - a);
            xa = x; ya = y + a;
            int xb = x + a, yb = y + r;
            if (in_range(x, y, r) && d[xa][ya] == 0 && d[xb][yb] == 0) {
                cnt--;
//                cout << u.fi << " C " << u.se << el;
            }
            // delete D
            x = u.fi - (r - a); y = u.se;
            xa = x; ya = y + a;
            xb = x + a; yb = y + r;
            int xc = x + r, yc = y + (r - a);
            if (in_range(x, y, r) && d[xa][ya] == 0 && d[xb][yb] == 0 && d[xc][yc]  == 0) {
                cnt--;
//                cout << u.fi << " D " << u.se << el;
            }
        }
    }
    cout << cnt;
}

void process(void) {
    cin >> m >> n >> k;
    FORE(i, 1, k) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
        d[x][y] = 1;
    }
//    if (k == 0) return sub3();
//    if (m <= 100 && n <= 100) return sub12();
    subfull();
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
