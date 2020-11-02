#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

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

int n,m;

struct edge
{
    int f,t,d;
}l[SZ];

bool cmp(edge a,edge b) { return a.d < b.d; }

int fa[SZ];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main()
{
    n = read();m = read();
    for(int i = 1;i <= m;i ++) l[i].f = read(),l[i].t = read(),l[i].d = read();
    sort(l + 1,l + 1 + m,cmp);
    for(int i = 1;i <= n;i ++) fa[i] = i;
    int ans = 0;
    for(int i = 1;i <= m;i ++)
    {
        int x = find(l[i].f),y = find(l[i].t);
        if(x != y)
            ans = max(ans,l[i].d),fa[x] = y;
    }
    printf("%d %d\n",n - 1,ans);
    return 0;
}
