#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e5 + 10;
const int mod = 1811939329;

LL ksm(LL a,LL b) {
	LL ans = 1;
	while(b) {
		if(b & 1) ans = a * ans % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

struct NTT {
	const LL wn[SZ],wnInv[SZ];
	const int g = 13;
}ntt;

LL c1[SZ],c2[SZ];

void multiply(LL a[],int n,LL b[],int m) {
	int len = 1;
	while(len < n || len < m) len <<= 1;
	for(int i = 0;i < len;i ++) {
		c1[i] = c2[i] = 0;
		if(i < n) c1[i] = a[i];
		if(i < m) c2[i] = b[i];
	}
	ntt.init(len); ntt.dft(c1,len); ntt.dft(c2,len);
	for(int i = 0;i < len;i ++) a[i] = c1[i] * c2[i] % mod;
	ntt.idft(a,len);
}

vector<int> g[SZ];
int n,sz[SZ],son[SZ],cson[SZ];

void dfs1(int u,int f) {
	sz[u] = 1;
	cson[u] = 0;
	son[u] = 0;
	for(int i = 0;i < g[u].size();i ++) {
		int v = g[u][i];
		if(v == f) continue;
		dfs1(v,u);
		sz[u] += sz[v];
		if(!son[u] || sz[son[u]] < sz[v]) son[u] = v;
	}
}

LL *a[SZ];
int pr[SZ];

void dfs(int u,int f,LL a[]) {
	a[u] = new LL(sz[cson[u]] * 2);
	memset(a[u],0,sizeof a[u]);
	a[u][1] = 1; len = 1;
	for(int i = 0;i < g[u].size();i ++) {
		int v = g[u][i];
		if(v == f || v == son[u]) continue;
		dfs(v,u);
		multiply(a[u],len + 1,a[v])
	}
}

vector<int> getGtmp;
int getG(int p) {
	int x = p - 1;
	for(int i = 2;i <= x;i ++) if(x % i == 0) getGtmp.push_back(i);
	for(int k = 2;;k ++) {	
		for(int i = 0;i < getGtmp.size();i ++) {
			if(ksm(k,getGtmp[i]) == 1) {
				if(getGtmp[i] == x) return k;
				else break;
			}
		}
	}
}

bool cmp(int a,int b) { return sz[a] < sz[b]; } 

int main() {
	int T;
	scanf("%d",&T);
	while(T --) {
		scanf("%d",&n);
		for(int i = 1;i <= n;i ++) g[i].clear();
		for(int i = 1;i < n;i ++) {
			int x,y;
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs1(1,0);
		for(int i = 1;i <= n;i ++) {
			sort(g[i].begin(),g[i].end(),cmp);
			if(i == 1) {
				if(g[i].size() >= 2) cson[i] = g[i][g[i].size() - 2];
			}
			else {
				if(g[i].size()) cson[i] = g[i][g[i].size() - 1];		
			}
		}
		dfs(1,0);
		for(int i = 1;i <= n;i ++) 
			printf("%lld%c",a[i],i == n ? '\n' : ' ');
	}
	return 0;
}

