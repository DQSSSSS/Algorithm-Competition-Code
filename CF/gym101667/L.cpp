#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;


struct ggg{
    int n,goal;
    vector<pii> G[SZ];

    void insert(int x,int y,int z) {
        G[x].push_back(make_pair(y,z));
    }

    LL dist[SZ];
    bool vis[SZ];

    LL dij(int s,int t) {
        for(int i = 1;i <= n;i ++) vis[i] = 0,dist[i] = 1e18;
        dist[s] = 0; priority_queue<pii> q;
        q.push(make_pair(0,s));
        while(q.size()) {
            int u = q.top().second; q.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            for(pii p : G[u]) {
                int v = p.first;
                if(dist[v] > dist[u] + p.second) {
                    dist[v] = dist[u] + p.second;
                    q.push(make_pair(-dist[v],v));
                }
            }
        }
        return dist[t];
    }

    void init(int nn) {
        n = nn;
    }

}g[4],gg;

int id(int x,int y,int z,int w) {
    return (x-1) * (g[2].n*g[3].n*3) + (y-1) * (g[3].n*3) + (z-1)*(3) + w;
}

int main() {
    int P;
    scanf("%d",&P);
    for(int i = 1;i <= P;i ++) {
        int n,m;
        scanf("%d%d",&n,&m);
        g[i].init(n);
        for(int j = 1;j <= n;j ++) {
            int x;
            scanf("%d",&x);
            g[i].insert(j,j,x);
        }
        while(m --) {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            g[i].insert(x,y,z);
        }
        int x;
        scanf("%d",&x);
        g[i].goal = x;
    }

    for(int i = P + 1;i <= 3;i ++) {
        g[i].init(1);
        g[i].insert(1,1,0);
        g[i].goal = 1;
    }

    gg.init(g[1].n*g[2].n*g[3].n*3);

    for(int i = 1;i <= g[1].n;i ++) {
        for(int j = 1;j <= g[2].n;j ++){
            for(int k = 1;k <= g[3].n;k ++) {
                for(int l = 1;l <= 3;l ++) {
                    int ii;
                    if(l == 1) ii = i;
                    else if(l == 2) ii = j;
                    else ii = k;
                    vector<pii> G = g[l].G[ii];

                    int ll = l == 3 ? 1 : l+1;
                    for(pii p : G) {
                        int x = p.first;
                        int dd;
                        if(l == 1) dd = id(x,j,k,ll);
                        else if(l == 2) dd = id(i,x,k,ll);
                        else dd = id(i,j,x,ll);
                        gg.insert(id(i,j,k,l),dd,p.second);
                    }
                }
            }
        }
    }

    cout << gg.dij(id(1,1,1,1),id(g[1].goal,g[2].goal,g[3].goal,1)) << endl;

}
/*
2
4 4
5
3
3
1
1 3 1
2 3 4
3 4 5
4 2 2
4
3 3
10
1
11
1 2 3
1 3 4
2 1 2
3


2
4 4
2
8
15
1
1 2 5
2 3 7
3 4 10
4 1 3
3
5 4
1
1
1
1
1
1 2 3
2 3 5
3 4 7
4 5 1
5

*/
