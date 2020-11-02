#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;
const int dx[] = {0,1,0,-1};
const int dy[] = {-1,0,1,0};

LL read() {
    LL n = 0;
    scanf("%lld",&n);
    return n;
}

vector<int> g[SZ];
int n,m;
int anc[SZ][22],deep[SZ],maxdist[SZ][22],node[SZ];

void dfs(int u,int f) {
    deep[u] = deep[f] + 1;
    anc[u][0] = f;
    maxdist[u][0] = node[f];
    for(int i = 1;anc[u][i-1];i ++) {
        anc[u][i] = anc[anc[u][i-1]][i-1];
        maxdist[u][i] = max(maxdist[u][i-1],maxdist[anc[u][i-1]][i-1]);
    }
    for(int v : g[u]) {
        if(v == f) continue;
        dfs(v,u);
    }
}

int ask(int u,int v) {
    if(deep[u] < deep[v]) swap(u,v);
    int ans = max(node[u],node[v]);
    int dd = deep[u] - deep[v];
    for(int i = 20;i >= 0;i --) {
        if(dd >> i & 1) {
            ans = max(ans,maxdist[u][i]);
            u = anc[u][i];
        }
    }
    if(u == v) return ans;
    for(int i = 20;i >= 0;i --) {
        if(anc[u][i] != anc[v][i]) {
            ans = max(ans,maxdist[u][i]);
            ans = max(ans,maxdist[v][i]);
            u = anc[u][i],v = anc[v][i];
        }
    }
    ans = max(ans,maxdist[u][0]);
    ans = max(ans,maxdist[v][0]);
    return ans;
}

int id(int i,int j) {
    return (i-1)*m+j;
}

struct haha {
    int val,x,y;
}a[SZ];


int fa[SZ];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

bool isin(int x,int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }

int val[510][510];
struct edge {
    int f,t,d;
}l[SZ];

bool cmp(edge a,edge b) { return a.d < b.d; }


int main() {
    n = read(),m = read(); int q = read();
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            int ii = id(i,j);
            a[ii].val = read();
            a[ii].x = i;
            a[ii].y = j;
            node[ii] = a[ii].val;
            val[i][j] = a[ii].val;
        }
    }

    int tot = 0;
    for(int i = 1;i <= n * m;i ++) fa[i] = i;
    for(int i = 1;i <= n * m;i ++) {
        int x = a[i].x;
        int y = a[i].y;
        for(int k = 0;k < 4;k ++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(isin(nx,ny)) {
                l[++ tot] = (edge){id(x,y),id(nx,ny),max(val[x][y],val[nx][ny])};
            }
        }
    }
    sort(l + 1,l + 1 + tot,cmp);
    for(int i = 1;i <= tot;i ++) {
        int u = find(l[i].f);
        int v = find(l[i].t);
        if(u != v) {
          //  printf("(%d,%d) (%d,%d)\n",l[i].f/m+1,l[i].f%m,l[i].t/m+1,l[i].t);
            g[l[i].f].push_back(l[i].t);
            g[l[i].t].push_back(l[i].f);
            fa[u] = v;
        }
    }

    dfs(1,0);

    while(q --) {
        int x = read(),y = read();
        int u = read(),v = read();
        printf("%d\n",ask(id(x,y),id(u,v)));
    }
}

/**
5 5
 _ _ _ _ _
|_ _  |_  |
|  _| |  _|
| |_   _| |
|    _ _  |
|_|_ _ _|_|
7
4 4
1 4
3 1
4 5
1 2
2 2
5 4

2 6
 _ _ _ _ _ _
|  _ _ _ _ _|
|_ _ _ _ _ _|
5
1 5
1 1
1 6
1 1
1 5
*/

