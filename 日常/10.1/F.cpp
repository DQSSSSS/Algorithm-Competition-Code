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
const int SZ = 200010;
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

struct segment
{
    int l,r;
    int d,q,minn,maxn,add;
    bool cd;
}tree[SZ * 4]; //0 : d  1 : q

void update(int p)
{
    tree[p].maxn = max(tree[p << 1].maxn,tree[p << 1 | 1].maxn);
    tree[p].minn = min(tree[p << 1].minn,tree[p << 1 | 1].minn);
}

void pushdown(int p)
{
    if(tree[p].cd)
    {
        tree[p << 1].maxn = tree[p << 1].minn = 0;
        tree[p << 1 | 1].maxn = tree[p << 1 | 1].minn = 0;
        tree[p << 1 | 1].add = tree[p << 1].add = 0;
        tree[p << 1].cd = tree[p << 1 | 1].cd = 1;
        tree[p].cd = 0;
    }

    int d = tree[p].d,q = tree[p].q;
    tree[p << 1].d = max(d,tree[p << 1].d);
    tree[p << 1].q = max(q,tree[p << 1].q);
    tree[p << 1 | 1].d = max(d,tree[p << 1 | 1].d);
    tree[p << 1 | 1].q = max(q,tree[p << 1 | 1].q);

    if(tree[p].add)
    {
        int d = tree[p].add;
        tree[p << 1].add += d;
        tree[p << 1].maxn += d;
        tree[p << 1].minn += d;
        tree[p << 1 | 1].add += d;
        tree[p << 1 | 1].maxn += d;
        tree[p << 1 | 1].minn += d;
        tree[p].add = 0;
    }

}

void build(int p,int l,int r)
{
    tree[p].l = l; tree[p].r = r;
    tree[p].maxn = tree[p].minn = 0;
    tree[p].d = tree[p].q = 0;
    if(l == r) return ;
    int mid = l + r >> 1;
    build(p << 1,l,mid); build(p << 1 | 1,mid + 1,r);
    update(p);
}

void change(int p,int l,int r,int d)
{
    if(l <= tree[p].l && tree[p].r <= r)
    {
        if(tree[p].maxn == 0)
        {
        //    cout << tree[p].l << " " << tree[p].r << " " << tree[p].d << endl;
            tree[p].d = max(tree[p].d,d);
            return ;
        }
        if(tree[p].minn)
        {
            tree[p].q = max(tree[p].q,d);
            return ;
        }
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p << 1,l,r,d);
    if(mid < r) change(p << 1 | 1,l,r,d);
    update(p);
}

void add(int p,int l,int r,int d)
{
    if(l <= tree[p].l && tree[p].r <= r)
    {
        tree[p].maxn += d; tree[p].minn += d;
        tree[p].add += d;
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) add(p << 1,l,r,d);
    if(mid < r) add(p << 1 | 1,l,r,d);
    update(p);
}

void changed(int p,int l,int r,int d)
{
    if(l <= tree[p].l && tree[p].r <= r)
    {
        tree[p].maxn = tree[p].minn = d;
        tree[p].cd = 1;
        tree[p].add = 0;
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) changed(p << 1,l,r,d);
    if(mid < r) changed(p << 1 | 1,l,r,d);
    update(p);
}

int askd(int p,int x)
{
    if(x == tree[p].l && tree[p].r == x)
        return tree[p].d;
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1,ans;
    if(x <= mid) ans = askd(p << 1,x);
    else ans = askd(p << 1 | 1,x);
    return ans;
}

int askq(int p,int x)
{
    if(x == tree[p].l && tree[p].r == x)
        return tree[p].q;
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1,ans;
    if(x <= mid) ans = askq(p << 1,x);
    else ans = askq(p << 1 | 1,x);
    return ans;
}

/***********************/
int askmaxn(int p,int x)
{
    if(x == tree[p].l && tree[p].r == x)
        return tree[p].maxn;
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1,ans;
    if(x <= mid) ans = askmaxn(p << 1,x);
    else ans = askmaxn(p << 1 | 1,x);
    return ans;
}


int askminn(int p,int x)
{
    if(x == tree[p].l && tree[p].r == x)
        return tree[p].minn;
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1,ans;
    if(x <= mid) ans = askminn(p << 1,x);
    else ans = askminn(p << 1 | 1,x);
    return ans;
}
/**********************/

struct haha
{
    int l,r,c,id;
}q[SZ];

bool cmp1(haha a,haha b) { return a.c != b.c ? a.c < b.c : a.id < b.id; }

int dd[SZ],qq[SZ];

int main()
{
    int T = read();
    while(T --)
    {
        memset(tree,0,sizeof(tree));

        int n = read(),m = read();
        build(1,1,n);
        for(int i = 1;i <= m;i ++)
        {
            int pos = read(),c = read(),d = read();
            int l = max(pos - d,1),r = min(pos + d,n);
            q[i].l = l,q[i].r = r,q[i].c = c,q[i].id = i;
        }
        sort(q + 1,q + 1 + m,cmp1);

        for(int i = 1;i <= m;i ++)
        {
            int l = q[i].l,r = q[i].r;
            if(q[i].c == q[i - 1].c)
            {
                change(1,l,r,q[i].id);
                add(1,l,r,1);
            }
            else
            {
                changed(1,1,n,0);
                change(1,l,r,q[i].id);
                add(1,l,r,1);
            }
        /*    {
                puts("");
                printf("maxn : "); for(int i = 1;i <= n;i ++) cout << askmaxn(1,i) << " "; puts("");
                printf("minn : "); for(int i = 1;i <= n;i ++) cout << askminn(1,i) << " "; puts("");
                printf("d    : "); for(int i = 1;i <= n;i ++) cout << askd(1,i) << " "; puts("");
                printf("q    : "); for(int i = 1;i <= n;i ++) cout << askq(1,i) << " "; puts("");
            }*/
        }

        int ans = 0;
        for(int j = 1;j <= n;j ++) dd[j] = askd(1,j);
        for(int j = 1;j <= n;j ++) qq[j] = askq(1,j);
    //    for(int i = 1;i <= n;i ++) cout << askd(1,i) << " "; puts("");
    //    for(int i = 1;i <= n;i ++) cout << askq(1,i) << " "; puts("");
        for(int i = 1;i <= n;i ++)
            if(dd[i] <= qq[i])
                ans ++;
        printf("%d\n",ans);
    }
    return 0;
}
/*
1
5 4
1 3 0
2 1 1
5 0 4
3 2 1
*/
