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

const int MAXN = 5e5 + 11;
//const int MOD = 1e9 + 7;
//const ll INF = 1e9 + 11;
//const ll BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

int k, m;
string s;
vector<string> v;

struct Hash {
    ll hashS[MAXN], hashRev[MAXN], POW[MAXN];

    static const ll base = 31, MOD = 1e9 + 7;

    int n;

    void init(const string &s) {
        string v = " " + s;
        string rev = " ";
        n = s.size();

        FORDE(i, n, 1) rev.push_back(v[i]);

        POW[0] = 1;
        hashS[0] = 0;
        hashRev[0] = 0;

        FORE(i, 1, n) {
            POW[i] = POW[i - 1] * base % MOD;
            hashS[i] = (hashS[i - 1] * base + v[i] - 'a' + 1)  % MOD;
            hashRev[i] = (hashRev[i - 1] * base + rev[i] - 'a' + 1) % MOD;
        }
    }

    ll getHash(int i, int j, ll *h) {
        return (h[j] - h[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
    }

    bool isPalin(int i, int j) {
        i++;
        j++;
        return (getHash(i, j, hashS) == getHash(n - j + 1, n - i + 1, hashRev));
    }
} h;

void Sub12() {
    h.init(s);
    int ans = 0;
    FORE(i, 0, s.size() - m) {
        if (h.isPalin(i, i + m - 1)) ans++;
    }
    cout << ans;
}

vector<string> mergeV(vector<string> &a, vector<string> &b) {
    vector<string> ret;
    for (string s : a) ret.push_back(s);
    for (string s : b) ret.push_back(s);
    return ret;
}

bool isPalinV(vector<string> x) {
    string d = "";
    for (string t : x) d = d + t;
    FOR(i, 0, d.size() / 2) if (d[i] != d[d.size() - i - 1]) return false;
    return true;
}

bool solve(vector<string> x, string &a) {
    x.push_back(a);
    if (isPalinV(x)) return true;
    while (next_permutation(ALL(x))) {
        if (isPalinV(x)) return true;
    }
    return false;
}

void Sub3() {
    string d = "";
    FOR(i, 0, m) d.push_back(s[i]);
    int ans = solve(v, d);
    FORE(i, 1, s.size() - m) {
        d.erase(0, 1);
        d.push_back(s[i + m - 1]);
        ans += solve(v, d);
    }
    cout << ans;
}

bool solve2(string &a) {
    vector<string> v1, v2;
    vector<vector<string>> x1, x2;

    v1.push_back(a);

    FOR(i, 0, v.size() / 2) v1.push_back(v[i]);
    FOR(i, v.size() / 2, v.size()) v2.push_back(v[i]);

    x1.push_back(v1);
    x2.push_back(v2);

    while (next_permutation(ALL(v1))) {
        x1.push_back(v1);
    }

    while (next_permutation(ALL(v2))) {
        x2.push_back(v2);
    }

    for (vector<string> &a : x1) {
        for (vector<string> &b : x2) {
            if (isPalinV(mergeV(a, b))) return true;
        }
    }

    return false;
}

void Sub5() {
    string d = "";
    FOR(i, 0, m) d.push_back(s[i]);
    int ans = solve2(d);
    FORE(i, 1, s.size() - m) {
        d.erase(0, 1);
        d.push_back(s[i + m - 1]);
        ans += solve2(d);
    }
    cout << ans;
}

void process(void) {
    cin >> k >> m >> s;
    if (k == 1) return void(Sub12());
    FORE(i, 1, k - 1) {
        int l, r; cin >> l >> r;
        l--;
        r--;
        v.push_back(s.substr(l, r - l + 1));
    }
    if (k <= 7) return void(Sub3());
    Sub5();
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    file("pw");

//	int t; cin >> t; while(t--)
	process();

	return 0;
}
