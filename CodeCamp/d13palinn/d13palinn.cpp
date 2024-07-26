    #include <bits/stdc++.h>

    using namespace std;

    #define name "d13palinn"
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
    //const int INF = 1e9 + 11; const ll INFF = 1e18 + 11;
    //const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

    #define int ll

    ll Pow[41], dp[41][111];
    int n, m, k;
    vector<int> d;

    void preprocess() {
        Pow[0] = 1;
        FORE(i, 1, 40) Pow[i] = (Pow[i - 1] * 10) % m;
    }


    ll calc(int i, int mod) {
        if (i > (n + 1) / 2) {
            return dp[i][mod] = mod == 0;
        }
        if (dp[i][mod] != -1) return dp[i][mod];
        ll res = 0;
        for (int v = (i == 1); v <= 9; ++v) {
            if (i == (n + 1) / 2 && n & 1) {
    //            cout << v << ": " << mod << "  " << (mod + v * Pow[n - i]) % m <<el;
                res += calc(i + 1, (mod + v * Pow[n - i]) % m);
            } else res += calc(i + 1, (mod + v * Pow[n - i] + v * Pow[i - 1]) % m);
        }
        return dp[i][mod] = res;
    }

    void order_to_config(int i, int mod) {
        if (i > (n + 1) / 2) {
            return ;
        }
        for (int v = (i == 1); v <= 9; ++v) {
            int val = v * Pow[n - i] + v * Pow[i - 1];
            if (i == (n + 1) / 2 && n & 1) val = v * Pow[n - i];
            val += mod;
            val %= m;
    //        cout << v << " " << dp[i + 1][val] << ": " << el;
            if (k > calc(i + 1, val)) k -= dp[i + 1][val];
            else {
                d.push_back(v);
                order_to_config(i + 1, val);
                break;
            }
        }
    }

    void process(void) {
        cin >> n >> m >> k;
        preprocess();
        memset(dp, -1, sizeof dp);
        calc(1, 0);
        cout << dp[1][0] << el;
        d.push_back(-1);
        order_to_config(1, 0);
        FORE(i, 1, n / 2) cout << d[i];
        if (n & 1) cout << d[(n + 1) / 2];
        FORDE(i, n / 2, 1) cout << d[i];
    }

    signed main(void) {
        ios_base::sync_with_stdio(false); cin.tie(nullptr);
        if (fopen(name".inp", "r")) {
            freopen(name".inp", "r", stdin);
            freopen(name".out", "w", stdout);
        }
    //	int t; cin >> t; while(t--)
        process();
        return 0;
    }
