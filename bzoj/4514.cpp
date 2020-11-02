#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2e5 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

struct edge {
    int f,t;
    LL d,c;
}l[SZ];

int n,m,head[SZ],nxt[SZ],tot = 1,totp;

void build(int f,int t,LL d,LL c) {
    l[++ tot] = (edge){f,t,d,c};
    nxt[tot] = head[f];
    head[f] = tot;
}

void insert(int f,int t,LL d,LL c) {
   // printf("%d->%d %lld %lld\n",f,t,d,c);
    build(f,t,d,c); build(t,f,0,-c);
}

struct MAMF{

    LL dist[SZ];
    queue<int> q;
    bool use[SZ];
    int pre[SZ];

    bool spfa(int s,int e) {
        for(int i = 0;i <= e;i ++) pre[i] = 0,use[i] = 0,dist[i] = -1e18;
        dist[s] = 0;
        q.push(s);
        while(q.size()) {
            int u = q.front(); q.pop();
            use[u] = 0;
            for(int i = head[u];i;i = nxt[i]) {
                int v = l[i].t;
                if(l[i].d && dist[v] < dist[u] + l[i].c) {
                    dist[v] = dist[u] + l[i].c;
                    pre[v] = i;
                    if(!use[v]) {
                        use[v] = 1; q.push(v);
                    }
                }
            }
        }
        return dist[e] != 1e-18;
    }

    LL mcmf(int s,int e) {
        LL ans = 0,flow = 0;
        while(spfa(s,e)) {
            LL maxflow = INF;
            for(int i = pre[e];i;i = pre[l[i].f])
                maxflow = min(maxflow,l[i].d);
            if(ans + maxflow * dist[e] < 0) maxflow = -ans / dist[e];
            flow += maxflow;
            if(maxflow == 0) break;
            for(int i = pre[e];i;i = pre[l[i].f])
                ans += l[i].c * maxflow,l[i].d -= maxflow,l[i^1].d += maxflow;
        }
        return flow;
    }
}ek;

int get(int x) {
    int ans = 0;
    for(int i = 2;i * i <= x;i ++) {
        if(x % i == 0) {
            while(x % i == 0) x /= i,ans ++;
        }
    }
    if(x != 1) ans ++;
    return ans;
}

LL a[SZ],b[SZ],c[SZ],d[SZ];

int main() {
    int n = read();
    int s = n + 1,e = s + 1;
    for(int i = 1;i <= n;i ++) a[i] = read();
    for(int i = 1;i <= n;i ++) b[i] = read();
    for(int i = 1;i <= n;i ++) c[i] = read();

    for(int i = 1;i <= n;i ++) {
        if(d[i] = (get(a[i])&1)) insert(s,i,b[i],0);
        else insert(i,e,b[i],0);
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= n;j ++)
            if(a[i] % a[j] == 0) {
                int x = get(a[i] / a[j]);
                if(x == 1) {
                    if(d[i]) insert(i,j,INF,c[i]*c[j]);
                    else insert(j,i,INF,c[i]*c[j]);
                }
            }
    }
    cout << ek.mcmf(s,e) << endl;
}
