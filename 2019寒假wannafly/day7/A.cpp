#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 500010;
const int mod = 998244353;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}

vector<int> g[SZ];
int num[SZ],a[SZ];

void dfs(int u,int fa,int d) {
    if(a[u]) num[d] ++;
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i];
        if(v == fa) continue;
        dfs(v,u,d+1);
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
    dfs(1,0,1);
    LL ans = 0,sum = 0;
    for(int i = 1,lst = 1;i <= n;i ++) {
        if(num[i]) {
            ans += num[i] - 1 + max(i - lst - ans,1ll);
            lst = i;
        }
    }
    cout << ans << endl;
    return 0;
}
/**
5
0 1 1 1 1
1 2
1 3
2 4
2 5
*/
