#include <bits/stdc++.h>

using namespace std;

#define el  "\n"
#define fi  first
#define se  second
#define name "D"
#define BIT(x, i) ((x) & (1 << (i)))
#define MASK(x) (1 << (x))
#define ALL(v) ((v).begin(), (v).end())
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
const int INF = 1e9 + 11; const ll INFF = 1e18 + 11;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int n, q, m;
ll seg[4 * MAXN], lazy[4 * MAXN];

void down(int id) {
    if (!lazy[id]) return ;
    lazy[id << 1] += lazy[id];
    lazy[id << 1 | 1] += lazy[id];
    seg[id << 1] += lazy[id];
    seg[id << 1 | 1] += lazy[id];
    lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return ;
    if (u <= l && r <= v) {
        seg[id] += val;
        lazy[id] += val;
        return ;
    }
    int mid = (l + r) >> 1;
    down(id);
    update(id << 1, l, mid, u, v, val);
    update(id << 1 | 1, mid + 1, r, u, v, val);
    seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
}

ll query(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return -1;
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) >> 1;
    down(id);
    return max(query(id << 1, l, mid, u, v),
                query(id << 1 | 1, mid + 1, r, u, v));
}

void process(void) {
    cin >> n >> m >> q;
    while (q--) {
        int l, r, w;
        cin >> l >> r >> w;
        r--;
        update(1, 1, n, l, r, w);
        if (query(1, 1, n, l, r) <= m) cout << "T";
        else cout << "N";
        cout << el;
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
