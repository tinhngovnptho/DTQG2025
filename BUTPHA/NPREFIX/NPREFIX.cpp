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
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define FORX(i, a, b, x) for (int i = (a), _b = (b); i <= _b; i += (x))
#define BIT(x, i) ((x) & (1LL << (i)))
#define MASK(x) (1LL << (x))
#define ONBIT(x, i) ((x) | (1LL << (i)))
#define OFFBIT(x, i) ((x) & ~(1LL << (i)))
#define file(name) if (fopen(name".inp", "r")) freopen(name".inp", "r", stdin), freopen(name".out", "w", stdout)

template<class X, class Y> bool maximize(X &a, const Y &b) { return a < b ? a = b, 1 : 0; };
template<class X, class Y> bool minimize(X &a, const Y &b) { return a > b ? a = b, 1 : 0; };

/// Author: tinhnopro
// end of template

//const int MAXN = (int) 5e5 + 11;
//const int MOD = (int) 1e9 + 7;
//const ll INF = (ll) 1e18 + 11;
//const ll BASE = 311;
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};


struct Trie {
    struct Node {
        Node *child[26];
        int cnt;
        Node() {
            FOR(i, 0, 25) child[i] = nullptr;
            cnt = 0;
        }
    };

    Node *root;

    Trie() {
        root = new Node();
    }

    void add(const string &s) {
        Node *p = root;
        for (char x : s) {
            int id = x - 'a';
            if (p->child[id] == nullptr) p->child[id] = new Node();
            p->cnt++;
            p = p->child[id];
        }
        p->cnt++;
    }
    int query(const string &x) {
        Node *p = root;
        for (char c : x) {
            int id = c - 'a';
            if (p->child[id] == nullptr) p->child[id] = new Node();
            p = p->child[id];
        }
        return p->cnt;
    }
} trie;

int n, m;

void process(void) {
    cin >> n;
    FOR(i, 1, n) {
        string s; cin >> s;
        trie.add(s);
    }
    cin >> m;
    while (m--) {
        string x; cin >> x;
        cout << trie.query(x) << el;
    }
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

    file("NPREFIX");

//	int t; cin >> t; while(t--)
	process();
	return 0;
}
