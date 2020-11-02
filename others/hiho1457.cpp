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

struct node {
	node *ch[12],*par;
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
}

struct edge {
	int t,d;
};

vector<edge> g[SZ];
int rd[SZ],rd2[SZ];
LL Ans[SZ],w[SZ];
bool vis[SZ];

char s[SZ];
queue<int> q;
	
int main() {
	lst = root = newnode(0);
	int n = read();
	for(int i = 1;i <= n;i ++) {
		scanf("%s",s);
		int l = strlen(s);
		for(int j = 0;j < l;j ++) {
			insert(s[j] - '0');
		}
		insert(10);
	}
	
	for(int i = 1;i <= Tcnt;i ++) {
		node *p = T + i;
		for(int j = 0;j < 10;j ++) {
			if(p -> ch[j] == NULL) continue;
			g[i].push_back((edge){p -> ch[j] - T,j});
		}
	}
	
	//for(int i = 1;i <= Tcnt;i ++) cout << rd[i] << " "; puts("");
	q.push(1); vis[1] = 1;
	while(q.size()) {
		int u = q.front(); q.pop();
		for(int i = 0;i < g[u].size();i ++) {
			int v = g[u][i].t;
			rd[v] ++;
			if(!vis[v]) vis[v] = 1,q.push(v);
		}
	}
	//for(int i = 1;i <= Tcnt;i ++) cout << w[i] << " "; puts("");
	q.push(1); w[1] = 1;
	int ans = 0;
	while(q.size()) {
		int u = q.front(); q.pop();
		(ans += Ans[u]) %= mod;
		for(int i = 0;i < g[u].size();i ++) {
			int v = g[u][i].t;
			(w[v] += w[u]) %= mod;
			(Ans[v] += Ans[u] * 10 + w[u] * g[u][i].d) %= mod;
			if(!-- rd[v]) q.push(v);
		}
	}
	printf("%d\n",ans);	
	return 0;
}
/**

*/
