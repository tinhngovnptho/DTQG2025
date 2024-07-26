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

const int MAXN = 3e6 + 11, MAX = 3e6 + 11;
const int MOD = 123456789;
//const int INF = 1e9 + 11;

int min_prime[MAX];
ll cnt_factor[MAX];

ll Mul(ll a, ll b) {
    ll res = a * b;
    return res % MOD;
}

void sieve(int n) {
    FORE(i, 1, n) min_prime[i] = i;
    for (int i = 2; i * i <= n; ++i) if (min_prime[i] == i) {
        for (int j = i * i; j <= n; j += i) if (min_prime[j] == j) min_prime[j] = i;
    }
}

void factor(int x) {
    while (x != 1) {
        cnt_factor[min_prime[x]]++;
        x /= min_prime[x];
    }
}

void process(void) {
    int m; cin >> m;
    sieve(MAX);
//    FORE(i, 1, 100) cerr << min_prime[i] << " ";
    FORE(i, 2, m) if (i % 10 != 4) factor(i);
    ll ans = 1;
    FORE(i, 2, MAX) if (cnt_factor[i]) {
//        cout << i << " " << cnt_factor[i] << "\n";
        ans = Mul(ans, cnt_factor[i] + 1);
    }
    cout << ans;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	file("cdiv2");
//	int t; cin >> t; while(t--)
	process();
	return 0;
}
