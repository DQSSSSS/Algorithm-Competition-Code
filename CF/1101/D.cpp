#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
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

vector<int> g[SZ],g2[SZ],nodes[SZ];
int a[SZ];
int fa[SZ],deep[SZ];

void dfs_pre(int u,int f) {
    fa[u] = f;
    deep[u] = deep[f] + 1;
    for(int v : g2[u]) {
        if(v == f) continue;
        dfs_pre(v,u);
    }
}

bool cmp(int a,int b) { return deep[a] < deep[b]; }

bool vis[SZ],w[SZ];
int f[SZ],ans;

void dfs(int u) {
    vis[u] = 1;
    f[u] = 0;
    //cout << u << endl;
    for(int v : g[u]) {
        dfs(v);
        ans = max(ans,f[u] + f[v] + 2);
        f[u] = max(f[u],f[v]+1);
    }
}

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        a[i] = read();
        int x = a[i];
        for(int j = 2;j * j <= x;j ++) {
            if(x % j == 0) {
                nodes[j].push_back(i);
                while(x % j == 0) x /= j;
            }
        }
        if(x != 1) nodes[x].push_back(i);
        if(a[i] != 1) ans = 1;
    }
    for(int i = 1;i < n;i ++) {
        int x = read();
        int y = read();
        g2[x].push_back(y);
        g2[y].push_back(x);
    }
    dfs_pre(1,0);

    for(int p = 2;p <= 2e5;p ++) {
        if(nodes[p].size() == 0) continue;
        sort(nodes[p].begin(),nodes[p].end(),cmp);
        for(int u : nodes[p]) w[u] = 1;
        for(int u : nodes[p]) if(w[fa[u]]) g[fa[u]].push_back(u);

       // printf("prime: %d\n",p);
        for(int u : nodes[p]) {
            if(!vis[u]) {
                dfs(u);
          //      puts("---");
            }
        }

        for(int u : nodes[p]) w[u] = 0,g[u].clear(),vis[u] = 0;
    }
    cout << ans << endl;
}
/**
8
7 3 6 3 12 5 4 3
1 2
1 3
3 4
3 5
3 6
5 7
5 8
*/

