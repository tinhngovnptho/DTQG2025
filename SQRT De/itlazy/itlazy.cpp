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

const int MAXN = (int) 1e5 + 11;
//const int MOD = (int) 1e9 + 7;
const ll INF = (ll) 1e18 + 11;
//const ll BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
const int BLOCK_SIZE = 320;

#define getBlock(i) ((i) - 1) / BLOCK_SIZE + 1
#define getLeft(i) ((i) - 1) * BLOCK_SIZE + 1
#define getRight(i) (i) * BLOCK_SIZE

ll mx[MAXN / BLOCK_SIZE + 2], a[MAXN], n, lazy[MAXN / BLOCK_SIZE + 2];

void update_lazy(int block) {
    FOR(i, getLeft(block), getRight(block)) a[i] += lazy[block];
    lazy[block] = 0;
}

void update_over(int l, int r, int val) {
    int block = getBlock(l);
    update_lazy(block);
    FOR(i, l, r) maximize(mx[block], a[i] += val);
}

void update(int l, int r, int val) {
    int blockL = getBlock(l);
    int blockR = getBlock(r);

    if (blockL == blockR) return void(update_over(l, r, val));

    update_over(l, getRight(blockL), val);
    update_over(getLeft(blockR), r, val);

    FOR(i, blockL + 1, blockR - 1) {
        lazy[i] += val;
        mx[i] += val;
    }
}

ll query_over(int l, int r) {
    int block = getBlock(l);
    update_lazy(block);

    ll res = -INF;
    FOR(i, l, r) {
        maximize(res, a[i]);
        maximize(mx[block], a[i]);
    }
    return res;
}

ll query(int l, int r) {
    int blockL = getBlock(l);
    int blockR = getBlock(r);

    if (blockL == blockR) return query_over(l, r);

    ll res = -INF;

    maximize(res, query_over(l, getRight(blockL)));
    maximize(res, query_over(getLeft(blockR), r));

    FOR(i, blockL + 1, blockR - 1) {
        maximize(res, mx[i]);
    }
    return res;
}

void process(void) {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    memset(mx, -0x3f, sizeof mx);
    FOR(i, 1, n) maximize(mx[getBlock(i)], a[i]);
    int q; cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            update(l, r, val);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(l, r) << el;
        }
    }
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    file("itlazy");

//	int t; cin >> t; while(t--)
	process();
	return 0;
}
