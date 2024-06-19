#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5;
int n,m;
struct edge {
    int v,c,w;
};
vector<edge> adj[N];
bool mini (int &a, int b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
bool maxi (int &a, int b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int d[2][N],a[2][N],b[2][N];
struct Ver {
    int u,d;
    bool operator < (const Ver &o) const {
        return d > o.d;
    }
};
void dijkstra (int st, int *d, int *a, int *b) {
    priority_queue<Ver> pq;
    d[st] = 0;
    pq.push({st,0});
    while (pq.size()) {
        Ver x = pq.top();
        int u = x.u, len = x.d;
        pq.pop();
        if (len > d[u]) continue;
        for (auto x : adj[u]) {
            int v = x.v, w = x.w, c = x.c;
            if (d[v] > d[u] + c) {
                d[v] = d[u] + c;
                a[v] = min(w,a[u]);
                b[v] = max(w,b[u]);
                pq.push({v,d[v]});
            }
            else if (d[v] == d[u] + c) {
                mini (a[v],w);
                mini (a[v],a[u]);
                maxi (b[v],w);
                maxi (b[v],b[u]);
            }
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset (d[0],0x3f3f3f,sizeof(d[0]));
    memset (a[0],0x3f3f3f,sizeof(a[0]));
    memset (d[1],0x3f3f3f,sizeof(d[1]));
    memset (a[1],0x3f3f3f,sizeof(a[1]));
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int u,v,c,w; cin >> u >> v >> c >> w;
        adj[u].push_back({v,c,w});
        adj[v].push_back({u,c,w});
    }
    dijkstra(1,d[0],a[0],b[0]);
    dijkstra(n,d[1],a[1],b[1]);
    int res = 0;
    for (int i=1; i<=n; i++) {
        if (d[0][i] + d[1][i] == d[0][n]) {
          cout << i << ' ' << a[0][i] << ' ' << a[1][i] << ' ' << b[0][i] << ' ' << b[1][i] << " ???\n";
            maxi (res,b[0][i]-a[1][i]);
            maxi (res,b[1][i]-a[0][i]);
        }
    }
    cout << res;
}
