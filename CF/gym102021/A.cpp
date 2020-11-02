#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;

LL read() {
    LL n = 0;
    scanf("%lld",&n);
    return n;
}

vector<int> g[SZ];
int n,m;
int anc[SZ][22],deep[SZ];

void dfs(int u,int f) {
    deep[u] = deep[f] + 1;
    anc[u][0] = f;
    for(int i = 1;anc[u][i-1];i ++) {
        anc[u][i] = anc[anc[u][i-1]][i-1];
    }
    for(int v : g[u]) {
        if(v == f) continue;
        dfs(v,u);
    }
}

int ask(int u,int v) {
    if(deep[u] < deep[v]) swap(u,v);
    int dd = deep[u] - deep[v];
    for(int i = 20;i >= 0;i --) {
        if(dd >> i & 1)
            u = anc[u][i];
    }
    if(u == v) return u;
    for(int i = 20;i >= 0;i --) {
        if(anc[u][i] != anc[v][i])
            u = anc[u][i],v = anc[v][i];
    }
    return anc[u][0];
}

int id(int i,int j) {
    return (i-1)*m+j;
}

char mp[2010][2010];

int main() {
    n = read(),m = read(); getchar();
    for(int i = 1;i <= n + 1;i ++) {
        gets(mp[i]+1);
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            int x,y;
            if(i < n && mp[i+1][j*2] != '_') {
                x = i + 1; y = j;
                g[id(x,y)].push_back(id(i,j));
                g[id(i,j)].push_back(id(x,y));
            }
            if(j < m && mp[i+1][j*2+1] != '|') {
                x = i; y = j +1;
                g[id(x,y)].push_back(id(i,j));
                g[id(i,j)].push_back(id(x,y));
            }
        }
    }
    dfs(1,0);
    LL ans = 0;
    int q = read(),lst = -1;
    while(q --) {
        int x = read(),y = read();
        int z = id(x,y);
        if(lst == -1) lst = z;
        else {
            int lca = ask(lst,z);
            ans += deep[z] + deep[lst] - deep[lca] * 2;
            lst = z;
        }
    }
    cout << ans << endl;
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
