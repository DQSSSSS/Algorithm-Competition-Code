#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000100;
const LL INF = 1e18 + 10;
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

LL tree[SZ];
int n;
vector<int> g[SZ];

void add(int x,LL d) {
    for(int i = x;i <= n;i += i & -i)
        tree[i] += d;
}

LL ask(int x) {
    LL ans = 0;
    for(int i = x;i > 0;i -= i & -i)
        ans += tree[i];
    return ans;
}

int deep[SZ];

void dfs1(int u,int fa) {
    deep[u] = deep[fa] + 1;
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i];
        if(v == fa) continue;
        dfs1(v,u);
    }
}

LL a[SZ];

struct haha {
    int d;
    LL v;
};

vector<haha> ins[SZ];

void dfs2(int u,int fa) {
    for(int i = 0;i < ins[u].size();i ++) {
        int dep = ins[u][i].d;
        LL val = ins[u][i].v;
        int l = deep[u],r = min(n,deep[u] + dep);
        add(l,val); add(r+1,-val);
    }
    a[u] = ask(deep[u]);
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i];
        if(v == fa) continue;
        dfs2(v,u);
    }
    for(int i = 0;i < ins[u].size();i ++) {
        int dep = ins[u][i].d;
        LL val = ins[u][i].v;
        int l = deep[u],r = min(n,deep[u] + dep);
        add(l,-val); add(r+1,val);
    }
}

int main() {
    n = read();
    for(int i = 1;i < n;i ++) {
        int x = read(),y = read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs1(1,0);
    int m = read();
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read(),z = read();
        ins[x].push_back((haha){y,z});
    }
    dfs2(1,0);
    for(int i = 1;i <= n;i ++) printf("%lld ",a[i]);
    return 0;
}
