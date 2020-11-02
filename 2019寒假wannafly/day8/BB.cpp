#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
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

int vis[SZ],match[SZ];
vector<int> g[SZ];

bool dfs(int u) {
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i];
        if(!vis[v]) {
            vis[v] = 1;
            if(match[v] == -1 || !dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

bool cmp(int a,int b) { return a > b; }

int ff[SZ],tt[SZ];

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read();
        if(x > y) swap(x,y);
        ff[i] = x; tt[i] = y;
    }
    int l = -1,r = n + 1;
    while(r - l > 1) {
        int mid = l + r >> 1;
        for(int i = 0;i < n;i ++) g[i].clear(),vis[i] = 0,match[i] = -1;
        for(int i = 1;i <= m;i ++) {
            if(ff[i] <= mid && tt[i] > mid)
                g[ff[i]].push_back(tt[i]);
        }
        bool flag = 0;
        for(int i = 0;i <= mid;i ++) {
            memset(vis,0,sizeof vis);
            if(!dfs(i)) { flag = 1; break; }
        }
        if(flag) r = mid;
        else l = mid;
    }
    printf("%d\n",r);
    return 0;
}
/**
4 5
0 1
1 2
2 3
0 2
1 3
*/

