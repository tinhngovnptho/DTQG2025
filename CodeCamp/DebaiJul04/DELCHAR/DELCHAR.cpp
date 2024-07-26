#include <bits/stdc++.h>

using namespace std;

#define name "DELCHAR"
#define el  "\n"
#define fi  first
#define se  second
#define BIT(x, i) ((x) & (1 << (i)))
#define MASK(x) (1 << (x))
#define ALL(v) (v).begin(), (v).end()
#define FOR(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define FORE(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORDE(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;

template<class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; };
template<class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; };

/// Author: tinhnopro
// end of template

//const int MAXN = 5e5 + 11, MAX = 1e6 + 11;
//const int MOD = 1e9 + 7;
//const int INF = 1e9 + 11; const ll INFF = 1e18 + 11
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

string s;
int n, dp[5011][5011], t[5011][5011];

bool Pair_Brackets(char a, char b) {
    if (a == '(') return b == ')';
    if (a == '{') return b == '}';
    if (a == '[') return b == ']';
    return false;
}

int solve(int i, int j) {
    if (i > j || i > n || j < 1) return 0;
    if (i == j) return dp[i][j] = 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (Pair_Brackets(s[i], s[j])) {
        dp[i][j] = solve(i + 1, j - 1) + 2;
    }
    int cur = -1;
    FORE(k, i, j - 1) if (maximize(cur, solve(i, k) + solve(k + 1, j))) t[i][j] = k;
    maximize(dp[i][j], cur);
//    cout << i << " " << j << " " << dp[i][j] << el;
    return dp[i][j];
}

void trace(int i, int j) {
    if (i >= j || i > n || j < 1) return ;
//    cout << i << " " << j << " " << dp[i][j] << " " << dp[i + 1][j - 1] << el;
    if (Pair_Brackets(s[i], s[j]) && dp[i][j] == solve(i + 1, j - 1) + 2)  {
        cout << s[i];
        trace(i + 1, j - 1);
        cout << s[j];
        return ;
    }
    int k = t[i][j];
//    cerr << i << " " << j << " " << k << el;
    trace(i, k);
    trace(k + 1, j);
}

void process(void) {
    cin >> s;
    n = s.size();
    s = " " + s;
    memset(dp, -1, sizeof dp);
//    cout << solve(1, n) << el;
    cout << n - solve(1, n);
    cout << el;
    trace(1, n);
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
