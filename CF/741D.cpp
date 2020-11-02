#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 2e5 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

vector<int> g[SZ];

int sz[SZ],son[SZ],f[SZ],val[SZ];
int num[SZ];

void dfs_pre(int u,int fa) {
    sz[u] = 1;
    son[u] = 0;
    deep[u] = deep[fa] + 1;
    val[u] ^= val[fa];
    for(int v : g[u]) {
        if(v == fa) continue;
        dfs_pre(v,u);
        sz[u] += sz[v];
        if(!son[u] || sz[son[u]] < sz[v]) son[u] = v;
    }
}

vector<int> tmp;
map<int,int> mp;
int id[SZ];

void dfs2(int u,int fa) {
    tmp.push_back(u);
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i];
        if(v == fa) continue;
        dfs2(v,u);
    }
}
void dfs(int u,int fa,bool c) { //c:u是否是它父亲的重儿子。
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i];
        if(v == fa) continue;
        if(v != son[u])
            dfs(v,u,0);
    }
    if(son[u]) dfs(son[u],u,1);
    for(int x : goal[u]) f[u] = max(f[u],num[x]-deep[u]);
    num[mp[val[u]]] = max(num[mp[val[u]]],deep[u]);
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i];
        if(v == son[u]) continue;
        if(v == fa) continue;
        tmp.clear();
        dfs2(v,u);
        for(int v : tmp) (ans += get_ans(v,2*D[u])) %= mod;
        for(int v : tmp) change(1,qj[v].l,qj[v].r,get_pii(v,1));
    }
    if(!c) {
        tmp.clear();
        dfs2(u,fa);
        for(int v : tmp) change(1,qj[v].l,qj[v].r,get_pii(v,-1));
    }
}


int main() {
    int n = read();
    for(int i = 2;i <= n;i ++) {
        int p = read();
        char s[2];
        scanf("%s",s);
        g[p].push_back(i);
        val[i] = 1 << (s[0] - 'a');
    }
    dfs_pre(1,0);
    int tot = 0;
    for(int i = 2;i <= n;i ++) {
        if(mp.count(val[i])) continue;
        mp[val[i]] = ++ tot;
        id[i] = tot;
    }
    for(int i = 1;i <= tot;i ++) num[i] = -INF;
    for(int i = 2;i <= n;i ++) {
        for(int j = 1;j < 26;j ++) {
            int v = 1 << j;
            if(!mp.count(val[i] ^ v)) continue;
            goal[i].push_back(mp[val[i] ^ v]);
        }
        goal[i].push_back(mp[val[i]]);
    }
    dfs(1,0,0);
    for(int i = 1;i <= n;i ++) printf("%d ",f[i]);
}
/*
2
1 5
1 4
1 2
*/
