#include <bits/stdc++.h>

using namespace std;

#define name "C"
#define el  "\n"
#define fi  first
#define se  second
#define BIT(x, i) ((x) & (1 << (i)))
#define MASK(x) (1 << (x))
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define FORE(ti, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
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

int n, m;
vi adj[MAXN];
map<pii, bool> isWay;
int low[MAXN], num[MAXN], color[MAXN], edges[MAXN], scc = 0;
ll ans = 0;

void dfs(int u) {
    static int timeDFS = 0;
    static stack<int> st;
    low[u] = num[u] = ++timeDFS;
    st.push(u);
    for (int v : adj[u]) {
        if (!num[v]) {
            dfs(v);
            minimize(low[u], low[v]);
        } else minimize(low[u], num[v]);
    }
    if (low[u] == num[u]) {
        int v = 0, res = 0;
        scc++;
        color[u] = scc;
        while (v != u) {
            v = st.top();
            color[v] = scc;
            num[v] = n + 1;
            res++;
            st.pop();
        }
        ans += 1LL * res * (res - 1);
    }
}

void process(void) {
    cin >> n >> m;
    FORE(i, 1, m) {
        int u, v; cin >> u >> v;
        if (!isWay[{u, v}]) {
            adj[u].push_back(v);
            isWay[{u, v}] = 1;
        }
    }
    FORE(i, 1, n) if (!num[i]) dfs(i);
    FORE(i, 1, n) {
        for (int v : adj[i]) {
            if  (color[i] == color[v]) edges[color[i]]++;
        }
    }
    FORE(i, 1, scc) ans -= edges[i];
    cout << ans;
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
