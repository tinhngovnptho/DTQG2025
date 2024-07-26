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

// end of template

const int MAXN = 5e5 + 11, MAX = 1e7 + 11;
const int MOD = 1e9 + 7;
//const ll INF = 1e9 + 11;
//const ll BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

bool isDel[MAX];
int n, k, d;

#define NODE(u) (u) & -(u)

namespace Brute {
    pii bit[MAXN];

    void add(int &a, int b) {
        a += b;
        if (a >= MOD) a -= MOD;
    }

    void update(int u, pii x) {
        for (; u <= n; u += NODE(u)) {
            if (bit[u].fi < x.fi) bit[u] = x;
            else if (bit[u].fi == x.fi) {
                add(bit[u].se, x.se);
            }
        }
    }

    pii query(int u) {
        pii res = {0, 1};
        for (; u; u -= NODE(u)) {
            if (bit[u].fi > res.fi) res = bit[u];
            else if (bit[u].fi == res.fi) add(res.se, bit[u].se);
        }
        return res;
    }

    void solve() {
        vector<int> a;
        a.push_back(-1);
        FORE(i, 1, n) if (!isDel[i]) a.push_back(i);
        FORE(i, 1, n - k) {
            pii tmp = query(a[i] - d);
            tmp.fi++;
            update(a[i] + d, tmp);
        }
        cout << query(n).fi << el << query(n).se;
    }
}

void process(void) {
    cin >> n >> k >> d;
    FORE(i, 1, k) {
        int x; cin >> x;
        isDel[x] = true;
    }
    return void(Brute::solve());
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    file("opset");

//	int t; cin >> t; while(t--)
	process();

	return 0;
}
