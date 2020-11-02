#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 6e6 + 10;
const LL INF = 1e18 + 10;
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

const int MAXN = 410;
const int MAXM = 15010;

struct min_cost_max_flow {

    struct edge {
        int t;
        LL d,c;
        int rev;
    };
    vector<edge> G[MAXN];

    void insert(int f,int t,LL d,LL c) {
        G[f].push_back((edge){t,d,c,(int)G[t].size()});
        G[t].push_back((edge){f,0,-c,(int)G[f].size()-1});
    }

    int n;
    LL h[MAXN],dist[MAXN];
    int preE[MAXN],preV[MAXN];

    pll work(int s,int e) {
        LL cost = 0,flow = 0;
        for(int i = 0;i <= n;i ++) h[i] = 0;
        while(1) {
            for(int i = 0;i <= n;i ++) dist[i] = INF;
            dist[s] = 0;
			priority_queue <pair<LL, LL>, vector<pair<LL, LL> >,
                greater<pair<LL, LL> > > q;
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

            LL maxflow = INF;
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

int main() {
    int n = read(),m = read();
   // int s = read(),e = read();
    mc.init(n);
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read();
        LL u = read(),v = read();
        mc.insert(x,y,u,v);
    }
    pll ans = mc.work(1,n);
    printf("%lld %lld\n",ans.first,ans.second);
}
