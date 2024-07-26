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

int n, m;
vector<int> adj[MAXN];
bool visited[MAXN];
int Child, cntBridge, child[MAXN];
int low[MAXN], num[MAXN];
vector<int> bridges;

void dfs(int u) {
    visited[u] = true;
    child[u] = 1;
    Child++;
    for (int v : adj[u]) if (!visited[v]) {
        dfs(v);
        child[u] += child[v];
    }
}

int cnt_ccs() {
    int res =  0;
    FORE(i, 1, n) if (!visited[i]) {
        Child = 0;
        dfs(i);
        res++;
        if (res >= 3) break;
    }
    return res;
}

void dfs1(int u, int par) {
    static int timeDFS = 0;
    low[u] = num[u] = ++timeDFS;
    for (int v : adj[u]) {
        if (v == par) continue;
        if (!num[v]) {
            dfs1(v, u);
            minimize(low[u], low[v]);
            if (low[v] > num[u]) {
                bridges.push_back(v);
            }
        } else minimize(low[u], num[v]);
    }
}

void process(void) {
    cin >> n >> m;
    FORE(i, 1, m) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ccs = cnt_ccs();
    if (ccs >= 3) return void (cout << 0);
    FORE(i, 1, n) if (!num[i]) dfs1(i, i);
    cntBridge = bridges.size();
    if (ccs == 2) {
        ll ans = 1LL * (n - Child) * Child;
        ans = 1LL * ans * (m - cntBridge);
        cout << ans;
    } else if (ccs == 1) {
        ll res = 1LL * n * (n - 1) / 2 - m;
        ll ans = 1LL * (m - cntBridge) * res;
//        FORE(i, 1, n) cout << child[i] << " ";
        for (int v : bridges) {
            ans += 1LL * child[v] * (n - child[v]) - 1;
        }
        cout << ans;
    }
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	file("d");
//	int t; cin >> t; while(t--)
	process();
	return 0;
}

