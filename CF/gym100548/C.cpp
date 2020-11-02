#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef unsigned int UI;
typedef pair<LL,LL> pii;
typedef pair<UI,UI> puu;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 998244353;
const double eps = 1e-6;

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
    double d;
}l[SZ];

int head[SZ],nxt[SZ],tot = 1;
int s,e;
int deep[SZ];

void build(int f,int t,double d) {
    l[++ tot] = (edge){f,t,d};
    nxt[tot] = head[f];
    head[f] = tot;
}

void insert(int f,int t,double d) {
    build(f,t,d);
    build(t,f,0);
}

queue<int> q;

bool bfs() {
    for(int i = 0;i <= e;i ++) deep[i] = 0;
    while(q.size()) q.pop();
    deep[s] = 1;
    q.push(s);
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = head[u];i;i = nxt[i]) {
            int v = l[i].t;
            if(l[i].d > eps && !deep[v]) {
                deep[v] = deep[u] + 1;
                if(v == e) return true;
                q.push(v);
            }
        }
    }
    return false;
}

double dfs(int u,double flow) {
    if(u == e || flow < eps) return flow;
    double ans = flow;
    for(int i = head[u];i;i = nxt[i]) {
        int v = l[i].t;
        if(l[i].d > eps && deep[v] == deep[u] + 1) {
            double f = dfs(v,min(ans,l[i].d));
            if(f > eps) {
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
double dinic() {
    double ans = 0;
    while(bfs()) {
        double tmp = dfs(s,INF);
        if(fabs(tmp) < eps) break;
        ans += tmp;
    }
    return ans;
}

int n,m,a[SZ],du[SZ];

double check(double mid) {
    for(int i = 1;i <= e;i ++) head[i] = 0; tot = 1;
    for(int i = 1;i <= n;i ++) {
        insert(s,i,m);
        insert(i,e,m+2*mid-du[i]);
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = i+1;j <= n;j ++) {
            if(a[i] > a[j]) {
                insert(i,j,1);
                insert(j,i,1);
            }
        }
    }
    return m*n-dinic();
}

int main() {
    int T = read(),cc = 0;
    while(T --) {
        n = read();
        for(int i = 1;i <= n;i ++) a[i] = read(),du[i] = 0;
        m = 0;
        for(int i = 1;i <= n;i ++) {
            for(int j = i+1;j <= n;j ++) {
                if(a[i] > a[j]) {
                    m ++;
                    du[i] ++;
                    du[j] ++;
                }
            }
        }
        s = n + 1;
        e = s + 1;
        double l = 0,r = n / 2.0;
        for(int t = 1;t <= 60;t ++) {
            double mid = (l + r) / 2;
            if(check(mid) < eps) r = mid;
            else l = mid;
        }
        printf("Case #%d: %.10f\n",++ cc,r);
    }
}
/**
1
5
3 4 2 5 1
*/
