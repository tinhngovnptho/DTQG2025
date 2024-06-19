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

const int MAXN = 5e5 + 11, MAX = 1e6 + 11;
//const int MOD = 1e9 + 7;
//const int INF = 1e9 + 11; const ll INFF = 1e18 + 11;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int n, x, cnt[MAXN], cnt0, cnt1;
char a[MAXN];

void process(void) {
    cin >> n >> x;
    cnt0 = cnt1 = 0;
    cnt[0] = 0;
    FORE(i, 1, n) {
        cin >> a[i];
        cnt0 += (a[i] == '0');
        cnt1 += (a[i] == '1');
        cnt[i] = cnt0 - cnt1;
//        cout << cnt[i] << " ";
    }
    if (cnt[n] == x) return void(cout << "-1\n");
    int res = 0;
    if (x == 0) res++;
    FORE(i, 1, n) {
        if ((x - cnt[i]) % cnt[n] == 0 && (x - cnt[i]) / cnt[n] >= 0) res++;
    }
    cout << res << "\n";
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	file("dog");
	int t; cin >> t; while(t--)
	process();
	return 0;
}
