#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
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

vector<int> g[SZ];

int f[SZ][2],Maxd[SZ],n,k;

void dfs(int u) {
	if(g[u].size() == 0) {
		f[u][1] = f[u][0] = 1;
		Maxd[u] = k;
		return ;
	}
	
	for(int i = 0;i < g[u].size();i ++) {
		int v = g[u][i];
		dfs(v);
	}
	int len = g[u].size(),sum = 0;
	for(int i = 0;i < len;i ++) if(Maxd[g[u][i]] >= 1) sum += f[g[u][i]][0];
	
	for(int i = 0;i < len;i ++) {
		int v = g[u][i];
		Maxd[u] = max(Maxd[u],Maxd[v] - 1);
		if(Maxd[v] >= 1) {
			f[u][0] += f[v][0];
			f[u][1] = max(f[u][1],sum - f[v][0] + f[v][1]);
		}
		else 
			f[u][1] = max(f[u][1],sum + f[v][1]);
	}	
}

int main() {
	n = read(),k = read();
	for(int i = 2;i <= n;i ++) {
		int x = read();
		g[x].push_back(i);
	}
	dfs(1);
	//for(int i = 1;i <= n;i ++)
	//	cout << i << " " << f[i][0] << " " << f[i][1] << " " << Maxd[i] << endl;
	cout << f[1][1] << endl;
	return 0;
}
