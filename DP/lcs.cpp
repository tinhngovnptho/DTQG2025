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

const int MAXN = 5e3 + 11, MAX = 1e6 + 11;
//const int MOD = 1e9 + 7;
//const int INF = 1e9 + 11; const ll INFF = 1e18 + 11;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int dp[MAXN][MAXN];
string a, b;

stack<char> st;

void trace(int i, int j) {
    if (i == 0 || j == 0) return ;
    if (a[i] == b[j]) {
        st.push(a[i]);
        trace(i - 1, j - 1);
    } else if (dp[i - 1][j] > dp[i][j- 1]) {
        trace(i - 1, j);
    } else trace(i, j - 1);
}

void process(void) {
    cin >> a >> b;
    int n = a.size(), m = b.size();
    a = " " + a;
    b = " " + b;
    FORE(i, 1, n) FORE(j, 1, m) {
        if (a[i] == b[j]) {
            dp[i][j] = dp[i - 1][j - 1] + 1;
        }
        maximize(dp[i][j], dp[i - 1][j]);
        maximize(dp[i][j], dp[i][j - 1]);
    }
    trace(n, m);
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	file("lcs");
//	int t; cin >> t; while(t--)
	process();
	return 0;
}
