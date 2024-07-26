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
//const int INF = 1e9 + 11;

int n, m, s, t;
vector <int> adj[MAXN];
bool visited[MAXN];
int par[MAXN];

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            par[v] = u;
            dfs(v);
        }
    }
}

void process(void) {
    cin >> n >> m >> s >> t;
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, 0, sizeof(visited));
    dfs(s);
    if (!visited[t]) return void(cout << -1);
    stack <int> path;
    while (t != s) {
        path.push(t);
        t = par[t];
    }
    path.push(s);
    cout << path.size() << "\n";
    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	file("A");
//	int t; cin >> t; while(t--)
	process();
	return 0;
}
