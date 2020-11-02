#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 5e5 + 10;
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
	int f,t;
	LL d;
}l[SZ];

bool cmp(edge a,edge b) { return a.d > b.d; }

int tot = 0;

struct haha {
	int t;
	LL d;
};

vector<haha> g[SZ];
int anc[SZ][22],deep[SZ];
LL dist[SZ];

void dfs(int u,int fa) {
	deep[u] = deep[fa] + 1;
    anc[u][0] = fa;
    for(int i = 1;anc[u][i - 1];i ++) {
    	anc[u][i] = anc[anc[u][i - 1]][i - 1];
    }
    for(int i = 0;i < g[u].size();i ++){
    	int v = g[u][i].t;
    	if(v == fa) continue;
		dist[v] = dist[u] + g[u][i].d;
    	dfs(v,u);
    }
}

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

int n,m;

int id(int x,int y) {
    return (x - 1) * m + y;
}

int fa[SZ];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main() {
    n = read(),m = read();
    for(int i = 1;i <= n * m;i ++) {
        char s1[2],s2[2];
        int x = (i - 1) / m + 1,y = i - m * (x - 1),w1,w2;
       // cout << i << " " << x << " " << y << endl;
        scanf("%s%d%s%d",s1,&w1,s2,&w2);
        if(s1[0] != 'X') l[++ tot] = (edge){id(x,y),id(x + 1,y),w1};
        if(s2[0] != 'X') l[++ tot] = (edge){id(x,y),id(x,y + 1),w2};
    	fa[i] = i;
    }
    sort(l + 1,l + 1 + tot,cmp);
    for(int i = 1;i <= tot;i ++) {
        int x = find(l[i].f),y = find(l[i].t);
        if(x != y) {
            fa[x] = y;
            //cout << l[i].f << " " << l[i].t << " " << l[i].d << endl;
            g[l[i].f].push_back((haha){l[i].t,l[i].d});
            g[l[i].t].push_back((haha){l[i].f,l[i].d});
        }
    }
    dfs(1,0);
    int q = read();
    while(q --) {
    	int x1 = read(),y1 = read(),x2 = read(),y2 = read();
		int id1 = id(x1,y1),id2 = id(x2,y2);
		int lca = ask_lca(id1,id2);
		//cout << id1 <<" " <<id2 << " " << lca << endl;
        printf("%d\n",deep[id1] + deep[id2] - 2 * deep[lca]);
    }
    return 0;
}
