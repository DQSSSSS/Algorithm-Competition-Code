#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;
const double eps = 1e-6;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

vector<int> g[SZ];
bool vis[SZ];
int match[SZ];

bool dfs(int u) {
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


int p[SZ],L[SZ],R[SZ];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) p[i] = read();
    for(int i = 1;i <= n;i ++) L[i] = read();
    for(int i = 1;i <= n;i ++) R[i] = read();
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= n;j ++) {
            if(L[j] <= p[i] && p[i] <= R[j]) {
                g[i].push_back(j);
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= n;j ++) vis[j] = 0;
        if(dfs(i)) ans ++;
        else break;
    }
    if(ans == n) puts("Possible");
    else puts("Impossible");
}
