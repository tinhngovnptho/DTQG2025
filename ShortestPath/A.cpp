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
using iLL = pair<int, ll>;

template<class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; };
template<class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; };

/// Author: tinhnopro
// end of template

const int MAXN = 5e5 + 11, MAX = 1e6 + 11;
//const int MOD = 1e9 + 7;
const int INF = 1e9 + 11; const ll INFF = 1e18 + 11;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int n, m, s, t;
vector<pii> adj[MAXN];
ll d[MAXN];

void Dijsktra(int s) {
    FORE(i, 1, n) d[i] = INFF;
    d[s] = 0;
    priority_queue<iLL, vector<iLL>, greater<iLL> > pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().se;
        ll d_u = pq.top().fi;
        pq.pop();
        if (d_u > d[u]) continue;
        for (pii x : adj[u]) {
            int v = x.se;
            ll w = x.fi;
            if (minimize(d[v], d[u] + w)) {
                pq.push({d[v], v});
            }
        }
    }
}

void process(void) {
    cin >> n >> m >> s >> t;
    FORE(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    Dijsktra(s);
    cout << d[t];
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	file("A");
//	int t; cin >> t; while(t--)
	process();
	return 0;
}#include <bits/stdc++.h>

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
using iLL = pair<int, ll>;

template<class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; };
template<class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; };

/// Author: tinhnopro
// end of template

const int MAXN = 5e5 + 11, MAX = 1e6 + 11;
//const int MOD = 1e9 + 7;
const int INF = 1e9 + 11; const ll INFF = 1e18 + 11;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int n, m, s, t;
vector<pii> adj[MAXN];
ll d[MAXN];

void Dijsktra(int s) {
    FORE(i, 1, n) d[i] = INFF;
    d[s] = 0;
    priority_queue<iLL, vector<iLL>, greater<iLL> > pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().se;
        ll d_u = pq.top().fi;
        pq.pop();
        if (d_u > d[u]) continue;
        for (pii x : adj[u]) {
            int v = x.se;
            ll w = x.fi;
            if (minimize(d[v], d[u] + w)) {
                pq.push({d[v], v});
            }
        }
    }
}

void process(void) {
    cin >> n >> m >> s >> t;
    FORE(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    Dijsktra(s);
    cout << d[t];
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	file("A");
//	int t; cin >> t; while(t--)
	process();
	return 0;
}
