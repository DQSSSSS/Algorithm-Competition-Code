#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 200010;
const LL INF = 1e18 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

bool use[SZ],vis[SZ];
int fa[SZ];
vector<pii> g[SZ];
char col[SZ];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int dfs(int u,int fa) {
    vis[u] = 1;
    int ans = 0;
    for(pii e : g[u]) {
        int v = e.first;
        int id = e.second;
        if(v == fa) continue;
        int d = dfs(v,u);
        if(d == 1) ans ^= 1;
        else {
            use[id] = 0;
        }
    }
    if(col[u] == 'B') ans ^= 1;
    return ans;
}

int X[SZ],Y[SZ];

int main() {
    freopen("uprtoff.in","r",stdin);
    freopen("uprtoff.out","w",stdout);
    int n = read(),m = read();
    scanf("%s",col+1);
    for(int i = 1;i <= n;i ++) fa[i] = i;
    for(int i = 1;i <= m;i ++) {
        X[i] = read();
        Y[i] = read();
    }

    for(int i = m;i >= 1;i --) {
        int x = X[i],y = Y[i];
        int xx = find(x);
        int yy = find(y);
        if(xx != yy) {
            g[x].push_back({y,i});
            g[y].push_back({x,i});
            fa[xx] = yy;
            use[i] = 1;
        }
    }
    for(int i = 1;i <= n;i ++) {
        if(!vis[i]) {
            vis[i] = 1;
            if(dfs(i,0) == 1) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    for(int i = 1;i <= m;i ++) {
        if(use[i]) {
            printf("%d ",i);
        }
    }
    return 0;
}
