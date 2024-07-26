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
const int INF = 1e9 + 11;
//const ll BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
const int BLOCK = 320;

multiset<int> s[MAXN / BLOCK + 2];
int n, q, a[MAXN];

#define getBlock(i) ((i) - 1) / BLOCK + 1
#define getLeft(i) ((i) - 1) * BLOCK + 1
#define getRight(i) (i) * BLOCK

void update(int i, int val) {
    int blockID = getBlock(i);
    s[blockID].erase(s[blockID].find(a[i]));
    a[i] = val;
    s[blockID].insert(val);
}

int query(int l, int r, int k) {
    int blockL = getBlock(l);
    int blockR = getBlock(r);

    if (blockL == blockR) {
        int res = INF;
        FOR(i, l, r) if (a[i] >= k) minimize(res, a[i]);
        return (res == INF ? -1 : res);
    }

    int res = INF;

    FOR(i, l, getRight(blockL)) if (a[i] >= k) minimize(res, a[i]);
    FOR(i, getLeft(blockR), r) if (a[i] >= k) minimize(res, a[i]);

    FOR(i, blockL + 1, blockR - 1) {
        auto it = s[i].lower_bound(k);
        if (it == s[i].end()) continue;
        minimize(res, *it);
    }

    return (res == INF ? -1 : res);
}

void process(void) {
    cin >> n >> q;
    FOR(i, 1, n) {
        cin >> a[i];
        s[getBlock(i)].insert(a[i]);
    }
    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int i, v;
            cin >> i >> v;
            update(i, v);
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            cout << query(l, r, k) << el;
        }
    }
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    file("itds1");

//	int t; cin >> t; while(t--)
	process();
	return 0;
}
