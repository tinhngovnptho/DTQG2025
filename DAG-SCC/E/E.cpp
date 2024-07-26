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
//const int MOD = (int) 1e9 + 7;
const ll INF = (ll) 1e18 + 11;
//const ll BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

struct Node {
    ll money;
    bool isGame;
    Node() {
        money = 0;
        isGame = false;
    }
};

int n, m, s, p;
Node data[MAXN], Zdata[MAXN];
vi adj[MAXN], Zadj[MAXN];

int scc = 0, low[MAXN], num[MAXN];
stack<int> st;

int color[MAXN];
set<pii> flag;
ll dp[MAXN];

void dfs(int u) {
    static int timeDFS = 0;
    low[u] = num[u] = ++timeDFS;
    st.push(u);

    for (int v : adj[u]) {
        if (!num[v]) {
            dfs(v);
            minimize(low[u], low[v]);
        } else minimize(low[u], num[v]);
    }
    if (low[u] == num[u]) {
        scc++;
        color[u] = scc;
        int v = -1;
        while (v != u) {
            v = st.top();
            color[v] = scc;
            Zdata[scc].money += data[v].money;
            Zdata[scc].isGame |= data[v].isGame;
            low[v] = num[v] = n + 1;
            st.pop();
        }
    }
}

void ZipGraph(void) {
    FOR(i, 1, n) if (!num[i]) dfs(i);
    FOR(i, 1, n) {
        int u = color[i];
        for (int j : adj[i]) {
            int v = color[j];
            if (u != v && flag.find({u, v}) == flag.end()) {
                Zadj[u].push_back(v);
                flag.insert({u, v});
            }
        }
    }
}

ll dfsZ(int u) {
    if (dp[u] != -1) return dp[u];
    if (Zdata[u].isGame) dp[u] = Zdata[u].money;
    else dp[u] = -INF;
    for (int v : Zadj[u]) {
        maximize(dp[u], Zdata[u].money + dfsZ(v));
    }
//    cout << u << ": " << dp[u] << el;
    return dp[u];
}

void process(void) {
    cin >> n >> m;
    FOR(i, 1, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    FOR(i, 1, n) cin >> data[i].money;
    cin >> s >> p;
    FOR(i, 1, p) {
        int v; cin >> v;
        data[v].isGame = true;
    }

    ZipGraph();

//    FOR(i, 1, scc) cout << Zdata[i].money << " " << Zdata[i].isGame << el;

    s = color[s];
    memset(dp, -1, sizeof dp);
    dfsZ(s);
    cout << dp[s];
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    file("E");

//	int t; cin >> t; while(t--)
	process();
	return 0;
}
