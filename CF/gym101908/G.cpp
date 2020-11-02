#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
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

int head[SZ],nxt[SZ],tot = 1;

struct edge {
    int f,t,d;
}l[SZ],edgelist[SZ];

bool cmp(edge a,edge b) {
    return a.d < b.d;
}

void build(int f,int t,int d) {
    l[++ tot] = (edge){f,t,d};
    nxt[tot] = head[f];
    head[f] = tot;
}

void insert(int f,int t,int d) {
    //cout << f << " " << t << " " << d << endl;
    build(f,t,d);
    build(t,f,0);
}

int dist[SZ];
queue<int> q;

bool bfs(int s,int e) {
    for(int i = 1;i <= e;i ++) dist[i] = -1;
    dist[s] = 1;
    while(q.size()) q.pop();
    q.push(s);
    while(q.size()) {
        int u = q.front(); q.pop();
        if(u == e) return true;
        for(int i = head[u];i;i = nxt[i]) {
            int v = l[i].t;
            if(l[i].d && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                if(v == e) return true;
            }
        }
    }
    return false;
}

int dfs(int u,int e,int flow) {
    if(u == e || flow == 0) return flow;
    int ans = flow;
    for(int i = head[u];i;i = nxt[i]) {
        int v = l[i].t;
        if(l[i].d && dist[v] == dist[u] + 1) {
            int f = dfs(v,e,min(ans,l[i].d));
            if(f > 0) {
                l[i].d -= f;
                l[i^1].d += f;
                ans -= f;
                if(ans == 0) break;
            }
            else dist[v] = 0;
        }
    }
    if(ans == flow) dist[u] = 0;
    return flow - ans;
}

int dinic(int s,int e) {
    int ans = 0;
    while(bfs(s,e)) {
        int tmp = dfs(s,e,INF);
        if(tmp == 0) break;
      //  cout << tmp <<endl;
        ans += tmp;
    }
    return ans;
}

int n,m,c,sum;
int a[SZ],b[SZ];

bool check(int mid) {
    int s = n+m+1;
    int e = s+1;
    for(int i = 1;i <= e;i ++) head[i] = 0;
    tot = 1;
    for(int i = 1;i <= n;i ++) insert(s,i,a[i]);
    for(int i = 1;i <= m;i ++) insert(i+n,e,b[i]);
    for(int i = 1;i <= mid;i ++) {
        insert(edgelist[i].f,edgelist[i].t,INF);
    }
    int ans = dinic(s,e);
    return ans >= sum;
}

int main() {
    n = read(),m = read(),c = read(),sum = 0;

    for(int i = 1;i <= n;i ++) a[i] = read(),sum += a[i];
    for(int i = 1;i <= m;i ++) b[i] = read();
    for(int i = 1;i <= c;i ++) {
        edgelist[i].f = read();
        edgelist[i].t = read()+n;
        edgelist[i].d = read();
    }
    sort(edgelist + 1,edgelist + c + 1,cmp);

    int l = 0,r = c + 1;
    while(r - l > 1) {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    if(r == c + 1) puts("-1");
    else cout << edgelist[r].d << endl;
}
