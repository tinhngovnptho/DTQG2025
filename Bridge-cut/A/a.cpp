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
//const int MOD = 1e9 + 7;
//const int INF = 1e9 + 11; const ll INFF = 1e18 + 11;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int numNode, numEdge;
vector<int> adj[MAXN];
int low[MAXN], num[MAXN];
vector<pii> bridges;

void dfs(int u, int par) {
    static int timeDFS = 0;
    low[u] = num[u] = ++timeDFS;
    for (int v : adj[u]) {
        if (v == par) continue;
        if (!num[v]) {
            dfs(v, u);
            minimize(low[u], low[v]);
            if (low[v] > num[u]) {
                bridges.push_back({u, v});
            }
        } else minimize(low[u], num[v]);
    }
}

void process() {
    cin >> numNode >> numEdge;
    FORE(i, 1, numEdge) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    FORE(i, 1, numNode) if (!num[i]) dfs(i, i);
    for (pii &bridge : bridges) {
        if (bridge.fi > bridge.se) swap(bridge.fi, bridge.se);
    }
    sort(ALL(bridges));
    cout << bridges.size() << "\n";
    for (pii bridge : bridges) cout << bridge.fi << " " <<bridge.se << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	file("a");
//	int t; cin >> t; while(t--)
	process();
	return 0;
}
