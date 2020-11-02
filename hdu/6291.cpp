#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UI;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 400010;
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
int a[SZ];
int anc[SZ][22],deep[SZ],lg[SZ];
ULL val[SZ],sum[SZ];

int ask_lca(int u,int v) {
	if(deep[u] < deep[v]) swap(u,v);
    int dd = deep[u] - deep[v];
    for(int i = 20;i >= 0;i --)
    	if(dd >> i & 1)
    		u = anc[u][i];
    if(u == v) return u;
    for(int i = 20;i >= 0;i --)
    	if(anc[u][i] != anc[v][i])
    		u = anc[u][i],v = anc[v][i];
    return anc[u][0];
}

struct haha {
    int l,r;
    ULL x;
}tree[5000010];

int len = 200001,Tcnt,root[SZ];

void insert(int l,int r,int last,int &now,int x) {
    now = ++ Tcnt;
    tree[now] = tree[last];
    tree[now].x ^= val[x];
    if(l == r) return ;
    int mid = l + r >> 1;
    if(x <= mid) insert(l,mid,tree[last].l,tree[now].l,x);
    else insert(mid + 1,r,tree[last].r,tree[now].r,x);
}

void dfs(int u,int f) {
	insert(1,len,root[f],root[u],a[u]);
    deep[u] = deep[f] + 1;
    anc[u][0] = f;
    for(int i = 1;i <= lg[deep[u]];i ++)
    	anc[u][i] = anc[anc[u][i - 1]][i - 1];
    for(int i = 0;i < g[u].size();i ++) {
    	int v = g[u][i];
        if(v == f) continue;
        dfs(v,u);
    }
}

int ask(int u,int v) {
    int lca = ask_lca(u,v),fa = anc[lca][0];
	int ru = root[u],rv = root[v],rl = root[lca],rf = root[fa];
    int l = 1,r = len;
    while(l != r) {
        int mid = l + r >> 1;
        ULL d = tree[tree[ru].l].x ^ tree[tree[rv].l].x ^ tree[tree[rl].l].x ^ tree[tree[rf].l].x;
        if(d != (sum[mid] ^ sum[l - 1]))
            ru = tree[ru].l,rv = tree[rv].l,rl = tree[rl].l,rf = tree[rf].l,r = mid;
        else
        	ru = tree[ru].r,rv = tree[rv].r,rl = tree[rl].r,rf = tree[rf].r,l = mid + 1;
    }
    return l;
}

UI randUI() {
	return ((UI)rand()) << 16u | ((UI)rand());
}

ULL randULL() {
	return ((ULL)randUI()) << 32llu | ((ULL)randUI());
}

int main() {
	int T = read();
	for(int i = 1;i <= 200001;i ++) val[i] = randUI();
	for(int i = 1;i <= 200001;i ++) sum[i] = sum[i - 1] ^ val[i];
	for(int i = 1;i <= 200000;i ++) lg[i] = log2(i);
	while(T --) {
		int n = read(),m = read();

        for(int i = 1;i <= n;i ++)
        	for(int j = 0;j <= 20;j ++)
        		anc[i][j] = 0;
        for(int i = 1;i <= n;i ++) g[i].clear(),root[i] = 0;
        for(int i = 1;i <= Tcnt;i ++) tree[i].l = tree[i].r = tree[i].x = 0;
		Tcnt = 0;

		for(int i = 1;i <= n;i ++) a[i] = read();
		for(int i = 1;i < n;i ++) {
			int x = read(),y = read();
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(1,0);
		while(m --) {
			int u = read(),v = read();
			printf("%d\n",ask(u,v));
		}
	}
	return 0;
}

