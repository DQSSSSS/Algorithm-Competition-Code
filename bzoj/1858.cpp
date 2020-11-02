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

struct segment
{
    int l,r;
    int L[2],R[2],ans[2],sum;
    int c,rol;
}tree[SZ * 4];

int Len(int p) { return tree[p].r - tree[p].l + 1; }

void update(int p)
{
    tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
    tree[p].ans[0] = max(max(tree[p << 1].ans[0],tree[p << 1 | 1].ans[0]),tree[p << 1].R[0] + tree[p << 1 | 1].L[0]);
    tree[p].ans[1] = max(max(tree[p << 1].ans[1],tree[p << 1 | 1].ans[1]),tree[p << 1].R[1] + tree[p << 1 | 1].L[1]);

    if(tree[p << 1].sum == Len(p << 1)) tree[p].L[1] = Len(p << 1) + tree[p << 1 | 1].L[1];
    else tree[p].L[1] = tree[p << 1].L[1];
    if(tree[p << 1].sum == 0) tree[p].L[0] = Len(p << 1) + tree[p << 1 | 1].L[0];
    else tree[p].L[0] = tree[p << 1].L[0];

    if(tree[p << 1 | 1].sum == Len(p << 1 | 1)) tree[p].R[1] = Len(p << 1 | 1) + tree[p << 1].R[1];
    else tree[p].R[1] = tree[p << 1 | 1].R[1];
    if(tree[p << 1 | 1].sum == 0) tree[p].R[0] = Len(p << 1 | 1) + tree[p << 1].R[0];
    else tree[p].R[0] = tree[p << 1 | 1].R[0];
}

void pushc(int p,int d)
{
    tree[p].c = d;
    tree[p].L[d ^ 1] = tree[p].R[d ^ 1] = tree[p].ans[d ^ 1] = 0;
    tree[p].L[d] = tree[p].R[d] = tree[p].ans[d] = Len(p);
    tree[p].sum = d * Len(p);
    tree[p].rol = 0;
}

void pushrol(int p)
{
    swap(tree[p].ans[0],tree[p].ans[1]);
    swap(tree[p].L[0],tree[p].L[1]);
    swap(tree[p].R[0],tree[p].R[1]);
    tree[p].sum = Len(p) - tree[p].sum;
    tree[p].rol ^= 1;
}


void pushdown(int p)
{
    int c = tree[p].c,r = tree[p].rol;
    if(c != -1)
        pushc(p << 1,c),pushc(p << 1 | 1,c),tree[p].c = -1;
    if(r)
        pushrol(p << 1),pushrol(p << 1 | 1),tree[p].rol = 0;

}

void build(int p,int l,int r)
{
    tree[p].l = l; tree[p].r = r;
    tree[p].c = -1; tree[p].rol = 0;
    if(l == r)
    {
        int d = val[l];
        tree[p].L[d] = tree[p].R[d] = tree[p].ans[d] = 1,
        tree[p].L[d ^ 1] = tree[p].R[d ^ 1] = tree[p].ans[d ^ 1] = 0;
        tree[p].sum = d;
        return ;
    }
    int mid = l + r >> 1;
    build(p << 1,l,mid); build(p << 1 | 1,mid + 1,r);
    update(p);
}

void change(int p,int l,int r,int d)
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

void roller(int p,int l,int r)
{
    if(l <= tree[p].l && tree[p].r <= r)
    {
        pushrol(p);
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) roller(p << 1,l,r);
    if(mid < r) roller(p << 1 | 1,l,r);
    update(p);
}


int ask_sum(int p,int l,int r)
{
    if(l <= tree[p].l && tree[p].r <= r)
        return tree[p].sum;
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    int ans = 0;
    if(l <= mid) ans += ask_sum(p << 1,l,r);
    if(mid < r) ans += ask_sum(p << 1 | 1,l,r);
    return ans;
}

int ask_lx(int p,int l,int r)
{
    if(l <= tree[p].l && tree[p].r <= r)
        return tree[p].L[1];
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    int ans = 0;
    if(l <= mid && mid < r)
    {
        int lx = ask_lx(p << 1,l,mid);
        if(lx == mid - l + 1) ans = lx + ask_lx(p << 1 | 1,mid + 1,r);
        else ans = lx;
    }
    else if(l <= mid) ans = ask_lx(p << 1,l,r);
    else if(mid < r) ans = ask_lx(p << 1 | 1,l,r);
    return ans;
}

int ask_rx(int p,int l,int r)
{
    if(l <= tree[p].l && tree[p].r <= r)
        return tree[p].R[1];
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    int ans = 0;
    if(l <= mid && mid < r)
    {
        int rx = ask_rx(p << 1 | 1,mid + 1,r);
        if(rx == r - mid) ans = rx + ask_rx(p << 1,l,mid);
        else ans = rx;
    }
    else if(l <= mid) ans = ask_rx(p << 1,l,r);
    else if(mid < r) ans = ask_rx(p << 1 | 1,l,r);
    return ans;
}

int ask_ans(int p,int l,int r)
{
    if(l <= tree[p].l && tree[p].r <= r)
        return tree[p].ans[1];
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    int ans = 0;
    if(l <= mid && mid < r)
    {
        int tmp = max(ask_ans(p << 1,l,mid),ask_ans(p << 1 | 1,mid + 1,r));
        ans = max(tmp,ask_rx(p << 1,l,mid) + ask_lx(p << 1 | 1,mid + 1,r));
    }
    else if(l <= mid) ans = ask_ans(p << 1,l,r);
    else if(mid < r) ans = ask_ans(p << 1 | 1,l,r);
    return ans;
}

int main()
{
	//freopen("in.txt","r",stdin); freopen("1858.txt","w",stdout);
    n = read(),m = read();
    for(int i = 1;i <= n;i ++) val[i] = read();
    build(1,1,n);
    while(m --)
    {
        int opt = read(),x = read() + 1,y = read() + 1;
        if(opt == 0)
            change(1,x,y,0);
        else if(opt == 1)
            change(1,x,y,1);
        else if(opt == 2)
            roller(1,x,y);
        else if(opt == 3)
            printf("%d\n",ask_sum(1,x,y));
        else
            printf("%d\n",ask_ans(1,x,y));
    }
    return 0;
}
/*
7 8
1 1 1 1 1 1 0
2 1 4
1 2 6
3 0 6
4 2 5
3 0 1
2 0 6
2 0 1
4 3 5

*/
