#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;

#define ll long long
#define pb push_back
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define iiii pair <ii, ii>
#define fi first
#define se second
#define For(j,n) for(int i = j; i <= n; i++)
#define Void void
#define be begin
#define ed end
#define sz size
#define rsz resize
#define ub upper_bound
#define lb lower_bound
#define b_ins back_inserter
#define int long long
#define MASK(i) (1ll << i)
#define BIT(mask,i) (((mask) >> (i)) & 1ll)
#define OFFBIT(mask, i) (mask &~ (1ll << (i)))
#define ONBIT(mask,i) (mask  (1ll << (i)))


const int XIII = 13;
const int MAXN = 1e3 + XIII;
const int MAXV = 5e5 + XIII;
const int MAXM = 1e6;
const ll oo = 1e17;
const ll MOD = 1e9 + 7;
const int base = 227;
const int onestack = 264;

int N, Q, cnt = -1;
int P[MAXN][MAXN], x[MAXV], y[MAXV];

Void Akao (Void) {

    cin >> Q >> N;
    for (int i = 1; i <= N; ++ i)
        cin >> x[i] >> y[i];
    for (int i = 1; i <= N; ++ i) {
        int id = i % N + 1  ;
        int curx = x[i], cury = y[i];
        while (curx != x[id] || cury != y[id]) {
            if (cury == y[id]) {
                if (curx < x[id])
                    ++ curx;
                else
                    -- curx;
            }
            else {
                if (cury < y[id])
                    ++ cury;
                else
                    -- cury;
            }
            P[curx][cury] = ++ cnt;
            //cout << curx << " " << cury << " " << cnt << "\n";
        }
    }
    ++ cnt;
    for (int i = 1, x1, x2, y1, y2; i <= Q; ++ i) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << min (abs (P[x1][y1] - P[x2][y2]), cnt - abs (P[x1][y1] - P[x2][y2])) << "\n";
    }
}

 main() {
     ios_base::sync_with_stdio (0);
     cin.tie (0);
    cout.tie (0);
    Akao ();
    return 0;
}
