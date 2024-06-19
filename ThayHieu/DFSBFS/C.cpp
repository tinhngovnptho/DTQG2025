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

const int MAXN = 111, MAX = 1e6 + 11;
//const int MOD = 1e9 + 7;
//const int INF = 1e9 + 11; const ll INFF = 1e18 + 11;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int n, m, Ex, Ey, Tx, Ty;
char a[MAXN][MAXN];
pii par[MAXN][MAXN];

void dfs(int x, int y) {
    a[x][y] = 'X';
    FOR(i, 0, 4) {
        int adj_x = x + dx[i], adj_y = y + dy[i];
        if (adj_x == 0 || adj_x > n || adj_y == 0 || adj_y > m) {
            Tx = x; Ty = y;
            return;
        }
        if (a[adj_x][adj_y] != '.') continue;
        par[adj_x][adj_y] = {x, y};
        dfs(adj_x, adj_y);
    }
}

void process(void) {
    cin >> n >> m;
    FORE(i, 1, n) FORE(j, 1, m) {
        cin >> a[i][j];
        if (a[i][j] == 'E') {
            Ex = i; Ey = j;
        }
    }
    Tx = -1; Ty = -1;
    dfs(Ex, Ey);
    if (Tx == -1 && Ty == -1) return void(cout << "NO");
    cout << "YES\n";
//    cerr << Tx << " " << Ty << "\n";
    stack <pii> path;
    while (!path.empty()) path.pop();
    while (Tx != Ex || Ty != Ey) {
        path.push({Tx, Ty});
        pii tmp = par[Tx][Ty];
        Tx = tmp.fi;
        Ty = tmp.se;
    }
    path.push({Ex, Ey});
    while (!path.empty()) {
        cout << path.top().fi << " " << path.top().se << "\n";
        path.pop();
    }
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	file("C");
//	int t; cin >> t; while(t--)
	process();
	return 0;
}
