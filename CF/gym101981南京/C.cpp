#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1e6 + 10;
const int mod = 998244353;
const int INF = 1e9 + 10;
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
bool rt1[SZ],rt2[SZ];

int dfs_sz(int u,int fa,bool rt[]) {
    int sz = 1,now = 0;
    for(int v : g[u]) {
        if(rt[v] || v == fa) continue;
        int son = dfs_sz(v,u,rt);
        sz += son;
    }
    return sz;
}

int maxn,root;

int find_rt(int u,int fa,int n,bool rt[]) {
    int sz = 1,now = 0;
    for(int v : g[u]) {
        if(rt[v] || v == fa) continue;
        int son = find_rt(v,u,n,rt);
        now = max(now,son);
        sz += son;
    }
    now = max(now,n - sz);
    if(now < maxn) maxn = now,root = u;
    return sz;
}

int n;

int main() {
    n = read();
    for(int i = 1;i < n;i ++) {
        int u = read(),v = read();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0,x = 1;
    int sz = dfs_sz(x,0,rt1);
    maxn = 1e9; find_rt(x,0,sz,rt1);
    x = root;

    while(!rt1[x]) {
        rt1[x] = 1;

        rt2[x] = 1;
        int maxd = 1e9,dir = -1;
        for(int u : g[x]) {
            int sz = dfs_sz(u,0,rt2);
            maxn = 1e9; find_rt(u,0,sz,rt2);
            int tmp = maxn+n-sz;
            if(tmp < maxd) dir = u,maxd = tmp;
        }
        rt2[x] = 0;

        ans = max(ans,maxd);
        int sz = dfs_sz(dir,0,rt1);
        maxn = 1e9; find_rt(dir,0,sz,rt1);
        x = root;
    }
    cout << ans << endl;
}
/**
7
1 2
1 3
2 4
2 5
5 6
5 7

5


8
1 2
1 3
1 4
1 8
3 5
3 6
3 7
*/
