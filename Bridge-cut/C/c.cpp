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

int n, m, l, k;
vector<int> adj[MAXN];
int low[MAXN], num[MAXN], cntA[MAXN], cntB[MAXN];
bool is_networkA[MAXN], is_networkB[MAXN];
vector<pii> bridges;

void dfs(int u, int par) {
    static int timeDFS = 0;
    low[u] = num[u] = ++timeDFS;
    if (is_networkA[u]) cntA[u]++;
    if (is_networkB[u]) cntB[u]++;
    for (int v : adj[u]) {
        if (v == par) continue;
        if (num[v] == 0) {
            dfs(v, u);
            cntA[u] += cntA[v];
            cntB[u] += cntB[v];
            minimize(low[u], low[v]);
            if (low[v] == num[v]) {
                bridges.push_back({u, v});
            }
        } else minimize(low[u], num[v]);
    }
}

void process(void) {
    cin >> n >> m >> l >> k;
    FORE(i, 1, l) {
        int u; cin >> u;
        is_networkA[u] = 1;
    }
    FORE(i, 1, k) {
        int u; cin >> u;
        is_networkB[u] = 1;
    }
    FORE(i, 1, m) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    FORE(i, 1, n) if (!num[i]) dfs(i, i);
    int ans = 0;
    for (pii bridge : bridges) {
//        cout << bridge.fi << " " << bridge.se << " " << cntA[bridge.se] << " " << cntB[bridge.se] << "\n";
        if (cntA[bridge.se] == 0 || cntA[bridge.se] == l){
            ans++;
            continue;
        }
        if (cntB[bridge.se] == 0 || cntB[bridge.se] == k) ans++;
    }
    cout << ans;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	file("c");
//	int t; cin >> t; while(t--)
	process();
	return 0;
}
