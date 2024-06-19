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

const int MAXN = 5e3 + 11, MAX = 1e6 + 11;
//const int MOD = 1e9 + 7;
const int INF = 1e9 + 11; const ll INFF = 1e18 + 11;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int m, n;
vector<pair<ll, int> > adj[MAXN];
ll d[MAXN], cntD[MAXN];

#define ii pair<ll, int>

void Dijsktra(int s) {
    FORE(i, 1, n) d[i] = INFF;
    priority_queue <ii, vector<ii>, greater<ii>> q;
    q.push({0, s});
    d[s] = 0;
    cntD[s] = 1;
    while (!q.empty()) {
        int u = q.top().se;
        ll d_u = q.top().fi;
        q.pop();
        if (d_u > d[u]) continue;
        for (pii v : adj[u]) {
            ll w = d[u] + v.fi;
            int x = v.se;
            if (d[x] == w) {
                cntD[x] += cntD[u];
            } else if (d[x] > w) {
                cntD[x] = cntD[u];
                d[x] = w;
                q.push({-d[x], x});
            }
        }
    }
}

void process(void) {
    cin >> n >> m;
    for (int i = 0, k, u, v; i < m; ++i) {
        ll l;
        cin >> k >> u >> v >> l;
        adj[u].push_back({l, v});
        if (k == 2) adj[v].push_back({l, u});
    }
    Dijsktra(1);
    cout << d[n] << " " << cntD[n];
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    file("CC");
//  int t; cin >> t; while(t--)
    process();
    return 0;
}
