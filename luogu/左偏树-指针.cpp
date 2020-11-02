#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const int INF = 1e9 + 10;


LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int n,m,use[SZ];

struct node
{
    node *lc,*rc;
    int id,dis;
    LL w;
    node(LL x,int i):w(x),id(i) { dis = 0; lc = rc = NULL; }
    int dist() { return this == NULL ? -1 : dis; }
}*rt[SZ];


node* merge(node *x,node *y)
{
    if(!y) return x;
    if(!x) return y;
    if(x -> w > y -> w || (x -> w == y -> w && x -> id > y -> id)) swap(x,y);
    x -> rc = merge(x -> rc,y);
    if(x -> rc -> dist() > x -> lc -> dist()) swap(x -> rc,x -> lc);
    x -> dis = x -> rc -> dist() + 1;
    return x;
}

void pop(node* &x)
{
    node *p = x;
    use[x -> id] = 1;
    x = merge(x -> lc,x -> rc);
    delete p;
}

int fa[SZ];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main()
{
    n = read(), m = read();
    for(int i = 1;i <= n;i ++)
        rt[i] = new node(read(),i),fa[i] = i;
    while(m --)
    {
        int opt = read(),x = read(),y;
        if(opt == 1)
        {
            y = read();
            if(use[x] || use[y]) continue;
            x = find(x),y = find(y);
            if(x != y)
                rt[x] = merge(rt[x],rt[y]),fa[y] = x;
        }
        else
        {
            if(use[x]) { puts("-1"); continue; }
            x = find(x);
            printf("%lld\n",rt[x] -> w);
            pop(rt[x]);
        }
    }
}

/*
5 5
1 5 4 2 3
1 1 5
1 2 5
2 2
1 4 2
2 2
*/
