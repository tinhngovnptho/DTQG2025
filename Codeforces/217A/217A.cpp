#include <bits/stdc++.h>

using namespace std;

#define el  "\n"
#define ll  long long
#define ull unsigned long long
#define pii pair<int, int>
#define vi  vector<int>
#define fi  first
#define se  second
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define FORE(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORDE(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define BIT(x, i) ((x) & (1LL << (i)))
#define MASK(x) (1LL << (x))
#define ONBIT(x, i) ((x) | (1LL << (i)))
#define OFFBIT(x, i) ((x) & ~(1LL << (i)))
#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout)

template<class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; };
template<class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; };

/// Author: tinhnopro
// end of template

const int MAXN = 1e3 + 11;
//const int MOD = 1e9 + 7;
//const ll INF = 1e9 + 11;
//const ll BASE = 311;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int a[MAXN][MAXN], n;

void dfs(int x, int y) {
    a[x][y] = 1;
    FOR(i, 0, 4) {
        int adj_x = x + dx[i], adj_y = y + dy[i];
        if (adj_x < 1 || adj_x >= MAXN || adj_y < 1 || adj_y >= MAXN) continue;
        if (a[adj_x][adj_y] == 1) continue;
        dfs(adj_x, adj_y);
    }
}

void process(void) {
    cin >> n;
    FORE(i, 1, n) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    int cnt = 0;
    FOR(i, 1, MAXN) FOR(j, 1, MAXN) if (a[i][j] == 1) {
        cnt++;
        dfs(i, j);
    }
    cout << cnt - 1;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    file("217A");

//	int t; cin >> t; while(t--)
	process();

	return 0;
}
