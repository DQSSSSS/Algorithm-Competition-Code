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
#define x first
#define y second
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 200010;
const LL INF = 1000000010;
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

int val[SZ],n,m;
LL mod;

struct segment
{
    int l,r;
    LL sum,d,c;
}tree[SZ * 4];

void update(int p)
{
    (tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum) %= mod;
}

void pushc(int p,LL c,LL d)
{
    LL len = (tree[p].r - tree[p].l + 1) % mod;
    tree[p].c = ((tree[p].c % mod) * c) % mod;
    tree[p].d = (c * (tree[p].d % mod) + d) % mod;
    tree[p].sum = (((tree[p].sum % mod) * c) % mod + d * len) % mod;
}

void pushdown(int p)
{
    int c = tree[p].c,d = tree[p].d;
    if(c != 1 || d)
        pushc(p << 1,c,d),pushc(p << 1 | 1,c,d),tree[p].c = 1,tree[p].d = 0;
}

void build(int p,int l,int r)
{
    tree[p].l = l; tree[p].r = r;
    tree[p].c = 1; tree[p].d = 0;
    if(l == r)
    {
        tree[p].sum = val[l] % mod;
        return ;
    }
    int mid = l + r >> 1;
    build(p << 1,l,mid); build(p << 1 | 1,mid + 1,r);
    update(p);
}

void change(int p,int l,int r,LL c,LL d)
{
    if(l <= tree[p].l && tree[p].r <= r)
    {
        pushc(p,c,d);
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p << 1,l,r,c,d);
    if(mid < r) change(p << 1 | 1,l,r,c,d);
    update(p);
}

LL ask_sum(int p,int l,int r)
{
    if(l <= tree[p].l && tree[p].r <= r)
        return tree[p].sum;
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    LL ans = 0;
    if(l <= mid) ans += ask_sum(p << 1,l,r);
    if(mid < r) ans += ask_sum(p << 1 | 1,l,r);
    return ans % mod;
}

int main()
{
    n = read(),mod = read();
    for(int i = 1;i <= n;i ++) val[i] = read();
    build(1,1,n);
    int m = read();
    while(m --)
    {
        int opt = read(),x = read(),y = read();
        LL d;
        if(opt == 1)
            d = read(),change(1,x,y,d,0);
        else if(opt == 2)
            d = read(),change(1,x,y,1,d);
        else
            printf("%lld\n",ask_sum(1,x,y));
    }
    return 0;
}
