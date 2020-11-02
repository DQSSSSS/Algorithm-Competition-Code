#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 5e6 + 10;
const LL INF = 1e9 + 10;
const LD eps = 1e-8;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

const int MAXN = 5010;
const int MAXM = 2200010;

struct min_cost_max_flow {

    struct edge {
        int t,d,c,rev;
    };
    vector<edge> G[MAXN];

    void insert(int f,int t,int d,int c) {
        G[f].push_back((edge){t,d,c,(int)G[t].size()});
        G[t].push_back((edge){f,0,-c,(int)G[f].size()-1});
    }

    int n,m;
    int h[MAXN],dist[MAXN];
    int preE[MAXN],preV[MAXN];

    pii work(int s,int e) {
        int cost = 0,flow = 0;
        for(int i = 0;i <= n;i ++) h[i] = 0;
        while(1) {
            for(int i = 0;i <= n;i ++) dist[i] = INF;
            dist[s] = 0;
			priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
            q.push(make_pair(0,s));
            while(q.size()) {
                int u = q.top().second;
                int d = q.top().first;
                q.pop();
                if(dist[u] < d) continue;
                for(int i = 0;i < G[u].size();i ++) {
                    edge& e = G[u][i];
                    int v = e.t;
                    if(e.d > 0 && dist[v] > dist[u] + e.c + h[u] - h[v]) {
                        dist[v] = dist[u] + e.c + h[u] - h[v];
                        preE[v] = i;
                        preV[v] = u;
                        q.push(make_pair(dist[v],v));
                    }
                }
            }
            if(dist[e] == INF) break;
            for(int i = 0;i <= n;i ++) h[i] += dist[i];

            int maxflow = INF;
            for(int u = e;u != s;u = preV[u])
                maxflow = min(maxflow,G[preV[u]][preE[u]].d);
            cost += maxflow * h[e];
            flow += maxflow;
            for(int u = e;u != s;u = preV[u]) {
                edge& e = G[preV[u]][preE[u]];
                e.d -= maxflow;
                G[u][e.rev].d += maxflow;
            }
        }
        return make_pair(flow,cost);
    }

    void init(int nn) {
        n = nn;
        for(int i = 0;i <= n;i ++) G[i].clear();
    }
}mc;

int a[SZ];

int main() {
    //freopen("multi.in","r",stdin);
    //freopen("my.out","w",stdout);
    int T = read();
    while(T --) {
        int n = read(),m = read();
        for(int i = 1;i <= n;i ++) a[i] = read();
        int s1 = 0,s2 = 2*n+1,e = 2*n+2;
        mc.init(e);
        mc.insert(s1,s2,m,0);
        for(int i = 1;i <= n;i ++) {
            mc.insert(i,i+n,1,-a[i]);
        }
        for(int i = 1;i <= n;i ++) {
            for(int j = i + 1;j <= n;j ++) {
                if(a[i] <= a[j])
                    mc.insert(i+n,j,1,0);
            }
        }
        for(int i = 1;i <= n;i ++) {
            mc.insert(s2,i,1,0);
            mc.insert(i+n,e,1,0);
        }
        printf("%d\n",-mc.work(s1,e).second);
    }
}
/**
691089
2325 0
2326 0
1162 0
2324 -22524
2327 -22524
1161 0
2323 -7591
1162 -7591
2324 -30115
2327 -30115
1160 0
2322 -14911
1162 -14911
2324 -37435
2327 -37435
1159 0
2321 -49141
2327 -49141
*/
