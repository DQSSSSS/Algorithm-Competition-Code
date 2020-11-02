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
    int x,y,z,id;
}l[SZ];

bool cmp(haha a,haha b) { return a.z < b.z; }
bool cmp2(haha a,haha b) { return a.id < b.id; }

struct edge {
    int t,d;
};

vector<edge> g[SZ];

int deep[SZ],fa[SZ],anc[SZ][22],maxd[SZ][22];

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
        dfs(v,u);
    }
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

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= m;i ++)
        l[i].x = read(),l[i].y = read(),l[i].z = read(),l[i].id = i;
    sort(l+1,l+1+m,cmp);
    for(int i = 1;i <= n;i ++) fa[i] = i;
    for(int i = 1;i <= m;i ++) {
        int x = find(l[i].x);
        int y = find(l[i].y);
        if(x != y) {
            g[l[i].x].push_back((edge){l[i].y,l[i].z});
            g[l[i].y].push_back((edge){l[i].x,l[i].z});
            fa[x] = y;
        }
    }
    dfs(1,0);
    sort(l+1,l+1+m,cmp2);
    for(int i = 1;i <= m;i ++) {
        int x = get(l[i].x,l[i].y);
        if(x != l[i].z) printf("%d\n",x);
        //cout << l[i].x << " " << l[i].y << " " << x << endl;
    }
}
