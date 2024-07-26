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

const int MAXN = 3e5 + 11;
//const int MOD = 1e9 + 7;
//const ll INF = 1e9 + 11;
//const ll BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, q, k, a[MAXN];

vector<int> pos[MAXN];

int randInt(int l, int r) {
    return uniform_int_distribution<int> (l, r) (rng);
}

void process(void) {
    cin >> n >> k;
    FORE(i, 1, n) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    cin >> q;

    while (q--) {
        int l, r; cin >> l >> r;
        bool check = false;
        int res = -1;
        FORE(i, 1, 31) {
            int k = randInt(l, r);
            int lk = lower_bound(ALL(pos[a[k]]), l) - pos[a[k]].begin();
            int rk = upper_bound(ALL(pos[a[k]]), r) - pos[a[k]].begin() - 1;
//            cout << k << " " << lk << " " << rk << el;
            if ((rk - lk + 1) * 2 > (r - l + 1)) {
                check = true;
                res = a[k];
                break;
            }
        }
        if (check) cout << 1 << " " << res << el;
        else cout << 0 << el;
    }
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    file("C");

//	int t; cin >> t; while(t--)
	process();

	return 0;
}
