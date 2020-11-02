#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 6e6 + 10;
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

int match[SZ];
bool vis[SZ],visz[SZ];

bool dfs(int u) {
    visz[u] = 1;
    for(int v : g[u]) {
        if(!vis[v]) {
            vis[v] = 1;
            if(!match[v] || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int a[SZ],b[SZ];

int main() {
    int n = read();
    vector<int> v[2];
    for(int i = 1;i <= n;i ++) {
        a[i] = read();
        int x = __builtin_parity(a[i]);
        v[x].push_back(i);
    }
    for(int i : v[0]) {
        for(int j : v[1]) {
            if(__builtin_popcount(a[i]^a[j]) == 1) {
                g[i].push_back(j);
            }
        }
    }
    int ans = 0;
    for(int u : v[0]) {
        for(int i = 1;i <= n;i ++) vis[i] = 0;
        if(dfs(u)) {
            ans ++;
        }
    }
    for(int i = 1;i <= n;i ++) vis[i] = 0,visz[i] = 0;
    for(int u : v[1]) b[match[u]] = 1;
    for(int u : v[0]) if(!b[u]) dfs(u);
    printf("%d\n",n-ans);
    for(int u : v[0]) if(visz[u]) printf("%d ",a[u]);
    for(int u : v[1]) if(!vis[u]) printf("%d ",a[u]);
    return 0;
}
