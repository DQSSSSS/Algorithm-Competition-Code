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
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

LL val[SZ];
int n,m;

struct seg
{
    int l,r;
    LL maxx,add;
}tree[SZ << 2];

void update(int p)
{
    tree[p].maxx = max(tree[p << 1].maxx,tree[p << 1 | 1].maxx);
}

void pushc(int p,LL d)
{
    tree[p].add += d;
    tree[p].maxx += d;
}

void pushdown(int p)
{
    if(tree[p].add)
        pushc(p << 1,tree[p].add),pushc(p << 1 | 1,tree[p].add),tree[p].add = 0;
}

void build(int p,int l,int r)
{
    tree[p].l = l; tree[p].r = r;
    tree[p].add = 0;
    if(l == r)
    {
        tree[p].maxx = val[l];
        return ;
    }
    int mid = l + r >> 1;
    build(p << 1,l,mid); build(p << 1 | 1,mid + 1,r);
    update(p);
}

void change(int p,int l,int r,LL d)
{
    if(l <= tree[p].l && tree[p].r <= r)
    {
        pushc(p,d);
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p << 1,l,r,d);
    if(mid < r) change(p << 1 | 1,l,r,d);
    update(p);
}

int pos[SZ],nx[SZ],a[SZ],w[SZ],use[SZ];

int main()
{
    n = read(),m = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    for(int i = 1;i <= m;i ++) pos[i] = n + 1;
    for(int i = n;i >= 1;i --)
        nx[i] = pos[a[i]],pos[a[i]] = i;
    for(int i = 1;i <= m;i ++) w[i] = read();
    LL sum = 0;
    for(int i = 1;i <= n;i ++)
    {
        if(!use[a[i]]) sum += w[a[i]];
        else if(use[a[i]] == 1) sum -= w[a[i]];
        val[i] = sum;
        use[a[i]] ++;
    }
    build(1,1,n);
    LL ans = 0;
//    for(int i = 1;i <= n;i ++) printf("%lld ",val[i]); puts("");
    for(int i = 1;i <= n;i ++)
    {
        ans = max(ans,tree[1].maxx);
        int r1 = nx[i],r2 = nx[r1];
        change(1,i,r1 - 1,-w[a[i]]);
        if(r1 != n + 1) change(1,r1,r2 - 1,w[a[i]]);
    }
    printf("%lld\n",ans);
    return 0;
}
