#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e6 + 3;
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
    int f,t;
    LL d;
}l[SZ];

int deep[SZ],head[SZ],nxt[SZ],s,e,tot = 1;

void build(int f,int t,LL d) {
    l[++ tot] = (edge){f,t,d};
    nxt[tot] = head[f];
    head[f] = tot;
}

void insert(int f,int t,LL d) {
    build(f,t,d); build(t,f,0);
}

bool bfs() {
    for(int i = 0;i <= e;i ++) deep[i] = 0;
    queue<int> q;
    deep[s] = 1;
    q.push(s);
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = head[u];i;i = nxt[i]) {
            int v = l[i].t;
            if(l[i].d && !deep[v]) {
                deep[v] = deep[u] + 1;
                if(v == e) return true;
                q.push(v);
            }
        }
    }
    return false;
}

LL dfs(int u,LL flow) {
    if(u == e || flow == 0) return flow;
    LL ans = flow;
    for(int i = head[u];i;i = nxt[i]) {
        int v = l[i].t;
        if(l[i].d && deep[v] == deep[u] + 1) {
            LL f = dfs(v,min(ans,l[i].d));
            if(f > 0) {
                l[i].d -= f;
                l[i ^ 1].d += f;
                ans -= f;
                if(ans == 0) break;
            }
            else deep[v] = 0;
        }
    }
    if(ans == flow) deep[u] = 0;
    return flow - ans;
}

LL dinic() {
    LL ans = 0;
    while(bfs()) {
        LL tmp = dfs(s,INF);
        if(tmp == 0) break;
        ans += tmp;
    }
    return ans;
}

int main() {
    int n,m;
    while(~scanf("%d%d",&n,&m)) {
        for(int i = 0;i <= n+2;i ++) head[i] = 0; tot = 1;
        s = n+1,e = s+1;
        LL sum = 0;
        for(int i = 1;i <= m;i ++) {
            int u = read(),v = read(),p = read(),r = read(),q = read();
            sum += 2 * (p+q+r);
            insert(s,u,p+r); insert(s,v,p+r);
            insert(u,v,p+q-2*r); insert(v,u,p+q-2*r);
            insert(u,e,q+r); insert(v,e,q+r);
        }
        printf("%lld\n",(sum-dinic())/2);
    }
}
