#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 100010;
const int INF = 1e9 + 10;
const int mod = 31011;

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

int fa[SZ];
int find(int x) { return x == fa[x] ? x : find(fa[x]); }

struct edge
{
    int f,t,d;
}l[SZ];

bool cmp(edge a,edge b) { return a.d < b.d; }

int n,m,cnt[SZ];
pii fw[SZ];

int dfs(int pos,int r,int d)
{
    if(pos == r + 1)
    {
        if(d == 0) return 1;
        return 0;
    }
    int ans = 0;
    int x = find(l[pos].f),y = find(l[pos].t);
    if(x != y)
    {
        fa[x] = y;
        ans += dfs(pos + 1,r,d - 1);
        fa[x] = x; fa[y] = y;
    }
    ans += dfs(pos + 1,r,d);
    return ans;
}


int main()
{
    n = read(),m = read();
    for(int i = 1;i <= m;i ++)
        l[i].f = read(),l[i].t = read(),l[i].d = read();
    sort(l + 1,l + 1 + m,cmp);

    int tot = 0;
    for(int i = 1,j = 0;i <= m;i ++)
    {
        if(l[i].d != l[i - 1].d) j ++,fw[j].x = i,tot ++;
        fw[j].y = i;
    }

    int flag = 0;
    for(int i = 1;i <= n;i ++) fa[i] = i;
    for(int i = 1,j = 0;i <= m;i ++)
    {
        int x = find(l[i].f),y = find(l[i].t);
        if(l[i].d != l[i - 1].d) j ++;
        if(x != y) fa[x] = y,cnt[j] ++,flag ++;
    }
    if(flag != n - 1) { puts("0"); return 0; }

    int ans = 1;
    for(int i = 1;i <= n;i ++) fa[i] = i;
    for(int i = 1;i <= tot;i ++)
    {
        int tmp = dfs(fw[i].x,fw[i].y,cnt[i]);
        (ans *= tmp) %= mod;
        for(int j = fw[i].x;j <= fw[i].y;j ++)
        {
            int x = find(l[j].f),y = find(l[j].t);
            if(x != y) fa[x] = y;
        }
    }
    printf("%d\n",ans);
    return 0;
}
