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

int lsh[SZ],a[SZ],n,m,q,rt[SZ];

struct seg
{
    int lc,rc;
    int sz;
}tree[SZ * 10];

int Segsz = 0;

int newnode()
{
    int k = ++ Segsz;
    tree[k].sz = tree[k].lc = tree[k].rc = 0;
    return k;
}

void insert(int l,int r,int x,int &y,int d)
{
    y = newnode();
    tree[y] = tree[x];  tree[y].sz ++;
    if(l == r) return ;
    int mid = l + r >> 1;
    if(d <= mid) insert(l,mid,tree[x].lc,tree[y].lc,d);
    else insert(mid + 1,r,tree[x].rc,tree[y].rc,d);
}

int ask(int x,int y,int d)
{
    int ans = 0,l = 1,r = m;
    while(l != r)
    {
    //    cout << l << " " << r << endl;
    //    cout << tree[x].sz << " " << tree[y].sz << endl;
        int mid = l + r >> 1;
        if(d <= mid)
            x = tree[x].lc,y = tree[y].lc,r = mid;
        else
            ans += tree[tree[y].lc].sz - tree[tree[x].lc].sz,
            x = tree[x].rc,y = tree[y].rc,l = mid + 1;
    }
    ans += tree[y].sz - tree[x].sz;
    return ans;
}

void init()
{
    Segsz = 0;
    for(int i = 0;i <= 100000;i ++) rt[i] = 0;
}

int L[SZ],R[SZ],X[SZ];

int main()
{
    int T = read();
    for(int cc = 1;cc <= T;cc ++)
    {
        init();
        n = read(),q = read();
        for(int i = 1;i <= n;i ++) lsh[i] = a[i] = read();
        for(int i = 1;i <= q;i ++)
        {
            L[i] = read() + 1,R[i] = read() + 1,X[i] = read();
            lsh[i + n] = X[i];
        }
        sort(lsh + 1,lsh + 1 + n + q);
        m = unique(lsh + 1,lsh + 1 + n + q) - lsh - 1;

        for(int i = 1;i <= n;i ++)
            a[i] = lower_bound(lsh + 1,lsh + 1 + m,a[i]) - lsh;
        for(int i = 1;i <= n;i ++)
            insert(1,m,rt[i - 1],rt[i],a[i]);

        //for(int i = 1;i <= n;i ++) printf("%d ",tree[rt[i]].sz); puts("");
        //for(int i = 1;i <= n;i ++) printf("%d ",a[i]); puts("");
        //for(int i = 1;i <= q;i ++) printf("%d ",X[i]); puts("");

        for(int i = 1;i <= q;i ++)
            X[i] = lower_bound(lsh + 1,lsh + 1 + m,X[i]) - lsh;
        printf("Case %d:\n",cc);
        for(int i = 1;i <= q;i ++)
            printf("%d\n",ask(rt[L[i] - 1],rt[R[i]],X[i]));
    }
    return 0;
}
