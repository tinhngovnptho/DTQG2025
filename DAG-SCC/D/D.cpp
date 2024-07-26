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
//const ll INF = (ll) 1e18 + 11;
//const ll BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int n, m;
vi adj[MAXN], zadj[MAXN];
int low[MAXN], num[MAXN], id[MAXN], display[MAXN];
int deg_in[MAXN], deg_out[MAXN];
stack<int> st;
set<pii> flag;
int scc = 0, sccZ = 0;

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
        display[scc] = u;
        id[u] = scc;

        int v = -1;

        while (v != u) {
            v = st.top();
            id[v] = scc;
            low[v] = num[v] = n + 1;
            st.pop();
        }
    }
}

void BuildZgraph(void) {
    FOR(i, 1, n) {
        int u = id[i];
        for (int j : adj[i]) if (id[i] != id[j]) {
            int v = id[j];
            if (flag.find({u, v}) == flag.end()) {
                zadj[u].push_back(v);
                deg_in[v]++;
                deg_out[u]++;
                flag.insert({u, v});
            }
        }
    }
}

void dfsZ(int u) {
    static int timeDFS = 0;
    low[u] = num[u] = ++timeDFS;
    st.push(u);

    for (int v : zadj[u]) {
        if (!num[v]) {
            dfsZ(v);
            minimize(low[u], low[v]);
        } else minimize(low[u], num[v]);
    }

    if (low[u] == num[u]) {
        sccZ++;
        int v = -1;

        while (v != u) {
            v = st.top();
            low[v] = num[v] = scc + 1;
            st.pop();
        }
    }
}

void process(void) {
    cin >> n >> m;
    FOR(i, 1, m) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    FOR(i, 1, n) if (!num[i]) dfs(i);

    if (scc == 1) return void(cout << "YES\n" << 1 << " " << 1);

    BuildZgraph();

    int u = -1;
    FOR(i, 1, scc) if (deg_out[i] == 0) {
        if (u != -1) return void(cout << "NO");
        u = i;
    }

    int v = -1;
    FOR(i, 1, scc) if (deg_in[i] == 0) {
        if (v != -1) return void(cout << "NO");
        v = i;
    }

    if (u == -1 || v == -1) return void(cout << "NO");
    zadj[u].push_back(v);

    memset(low, 0, sizeof low);
    memset(num, 0, sizeof num);

    while (!st.empty()) st.pop();

    FOR(i, 1, scc) if (!num[i]) dfsZ(i);

    if (sccZ > 1) cout << "NO";
    else cout << "YES" << el << display[u] << " " << display[v];
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    file("D");

//	int t; cin >> t; while(t--)
    process();
    return 0;
}
