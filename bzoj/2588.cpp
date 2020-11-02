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
int a[SZ];
int anc[SZ][22],deep[SZ];

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
    int l,r,cnt;
}tree[2000010];

int len,Tcnt,root[SZ];

void insert(int l,int r,int last,int &now,int x) {
    now = ++ Tcnt;
    tree[now] = tree[last];
    tree[now].cnt ++;
    if(l == r) return ;
    int mid = l + r >> 1;
    if(x <= mid) insert(l,mid,tree[last].l,tree[now].l,x);
    else insert(mid + 1,r,tree[last].r,tree[now].r,x);
}

void dfs(int u,int f) {
	insert(1,len,root[f],root[u],a[u]);
    deep[u] = deep[f] + 1;
    anc[u][0] = f;
    for(int i = 1;anc[u][i - 1];i ++)
    	anc[u][i] = anc[anc[u][i - 1]][i - 1];
    for(int i = 0;i < g[u].size();i ++) {
    	int v = g[u][i];
        if(v == f) continue;
        dfs(v,u);
    }
}

int ask(int u,int v,int k) {
    int lca = ask_lca(u,v),fa = anc[lca][0];
	int ru = root[u],rv = root[v],rl = root[lca],rf = root[fa];
    int l = 1,r = len;
    while(l != r) {
        int mid = l + r >> 1;
        int d = tree[tree[ru].l].cnt + tree[tree[rv].l].cnt - tree[tree[rl].l].cnt - tree[tree[rf].l].cnt;
        if(d >= k)
            ru = tree[ru].l,rv = tree[rv].l,rl = tree[rl].l,rf = tree[rf].l,r = mid;
        else
        	ru = tree[ru].r,rv = tree[rv].r,rl = tree[rl].r,rf = tree[rf].r,k -= d,l = mid + 1;
    }
    return l;
}

int lsh[SZ];

int main() {
	int n = read(),m = read();
	for(int i = 1;i <= n;i ++) a[i] = read(),lsh[i] = a[i];
	sort(lsh + 1,lsh + 1 + n);
    len = unique(lsh + 1,lsh + 1 + n) - lsh - 1;
	for(int i = 1;i <= n;i ++) a[i] = lower_bound(lsh + 1,lsh + 1 + len,a[i]) - lsh;
	for(int i = 1;i < n;i ++) {
		int x = read(),y = read();
		g[x].push_back(y);
		g[y].push_back(x);
	}
   	dfs(1,0);
	int lastans = 0;
	while(m --) {
		int u = read(),v = read(),k = read();
        u ^= lastans;
        printf("%d\n",lastans = lsh[ask(u,v,k)]);
	}
	return 0;
}
