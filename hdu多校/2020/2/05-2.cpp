#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 200010;
const LL INF = 1e18 + 10;
const LL mod = 1e17;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}


const int MAXN = SZ;
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

struct haha {
    LL a,b,c;
}A[55];

int main() {
    int T = read();
    while(T --) {
        int n = read(),m = read();
        set<int> node;
        for(int i = 1;i <= n;i ++) {
            LL a = read(),b = read(),c = read();
            A[i].a = a;
            A[i].b = b;
            A[i].c = c;
            LL id = -b/(2*a);
            id = max(id,1ll);
            id = min(id,(LL)m);
            for(int j = id-n;j <= id+n;j ++) {
                if(1 <= j && j <= m) {
                    node.insert(j);
                }
            }
        }
        int ln = n,rn = node.size();
        vector<int> vec;
        for(int j : node) vec.push_back(j);

        mc.init(ln+rn+3);
        for(int i = 1;i <= ln;i ++) mc.insert(ln+rn+1,i,1,0);
        for(int i = 1;i <= rn;i ++) mc.insert(i+ln,ln+rn+2,1,0); // e
        for(int i = 1;i <= ln;i ++) {
            LL id = -A[i].b/(2*A[i].a);
            id = max(id,1ll);
            id = min(id,(LL)m);
            for(int j = id-n;j <= id+n;j ++) {
                if(1 <= j && j <= m) {
                    int t = lower_bound(vec.begin(),vec.end(),j) - vec.begin() + 1;
                    mc.insert(i,t+ln,1,A[i].a * j * j + A[i].b * j + A[i].c);
                }
            }
        }
        LL ans = 0;
        for(int i = 1;i <= n;i ++) {
            mc.insert(ln+rn+3,ln+rn+1,1,0);
            LL t = mc.work(ln+rn+3,ln+rn+2).second;
            ans += t;
            printf("%lld%c",ans,i==n?'\n':' ');
        }

    }
    return 0;
}
