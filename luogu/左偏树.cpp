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

struct Heap
{
    int lc,rc,w2,d;
    LL w1;
}tree[SZ];

int merge(int x,int y)
{
    if(!x || !y) return x + y;
    if(tree[x].w1 > tree[y].w1 || (tree[x].w1 == tree[y].w1 && tree[x].w2 > tree[y].w2)) swap(x,y);
    tree[x].rc = merge(tree[x].rc,y);
    if(tree[tree[x].rc].d > tree[tree[x].lc].d) swap(tree[x].rc,tree[x].lc);
    tree[x].d = tree[tree[x].rc].d + 1;
    return x;
}

int pop(int x)
{
    int l = tree[x].lc,r = tree[x].rc;
    tree[x].d = tree[x].lc = tree[x].rc = 0;
    return merge(l,r);
}

int fa[SZ];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main()
{
    n = read(), m = read();
    tree[0].lc = tree[0].rc = tree[0].w1 = tree[0].w2 = 0;
    tree[0].d = -1;
    for(int i = 1;i <= n;i ++)
    {
        tree[i].w1 = read(); tree[i].w2 = fa[i] = i;
        tree[i].d = tree[i].lc = tree[i].rc = 0;
    }
    while(m --)
    {
        int opt = read(),x = read(),y;
        if(opt == 1)
        {
            y = read();
            if(use[x] || use[y]) continue;
            x = find(x),y = find(y);
            int xx;
            if(x != y)
                xx = merge(x,y),fa[y] = fa[x] = xx;
        }
        else
        {
            if(use[x]) { puts("-1"); continue; }
            x = find(x);
            use[tree[x].w2] = 1;
            printf("%lld\n",tree[x].w1);
            tree[x] = tree[pop(x)];
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
