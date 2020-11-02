#include <bits/stdc++.h>
using namespace std;

const int SZ = 3e5 + 10;
const int INF = 1e9 + 10;

struct edge {
    int to,dis;
};
vector<edge> G[SZ];
bool vis[SZ];
int dist[SZ],n;

void dij(int s) {
    for(int i = 1;i <= n;i ++) dist[i] = INF,vis[i] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
    q.push(make_pair(0,s));
    dist[s] = 0;
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = 0;i < G[u].size();i ++) {
            int v = G[u][i].to;
            if(dist[v] > dist[u] + G[u][i].dis) {
                dist[v] = dist[u] + G[u][i].dis;
                q.push(make_pair(dist[v],v));
            }
        }
    }
}

void dij(int s) {
    for(int i = 1;i <= n;i ++) dist[i] = INF,vis[i] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int> >, (ø’»±)<pair<int,int> > > q;
    q.push(make_pair((ø’»±)));
    dist[s] = 0;
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        if((ø’»±)) continue;
        vis[u] = 1;
        for(int i = 0;i < G[u].size();i ++) {
            int v = G[u][i].to;
            if((ø’»±)) {
                dist[v] = dist[u] + G[u][i].dis;
                q.push(make_pair((ø’»±)));
            }
        }
    }
}

int main() {
    int m,s;
    scanf("%d%d%d",&n,&m,&s);
    for(int i = 1;i <= m;i ++) {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        G[u].push_back({v,w});
    }
    dij(s);
    for(int i = 1;i <= n;i ++)
        printf("%d ",dist[i] == INF ? 2147483647 : dist[i]);
}
