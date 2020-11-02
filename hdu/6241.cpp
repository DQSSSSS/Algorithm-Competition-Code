#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200010;
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

int sz[SZ];

void dfs1(int u,int f) {
	sz[u] = 1;
	for(int i = 0;i < g[u].size();i ++) {
		int v = g[u][i];
		if(v == f) continue;
		dfs1(v,u);
		sz[u] += sz[v];
	}
}

int a[SZ],b[SZ],L[SZ],R[SZ],n;

void dfs(int u,int f) {
	if(g[u].size() == 1) return ;
	int l = 0,r = 0;
	for(int i = 0;i < g[u].size();i ++) {
		int v = g[u][i];
		if(v == f) continue;
		dfs(v,u);
		l += L[v]; r += R[v];
	}
	L[u] = max(L[u],l); R[u] = min(R[u],r + 1);
}

bool check(int mid) {
	for(int i = 1;i <= n;i ++) {
		L[i] = a[i],R[i] = min(sz[i],mid - b[i]);
		if(L[i] > R[i]) return false;
	}
	//puts("------------");
	//cout << mid << endl;
	//for(int i = 1;i <= n;i ++) cout << L[i] << " " << R[i] << endl;
	
	dfs(1,0);
	for(int i = 1;i <= n;i ++) {
		if(L[i] > R[i]) return false;
	}
	//cout << mid << endl;
	//for(int i = 1;i <= n;i ++) cout << L[i] << " " << R[i] << endl;
	return L[1] <= mid && mid <= R[1];
}

int Div() {
	int l = -1,r = n + 1;
	while(r - l > 1) {
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid;
	}
	return r == n + 1 ? -1 : r;
}

int main() {
	int T = read();
	while(T --) {
		n = read();
		for(int i = 1;i <= n;i ++) g[i].clear(),a[i] = b[i] = 0;
		for(int i = 1;i < n;i ++) {
			int x = read(),y = read();
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs1(1,0);
		int A = read();
		for(int i = 1;i <= A;i ++) {
			int x = read(),y = read();
			a[x] = max(a[x],y);
		}
		int B = read();
		for(int i = 1;i <= B;i ++) {
			int x = read(),y = read();
			b[x] = max(b[x],y);
		}
		//cout << "check :" << check(4) << endl;
		printf("%d\n",Div());
	}
	return 0;
}	
/***
233
7
1 2
1 3
2 4
2 5
3 6
3 7
1
6 1
2
2 3
3 2

*/
