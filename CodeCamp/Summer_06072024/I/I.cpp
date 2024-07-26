#include <bits/stdc++.h>

using namespace std;

#define name "I"
#define el  "\n"
#define ll  long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi  first
#define se  second
#define BIT(x, i) ((x) & (1 << (i)))
#define MASK(x) (1LL << (x))
#define ON_BIT(x, i) ((x) | (1LL << (i)))
#define OFF_BIT(x, i) ((x) & ~(1LL << (i)))
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define FORE(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORDE(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)

template<class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; };
template<class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; };

/// Author: tinhnopro
// end of template

const int MAXN = 5e5 + 11, MAX = 1e6 + 11;
//const int MOD = 1e9 + 7;
//const int INF = 1e9 + 11; const ll INF = (ll) 1e18 + 11;
//const int BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int n, a[MAXN], q, cnt;

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int seg[4 * MAXN];

void build(int id, int l, int r) {
    if (l == r) return void(seg[id] = a[l]);
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    seg[id] = gcd(seg[id << 1], seg[id << 1 | 1]);
}

void update(int id, int l, int r, int pos, int val) {
    if (l > pos || pos > r) return ;
    if (l == r) {
        seg[id] = val;
        return ;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, pos, val);
    update(id << 1 | 1, mid + 1, r, pos, val);
    seg[id] = gcd(seg[id << 1], seg[id << 1 | 1]);
}

//int dfs(int id, int l, int r, int u, int v, int k) {
//    if (l > v || r < u || it[id] % k == 0) return -1;
//    if (l == r) return l;
//    int mid = (l + r) >> 1;
//    int it1 = dfs((id << 1), l, mid, u, v, k);
//    if (it1 == -1) return dfs((id << 1 | 1), mid + 1, r, u, v, k);
//    else return it1;
//}

void dfs(int id, int l, int r, int u, int v, int k) {
    if (l > v || r < u) return ;
    if (l == r) {
        cnt += (seg[id] % k != 0);
        return ;
    }
    if (u <= l && r <= v) {
        if (seg[id] == k) return ;
        int mid = (l + r) >> 1;
        dfs(id << 1, l, mid, u, v, k);
        dfs(id << 1 | 1, mid + 1, r, u, v, k);
        return ;
    }
    int mid = (l + r) >> 1;
    dfs(id << 1, l, mid, u, v, k);
    dfs(id << 1 | 1, mid + 1, r, u, v, k);
}

void process(void) {
    cin >> n;
    FORE(i, 1, n) cin >> a[i];
    build(1, 1, n);
    cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 2) {
            int i, x; cin >> i >> x;
            update(1, 1, n, i, x);
        } else {
            int l, r, x; cin >> l >> r >> x;
            cnt = 0;
            dfs(1, 1, n, l, r, x);
            cout << (cnt < 2 ? "YES" : "NO") << el;
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
