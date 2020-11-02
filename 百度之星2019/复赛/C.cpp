#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
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

int l[SZ],r[SZ],mn[SZ],sz[SZ],a[SZ];

void dfs1(int u) {
    sz[u] = 1;
    mn[u] = u;
    if(l[u]) {
        dfs1(l[u]);
        mn[u] = min(mn[u],mn[l[u]]);
        sz[u] += sz[l[u]];
    }
    if(r[u]) {
        dfs1(r[u]);
        mn[u] = min(mn[u],mn[r[u]]);
        sz[u] += sz[r[u]];
    }
}

void dfs(int u,int L,int R) {
    if(u == 0) return ;
    if(L == R) { a[u] = L; return ; }
    int lc = l[u],rc = r[u];
    if(mn[u] == u) {
        if(sz[lc]<sz[rc] || (sz[lc] == sz[rc] && mn[lc] < mn[rc])) {
            a[u] = sz[lc] + L;
            dfs(lc,L,a[u]-1);
            dfs(rc,a[u]+1,R);
        }
        else {
            a[u] = sz[rc] + L;
            dfs(rc,L,a[u]-1);
            dfs(lc,a[u]+1,R);
        }
    }
    else {
        if(mn[u] == mn[lc]) {
            a[u] = sz[lc] + L;
            dfs(lc,L,a[u]-1);
            dfs(rc,a[u]+1,R);
        }
        if(mn[u] == mn[rc]) {
            a[u] = sz[rc] + L;
            dfs(rc,L,a[u]-1);
            dfs(lc,a[u]+1,R);
        }
    }
}

int gen[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 1;i <= n;i ++) gen[i] = 0;
        for(int i = 1;i <= n;i ++) {
            l[i] = read(),r[i] = read();
            gen[l[i]] = 1;
            gen[r[i]] = 1;
        }
        int rt;
        for(int i = 1;i <= n;i ++) if(!gen[i]) rt = i;
        dfs1(rt);
        dfs(rt,1,n);
        int ans = 0;
        /*for(int i = 1;i <= n;i ++) cout << mn[i] << " "; puts("");
        for(int i = 1;i <= n;i ++) cout << sz[i] << " "; puts("");
        for(int i = 1;i <= n;i ++) cout << a[i] << " "; puts("");*/
        for(int i = 1,d = 233;i <= n;i ++,d=1ll*d*233%mod)
            (ans += 1ll*(a[i]^i)*d%mod)%=mod;
        printf("%d\n",ans);
    }
}
