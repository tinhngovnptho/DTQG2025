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
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
//const int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int n, par[MAXN], s, t;
vector<int> adj[MAXN];
bool visited[MAXN];

bool dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            par[v] = u;
            if (dfs(v)) return true;
        } else if (v != par[u]) {
            s = v; t = u;
            return true;
        }
    }
    return false;
}

void process(void) {
    cin >> n;
    int x, y;
    while (cin >> x >> y) {
        adj[x].push_back(y);
        adj[y].push_back(x);
        }
    FORE(i, 1, n) if (!visited[i]) {
        par[i] = 0;
        if (dfs(i)) {
            cout << "YES\n";
            stack<int> cyc;
            while (t != s) {
                cyc.push(t);
                t = par[t];
            }
            cyc.push(s);
            while (!cyc.empty()) {
                cout << cyc.top() << " ";
                cyc.pop();
            }
            cout << s;
            return ;
        }
    }
    cout << "NO";
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	file("E");
//	int t; cin >> t; while(t--)
	process();
	return 0;
}
