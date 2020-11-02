#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int SZ = 1000010;
const int INF = 1000000010;

struct node{
    node *f,*ch[2];
    int v,sz,cnt,sum,lx,rx,mx;
    bool same,rev;

    void setc(node *x,int d) { (ch[d] = x) -> f = this; }
    int dir() { return f -> ch[1] == this; }
    void pushdown();
    void maintain()
    {
        sz = ch[0] -> sz + ch[1] -> sz + cnt;
        sum = ch[0] -> sum + ch[1] -> sum + v;
        lx = max(ch[0] -> lx,ch[0] -> sum + v + max(ch[1] -> lx,0));
        rx = max(ch[1] -> rx,ch[1] -> sum + v + max(ch[0] -> rx,0));
        mx = max(max(ch[0] -> mx,ch[1] -> mx),max(ch[0] -> rx,0) + v + max(ch[1] -> lx,0));
    }
}T[SZ], *root, *null;

int sa[SZ],Tcnt1 = 0,Tcnt2 = 0;

int num[SZ];

node* newnode(int v,node *f)
{
    int cnt;
    if(Tcnt2) cnt = sa[Tcnt2 --];
    else cnt = Tcnt1++;
    node *k = T + cnt;
    k -> ch[0] = k -> ch[1] = null;
    k -> f = f;
    k -> v = k -> sum = k -> lx = k -> rx = k -> mx = v;
    k -> sz = k -> cnt = 1;
    k -> same = k -> rev = 0;
    return k;
}

void pushdrev(node *p)
{
    if(p == null) return ;
    swap(p -> ch[0],p -> ch[1]);
    swap(p -> lx,p -> rx);
    p -> rev ^= 1;
}

void pushdsame(node *p,int v)
{
    if(p == null) return ;
    p -> same = 1;
    p -> sum = v * p -> sz;
    p -> v = v;
    p -> mx = p -> lx = p -> rx = max(v,p -> sum);
}

void node::pushdown()
{
    if(this == null) return ;
    if(rev)
    {
        pushdrev(ch[0]);
        pushdrev(ch[1]);
        rev = 0;
    }
    if(same)
    {
        pushdsame(ch[0],v);
        pushdsame(ch[1],v);
        same = 0;
    }
}

void rotate(node *p)
{
    node *fa = p -> f;
    int d = p -> dir();
    fa -> f -> setc(p,fa -> dir());
    fa -> setc(p -> ch[d ^ 1],d); fa -> maintain();
    p -> setc(fa,d ^ 1); p -> maintain();
    if(fa == root) root = p;
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
            if(p -> dir() == p -> f -> dir()) rotate(p -> f),rotate(p);
            else rotate(p),rotate(p);
        }
    }
    p -> maintain();
}

node* find(node *p,int k)
{
    while(p != null)
    {
        p -> pushdown();
        int l = p -> ch[0] -> sz + 1;
        int r = p -> ch[0] -> sz + p -> cnt;
        if(l <= k && k <= r) return p;
        if(k > r) k -= r,p = p -> ch[1];
        else p = p -> ch[0];
    }
}

void build(node* &p,int l,int r,node *fa)
{
    if(l > r) return ;
    int mid = (l + r) >> 1;
    p = newnode(num[mid],fa);
    build(p -> ch[0],l,mid - 1,p);
    build(p -> ch[1],mid + 1,r,p);
    p -> maintain();
}

void insert(int pos,int tot)
{
    pos ++;
    for(int i = 1;i <= tot;++ i) scanf("%d",&num[i]);
    splay(find(root,pos)); splay(find(root,pos + 1),root);
    build(root -> ch[1] -> ch[0],1,tot,root -> ch[1]);
    root -> ch[1] -> maintain();
    root -> maintain();
}

void dfs(node *p)
{
    if(p == null) return ;
    sa[++ Tcnt2] = p - T;
    dfs(p -> ch[0]);
    dfs(p -> ch[1]);
}

void erase(int l,int r)
{
    l ++,r ++;
    splay(find(root,l - 1));    splay(find(root,r + 1),root);
    dfs(root -> ch[1] -> ch[0]);
    root -> ch[1] -> ch[0] = null;
    root -> ch[1] -> maintain();
    root -> maintain();
}

void change(int l,int r,int v)
{
    l ++,r ++;
    splay(find(root,l - 1));    splay(find(root,r + 1),root);
    pushdsame(root -> ch[1] -> ch[0],v);
    root -> ch[1] -> maintain();
    root -> maintain();
}

void reverse(int l,int r)
{
    l ++,r ++;
    splay(find(root,l - 1));    splay(find(root,r + 1),root);
    pushdrev(root -> ch[1] -> ch[0]);
    root -> ch[1] -> maintain();
    root -> maintain();
}

int ask_sum(int l,int r)
{
    l ++,r ++;
    splay(find(root,l - 1));    splay(find(root,r + 1),root);
    return root -> ch[1] -> ch[0] -> sum;
}


int ask_ans(int l,int r)
{
    l ++,r ++;
    splay(find(root,l - 1));    splay(find(root,r + 1),root);
    return root -> ch[1] -> ch[0] -> mx;
}

void init()
{
    null = newnode(-INF,null);
    null -> cnt = null -> sz = 0;

    root = newnode(-INF,null);
    root -> ch[1] = newnode(-INF,root);
    root -> sum = null -> sum = root -> ch[1] -> sum = 0;
    root -> maintain();
}

int main() {
    int m = read();
    init();
    while(m --) {
        int opt = read();
        if(opt == 1) {
            int x = read();

        }
        if(in[2] == 'S')
        {
            int pos,tot;
            scanf("%d%d",&pos,&tot);
            insert(pos,tot);
        }
        else if(in[2] == 'L')
        {
            int pos,tot;
            scanf("%d%d",&pos,&tot);
            int l = pos,r = pos + tot - 1;
            erase(l,r);
        }
        else if(in[2] == 'K')
        {
            int pos,tot,c;
            scanf("%d%d%d",&pos,&tot,&c);
            int l = pos,r = pos + tot - 1;
            change(l,r,c);
        }
        else if(in[2] == 'V')
        {
            int pos,tot;
            scanf("%d%d",&pos,&tot);
            int l = pos,r = pos + tot - 1;
            reverse(l,r);
        }
        else if(in[2] == 'T')
        {
            int pos,tot;
            scanf("%d%d",&pos,&tot);
            int l = pos,r = pos + tot - 1;
            printf("%d\n",ask_sum(l,r));
        }
        else
        {
            printf("%d\n",ask_ans(1,root -> sz  - 2));
        }
    }
    return 0;
}
