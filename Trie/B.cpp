#include <bits/stdc++.h>

using namespace std;

#define name "B"
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

struct Trie {
    struct Node {
        Node *child[26];
        bool isEnd;
        int cnt;
        Node() {
            FOR(i, 0, 25) child[i] = nullptr;
            isEnd = false;
            cnt = 0;
        }
    };

    Node *root;

    Trie() {
        root = new Node();
    }

    void add_string(string s) {
        Node *p = root;
        FOR(i, 0, s.size()) {
            int id = s[i] - 'a';
            if (p->child[id] == nullptr) p->child[id] = new Node();
            p->cnt++;
            p = p->child[id];
        }
        p->cnt++;
        p->isEnd = true;
    }

    int cntPrefix(string s) {
        Node *p = root;
        FOR(i, 0, s.size()) {
            int id = s[i] - 'a';
            if (p->child[id] == nullptr) p->child[id] = new Node();
            p = p->child[id];
        }
        return p->cnt;
    }
} trie;

int n, m;

void process(void) {
    cin >> n;
    FORE(i, 1, n) {
        string s; cin >> s;
        trie.add_string(s);
    }
    cin >> m;
    FORE(i, 1, m) {
        string s; cin >> s;
        cout << trie.cntPrefix(s) << el;
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
