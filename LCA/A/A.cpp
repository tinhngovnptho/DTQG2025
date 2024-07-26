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
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define FORX(i, a, b, x) for (int i = (a), _b = (b); i <= _b; i += (x))
#define BIT(x, i) ((x) & (1LL << (i)))
#define MASK(x) (1LL << (x))
#define ONBIT(x, i) ((x) | (1LL << (i)))
#define OFFBIT(x, i) ((x) & ~(1LL << (i)))
#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout)

template<class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; };
template<class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; };

/// Author: tinhnopro
// end of template

const int MAXN = (int) 5e5 + 11;
const int LOG = 20;
//const int MOD = (int) 1e9 + 7;
//const ll INF = (ll) 1e18 + 11;
//const ll BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int n, m, k, st[LOG + 1][MAXN], depth[MAXN];
vector<int> adj[MAXN];

void dfs(int u, int par) {
    depth[u] = depth[par] + 1;
    st[0][u] = par;
    FOR(i, 1, LOG) st[i][u] = st[i - 1][st[i - 1][u]];
    for (int v : adj[u]) {
        if (v == par) continue;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    FORD(i, LOG, 0) if (depth[st[i][u]] >= depth[v]) {
        u = st[i][u];
    }
    if (u == v) return u;
    FORD(i, LOG, 0) if (st[i][u] != st[i][v]) {
        u = st[i][u];
        v = st[i][v];
    }
    return st[0][u];
}

void process(void) {
    cin >> n >> k >> m;
    FOR(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(k, 0);
    while (m--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << el;
    }
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    file("A");

//	int t; cin >> t; while(t--)
	process();
	return 0;
}
