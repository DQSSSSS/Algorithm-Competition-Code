#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1000010;
const LL INF = 1e18 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-12;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

struct haha {
    int f,t,d1,d2;
}e[SZ];

int p1[SZ],p2[SZ],s[SZ];
LL nosleep[SZ];

struct edge {
    int t,d;
};

vector<edge> g[SZ];

int n,m;
LL dist[SZ];
bool vis[SZ];
priority_queue<pli> q;

void dij(int u) {
    for(int i = 1;i <= n;i ++) dist[i] = INF,vis[i] = 0;
    dist[u] = 0;
    q.push(make_pair(0,u));
    while(q.size()) {
        int u = q.top().second; q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(edge e : g[u]) {
            int v = e.t;
            if(dist[v] > dist[u] + e.d) {
                dist[v] = dist[u] + e.d;
                q.push(make_pair(-dist[v],v));
            }
        }
    }
}

vector<int> ans;

int main() {
    n = read(),m = read();
    for(int i = 1;i <= m;i ++) {
        e[i].f = read(),e[i].t = read();
        e[i].d1 = read(),e[i].d2 = read();
        g[e[i].t].push_back((edge){e[i].f,e[i].d2});
    }
    dij(n);
    int l1 = read();
    for(int i = 1;i <= l1;i ++) {
        p1[i] = read(); s[i] = read();
    }

    nosleep[n] = 0;
    for(int i = l1;i >= 1;i --) {
        int u = e[p1[i]].f,d = e[p1[i]].d1;
        nosleep[u] = nosleep[e[p1[i]].t] + d;
    }

    int l2 = read();
    for(int i = 1;i <= l2;i ++) {
        p2[i] = read();
    }

    for(int i = 1;i <= n;i ++) g[i].clear();
    for(int i = 1;i <= m;i ++) {
        g[e[i].f].push_back((edge){e[i].t,e[i].d2});
    }

    int t = 1,r = 1;
    LL st = 0,sr = 0;
    for(int i = 1,j = 1;i <= l2;i ++) {

        bool flag = 0;
        for(edge b : g[r]) {
            if(dist[r] == dist[b.t] + b.d && b.t != e[p2[i]].t) {
                flag = 1;
            }
        }
        if(flag) {
            while(j <= l1 && st + e[p1[j]].d1 + s[j] <= sr) {
                st += e[p1[j]].d1 + s[j]; j ++;
            }
            if(j > l1) break;

            if(st + e[p1[j]].d1 > sr) {
                if(st + e[p1[j]].d1 + nosleep[e[p1[j]].t] >= sr + dist[r]) {
                    ans.push_back(r);
                //    printf("%d %lld %lld\n",r,st + e[p1[j]].d1 + nosleep[e[p1[j]].t],sr + dist[r]);
                }
            }
            else {
                if(st + e[p1[j]].d1 + s[j] + nosleep[e[p1[j]].t] >= sr + dist[r]) {
                    ans.push_back(r);
             //       printf("%d %lld %lld\n",r,st + e[p1[j]].d1 + s[j] + nosleep[e[p1[j]].t],sr + dist[r]);
                }
            }

        }
        r = e[p2[i]].t; sr += e[p2[i]].d2;
    }
    printf("%d\n",ans.size());
    sort(ans.begin(),ans.end());
    for(int i = 0;i < ans.size();i ++)
        printf("%d ",ans[i]);
}
/**
8 12
1 2 2 10
2 3 1 10
3 8 2 10
1 4 10 1
4 5 10 2
5 6 10 4
6 8 10 2
1 7 10 5
4 7 10 2
5 7 10 2
6 7 10 1
7 8 10 1
3
1 3
2 2
3 0
4
4 5 6 7
*/
