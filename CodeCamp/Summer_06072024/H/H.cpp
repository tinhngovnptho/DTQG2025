#include <bits/stdc++.h>

using namespace std;

#define name "H"
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

const int MAXN = 5e5 + 11, MAX = 1e6 + 11;
//const int MOD = 1e9 + 7;
//const int INF = 1e9 + 11; const ll INF = (ll) 1e18 + 11;
//const int BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

struct Trie {
    struct Node {
        Node *child[26];
        bool isEnd;
        Node() {
            FOR(i, 0, 26) child[i] = nullptr;
            isEnd = false;
        }
    };
    Node *root = new Node();

    void add(const string &s) {
        Node *p = root;
        FOR(i, 0, s.size()) {
            int id = s[i] - 'a';
            if (p->child[id] == nullptr) p->child[id] = new Node();
            p = p->child[id];
        }
        p->isEnd = true;
    }
    bool query(const string &s) {
        Node *p = root;
        FOR(i, 0, s.size()) {
            int id = s[i] - 'a';
            if (p->child[id] == nullptr) return false;
            p = p->child[id];
        }
        return p->isEnd;
    }
} trie;

int n, dp[MAXN];
string s, d;
unordered_set<int> v;

void process(void) {
    cin >> n >> s;
    while (n--) {
        cin >> d;
        trie.add(d);
        v.insert(d.size());
    }
    FORDE(i, s.size() - 1, 0) {
        for (int x : v) if (i + x - 1 < s.size()) {
//            cout << s.substr(i, x) << el;
            if (trie.query(s.substr(i, x))) maximize(dp[i], dp[i + x] + x);
        }
    }
    cout << *max_element(dp, dp + s.size());
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
