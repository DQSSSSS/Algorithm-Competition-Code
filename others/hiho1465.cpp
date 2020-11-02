#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 3000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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
	node *par,*ch[27];
	int val;
}T[SZ], *root, *lst;

int Tcnt = 0;

node* newnode(int x) {
	node *p = T + (++ Tcnt);
	p -> val = x;
	p -> par = NULL;
	memset(p -> ch,0,sizeof p -> ch);
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
			q -> par = nq; np -> par = nq;
			while(p && p -> ch[x] == q) p -> ch[x] = nq,p = p -> par;
		}
	}
	lst = np; sz[np - T] = 1;
}

vector<int> g[SZ];

void dfs(int u) {
	for(int i = 0;i < g[u].size();i ++) {
		int v = g[u][i];
		dfs(v);
		sz[u] += sz[v];
	}
}

int nxt[SZ];

void getnxt(char s[]) {
	int n = strlen(s);
	nxt[0] = nxt[1] = 0;
	for(int i = 1;i < n;i ++) {
		int j = nxt[i];
		while(j && s[i] != s[j]) j = nxt[j];
		nxt[i + 1] = s[i] == s[j] ? j + 1 : 0;
	}
}

bool vis[SZ];
int S[SZ];

LL work(char s[]) {
	int n = strlen(s),top = 0;
	node *p = root;
	LL ans = 0;
	int len = 0;
	for(int i = 0;i < 2 * n - 1;i ++) {
		char c = s[i%n] - 'a';
		if(p -> ch[c]) len ++,p = p -> ch[c];
		else {
			while(p != root && !p -> ch[c]) p = p -> par;
			len = p -> val;
			if(p -> ch[c]) len ++,p = p -> ch[c];
			else len = 0;
		}
		if(len > n)
			while(p && p -> par && p -> par -> val >= n) 
				p = p -> par,len = p -> val;
		if(len >= n && !vis[p - T]) ans += sz[p - T],vis[p - T] = 1,S[++ top] = p - T;
	//	cout << len << " " << p -> val << endl;
	}
	while(top) vis[S[top --]] = 0;
	return ans;
}

char s[SZ];

int main() {
	lst = root = newnode(0);
	scanf("%s",s);
	int l = strlen(s);
	for(int i = 0;i < l;i ++) insert(s[i] - 'a');
	for(int i = 2;i <= Tcnt;i ++) {
		node *p = T + i;
		g[p -> par - T].push_back(i);
	//	cout << p -> par - T << " " << i << endl;
	}
	dfs(1);
	//for(int i = 1;i <= Tcnt;i ++) cout << sz[i] << " "; puts("");
	int n = read();
	for(int i = 0;i < n;i ++) {
		scanf("%s",s);
		printf("%lld\n",work(s));
	}
	return 0;
}
