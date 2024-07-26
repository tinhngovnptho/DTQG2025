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

const int MAXN = (int) 5e5 + 11, MAX = 5e4 + 5;
//const int MOD = (int) 1e9 + 7;
//const ll INF = (ll) 1e18 + 11;
//const ll BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
const int BLOCK = 1000;

#define getBlock(i) ((i) - 1) / BLOCK + 1
#define getLeft(i) ((i) - 1) * BLOCK + 1
#define getRight(i) i * BLOCK
#define Node(i) ((i) & -(i))

int bit[MAXN / BLOCK + 2][MAX], a[MAXN], n, bit2[MAX];

void update(int u) {
     for (; u; u -= Node(u)) bit2[u]++;
}

int query(int u) {
    int res = 0;
    for (; u < MAX; u += Node(u)) res += bit2[u];
    return res;
}


void update2(int block, int u, int val) {
    for (; u; u -= Node(u)) bit[block][u] += val;
}

int query2(int block, int u) {
    int res = 0;
    for (; u < MAX; u += Node(u)) res += bit[block][u];
    return res;
}

int solve(int x) {
    int blockID = getBlock(x);

    int res = 0;

    FOR(i, 1, blockID - 1) res += query2(i, a[x] + 1);
    FOR(i, blockID + 1, getBlock(n)) res += query2(i, 1) - query2(i, a[x]);

    FOR(i, getLeft(blockID), x - 1) if (a[i] > a[x]) res++;
    FOR(i, x + 1, getRight(blockID)) if (a[x] > a[i]) res++;

    return res;
}

void process(void) {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    ll res = 0;

    FOR(i, 1, n) {
        update2(getBlock(i), a[i], 1);
        res += query(a[i] + 1);
        update(a[i]);
    }

//    cout << res << el;

    int q; cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        int blockID = getBlock(x);
        res -= solve(x);
        update2(blockID, a[x], -1);
        a[x] = y;
        update2(blockID, a[x], 1);
        res += solve(x);
        cout << res << el;
    }
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    file("sqrt_f");

//	int t; cin >> t; while(t--)
	process();
	return 0;
}
