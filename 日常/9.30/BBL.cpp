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
const int SZ = 2000010;
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

int n;

struct haha
{
    int x,y;
}p[SZ];

LL dis(haha a,haha b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}


struct edge
{
    int u,v;
    LL d;
}l[SZ];

bool cmp(edge a,edge b) { return a.d > b.d; }

int fa[SZ];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main()
{
    n = read();
    for(int i = 1;i <= n;i ++)
        p[i].x = read(),p[i].y = read();
    int tot = 0;
    for(int i = 1;i <= n;i ++)
        for(int j = i + 1;j <= n;j ++)
            l[++ tot] = (edge){i,j,dis(p[i],p[j])};
    sort(l + 1,l + 1 + tot,cmp);
    LL ans = INF;
    for(int i = 1;i <= n;i ++) fa[i] = i;
    for(int i = 1;i <= tot;i ++)
    {
        int u = find(l[i].u),v = find(l[i].v);
        if(u != v) fa[u] = v,ans = min(ans,l[i].d);
    }
    cout << ans << endl;
    return 0;
}
