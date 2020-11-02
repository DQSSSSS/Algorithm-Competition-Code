#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 5010;
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

LL read() {
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
	if(flag) n = -n;
	return n;
}

int a[SZ];

struct node {
	node *f,*ch[2];
    int sz,v;

	node(int v,node *fa);
    void setc(node *x,int d) { (ch[d] = x) -> f = this; }
    int dir() { return f -> ch[1] == this; }
    void pushdown() {}
    void maintain() {
    	sz = ch[0] -> sz + ch[1] -> sz + 1;
    }
} *root, *null;

node :: node(int val,node *fa) {
	ch[0] = ch[1] = null;
    f = fa;
    sz = 1;
    v = val;
}

void rotate(node *p) {
    node *fa = p -> f;
    int d = p -> dir();
    fa -> f -> setc(p,fa -> dir());
    fa -> setc(p -> ch[d ^ 1],d); fa -> maintain();
    p -> setc(fa,d ^ 1); p -> maintain();
	if(fa == root) root = p;
}

void splay(node *p,node *rt = null) {
    p -> pushdown();
    while(p -> f != rt) {
        if(p -> f -> f == rt) rotate(p);
		else {
            p -> f -> f -> pushdown(); p -> f -> pushdown(); p -> pushdown();
            if(p -> dir() == p -> f -> dir()) rotate(p -> f),rotate(p);
            else rotate(p),rotate(p);
		}
    }
    p -> maintain();
}

void build(node* &p,int l,int r,node *fa) {
    if(l > r) return ;
    int mid = l + r >> 1;
    p = new node(mid,fa);
    build(p -> ch[0],l,mid - 1,p);
    build(p -> ch[1],mid + 1,r,p);
    p -> maintain();
}

node* findNode(int k) {
	node *p = root;
    while(233) {
        p -> pushdown();
        int x = p -> ch[0] -> sz + 1;
        if(k == x) return p;
        if(k > x) k -= x,p = p -> ch[1];
        else p = p -> ch[0];
    }
}

node* getNode(int l,int r) {
	l ++; r ++;
    splay(findNode(l - 1)); splay(findNode(r + 1),root);
    return root -> ch[1] -> ch[0];
}

void dfs(node *p) {
    if(p == null) return ;
    dfs(p -> ch[0]);
   	printf("%d ",p -> v);
    dfs(p -> ch[1]);
}

void init(){
    null = new node(-INF,null);
    null -> sz = 0;
    root = new node(-INF,null);
    root -> ch[1] = new node(-INF,root);
    root -> maintain();
}

int main() {
	init();
    int n = read(),m = read();
    build(root -> ch[1] -> ch[0],1,n,root -> ch[1]);
    while(m --) {
    	int pos = read(),len = read();
		int l = pos,r = pos + len - 1;
		node *p = getNode(l,r);
        root -> ch[1] -> ch[0] = null;
        root -> ch[1] -> maintain(); root -> maintain();
        splay(findNode(1)); splay(findNode(2),root);
        root -> ch[1] -> setc(p,0);
        root -> ch[1] -> maintain(); root -> maintain();
    }
    dfs(getNode(1,n));
    return 0;
}
