#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = acos(-1);
const int SZ = 510010;
const LL INF = 1e18;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

LL f[SZ];

int n,mp[22][22],id[SZ],xd[SZ];
vector<int> g[40010];

void get(int S) {
	for(int i = S;i;i -= i & -i) 
		g[S].push_back(id[i&(i&-i)]);
}

LL dfs(int S) {
	if(S == 0 || f[S] != -1) return f[S];
	LL ans = xd[S];
	for(int S0 = (S - 1) & S;S0;S0 = (S0 - 1) & S) {
		//cout << S0 << endl;
		int S1 = S0,S2 = S ^ S0;
		LL tmp = 0;
		for(int i = 0;i < g[S1].size();i ++)
			for(int j = 0;j < g[S2].size();j ++)
				tmp += mp[g[S1][i]][g[S2][j]];
		ans = min(ans,tmp + dfs(S1) + dfs(S2));
	}
	return f[S] = ans;
}
	
int main() {
	n = read();
	for(int i = 1;i <= 2 * n * (n - 1);i ++) {
		int x = read(),y = read();
		mp[x-1][y-1] ++;
	}
	for(int i = 0,t = 1;i <= 15;i ++) id[t] = i,t *= 2;
	for(int S = 0;S < (1<<n);S ++) {
		get(S);
		for(int i = 0;i < g[S].size();i ++)
			for(int j = i + 1;j < g[S].size();j ++)
				xd[S] += abs(mp[g[S][i]][g[S][j]] - mp[g[S][j]][g[S][i]]);
	}
	memset(f,-1,sizeof f);
	printf("%lld\n",dfs((1 << n) - 1));
	return 0;
}
