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

struct edge {
	int t,w;
};

vector<edge> g[SZ];

bool red[SZ];
int sz[SZ],deep[SZ],son[SZ],fa[SZ],val[SZ];
int anc[SZ][22];
LL dist[SZ][22];
int top[SZ],inseg[SZ],dfs_clock;

void dfs1(int u,int f){
    sz[u] = 1;
    son[u] = 0;
    deep[u] = deep[f] + 1;
    fa[u] = f;
    anc[u][0] = f;
    for(int i = 1;anc[u][i - 1];i ++)
    	anc[u][i] = anc[anc[u][i - 1]][i - 1],
    	dist[u][i] = dist[u][i - 1] + dist[anc[u][i - 1]][i - 1];
   // cout << u << endl;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].t;
        if(v == f) continue;
        val[v] = g[u][i].w + val[u]; 
        if(red[v]) val[v] = 0;
		dist[v][0] = g[u][i].w;
        dfs1(v,u);
 //       cout << u << " " << val[u] << " " << val[v] << endl;		
        sz[u]+=sz[v];
        if (sz[v]>sz[son[u]]) son[u]=v;
    }
}

void dfs2(int u,int pre){
    top[u]=pre; inseg[u]=++dfs_clock;
    if (son[u]!=0) dfs2(son[u],pre);
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i].t;
        if (v==son[u] || v == fa[u]) continue;
        dfs2(v,v);
    }
}

struct segment {
	int l,r;
	int add,Max;
}tree[SZ * 4];

void update(int p) {
	tree[p].Max = max(tree[p << 1].Max,tree[p << 1 | 1].Max);
}

void pushc(int p,int d) {
	tree[p].Max += d;
}

void pushdown(int p) {
	if(tree[p].add) {
		pushc(p << 1,tree[p].add);
		pushc(p << 1 | 1,tree[p].add);
		tree[p].add = 0;
	}
}

void build(int p,int l,int r) {
	tree[p].l = l; tree[p].r = r;
	tree[p].add = 0;
	if(l == r) {
		tree[p].Max = 0;
		return ;
	}
	int mid = l + r >> 1;
	build(p << 1,l,mid); build(p << 1 | 1,mid + 1,r);
	update(p);
}

void change(int p,int l,int r,int d) {
	if(l <= tree[p].l && tree[p].r <= r) {
		pushc(p,d);
		return ;
	}
	pushdown(p);
	int mid = tree[p].l + tree[p].r >> 1;
	if(l <= mid) change(p << 1,l,r,d);
	if(mid < r) change(p << 1 | 1,l,r,d);
	update(p);
}

int ask(int p,int l,int r) {
	if(l <= tree[p].l && tree[p].r <= r) {
		return tree[p].Max;
	}
	pushdown(p);
	int mid = tree[p].l + tree[p].r >> 1;
	int ans = 0;
	if(l <= mid) ans = max(ans,ask(p << 1,l,r));
	if(mid < r) ans = max(ans,ask(p << 1 | 1,l,r));
	return ans;
}

void change(int x,int y,int d) {
	int fx = top[x],fy = top[y];
	while(fx != fy) {
		if(deep[fx] < deep[fy]) swap(x,y),swap(fx,fy);
		change(1,inseg[fx],inseg[x],d);
		x = fa[fx]; fx = top[x];
	}
	if(deep[x] > deep[y]) swap(x,y);
	change(1,inseg[x],inseg[y],d);
}

int jump(int x,LL d) {
	for(int i = 20;i >= 0;i --)
		if(dist[x][i] <= d) {
			d -= dist[x][i],x = anc[x][i];
		//	cout << d << " " << x << endl;
		}
	if(dist[x][0] <= d) return anc[x][0];
	return x;
}

vector<int> node;

pii path[SZ];

bool check(LL mid) {
	int tot = 0,t = 0;
	for(int i = 0;i < node.size();i ++) {
		int x = node[i];
		if(val[x] > mid) {
			t ++;
			int fa = jump(x,mid);
			change(x,fa,1);
			path[++ tot] = make_pair(x,fa);
		}
	}
	int d = tree[1].Max;
	//cout << d << endl;
	//for(int i = 1;i <= tot;i ++) cout << path[i].first << " " << path[i].second << endl;
	for(int i = 1;i <= tot;i ++) change(path[i].first,path[i].second,-1);
	if(d == t) return true;
	return false;
}

int div() {
	LL l = -1,r = 1e15;
	while(r - l > 1) {
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid;
	}
	return r;
}

bool cmp(int a,int b) { return val[a] < val[b]; }
int n,m,q;

int main() {
	int T = read();
	while(T --) {
		n = read(),m = read(),q = read();
		for(int i = 1;i <= n;i ++) red[i] = 0,g[i].clear();
		dfs_clock = 0;
		for(int i = 1;i <= m;i ++) red[read()] = 1;
		for(int i = 1;i < n;i ++) {
			int x = read(),y = read(),z = read();
			g[x].push_back((edge){y,z});
			g[y].push_back((edge){x,z});
		}
		for(int i = 1;i <= n;i ++)
			for(int j = 0;j <= 20;j ++)
				dist[i][j] = 1e18,anc[i][j] = 0;
		dfs1(1,0); 
		dfs2(1,1);
		//puts("233");
		build(1,1,n);
		//for(int i = 1;i <= n;i ++) cout << red[i] << " "; puts("");
		//for(int i = 1;i <= n;i ++) cout << val[i] << " "; puts("");
		/*for(int i = 1;i <= n;i ++,puts(""))
			for(int j = 0;j <= 10;j ++)
				cout << dist[i][j] << " ";*/
		//cout << jump(8,5);
		while(q --) {
			int k = read(); node.clear();
			for(int i = 1;i <= k;i ++) {
				int x = read();
				if(red[x]) continue;
				node.push_back(x);
			}
			if(node.size() == 1) { puts("0"); continue; }
			//sort(node.begin(),node.end(),cmp);
	//		cout << check(0) << endl;
			//cout <<node.size()<< endl;
			printf("%d\n",div());
		}
	}
	return 0;
}
/**
2
12 2 4
1 9
1 2 1
2 3 4
3 4 3
3 5 2
2 6 2
6 7 1
6 8 2
2 9 5
9 10 2
9 11 3
1 12 10
4 4 5 7 8

233
3 2 3
1 2
1 2 1
1 3 1
3 1 2 3
*/
