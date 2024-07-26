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

int N, M, pos [MAXN], cnt;
ii A[MAXN * MAXN];

Void Akao (Void) {
    cin >> N >> M;
    for (int i = 1; i <= N; ++ i) {
        for (int j = 1; j <= M; ++ j) {
            ++ cnt;
            cin >> A[cnt].fi;
            A[cnt].se = i;
        }
    }
    int ans = oo;
    sort (A + 1, A + cnt + 1);
//    for (int i = 1; i <= cnt; ++i) cout << A[i].fi << " " << A[i].se << "\n";
    int l = 1, cur = 0;
    for (int r = 1; r <= cnt; ++ r) {
        if (pos[A[r].se] == 0)
            ++ cur;
        pos[A[r].se]++;
        if (cur == N) {
            while (pos[A[l].se] > 1 && l < r) {
                -- pos[A[l].se];
                ++ l;
            }
            ans = min (ans, A[r].fi - A[l].fi);
            -- pos[A[l].se];
            -- cur;
            ++ l;
        }
    }
    cout << ans;
}

 main() {
     ios_base::sync_with_stdio (0);
     cin.tie (0);
    cout.tie (0);
    Akao ();
    return 0;
}
