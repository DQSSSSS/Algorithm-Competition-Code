#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
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

LL f[SZ][2],a[SZ];
vector<int> g[SZ];

void dfs(int u,int fa) {
    LL max1 = 0,max2 = 0;
    for(int i = 0;i < g[u].size();i ++) {
    	int v = g[u][i];
    	if(v == fa) continue;
    	dfs(v,u);
        max1 = max(max1,f[v][0]); ///in
        max2 = max(max2,f[v][1]); ///de
    }
    LL d = a[u] + max1 - max2;
    if(d >= 0) { f[u][0] = max1; f[u][1] = max2 + d; }
	else { f[u][0] = max1 - d; f[u][1] = max2; }
}

int main() {
    int n = read();
    for(int i = 1;i < n;i ++) {
    	int x = read(),y = read();
    	g[x].push_back(y);
    	g[y].push_back(x);
    }
    for(int i = 1;i <= n;i ++) a[i] = read();
    dfs(1,0);
    printf("%I64d\n",f[1][0] + f[1][1]);
    return 0;
}
