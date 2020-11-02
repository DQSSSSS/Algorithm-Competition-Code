#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 1010;
const int mod = 1e9 + 7;
const LL INF = 1e15;

struct GRAPH {
    int n;
    LL dist[SZ];
    bool vis[SZ];

    vector<pii> g[SZ];

    void insert(int x,int y,int z) {
        g[x].push_back(make_pair(y,z));
    }

    LL ask(int s,int t) {
        for(int i = 1;i <= n;i ++) vis[i] = 0,dist[i] = INF;
        dist[s] = 0;
        priority_queue<pii> q;
        q.push(make_pair(0,s));
        while(q.size()) {
            int u = q.top().second; q.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            for(pii p : g[u]) {
                int v = p.first;
                int d = p.second;
                if(dist[v] > dist[u] + d) {
                    dist[v] = dist[u] + d;
                    q.push(make_pair(-dist[v],v));
                }
            }
        }
        return dist[t];
    }

    void init(int nn) {
        n = nn;
    }

}graph;

struct haha {
    int s,u,t;
}b[SZ];

int k;
LL r[SZ];
LL dis[SZ],dis2[SZ],w[SZ][SZ],f[SZ],tmp[SZ][SZ];

bool check(LL mid) {
    for(int i = 1;i <= k;i ++) r[i] = b[i].s+mid;
    for(int i = 1;i <= k;i ++) {
        for(int j = i;j <= k;j ++) {
            tmp[i][j] = r[j] - w[i][j];
        }
        for(int j = i+1;j <= k;j ++) tmp[i][j] = min(tmp[i][j],tmp[i][j-1]);
    }
   /* puts("");
    for(int i = 1;i <= k;i ++) printf("%lld ",r[i]); puts("");
    for(int i = 1;i <= k;i ++) {
        for(int j = 1;j <= k;j ++) {
            printf("%lld ",tmp[i][j]);
        }
        puts("");
    }*/
    f[1] = 0;
    for(int i = 2;i <= k;i ++) {
        f[i] = INF;
        for(int j = i - 1;j >= 1;j --) {
            LL l = max(f[j]+dis[j],1ll*b[i].t) + dis[j+1];
            LL r = tmp[j+1][i];
            if(l <= r) {
                f[i] = min(f[i],f[j] + dis[j] + dis[j+1] + w[j+1][i]);
            }
        }
      //  cout << f[i] << " "; puts("");
    }
    return f[k] < INF;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    graph.init(n);
    for(int i = 1;i <= m;i ++) {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        graph.insert(x,y,z);
        graph.insert(y,x,z);
    }
    scanf("%d",&k);
    for(int i = 1;i <= k;i ++) {
        scanf("%d%d%d",&b[i].s,&b[i].u,&b[i].t);
    }
    for(int i = 1;i < k;i ++) dis2[i] = graph.ask(b[i].u,b[i+1].u);
    for(int i = 1;i <= k;i ++) {
        dis[i] = graph.ask(1,b[i].u);
        w[i][i] = 0;
        for(int j = i+1;j <= k;j ++) {
            w[i][j] = w[i][j-1] + dis2[j-1];
        }
    }
/*
    for(int i = 1;i <= k;i ++) printf("%lld ",dis[i]); puts("");
    for(int i = 1;i <= k;i ++) {
        for(int j = 1;j <= k;j ++) {
            printf("%lld ",w[i][j]);
        }
        puts("");
    }*/
   // check(6); return 0;
    LL l = 0,r = INF;
    while(r-l>1) {
        LL mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
}
/**
4 4
1 2 200000000
2 3 400000000
3 4 100000000
4 1 200000000
3
1 4 2
3 3 3
4 3 6
*/

