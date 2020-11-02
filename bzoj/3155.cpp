#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 100010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

struct segment
{
    int l,r;
    LL sum,add;
}tree[SZ << 2];

int n,m,a[SZ];
LL sum[SZ];

void update(int p)
{
    tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
}

void pushc(int p,LL d)
{
    tree[p].add += d;
    tree[p].sum += d * (tree[p].r - tree[p].l + 1);
}

void pushdown(int p)
{
    if(tree[p].add)
        pushc(p << 1,tree[p].add),
        pushc(p << 1 | 1,tree[p].add),
        tree[p].add = 0;
}

void build(int p,int l,int r)
{
    tree[p].l = l; tree[p].r = r;
    if(l == r)
    {
        tree[p].sum = sum[l];
        tree[p].add = 0;
        return ;
    }
    int mid = l + r >> 1;
    build(p << 1,l,mid); build(p << 1 | 1,mid + 1,r);
    update(p);
}

LL ask(int p,int l,int r)
{
    if(l <= tree[p].l && tree[p].r <= r)
        return tree[p].sum;
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    LL ans = 0;
    if(l <= mid) ans += ask(p << 1,l,r);
    if(mid < r) ans += ask(p << 1 | 1,l,r);
    return ans;
}

void change(int p,int l,int r,LL d)
{
    if(l <= tree[p].l && tree[p].r <= r)
        { pushc(p,d); return ; }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p << 1,l,r,d);
    if(mid < r) change(p << 1 | 1,l,r,d);
    update(p);
}

int main()
{
    n = read(),m = read();
    for(int i = 1;i <= n;i ++) a[i] = read(),sum[i] = sum[i - 1] + a[i];
    build(1,1,n);
    while(m --)
    {
        char opt[10];
        scanf("%s",opt);
        int x = read();
        LL y;
        if(opt[0] == 'Q') printf("%lld\n",ask(1,1,x));
        else y = read(),change(1,x,n,y - a[x]),a[x] = y;
    }
    return 0;
}
