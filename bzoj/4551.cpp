#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int SZ = 200010;
const int INF = 1e9 + 10;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar();  }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

vector<int> g[SZ];
int ans[SZ],f[SZ];
int fa[SZ],n,m,c[SZ];

void dfs(int u,int faa,int now)
{
    f[u] = faa;
    int nx = c[u] ? u : now;
    fa[u] = nx;
    for(int i = 0;i < g[u].size();i ++)
    {
        int v = g[u][i];
        if(v == faa) continue;
        dfs(v,u,nx);
    }
}
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

struct haha
{
    char s[3];
    int x;
}l[SZ];

int main()
{
    n = read(),m = read();
    for(int i = 1;i < n;i ++)
    {
        int x = read(),y = read();
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i = 1;i <= m;i ++)
    {
        scanf("%s%d",l[i].s,&l[i].x);
        if(l[i].s[0] == 'C') c[l[i].x] ++;
    }

    for(int i = 1;i <= n;i ++) fa[i] = i;
    dfs(1,1,1);
    //for(int i = 1;i <= n;i ++) cout << c[i] << endl;
    int tot = 0;
    for(int i = m;i >= 1;i --)
    {
        if(l[i].s[0] == 'C')
        {
            if(-- c[l[i].x]) continue;
            fa[l[i].x] = find(f[l[i].x]);
        }
        else ans[++ tot] = find(l[i].x);
    }
    for(int i = tot;i >= 1;i --) printf("%d\n",ans[i]);
    return 0;
}
