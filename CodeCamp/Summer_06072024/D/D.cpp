#include <bits/stdc++.h>

using namespace std;

#define name "D"
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
const int INF = 1e9 + 11;
//const int BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int n, a[MAXN], q, pre[MAXN], nxt[MAXN], l[MAXN];
stack<int> stk;
vector<pii> v;

/*
    pre[i] = j min j -> i - 1 < = a[i]
    nxt[i] = k max i + 1 -> k <= a[i]
    max(j..k) = a[i]
    l[i] = k - j + 1 max
*/

bool cmp(const pii &a, const pii &b) {
    if (a.fi == b.fi) return a.se < b.se;
    return a.fi < b.fi;
}

void process(void) {
    cin >> n >> q;
    FORE(i, 1, n) cin >> a[i];
    a[0] = a[n + 1] = INF;
    stk.push(0);
    FORE(i, 1, n) {
        while (!stk.empty() && a[stk.top()] <= a[i]) stk.pop();
        pre[i] = stk.top() + 1;
        stk.push(i);
    }
    while (!stk.empty()) stk.pop();
    stk.push(n + 1);
    FORDE(i, n, 1) {
        while (!stk.empty() && a[stk.top()] <= a[i]) stk.pop();
        nxt[i] = stk.top() - 1;
        stk.push(i);
    }
    v.push_back({-INF, 0});
    FORE(i, 1, n) l[i] = nxt[i] - pre[i] + 1;
    FORE(i, 1, n) v.push_back({a[i], l[i]});
    sort(ALL(v), cmp);
    FORE(i, 1, n) maximize(v[i].se, v[i - 1].se);
    while (q--) {
        int k;
        cin >> k;
        pii x = {k, 2e9};
        int idx = upper_bound(ALL(v), x) - v.begin() - 1;
        cout << v[idx].se << el;
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
