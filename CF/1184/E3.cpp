#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

struct haha {
    int x,y,z,id,ans;
}l[SZ];

bool cmp(haha a,haha b) { return a.z < b.z; }
bool cmp2(haha a,haha b) { return a.id < b.id; }

struct edge {
    int t,d,id;
};

vector<edge> g[SZ];

int deep[SZ],fa[SZ],anc[SZ][22],maxd[SZ][22],Fa[SZ];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void dfs(int u,int f) {
    deep[u] = deep[f] + 1;
    anc[u][0] = f;
    for(int i = 1;anc[u][i-1];i ++) {
        anc[u][i] = anc[anc[u][i-1]][i-1];
        maxd[u][i] = max(maxd[anc[u][i-1]][i-1],maxd[u][i-1]);
    }
    for(edge e : g[u]) {
        int v = e.t;
        if(v == f) continue;
        maxd[v][0] = e.d;
        Fa[v] = e.id;
        dfs(v,u);
    }
}

int ask_lca(int x,int y) {
    if(deep[x] < deep[y]) swap(x,y);
    int dd = deep[x] - deep[y],ans = 0;
    for(int i = 20;i >= 0;i --)
        if(dd >> i & 1) {
            x = anc[x][i];
        }
    if(x == y) return x;
    for(int i = 20;i >= 0;i --)
        if(anc[x][i] != anc[y][i]) {
            x = anc[x][i];
            y = anc[y][i];
        }
    return anc[x][0];
}

int get(int x,int y) {
    if(deep[x] < deep[y]) swap(x,y);
    int dd = deep[x] - deep[y],ans = 0;
    for(int i = 20;i >= 0;i --)
        if(dd >> i & 1) {
            ans = max(ans,maxd[x][i]);
            x = anc[x][i];
        }
    if(x == y) return ans;
    for(int i = 20;i >= 0;i --)
        if(anc[x][i] != anc[y][i]) {
            ans = max(ans,max(maxd[x][i],maxd[y][i]));
            x = anc[x][i];
            y = anc[y][i];
        }
    ans = max(ans,max(maxd[x][0],maxd[y][0]));
    return ans;
}

bool mark[SZ];

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= m;i ++)
        l[i].x = read(),l[i].y = read(),l[i].z = read(),l[i].id = i,l[i].ans = 1e9;
    sort(l+1,l+1+m,cmp);
    for(int i = 1;i <= n;i ++) fa[i] = i;
    for(int i = 1;i <= m;i ++) {
        int x = find(l[i].x);
        int y = find(l[i].y);
        if(x != y) {
            g[l[i].x].push_back((edge){l[i].y,l[i].z,i});
            g[l[i].y].push_back((edge){l[i].x,l[i].z,i});
            fa[x] = y;
            mark[l[i].id] = 1;
        }
    }
    dfs(1,0);

    for(int i = 1;i <= n;i ++) fa[i] = i;
    for(int i = 1;i <= m;i ++) {
        if(!mark[l[i].id]) {
            int x = find(l[i].x),y = find(l[i].y),lca = find(ask_lca(x,y));
            while(x != lca) {
                l[Fa[x]].ans = l[i].z;
                fa[x] = find(anc[x][0]);
                x = find(x);
            }
            while(y != lca) {
                l[Fa[y]].ans = l[i].z;
                fa[y] = find(anc[y][0]);
                y = find(y);
            }
        }
    }

    sort(l+1,l+1+m,cmp2);
    for(int i = 1;i <= m;i ++) {
        if(!mark[i]) {
            int x = get(l[i].x,l[i].y);
            printf("%d\n",x);
        }
        else {
            printf("%d\n",l[i].ans);
        }
    }
}
