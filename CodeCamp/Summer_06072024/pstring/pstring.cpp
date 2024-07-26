#include <bits/stdc++.h>

using namespace std;

#define name "pstring"
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

//const int MAXN = 5e5 + 11, MAX = 1e6 + 11;
//const int MOD = 1e9 + 7;
//const int INF = 1e9 + 11; const ll INF = (ll) 1e18 + 11;
//const int BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

string s;

int solve(int u, int v) {
    int ret = 0;
    FOR(i, 0, s.size()) if (s[i] == char(u + '0')) {
        ret++;
        swap(u, v);
    }
    return (ret & 1 ? ret - 1 : ret);
}

void process(void) {
    cin >> s;
    int res = 0;
    FOR(i, 0, 10) {
        FOR(j, 0, 10) {
            if (i == j) {
                int cnt = 0;
                FOR(k, 0, s.size()) if (s[k] == char(i + '0')) cnt++;
                maximize(res, cnt);
                continue;
            }
            maximize(res, solve(i, j));
        }
    }
    cout << s.size() - res;
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
