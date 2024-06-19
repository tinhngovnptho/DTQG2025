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
using pii = pair<ll, ll>;
using vi = vector<int>;
template<class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; };
template<class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; };

/// Author: tinhnopro
// end of template

const int MAXN = 5e5 + 11, MAX = 1e6 + 11;
//const int MOD = 1e9 + 7;
const ll INF = 1e18 + 11;

int n, m;
pii a[MAXN];

bool cmp(const pii &a, const pii &b) {
    return a.se < b.fi;
}

bool check(ll D) {
    ll total = 0;
    ll prev = -INF;
    FORE(i, 1, m) {
        while (max(prev + D, a[i].fi) <= a[i].se) {
            prev = max(prev + D, a[i].fi);
            total++;
            if (total >= n) return true;
        }
    }
    return total >= n;
}

void process(void) {
    cin >> n >> m;
    FORE(i, 1, m) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + 1 + m, cmp);
    ll L = 1, R = 1e18 + 11, res = -1;
    while (L <= R) {
        ll mid = (L + R) / 2;
        if (check(mid)) {
            res = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }
    cout << res;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	file("maxd");
//	int t; cin >> t; while(t--)
	process();
	return 0;
}
