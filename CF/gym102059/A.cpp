#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 3000100;
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

struct node {
    node *f,*ch[2];
    int col,sz,c,val;
    bool rev;

    void maintain() {
        sz = ch[0] -> sz + val + ch[1] -> sz;
    }
    void setc(node *x,int d) { (ch[d] = x) -> f = this; }
    int dir() { return f -> ch[1] == this; }

    void pushc(int d) {
        col = d; c = d;
    }
    void pushrev();

    void pushdown() {
        if(c) {
            ch[0] -> pushc(c);
            ch[1] -> pushc(c);
            c = 0;
        }
        if(rev) {
            ch[0] -> pushrev();
            ch[1] -> pushrev();
            rev = 0;
        }
    }

    bool isroot() { return f -> ch[0] != this && f -> ch[1] != this; }
}T[SZ], *null, *tree[SZ];

int Tcnt = 0;

node* newnode(int x) {
    node *k = T + (Tcnt ++);
    k -> ch[0] = k -> ch[1] = null;
    k -> f = null;
    k -> col = k -> c = 0;
    k -> sz = x;
    k -> rev = 0;
    k -> val = x;
    return k;
}

void node::pushrev() {
    if(this == null) return ;
    rev ^= 1;
    swap(ch[0],ch[1]);
}

void rotate(node *p) {
    node *fa = p -> f;
    int d = p -> dir();
    p -> f = fa -> f;
    if(!fa -> isroot())  p -> f -> ch[fa -> dir()] = p;
    fa -> ch[d] = p -> ch[d^1];
    if(fa -> ch[d] != null) fa -> ch[d] -> f = fa;
    p -> setc(fa,d^1);
    fa -> maintain(); p -> maintain();
}

stack<node*> S;
void pushpath(node *p) {
    while(!p -> isroot()) S.push(p),p = p -> f;
    S.push(p);
    while(S.size()) S.top() -> pushdown(),S.pop();
}

void splay(node *p) {
    pushpath(p);
    while(!p -> isroot()) {
        if(p -> f -> isroot()) rotate(p);
        else {
            if(p -> dir() == p -> f -> dir()) rotate(p -> f),rotate(p);
            else rotate(p),rotate(p);
        }
    }
    p -> maintain();
}

int num[SZ],tong[SZ],n,C,Q;

void access(node *p,int c) {
    node *x = p;
    node *lst = null;
    while(p != null) {
        splay(p);
        int sz = p -> ch[1] -> sz,col = p -> col;
        if(p -> ch[1] == null) sz = 0;
       // printf(" %d %d %d %d %d\n",p-T,col,p->sz,sz,lst->sz);
        tong[num[col]] --; num[col] -= p->sz-sz; tong[num[col]] ++;
       // printf(" %d %d %d %d %d\n",p-T,col,p->sz,sz,lst->sz);
        p -> ch[1] = lst; p -> maintain();
        lst = p;
        p = p -> f;
    }
    splay(x);
    x -> pushc(c);
    int sum = x -> sz;
   // cout << sum << endl;
    tong[num[c]] --; num[c] += sum; tong[num[c]] ++;
}

void access(node *p) {
    node *lst = null;
    while(p != null) {
        splay(p);
        p -> ch[1] = lst; p -> maintain();
        lst = p;
        p = p -> f;
    }
}

void toroot(node *p) {
    access(p); splay(p); p->pushrev();
}

void link(node *u,node *v) {
    toroot(u); u -> f = v;
}

int main() {
    null = newnode(0);
    n = read(),C = read(),Q = read();
    tree[1] = newnode(0);
    for(int i = 2;i <= n;i ++) tree[i] = newnode(1);
    for(int i = 1;i < n;i ++) {
        int x = read(),y = read();
        link(tree[x],tree[y]);
    }
    toroot(tree[1]);
    num[0] = n-1; tong[n-1] = 1; tong[0] += C;

    while(Q --) {
        int u = read(),c = read(),m = read();

        access(tree[u],c);
   /*     for(int i = 0;i < n;i ++) printf("%d ",i); puts("");
        for(int i = 0;i < n;i ++) printf("%d ",tong[i]); puts("");
        puts("");
        for(int i = 0;i <= C;i ++) printf("%d ",i); puts("");
        for(int i = 0;i <= C;i ++) printf("%d ",num[i]); puts("");*/
        printf("%d\n",num[0]==m?tong[m]-1:tong[m]);
    }
}
/***
8 8 233
1 2
1 3
1 4
1 5
4 7
4 6
7 8
8 2 2
*/
