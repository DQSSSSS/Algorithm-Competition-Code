#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;
const LD PI = acos(-1);

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int sz[SZ];

struct node {
	node *ch[27],*par;
	int val;
}T[SZ], *root, *lst;

int Tcnt = 0;

node* newnode(int x) {
	node *p = T + (++ Tcnt);
	memset(p -> ch,0,sizeof p -> ch);
	p -> par = NULL; p -> val = x;
	return p;
}

void insert(int x) {
	node *p = lst,*np = newnode(p -> val + 1);
	while(p && !p -> ch[x]) p -> ch[x] = np,p = p -> par;
	if(!p) np -> par = root;
	else {
		node *q = p -> ch[x];
		if(q -> val == p -> val + 1) np -> par = q;
		else {
			node *nq = newnode(p -> val + 1);
			memcpy(nq -> ch,q -> ch,sizeof nq -> ch);
			nq -> par = q -> par;
			np -> par = nq; q -> par = nq;
			while(p && p -> ch[x] == q) p -> ch[x] = nq,p = p -> par;
		}
	}
	lst = np;
	sz[np - T] = 1;
}

vector<int> g[SZ];
int Ans[SZ];

void dfs(int u) {
	for(int i = 0;i < g[u].size();i ++) {
		int v = g[u][i];
		dfs(v);
		sz[u] += sz[v];
	}
	node *p = T + u;
	Ans[p -> val] = max(Ans[p -> val],sz[u]);
}

char s[SZ];
	
int main() {
	lst = root = newnode(0);
	scanf("%s",s);
	int n = strlen(s);
	for(int i = 0;i < n;i ++) {
		insert(s[i] - 'a' + 1);
	}
	for(int i = 2;i <= Tcnt;i ++) {
		node *p = T + i;
		g[p -> par - T].push_back(p - T);
	}
	dfs(1);
	for(int i = n - 1;i >= 1;i --) Ans[i] = max(Ans[i],Ans[i + 1]);
	for(int i = 1;i <= n;i ++) printf("%d\n",Ans[i]);
	return 0;
}
