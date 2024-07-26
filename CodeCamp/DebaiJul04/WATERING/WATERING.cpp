#include <bits/stdc++.h>

using namespace std;

#define name "WATERING"
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

const int MAXN = 5e5 + 11, MAX = 1e6 + 11;
//const int MOD = 1e9 + 7;
//const int INF = 1e9 + 11; const ll INFF = 1e18 + 11;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int n;
pii a[MAXN];
vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) if (!visited[v]) dfs(v);
}

void process(void) {
    cin >> n;
    FORE(i, 1, n) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    FORE(i, 1, n - 1) {
        if (a[i].fi > a[i + 1].fi) adj[i].push_back(i + 1);
        else {
            if (a[i].fi == a[i + 1].fi) adj[i].push_back(i + 1);
            adj[i + 1].push_back(i);
        }
    }
    sort(a + 1, a + n + 1, greater<pii>());
    int cnt = 0;
    FORE(i, 1, n) if (!visited[a[i].se]) {
        dfs(a[i].se);
        cnt++;
    }
    cout << cnt;
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
