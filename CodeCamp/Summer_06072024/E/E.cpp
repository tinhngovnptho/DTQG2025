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
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define FORE(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORDE(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define BIT(x, i) ((x) & (1LL << (i)))
#define MASK(x) (1LL << (x))
#define ONBIT(x, i) ((x) | (1LL << (i)))
#define OFFBIT(x, i) ((x) & ~(1LL << (i)))
#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout)

template<class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; };
template<class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; };

/// Author: tinhnopro
// end of template

const int MAXN = 5e5 + 11;
//const int MOD = 1e9 + 7;
//const ll INF = 1e9 + 11;
//const ll BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int n, k, a[MAXN], bit[MAXN];
ll sum[MAXN];

#define NODE(u) (u) & -(u)

void update(int u) {
    for (; u <= n; u += NODE(u)) bit[u]++;
}

int query(int u) {
    int ret = 0;
    for (; u; u -= NODE(u)) ret += bit[u];
    return ret;
}

ll f(ll x) {
    memset(bit, 0, sizeof bit);
    ll cur = 0, ret = 0;
    FORE(i, 1, n) {
        update(lower_bound(sum + 1, sum + n + 1, cur) - sum);
        cur += a[i];
        ret += query(upper_bound(sum + 1, sum + n + 1, cur - x) - sum - 1);
    }
    return ret;
}

void process(void) {
    cin >> n >> k;
    FORE(i, 1, n) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i - 1];
    }

    sort(sum + 1, sum + n + 1);

    ll l = -1e14, r = 1e14, res = -1;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (f(mid) >= k) {
            res = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    cout << res;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    file("E");

//	int t; cin >> t; while(t--)
	process();

	return 0;
}
