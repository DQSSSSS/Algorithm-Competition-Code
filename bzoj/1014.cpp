#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
const int SZ = 2000010;
const LL INF = 1000000010;
const LL mod = 1000000007;

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

ULL mi[SZ];
char s[SZ];

struct node
{
    node *ch[2],*f;
    ULL v,sum,c;
    int sz;
    void maintain()
    {
        sz = ch[0] -> sz + ch[1] -> sz + 1;
        sum = ch[0] -> sum + v + ch[1] -> sum;
    }

    int dir() { return f -> ch[1] == this; }
    void setc(node *x,int d) { (ch[d] = x) -> f = this; }
    void pushdown();

}T[SZ], *root, *null;

int Tcnt = 0;

node* newnode(ULL x,node *fa)
{
    node *k = T + Tcnt ++;
    k -> ch[0] = k -> ch[1] = null;
    k -> f = fa;
    k -> v = k -> sum = x;
    k -> c = 1;
    k -> sz = 1;
    return k;
}

void pushc(node *p,ULL d)
{
    if(p == null) return ;
    p -> v *= d;
    p -> sum *= d;
    p -> c *= d;
}

void node :: pushdown()
{
    if(c != 1)
        pushc(ch[0],c),pushc(ch[1],c),c = 1;
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

node* find(int k)
{
    node *p = root;
    while(p != null)
    {
        p -> pushdown();
        int l = p -> ch[0] -> sz;
        if(k == l + 1) return p;
        if(k > l + 1) k -= l + 1,p = p -> ch[1];
        else p = p -> ch[0];
    }
}

void build(node* &p,int l,int r,node *fa)
{
    if(l > r) return ;
    int mid = l + r >> 1;
    p = newnode((s[mid] - 'a' + 1) * mi[mid],fa);
    build(p -> ch[0],l,mid - 1,p);
    build(p -> ch[1],mid + 1,r,p);
    p -> maintain();
}

void change(int pos,ULL d)
{
    pos ++;
    node *p = find(pos);
    splay(p);
    p -> pushdown();
    p -> v = d;
    p -> maintain();
}

void insert(int pos,ULL d)
{
    pos ++;
    splay(find(pos));
    splay(find(pos + 1),root);
    root -> ch[1] -> ch[0] = newnode(d,root -> ch[1]);
    root -> ch[1] -> maintain();
    root -> maintain();
    splay(root -> ch[1] -> ch[0]);
    pushc(root -> ch[1],1331);
}

ULL ask_sum(int l,int r)
{
    l ++; r ++;
    splay(find(l - 1)); splay(find(r + 1),root);
    return root -> ch[1] -> ch[0] -> sum;
}

int len;
bool check(int len,int x,int y)
{
    if(y + len - 1 > root -> sz - 2) return false;
    return ask_sum(x,x + len - 1) * mi[y - x] == ask_sum(y,y + len - 1);
}

int ask(int x,int y)
{
    int l = 0,r = root -> sz - 1;
    if(x > y) swap(x,y);
    while(r - l > 1)
    {
        int mid = l + r >> 1;
        if(check(mid,x,y)) l = mid;
        else r = mid;
    }
    return l;
}


void init()
{
    null = newnode(0,null);
    null -> sz = 0;

    root = newnode(0,null);
    root -> ch[1] = newnode(0,root);
    scanf("%s",s + 1);
    len = strlen(s + 1);
    build(root -> ch[1] -> ch[0],1,len,root -> ch[1]);
    root -> ch[1] -> maintain();
    root -> maintain();
}

int main()
{
    mi[0] = 1;
    for(int i = 1;i <= 200000;i ++) mi[i] = mi[i - 1] * 1331;
    init();

    int q = read();
    while(q --)
    {
        char s[10],c[10];
        int x,y;
        scanf("%s",s);
        if(s[0] == 'Q')
            x = read(),y = read(),printf("%d\n",ask(x,y));
        else if(s[0] == 'R')
            x = read(),scanf("%s",c),change(x,(c[0] - 'a' + 1) * mi[x]);
        else
            x = read(),scanf("%s",c),insert(x,(c[0] - 'a' + 1) * mi[x + 1]);
    }
    return 0;
}

/*
madamimadam
7
Q 1 7
Q 4 8
Q 10 11
R 3 a
Q 1 7
I 10 a
Q 2 11
*/
