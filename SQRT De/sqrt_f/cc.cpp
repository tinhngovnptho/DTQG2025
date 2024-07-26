#include <bits/stdc++.h>
#define task "sqrt_f"
#define ll long long
#define double long double
#define ii pair<int,int>
#define fi first
#define se second
#define c_bit(i)       __builtin_popcountll(i)
#define Bit(mask,i)    ((mask >> i) & 1)
#define onbit(mask,i)  ((mask) | (1LL << i))
#define offbit(mask,i) ((mask) &~ (1LL << i))
using namespace std;
const int maxn = 2e5 + 5e4 + 1;
const int MAX = 5e4 + 1;
const ll oo = 1e18;
const int mod = 1e9 + 7;
const int dx[] = {0,1,0,-1} , dy[] = {1,0,-1,0};
const int BLOCK_SIZE = 1000;
#define getBlock(i) (((i) - 1) / BLOCK_SIZE + 1)
#define getLeft(id) (((id) - 1) * BLOCK_SIZE + 1)
#define getRight(id) ((id) * BLOCK_SIZE)
int n, a[maxn], q, bit[501][MAX], bit2[MAX];
void update2(int id)
{
    for(; id; id -= id & -id) bit2[id] ++;
}
int get2(int id)
{
    int res = 0;
    for(; id < MAX; id += id & -id) res += bit2[id];
    return res;
}
void update(int block, int id, int val)
{
    for(; id; id -= id & -id) bit[block][id] += val;
}
int get(int block, int id)
{
    int res = 0;
    for(; id < MAX; id += id & -id) res += bit[block][id];
    return res;
}
int getRange(int block, int r)
{
    return get(block, 1) - get(block, r + 1);
}
int solve(int pos, int val)
{
    int cnt = 0, blockID = getBlock(pos);

    for(int i = getLeft(blockID); i < pos; i ++) cnt += a[i] > val;
    for(int i = pos + 1;i <= min(getRight(blockID), n);i ++) cnt += a[i] < val;

    for(int id = 1; id < blockID; id ++) cnt += get(id, val + 1);
    for(int id = blockID + 1; id <= getBlock(n); id ++) cnt += getRange(id, val - 1);

    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    if(fopen(task".inp","r")){
       freopen(task".inp","r",stdin);
       freopen(task".out","w",stdout);
    }
    cin >> n;
    ll res = 0;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
        update(getBlock(i), a[i], 1);
        res += get2(a[i] + 1);
        update2(a[i]);
    }
//    cout << res << "\n";
    cin >> q;
    while(q --){
        int pos, val; cin >> pos >> val;
        int blockID = getBlock(pos);
        res -= solve(pos, a[pos]);
        update(blockID, a[pos], -1);
        update(blockID, val, 1);
        a[pos] = val;
        res += solve(pos, val);
        cout << res << '\n';
    }
    return 0;
}
