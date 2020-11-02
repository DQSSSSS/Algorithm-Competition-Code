#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

struct node{
    node *f,*ch[2];
    int sz;
    bool rev;

    node();
    void setc(node *x,int d) { (ch[d] = x) -> f = this; }

    int dir() { return f -> ch[1] == this; }

    bool isroot() { return f -> ch[0] != this && f -> ch[1] != this; }

    void maintain() { sz = ch[0] -> sz + 1 + ch[1] -> sz; }

    void pushdown();
}*null, *tree[SZ], *S[SZ];

int Tcnt = 0;

node :: node() {
    ch[0] = ch[1] = f = null;
    sz = 1;
    rev = 0;
}

void pushrev(node *p) { if(p == null) return ; swap(p -> ch[0],p -> ch[1]); p -> rev ^= 1; }

void node :: pushdown()
{
    if(rev) { pushrev(ch[0]); pushrev(ch[1]); rev = 0; }
}

void rotate(node *p)
{
    int d = p -> dir();
    node *fa = p -> f;
    p -> f = fa -> f;
    if(!fa -> isroot()) fa -> f -> ch[fa -> dir()] = p;
    fa -> ch[d] = p -> ch[d ^ 1];
    if(fa -> ch[d] != null) fa -> ch[d] -> f = fa;
    p -> setc(fa, d ^ 1);
    fa -> maintain(); p -> maintain();
}

int top = 0;

void pushpath(node *p)
{
    while(!p -> isroot()) S[++ top] = p,p = p -> f;
    S[++ top] = p;
    while(top) S[top --] -> pushdown();
}

void splay(node *p)
{
    pushpath(p);
    while(!p -> isroot())
    {
        p -> maintain();
        if(p -> f -> isroot()) rotate(p);
        else
        {
            if(p -> dir() == p -> f -> dir()) rotate(p -> f),rotate(p);
            else rotate(p),rotate(p);
        }
    }
    p -> maintain();
}

void access(node *p)
{
    node *last = null;
    while(p != null)
    {
        splay(p);
        p -> ch[1] = last; p -> maintain();
        last = p;
        p = p -> f;
    }
}

void toroot(node *p)
{
    access(p);
    splay(p);
    pushrev(p);
}

void link(node *u,node *v)
{
    toroot(u);
    u -> f = v;
}

void cut(node *u,node *v)
{
    toroot(u);
    access(v);
    splay(v);
    v -> ch[0] = u -> f = null;
}

int n,rt;

int ask(node *p)
{
    toroot(tree[rt]);
    access(p);
    splay(p);
    return p -> sz;
}


/***************************/

vector<int> g[SZ];
int deep[SZ],anc[SZ][22],lg[SZ];

void dfs(int u,int fa) {
	anc[u][0] = fa;
	deep[u] = deep[fa] + 1;
	for(int i = 1;i <= lg[deep[u]];i ++)
		anc[u][i] = anc[anc[u][i - 1]][i - 1];
	for(int i = 0;i < g[u].size();i ++) {
		int v = g[u][i];
		if(v == fa) continue;
		dfs(v,u);
	}
}

/**************************/

int fa[SZ];

int ask(int u,int d) {
	if(d >= deep[u]) return rt;
	else {
		for(int i = lg[deep[u]];i >= 0;i --)
    	if(d & (1 << i))
    		u = anc[u][i];
    	return u;
	}
}

int a[SZ];

int main() {
	for(int i = 1;i <= 100000;i ++) lg[i] = log2(i);
	null = new node(); null -> sz = 0;
	int T = read();
	while(T --) {
        n = read();
        for(int i = 1;i <= n + 1;i ++) g[i].clear();
		for(int i = 2;i <= n;i ++) {
            int x = read();
            g[x].push_back(i);
            g[i].push_back(x);
		}
		for(int i = 1;i <= n;i ++) a[i] = read();
		dfs(1,0);

		rt = n + 1;
		for(int i = 1;i <= n + 1;i ++) tree[i] = new node();
		for(int i = 1;i <= n;i ++) {
			int f = ask(i,a[i]);
            link(tree[i],tree[f]);
            fa[i] = f;
		}

        int q = read();
        for(int cc = 1;cc <= q;cc ++) {
        	int opt = read();
        	if(opt == 1) {
				int u = read();
				printf("%d\n",ask(tree[u]) - 1);
        	}
        	else {
                int u = read(),d = read();
                cut(tree[u],tree[fa[u]]);
                fa[u] = ask(u,d);
                link(tree[u],tree[fa[u]]);
        	}
        }
        for(int i = 1;i <= n + 1;i ++) delete tree[i];
	}
}
