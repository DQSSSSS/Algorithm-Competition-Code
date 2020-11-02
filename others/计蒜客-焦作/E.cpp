#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 100010;
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

vector<int> g[SZ];

int sz[SZ],deep[SZ],son[SZ],fa[SZ];
int top[SZ],inseg[SZ],dfs_clock;

void dfs1(int u,int f){
    sz[u] = 1;
    son[u] = 0;
    deep[u] = deep[f] + 1;
    fa[u] = f;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        dfs1(v,u);
        sz[u]+=sz[v];
        if (sz[v]>sz[son[u]]) son[u]=v;
    }
}

void dfs2(int u,int pre){
    top[u]=pre; inseg[u]=++dfs_clock;
    if (son[u]!=0) dfs2(son[u],pre);
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if (v==son[u]) continue;
        dfs2(v,v);
    }
}

struct segment {
	int l,r;
	ULL add,mult,sum;
}tree[SZ * 4];

void update(int p) {
	tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
}

void pushc(int p,ULL a,ULL b) {
	ULL len = tree[p].r - tree[p].l + 1;
	tree[p].add = a * tree[p].add + b;
	tree[p].mult *= a;
	tree[p].sum = tree[p].sum * a + b * len;
}

void pushdown(int p) {
	if(tree[p].add || tree[p].mult != 1) {
		pushc(p << 1,tree[p].mult,tree[p].add);
		pushc(p << 1 | 1,tree[p].mult,tree[p].add);
		tree[p].add = 0; tree[p].mult = 1;
	}
}

void build(int p,int l,int r) {
	tree[p].l = l; tree[p].r = r;
	tree[p].add = 0; tree[p].mult = 1;
	if(l == r) {
		tree[p].sum = 0;
		return ;
	}
	int mid = l + r >> 1;
	build(p << 1,l,mid); build(p << 1 | 1,mid + 1,r);
	update(p);
}

void change(int p,int l,int r,ULL a,ULL b) {
	if(l <= tree[p].l && tree[p].r <= r) {
		pushc(p,a,b);
		return ;
	}
	pushdown(p);
	int mid = tree[p].l + tree[p].r >> 1;
	if(l <= mid) change(p << 1,l,r,a,b);
	if(mid < r) change(p << 1 | 1,l,r,a,b);
	update(p);
}

ULL ask(int p,int l,int r) {
	if(l <= tree[p].l && tree[p].r <= r) {
		return tree[p].sum;
	}
	pushdown(p);
	int mid = tree[p].l + tree[p].r >> 1;
	ULL ans = 0;
	if(l <= mid) ans += ask(p << 1,l,r);
	if(mid < r) ans += ask(p << 1 | 1,l,r);
	return ans;
}

void change(int x,int y,ULL a,ULL b) {
	int fx = top[x],fy = top[y];
	while(fx != fy) {
		if(deep[fx] < deep[fy]) swap(x,y),swap(fx,fy);
		change(1,inseg[fx],inseg[x],a,b);
		x = fa[fx]; fx = top[x];
	}
	if(deep[x] > deep[y]) swap(x,y);
	change(1,inseg[x],inseg[y],a,b);
}

ULL ask(int x,int y) {
	int fx = top[x],fy = top[y];
	ULL ans = 0;
	while(fx != fy) {
		if(deep[fx] < deep[fy]) swap(x,y),swap(fx,fy);
		ans += ask(1,inseg[fx],inseg[x]);
		x = fa[fx]; fx = top[x];
	}
	if(deep[x] > deep[y]) swap(x,y);
	ans += ask(1,inseg[x],inseg[y]);
	return ans;
}

int n;

void init() {
	dfs_clock = 0;
	for(int i = 1;i <= n;i ++) g[i].clear();
}

int main(){
    while(scanf("%d",&n)!=EOF){
		init();
        for(int i=2;i<=n;i++){
            int a = read();
            g[a].push_back(i);
        }
        dfs1(1,0); dfs2(1,1);
		build(1,1,n);
		int q = read();
		while(q --) {
			int opt = read(),u = read(),v = read();
			ULL x;
			if(opt == 1) {
				scanf("%llu",&x);
				change(u,v,x,0);
			}
			else if(opt == 2) {
				scanf("%llu",&x);
				change(u,v,1,x);
			}
			else if(opt == 3) {
				change(u,v,-1,-1);
			}
			else {
				printf("%llu\n",ask(u,v));
			}
		}
    }	
    return 0;
}
