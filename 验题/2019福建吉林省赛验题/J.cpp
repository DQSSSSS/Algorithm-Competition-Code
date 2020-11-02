#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 500010;
const LL INF = 1e18;
const int mod = 1e9 + 7;
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

struct edge {
    int f,t,d;
};

bool cmp(edge a,edge b) { return a.d < b.d; }

vector<edge> a,g[SZ];

int n;
LL dist[SZ],vis[SZ];
priority_queue<pli> q;

LL dij(int s,int e) {
    for(int i = 1;i <= n;i ++) dist[i] = INF,vis[i] = 0;
    dist[s] = 0;
    while(q.size()) q.pop();
    q.push(make_pair(0,s));
    while(q.size()) {
        int u = q.top().second; q.pop();
        if(u == e) break;
        if(vis[u]) continue;
        vis[u] = 1;
        for(edge e: g[u]) {
            int v = e.t;
            if(dist[v] > dist[u] + e.d) {
                dist[v] = dist[u] + e.d;
                q.push(make_pair(-dist[v],v));
            }
        }
    }
    return dist[e];
}

int main() {
    while(~scanf("%d",&n)) {
        a.clear();
        for(int i = 1;i <= n;i ++) g[i].clear();
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= n;j ++) {
                int x = read();
                if(i > j)
                    a.push_back((edge){i,j,x});
            }
        }
        sort(a.begin(),a.end(),cmp);

        int ans = 0;
        for(edge e : a) {
            int f = e.f,t = e.t,d = e.d;
            LL mindist = dij(f,t);
            if(mindist == d) continue;
            else {
                ans ++;
                g[f].push_back(e);
                g[t].push_back((edge){t,f,d});
            }
        }

        cout << ans << endl;
    }
    return 0;
}
