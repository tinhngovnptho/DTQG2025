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

int n, a[MAXN];

void Compress(int *a) {
    set<int> s;
    FORE(i, 1, n) s.insert(a[i]);
    FORE(i, 1, n) {

    }
}

void LIS() {
    // binary search
//    vector<int> lis;
//    lis.push_back(a[1]);
//    FORE(i, 2, n) {
//        if (a[i] > lis.back()) lis.push_back(a[i]);
//        int l = lower_bound(ALL(lis), a[i]) - lis.begin();
//        lis[l] = a[i];
//    }
//    cout << lis.size();
    // fenwick tree
    Compress(a);
}

void process(void) {
    cin >> n;
    FORE(i, 1, n) cin >> a[i];
    LIS();
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	file("lis");
//	int t; cin >> t; while(t--)
	process();
	return 0;
}
