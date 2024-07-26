#include <bits/stdc++.h>

using namespace std;

#define el  "\n"
#define fi  first
#define se  second
#define BIT(x, i) ((x) & (1 << (i)))
#define MASK(x) (1 << (x))
#define ALL(v) ((v).begin(), (v).end())
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
int low[MAXN], num[MAXN], isCut[MAXN], child[MAXN];
ll res[MAXN];

ll visit(int u) {
    return 1LL * u * (u - 1);
}

void dfs(int u, int par) {
    static int timeDFS = 0;
    int Child = 0, sum_v = 0;
    child[u] = 1;
    low[u] = num[u] = ++timeDFS;
    for (int v : adj[u]) {
        if (v == par) continue;
        if (!num[v]) {
            dfs(v, u);
            Child++;
            child[u] += child[v];
            minimize(low[u], low[v]);
            if (low[v] >= num[u]) {
                res[u] += visit(child[v]);
                sum_v += child[v];
            }
            if (u == par) {
                if (Child > 1) {
                    isCut[u] = 1;
                }
            } else if (low[v] >= num[u]) {
                isCut[u] = 1;
            }
        } else minimize(low[u], num[v]);
    }
//    cout << u << ": " << sum_v << "\n";
    res[u] += visit(n - 1 - sum_v);
}

void process(void) {
    cin >> n >> m;
    FORE(i, 1, m) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    FORE(i, 1, n) if (!num[i]) {
        memset(child, 0, sizeof child);
        dfs(i, i);
    }
    res[0] = visit(n) - visit(n - 1);
    ll inital = visit(n);
    FORE(i, 1, n) {
        if (!isCut[i]) cout << res[0];
        else cout << inital - res[i];
        cout << el;
    }
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	file("f");
//	int t; cin >> t; while(t--)
	process();
	return 0;
}
