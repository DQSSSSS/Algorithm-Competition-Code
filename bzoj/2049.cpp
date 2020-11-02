#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar();  }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

struct node
{
    node *f,*ch[2];
    int sz;
    bool rev;

    void setc(node *x,int d) { (ch[d] = x) -> f = this; }
    int dir() { return f -> ch[1] == this; }
    bool isroot() { return f -> ch[0] != this && f -> ch[1] != this; }
    void maintain() { sz = ch[0] -> sz + ch[1] -> sz + 1; }
    void pushdown();
}T[SZ],*tree[SZ],*null,*S[SZ];

int Tcnt = 0;

node* newnode()
{
    node *k = T + (Tcnt ++);
    k -> ch[0] = k -> ch[1] = k -> f = null;
    k -> sz = 1;
    k -> rev = 0;
    return k;
}

void pushrev(node *p)
{
    if(p == null) return ;
    p -> rev ^= 1;
    swap(p -> ch[0],p -> ch[1]);
}

void node :: pushdown()
{
    if(rev)
        pushrev(ch[0]),pushrev(ch[1]),rev = 0;
}

void rotate(node *p)
{
    node *fa = p -> f;
    int d = p -> dir();
    p -> f = fa -> f;
    if(!fa -> isroot())
        fa -> f -> setc(p,fa -> dir());
    fa -> setc(p -> ch[d ^ 1],d);
    p -> setc(fa,d ^ 1);
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
    node *lst = null;
    while(p != null)
    {
        splay(p);
        p -> ch[1] = lst; p -> maintain();
        lst = p;
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

int n,m;

node* find(node *p)
{
    while(p -> f != null) p = p -> f;
    return p;
}


void init()
{
    null = newnode();
    null -> sz = 0;
}

int main()
{
    init();
    n = read(),m = read();
    for(int i = 0;i <= n;i ++) tree[i] = newnode();
    for(int i = 1;i <= m;i ++)
    {
        char opt[22];
        scanf("%s",opt);
        int u = read(),v = read();
        if(opt[0] == 'Q')
            puts(find(tree[u]) == find(tree[v]) ? "Yes" : "No");
        else if(opt[0] == 'D')
            cut(tree[u],tree[v]);
        else
            link(tree[u],tree[v]);
    }
    return 0;
}
/*
3  5

Connect 1 2

Connect 3 1

Query 2 3

Destroy 1 3

Query 2 3
*/
