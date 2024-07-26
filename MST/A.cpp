#include <bits/stdc++.h>

using namespace std;

#define name "A"
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

//const int MAXN = 5e5 + 11, MAX = 1e6 + 11;
//const int MOD = 1e9 + 7;
//const int INF = 1e9 + 11; const ll INFF = 1e18 + 11;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        w = _w;
    }
    bool operator < (const Edge &other) const {
        return w < other.w;
    }
};

struct DSU {
    vector<int> lab;

    void init(int length) {
        lab.assign(length + 1, -1);
    }

    int find_par(int u) {
        return lab[u] < 0 ? u : lab[u] = find_par(lab[u]);
    }

    bool union_set(int a, int b) {
        a = find_par(a);
        b = find_par(b);
        if (a == b) return false;
        if (lab[a] > lab[b]) swap(a, b);
        lab[a] += lab[b];
        lab[b] = a;
        return true;
    }
} dsu;

int n, m;
vector<Edge> edges;
vector<pii> mst;
int total = 0;

void process(void) {
    cin >> n >> m;
    FORE(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    sort(ALL(edges));
    dsu.init(n);
    for (int i = 0; i < int(edges.size()) && int(mst.size()) < n - 1; ++i) {
        if (!dsu.union_set(edges[i].u, edges[i].v)) continue;
        mst.push_back({edges[i].u, edges[i].v});
        total += edges[i].w;
    }
    cout << total;
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
