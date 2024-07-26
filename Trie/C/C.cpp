#include <bits/stdc++.h>

using namespace std;

#define name "C"
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
        Node *child[2];
        int exsit, cnt;
        Node() {
            FOR(i, 0, 2) child[i] = nullptr;
            exsit = cnt = 0;
        }
    };
    Node *root = new Node();

    void add(int x) {
        Node *p = root;
        FORDE(i, 30, 0) {
            int c = (x >> i) & 1;
            if (p->child[c] == nullptr) p->child[c] = new Node();
            p = p->child[c];
            p->cnt++;
        }
        p->exsit++;
    }

    int Kth(int k) {
        Node *p = root;
        int res = 0;
        while (true) {
            if (k < p->exsit) break;
            k -= p->exsit;
            FOR(i, 0, 2) if (p->child[i] != nullptr)  {
                Node *nxt = p->child[i];
                if (nxt->cnt >= k) {

                    p = nxt;
                    break;
                }
                k -= p->cnt;
            }
        }
        return res;
    }
}  trie;

void process(void) {
    int q; cin >> q;
    while (q--) {
        int type, x;
        cin >> type >> x;
        if (type == 1) {
            trie.add(x);
        } else {
            cout << convert_to_dec(trie.Kth(x)) << el;
        }
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
