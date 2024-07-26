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

const int MAXN = 5e5 + 11;
//const int MOD = 1e9 + 7;
//const ll INF = 1e9 + 11;
//const ll BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int n, m;
vector<pii> adj[MAXN];
bool visited[MAXN];

void dfs(int u) {
    visited[u] = true;
    for (pii x : adj[u]) {
        int v = x.fi;
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void process(void) {
    cin >> n >> m;
    bool checkSub1 = true;
    FORE(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w != 1) checkSub1 = false;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int cc = 0;

    FORE(i, 1, n) if (!visited[i]) {
        cc++;
        dfs(i);
    }
    if (cc == 1) return void(cout << 0);
    if (checkSub1) return void(cout << cc);
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    file("comnet");

//	int t; cin >> t; while(t--)
	process();

	return 0;
}
