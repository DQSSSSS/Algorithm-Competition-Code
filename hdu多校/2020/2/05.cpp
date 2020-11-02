#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 300010;
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
        int f,t;
        LL d,c;
    }l[SZ];

    int head[SZ],nxt[SZ],tot = 1;
    void build(int f,int t,LL d,LL c) {
        l[++ tot] = (edge){f,t,d,c};
        nxt[tot] = head[f];
        head[f] = tot;
    }

    void insert(int f,int t,LL d,LL c) {
        build(f,t,d,c);
        build(t,f,0,-c);
    }

    int n;
    LL h[MAXN],dist[MAXN];
    int pre[MAXN],use[MAXN];

    bool spfa(int s,int e) {
        for(int i = 1;i <= n;i ++)
            dist[i] = INF,pre[i] = 0,use[i] = 0;
        dist[s] = 0;
        queue<int> q; q.push(s);
        use[s] = 1;
        while(q.size()) {
            int u = q.front(); q.pop();
            use[u] = 0;
            for(int i = head[u];i;i = nxt[i]) {
                edge e = l[i];
                int v = e.t;
                if(e.d && dist[v] > dist[u] + e.c) {
                    dist[v] = dist[u] + e.c;
                    pre[v] = i;
                    if(!use[v]) q.push(v);
                }
            }
        }
        return dist[e] != INF;
    }

    pll work(int s,int e) {
        LL cost = 0,flow = 0;
        while(spfa(s,e)) {
            LL maxflow = INF;
            for(int i = pre[e];i;i = pre[l[i].f]) {
                maxflow = min(maxflow,l[i].d);
            }
            for(int i = pre[e];i;i = pre[l[i].f]) {
                l[i].d -= maxflow;
                l[i^1].d += maxflow;
                cost += l[i].c * maxflow;
            }
        }
        return {flow,cost};
    }

    void init(int nn) {
        n = nn;
        tot = 1;
        for(int i = 0;i <= n;i ++) head[i] = 0;
    }
}mc;

struct haha {
    LL a,b,c;
}A[55];

int main() {
//    printf("%lld\n",50*(LL)(1e17+2e16));
    int T = read();
    while(T --) {
        int n = read(),m = read();
        set<int> node;
        for(int i = 1;i <= n;i ++) {
            LL a = read(),b = read(),c = read();
            A[i].a = a;
            A[i].b = b;
            A[i].c = c;
            LL id = -b/2*a;
            id = max(id,1ll);
            id = min(id,(LL)m);
            for(int j = id-n;j <= id+n;j ++) {
                if(1 <= j && j <= m) {
                    node.insert(j);
                }
            }
        }
        int ln = n,rn = node.size();
        mc.init(ln+rn+3);
        for(int i = 1;i <= ln;i ++) mc.insert(ln+rn+1,i,1,0);
        for(int i = 1;i <= rn;i ++) mc.insert(i+ln,ln+rn+2,1,0); // e
        for(int i = 1;i <= ln;i ++) {
            int t = 1;
            for(int j : node) {
                mc.insert(i,t+ln,1,A[i].a * j * j + A[i].b * j + A[i].c);
                t ++;
            }
        }
        LL ans = 0;
        for(int i = 1;i <= n;i ++) {
            mc.insert(ln+rn+3,ln+rn+1,1,0);
            pii tt = mc.work(ln+rn+3,ln+rn+2);
            LL t = tt.second;
            ans += t;
            printf("%lld%c",ans,i==n?'\n':' ');
        }

    }
    return 0;
}
/*
233
3 100
2 3 10
2 -3 10
1 -1 4000
*/
