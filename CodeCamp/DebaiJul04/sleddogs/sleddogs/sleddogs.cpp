    #include <bits/stdc++.h>

    using namespace std;

    #define name "sleddogs"
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

    const int MAXN = 5e5 + 11, MAX = 1e6 + 11;
    //const int MOD = 1e9 + 7;
    //const int INF = 1e9 + 11; const ll INFF = 1e18 + 11;
    //const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

    int n, a[MAXN], b[MAXN], k;

    void process(void) {
        cin >> n >> k;
        FORE(i, 1, n) cin >> a[i];
        FORE(i, 1, n) cin >> b[i];
        int ans = 0;
        FORE(i, 1, n)  {
            int p = (a[i] + k - 1) / k;
            int q = (b[i] + k - 1) / k;
            ans +=  p + q;
            a[i] = p * k - a[i];
            b[i] = q * k - b[i];
        }
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        int j = n;
        FORE(i, 1, n) {
            if (a[i] + b[j] >= k) {
                ans--;
                j--;
            }
        }
        cout << ans;
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

