#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 2000100;
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

struct edge {
    int t;
    LL d;
};

pll f[SZ][2];
vector<edge> g[SZ];

void dfs(int u,int fa) {
    f[u][1] = make_pair(0,0);
    f[u][0] = make_pair(0,0);

    for(edge e : g[u]) {
        int v = e.t;
        if(v == fa) continue;
        dfs(v,u);
        pll tmp = max(f[v][0],f[v][1]);

        f[u][0].first += tmp.first;
        f[u][0].second += tmp.second;
    }

    for(edge e : g[u]) {
        int v = e.t;
        if(v == fa) continue;
        pll tmp = max(f[v][0],f[v][1]);
        pll sum = make_pair(f[u][0].first-tmp.first,f[u][0].second-tmp.second);
        sum.first += e.d + f[v][0].first;
        sum.second += 1 + f[v][0].second;
        f[u][1] = max(f[u][1],sum);
    }
}

int ff[SZ],tt[SZ],dd[SZ];

int main() {
    int n = read(),m = read();
    for(int i = 1;i < n;i ++) {
        ff[i] = read(); tt[i] = read(); dd[i] = read();
    }
    LL l = -1e12-1,r = 1e12+1;
    LL sum = -1e18;
    while(r-l>1) {
        LL mid = l + r >> 1;
        for(int i = 1;i <= n;i ++) g[i].clear();
        for(int i = 1;i < n;i ++) {
            int x = ff[i],y = tt[i];
            LL z = dd[i] + mid;
            g[x].push_back((edge){y,z});
            g[y].push_back((edge){x,z});
        }
        dfs(1,0);
        pll ans = max(f[1][0],f[1][1]);
        if(ans.second >= m) r = mid,sum = ans.first - 1ll*m * mid;
        else l = mid;
    }
    if(sum == -1e18) puts("Impossible");
    else printf("%lld\n",sum);
    return 0;
}
