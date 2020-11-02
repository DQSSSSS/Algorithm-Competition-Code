#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-12;

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

LL sz[SZ],a[SZ],Ans[SZ],ans;

void dfs1(int u,int f) {
    sz[u] = a[u];
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i];
        if(v == f) continue;
        dfs1(v,u);
        sz[u] += sz[v];
        Ans[u] += Ans[v];
    }
    Ans[u] += sz[u];
}

void dfs2(int u,int f,LL d,LL d2) {
    //cout << u << " " << d + Ans[u] - sz[u] << " " << d << " " << d2 <<endl;
    ans = max(ans,d + Ans[u] - sz[u]);

    LL sumAns = 0,sumSz = 0;
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i];
        if(v == f) continue;
        sumAns += Ans[v];
        sumSz += sz[v];
    }

    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i];
        if(v == f) continue;
        dfs2(v,u,d+sumAns-Ans[v]+d2+sumSz-sz[v]+a[u],d2+sumSz-sz[v]+a[u]);
    }
}

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    for(int i = 1;i < n;i ++) {
        int x = read(),y = read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs1(1,0);
   // for(int i = 1;i <= n;i ++) cout << sz[i] << " "; puts("");
   // for(int i = 1;i <= n;i ++) cout << Ans[i] << " "; puts("");
    ans = 0;
    dfs2(1,0,0,0);
    cout << ans << endl;
    return 0;
}
