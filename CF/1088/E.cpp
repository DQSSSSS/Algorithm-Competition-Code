#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = acos(-1);
const int SZ = 510010;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

LL val[SZ],a[SZ];
vector<int> g[SZ];

void dfs1(int u,int fa) {
	val[u] = a[u];
	for(int i = 0;i < g[u].size();i ++) {
		int v = g[u][i];
		if(v == fa) continue;
		dfs1(v,u);
		val[u] = max(val[u],val[u] + val[v]);
	}
}

LL Maxval,f[SZ],sum[SZ];

void dfs(int u,int fa) {
	sum[u] = a[u];
	for(int i = 0;i < g[u].size();i ++) {
		int v = g[u][i];
		if(v == fa) continue;
		dfs(v,u);
		f[u] += f[v];
		if(sum[v] > 0) sum[u] += sum[v];
	}
	if(sum[u] == Maxval) f[u] ++,sum[u] = 0;
}

int main() {
	int n = read();
	for(int i = 1;i <= n;i ++) a[i] = read();
	for(int i = 1;i < n;i ++) {
		int u = read(),v = read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(1,0);
	Maxval = val[1];
	for(int i = 1;i <= n;i ++) Maxval = max(Maxval,val[i]);
	//cout << Maxval << endl;
	dfs(1,0);
	LL num = f[1];
	printf("%lld %lld\n",Maxval * num,num);
	return 0;
}
