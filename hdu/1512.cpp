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

struct Heap
{
    int lc,rc,w,d,fa;
}tree[SZ];

int merge(int x,int y)
{
    if(!x || !y) return x + y;
    if(tree[x].w < tree[y].w) swap(x,y);
    tree[x].rc = merge(tree[x].rc,y);
    tree[tree[x].rc].fa = x;
    if(tree[tree[x].lc].d < tree[tree[x].rc].d) swap(tree[x].lc,tree[x].rc);
    tree[x].d = tree[tree[x].rc].d + 1;
    return x;
}

int pop(int x)
{
    int l = tree[x].lc,r = tree[x].rc;
    tree[l].fa = l; tree[r].fa = r;
    tree[x].lc = tree[x].rc = tree[x].d = 0;
    return merge(l,r);
}

int fa[SZ],n;

int find(int x) { return x == tree[x].fa ? x : tree[x].fa = find(tree[x].fa); }

int main()
{
    while(~scanf("%d",&n))
    {
        tree[0].lc = tree[0].rc = 0;
        tree[0].w = 0; tree[0].d = -1;
        for(int i = 1;i <= n;i ++)
        {
            tree[i].d = tree[i].lc = tree[i].rc = 0;
            tree[i].fa = i; tree[i].w = read();
        }
        int m = read();
        while(m --)
        {
            int a = read(),b = read();
            int x = find(a),y = find(b);
            if(x == y) puts("-1");
            else
            {
                fa[x] = y;
                tree[x].w /= 2;
                int xx = pop(x);
                xx = merge(xx,x);

                tree[y].w /= 2;
                int yy = pop(y);
                yy = merge(yy,y);
                printf("%d\n",tree[merge(xx,yy)].w);
            }
        }
    }
    return 0;
}
