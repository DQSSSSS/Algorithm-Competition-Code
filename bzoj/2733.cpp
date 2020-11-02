#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<vector>
#include<ctime>
#include<bitset>
#include<set>
#define x first
#define y second
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 200010;
const LL INF = 1000000010;
const LL mod = 1000000007;
const int Dx[] = {0,1,0,-1};
const int Dy[] = {1,0,-1,0};


LL read()
{
    LL n = 0;
    char a = getchar();
    int flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}


struct node
{
    node *f,*ch[2];
    int v,sz,cnt;

    void setc(node *x,int d) { (ch[d] = x) -> f = this; }
    int dir() { return f -> ch[1] == this; }
    void maintain()
    {
        sz = ch[0] -> sz + cnt + ch[1] -> sz;
    }
    int cmp(int x)
    {
        if(x == v) return -1;
        return x < v ? 0 : 1;
    }
    void pushdown() {} ;
}T[SZ], *root[SZ], *null;

int Tcnt = 0;

node* newnode(int x,node *fa)
{
    node *k = T + Tcnt ++;
    k -> f = fa;
    k -> ch[0] = k -> ch[1] = null;
    k -> v = x;
    k -> cnt = k -> sz = 1;
    return k;
}

void rotate(node *p)
{
    node *fa = p -> f;
    int d = p -> dir();
    fa -> f -> setc(p,fa -> dir());
    fa -> setc(p -> ch[d ^ 1],d); fa -> maintain();
    p -> setc(fa,d ^ 1); p -> maintain();
}

void splay(node *p,node *rt = null)
{
    p -> pushdown();
    while(p -> f != rt)
    {
        if(p -> f -> f == rt) rotate(p);
        else
        {
            p -> f -> f -> pushdown(); p -> f -> pushdown(); p -> pushdown();
            if(p -> dir() == p -> f -> dir())
                rotate(p -> f),rotate(p);
            else
                rotate(p),rotate(p);
        }
    }
    p -> maintain();
}

void insert(node *p,int x,node* &root)
{
    if(root == null) { root = newnode(x,null); return ; }
    while(p != null)
    {
        p -> sz ++;
        int d = p -> cmp(x);
        if(d == -1) { p -> cnt ++; break; }
        if(p -> ch[d] == null)
        {
            p -> ch[d] = newnode(x,p);
            p = p -> ch[d];
            break;
        }
        p = p -> ch[d];
    }
    splay(p);
    root = p;
}

void erase(node *p,int x,node* &root)
{
    while(p != null)
    {
        p -> sz --;
        int d = p -> cmp(x);
        if(d == -1) { p -> cnt --; break;}
        p = p -> ch[d];
    }
    if(p -> cnt) return ;
    splay(p);
    while(root -> f != null) root = root -> f;
    if(p -> ch[1] == null) { root = p -> ch[0],root -> f = null; return ; }
    if(p -> ch[0] == null) { root = p -> ch[1],root -> f = null; return ; }
    p = p -> ch[0];
    while(p -> ch[1] != null) p = p -> ch[1];
    splay(p,root);
    p -> ch[1] = root -> ch[1]; p -> ch[1] -> f = p;
    p -> f = null; p -> maintain();
    root = p;
}



int ask_num(node *p,int k)
{
    while(p != null)
    {
        int l = p -> ch[0] -> sz + 1;
        int r = p -> ch[0] -> sz + p -> cnt;
        if(l <= k && k <= r) return p -> v;
        if(k > r) k -= r,p = p -> ch[1];
        else p = p -> ch[0];
    }
    return -1;
}

void init()
{
    null = newnode(-INF,null);
    null -> sz = null -> cnt = 0;
}

void merge(node* &p,node* &y)
{
    if(p == null) return ;
    merge(p -> ch[0],y);
    merge(p -> ch[1],y);
    insert(y,p -> v,y);
    p = null;
}


int a[SZ];

int fa[SZ];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main()
{
    init();
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++) fa[i] = i;

    for(int i = 1,x;i <= n;i ++)
        x = read(),a[x] = i,root[i] = newnode(x,null);
    for(int i = 1;i <= m;i ++)
    {
        int x = read(),y = read();
        int a = find(x),b = find(y);

        if(a == b) continue;
        if(root[a] -> sz < root[b] -> sz) swap(a,b);
        fa[b] = a,merge(root[b],root[a]);
    }
    int q = read();
    while(q --)
    {
        char opt[3];
        scanf("%s",opt);
        int x = read(),y = read();
        if(opt[0] == 'Q')
        {
            int xx = find(x);
            int d = ask_num(root[xx],y);
            printf("%d\n",d == -1 ? d : a[d]);
        }
        else
        {
            int a = find(x),b = find(y);
            if(a == b) continue;
            if(root[a] -> sz < root[b] -> sz) swap(a,b);
            fa[b] = a,merge(root[b],root[a]);
        }
    }
    return 0;
}
