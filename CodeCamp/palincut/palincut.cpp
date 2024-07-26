#include <bits/stdc++.h>

using namespace std;

#define name "palincut"
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

const int MAXN = 1e4 + 11, MAX = 1e6 + 11;
const ll MOD = 1e9 + 7;
const ll base = 31;
const int INF = 1e9 + 11; const ll INFF = 1e18 + 11;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

struct Hash {
    ll hashT[MAXN], hashRT[MAXN], Pow[MAXN];
    string s, revs;
    int n;
    void init(string &_s, int &_n) {
        n = _n;
        s = _s;
        FORDE(i, s.size() - 1, 0) revs += s[i];
        s = " " + s;
        revs = " " + revs;
        _s = " " + _s;
        Pow[0] = 1;
        FORE(i, 1, n) {
            Pow[i] = (Pow[i - 1] * base) % MOD;
            hashT[i] = (hashT[i - 1] * base + s[i] - 'a' + 1) % MOD;
            hashRT[i] = (hashRT[i - 1] * base + revs[i] - 'a' + 1) % MOD;
        }
    }
    ll getHashT(int i, int j) {
        return (hashT[j] - hashT[i - 1] * Pow[j - i + 1] + MOD * MOD) % MOD;
    }
    ll getHashRT(int i, int j) {
        return (hashRT[j] - hashRT[i - 1] * Pow[j - i + 1] + MOD * MOD) % MOD;
    }
    bool isPalin(int i, int j) {
//        cerr <<getHashRT(n - j + 1,  n - i + 1) << " " << getHashT(i, j) << el;
        return getHashRT(n - j + 1, n - i + 1) == getHashT(i, j);
    }
} h;

string s;

int n, k, dp[MASK(13) + 1], nxt[MAXN][20], l[20];

void process(void) {
    cin >> s;
    n = s.size();
    h.init(s, n);
//    cerr << h.isPalin(6, 7);
    int t; cin >> t;
    while (t--) {
        cin >> k;
        FORE(i, 1, k) cin >> l[i];
        memset(dp, 0, sizeof dp);
        memset(nxt, 0, sizeof nxt);
        FORDE(i, n, 1) FORE(j, 1, k) {
            nxt[i][j] = nxt[i + 1][j];
            if (i + l[j] - 1 <= n && h.isPalin(i, i + l[j] - 1)) {
//                cerr << i << " ";
                nxt[i][j] = i;
            }
        }
//        FORE(i, 1, n) {
//            FORE(j, 1, k) cout << nxt[i][j] << " ";
//            cout << el;
//        }
        dp[0] = 0;
        FOR(i, 1, MASK(k)) dp[i] = INF;
        FOR(t, 0, MASK(k)) {
            FORE(j, 1, k) if (BIT(t, j - 1) == 0) {
                int P = nxt[dp[t]][j] + 1;
                cout << P << " " << dp[t | MASK(j - 1)] << el;
                dp[t | MASK(j - 1)] = min(dp[t], P + l[j] - 1);
            }
        }
        cout << dp[MASK(k) - 1] << "\n";
        cout << (dp[MASK(k) - 1] != INF ? "YES" : "NO") << el;
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
