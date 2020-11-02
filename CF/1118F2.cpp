#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 3e5 + 10;
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

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b & 1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int n,k;
vector<int> g[SZ];
int a[SZ],anc[SZ][22],deep[SZ];

void dfs_lca(int u,int fa) {
    deep[u] = deep[fa] + 1;
    anc[u][0] = fa;
    for(int i = 1;anc[u][i-1];i ++)
        anc[u][i] = anc[anc[u][i-1]][i-1];
    for(int v : g[u]) {
        if(v == fa) continue;
        dfs_lca(v,u);
    }
}

int ask_lca(int u,int v) {
    if(deep[u] < deep[v]) swap(u,v);
    int dd = deep[u] - deep[v];
    for(int i = 20;i >= 0;i --) {
        if(dd >> i & 1)
            u = anc[u][i];
    }
    if(u == v) return u;
    for(int i = 20;i >= 0;i --)
        if(anc[u][i] != anc[v][i])
            u = anc[u][i],v = anc[v][i];
    return anc[u][0];
}

int up[SZ];

vector<int> node[SZ];
int bel[SZ];
bool vis[SZ];
LL f[SZ][2];

void fucknode(int u,int fa) {
    vis[u] = 1;
    if(bel[u]) { f[u][0] = 0; f[u][1] = 1; return ; }
    f[u][0] = -1;
    f[u][1] = -1;
    for(int v : g[u]) {
        if(v == fa) continue;
        fucknode(v,u);
        if(f[v][0] == -1) continue;
        if(f[u][0] == -1) f[u][0]=(f[v][0]+f[v][1])%mod,f[u][1]=f[v][1];
        else {
            LL a=(f[u][1]*f[v][0]%mod+f[u][0]*f[v][1]%mod+f[u][1]*f[v][1]%mod)%mod;
            LL b=f[u][0]*(f[v][1]+f[v][0])%mod;
            f[u][1]=a;
            f[u][0]=b;
        }
    }
}

int main() {
    n = read(),k = read();
    int rt = 1;
    for(int i = 1;i <= n;i ++) {
        a[i] = read();
        if(a[i]) node[a[i]].push_back(i);
    }
    for(int i = 1;i < n;i ++) {
        int x = read(),y = read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs_lca(rt,0);
    for(int i = 1;i <= n;i ++) {
        int c = a[i];
        if(!up[c]) up[c] = i;
        else up[c] = ask_lca(up[c],i);
    }

    for(int i = 1;i <= k;i ++) {
        int x = up[i];
        if(bel[x]) return cout << 0,0;
        bel[x] = i;
        for(int u : node[i]) {
            int x = u;
            while(x) {
                if(bel[x] == i) break;
                else if(bel[x]) return cout << 0,0;
                else {
                    bel[x] = i;
                    x = anc[x][0];
                }
            }
        }
    }

    LL ans = 1;
    for(int i = 1;i <= n;i ++) {
        if(!vis[i] && !bel[i]) {
            fucknode(i,0);
            ans = ans * f[i][1] % mod;
        }
    }
    cout << ans << endl;
}

