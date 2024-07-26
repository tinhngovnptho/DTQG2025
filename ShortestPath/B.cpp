#include <bits/stdc++.h>

using namespace std;

#define name "B"
#define el  "\n"
#define fi  first
#define se  second
#define BIT(x, i) ((x) & (1 << (i)))
#define MASK(x) (1 << (x))
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define FORE(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
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
const int INF = 1e9 + 11; const ll INFF = 1e18 + 11;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int n, m, Ha, Hb, Sa, Sb;
vector<pii> adj[MAXN];
int minT_Ha[MAXN], minT_Hb[MAXN], minT_Sa[MAXN], minT_Sb[MAXN], preA[MAXN], preB[MAXN];

void Dijsktra(int s, int *d) {
    FORE(i, 1, n) d[i] = INF;
    d[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().se, d_u = pq.top().fi;
        pq.pop();
        if (d_u > d[u]) continue;
        for (pii x : adj[u]) {
            int v = x.fi, w = x.se;
            if (minimize(d[v], d[u] + w)) {
                pq.push({d[v], v});
            }
        }
    }
}

void process(void) {
    cin >> n >> m >> Ha >> Sa >> Hb >> Sb;
    FORE(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    Dijsktra(Sa, minT_Sa);
    Dijsktra(Sb, minT_Sb);
    Dijsktra(Ha, minT_Ha);
    Dijsktra(Hb, minT_Hb);
    int res = INF, ans;
    FORE(u, 1, n) {
        if (minT_Ha[u] == minT_Hb[u] && minT_Ha[u] + minT_Sa[u] == minT_Ha[Sa] && minT_Hb[u] + minT_Sb[u] == minT_Hb[Sb]) {
            if (minimize(te))
        }
    }
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
