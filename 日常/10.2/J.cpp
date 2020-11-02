#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<bitset>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
const int SZ = 4000010;
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
    int sum;
    bool cd,c;
}tree[SZ * 4]; //0 : d  1 : q

void update(int p)
{
    tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
}

void pushdown(int p)
{
    if(tree[p].cd)
    {
        tree[p << 1].sum = tree[p << 1].c = 0;
        tree[p << 1 | 1].sum = tree[p << 1 | 1].c = 0;
        tree[p << 1].cd = tree[p << 1 | 1].cd = 1;
        tree[p].cd = 0;
    }
    if(tree[p].c)
    {
        tree[p << 1].sum = tree[p << 1].r - tree[p << 1].l + 1 - tree[p << 1].sum;
        tree[p << 1 | 1].sum = tree[p << 1 | 1].r - tree[p << 1 | 1].l + 1 - tree[p << 1 | 1].sum;
        tree[p << 1].c ^= 1;
        tree[p << 1 | 1].c ^= 1;
        tree[p].c = 0;
    }
}

void build(int p,int l,int r)
{
    tree[p].l = l; tree[p].r = r;
    tree[p].sum = tree[p].cd = tree[p].c = 0;
    if(l == r) return ;
    int mid = l + r >> 1;
    build(p << 1,l,mid); build(p << 1 | 1,mid + 1,r);
    update(p);
}

void changexor(int p,int l,int r)
{
    if(l <= tree[p].l && tree[p].r <= r)
    {
        tree[p].c ^= 1;
        tree[p].sum = tree[p].r - tree[p].l + 1 - tree[p].sum;
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) changexor(p << 1,l,r);
    if(mid < r) changexor(p << 1 | 1,l,r);
    update(p);
}

void changed(int p,int l,int r)
{
    if(l <= tree[p].l && tree[p].r <= r)
    {
        tree[p].sum = tree[p].c = 0;
        tree[p].cd = 1;
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) changed(p << 1,l,r);
    if(mid < r) changed(p << 1 | 1,l,r);
    update(p);
}



struct haha
{
    int x,y,id;
}l[SZ];

int tot = 0,n;

bool cmp(haha a,haha b) { return a.id < b.id; }

int main()
{
    freopen("J.in","r",stdin);
    n = read();
    int m = read();
    while(m --)
    {
        int x = read(),y = read(),r = read(),opt = read();
        if(opt == 0)
        {
            x ++;
            for(int i = x;i <= min(n,x + r - 1);i ++)
            {
                int d = r - (i - x);
                int l = max(1,y - d + 1),r = y;
        //        cout << l << " " <<r << " " << i <<endl;
                ::l[++ tot] = (haha){l,r,i};
            }
        }
        else if(opt == 1)
        {
            x ++; y ++;
            for(int i = x;i <= min(n,x + r - 1);i ++)
            {
                int d = r - (i - x);
                int l = y,r = min(n,y + d - 1);
                ::l[++ tot] = (haha){l,r,i};
            }
        }
        else if(opt == 2)
        {
            y ++;
            for(int i = x;i >= max(x - r + 1,1);i --)
            {
                int d = r - (x - i);
                int l = y,r = min(n,y + d - 1);
                ::l[++ tot] = (haha){l,r,i};
            }
        }
        else if(opt == 3)
        {
            for(int i = x;i >= max(x - r + 1,1);i --)
            {
                int d = r - (x - i);
                int l = max(1,y - d + 1),r = y;
                ::l[++ tot] = (haha){l,r,i};
            }
        }
    }
    build(1,1,n);
    sort(l + 1,l + 1 + tot,cmp);
    LL ans = 0;
    for(int i = 1;i <= tot;i ++)
    {
        if(l[i].id != l[i - 1].id)
        {
            ans += tree[1].sum;
            changed(1,1,n);
            changexor(1,l[i].x,l[i].y);
        }
        else
        {
            changexor(1,l[i].x,l[i].y);
        }
    //    cout << l[i].id << " " << l[i].x << " " <<l[i].y << " ";
    //    cout << tree[1].sum << endl;
    }
    ans += tree[1].sum;
    printf("%d\n",ans);
    return 0;
}
/*



*/
