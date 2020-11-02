#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<ctime>
#include<bitset>
#define x first
#define y second
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 500010;
const LL INF = 1000000010;
const LL mod = 1000000007;
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

int n,m,r;

int head[SZ],nxt[SZ],tot = 1;

struct edge
{
    int t,d;
}l[SZ];

void build(int f,int t,int d)
{
    if(f > t) cout << t << " " << f << " " << d << endl;
    l[++ tot] = (edge){t,d};
    nxt[tot] = head[f];
    head[f] = tot;
}

int c[SZ];
bool vis[SZ];

void dfs_clear(int u,int fa)
{
    if(vis[u]) return ;
    c[u] = -1;
    for(int i = head[u];i;i = nxt[i])
    {
        int v = l[i].t;
        if(v == fa) continue;
        dfs_clear(v,u);
    }
}

bool dfs(int u,int fa,int col)
{
    c[u] = col;
    cout << u << " " << col << endl;
    vis[u] = 1;
    for(int i = head[u];i;i = nxt[i])
    {
        int v = l[i].t;
        if(v == fa) continue;
        if(c[v] != -1)
        {
            if(c[v] == c[u] && c[v] == l[i].d)
                { vis[u] = 0; return false; }
        }
        else
        {
            if(c[u] == l[i].d)
            {
                if(!dfs(v,u,l[i].d ^ 1)) { vis[u] = 0; return false; }
            }
            else
            {
                if(!dfs(v,u,l[i].d ^ 1))
                {
                    dfs_clear(v,u);
                    if(!dfs(v,u,l[i].d))
                        { vis[u] = 0; return false; }
                }
            }
        }
    }
    vis[u] = 0;
    return true;
}

pii p[SZ];

int main()
{
    n = read(),r = read(),m = read();
    for(int i = 1;i <= m;i ++)
        p[i].x = read(),p[i].y = read();
    for(int i = 1;i <= m;i ++)
        for(int j = i + 1;j <= m;j ++)
        {
            if(p[i].x == p[j].x)
            {
                int d = abs(p[i].y - p[j].y) - 1;
                if(2 * r > d)
                    build(i,j,1),build(j,i,1);
            }
            if(p[i].y == p[j].y)
            {
                int d = abs(p[i].x - p[j].x) - 1;
                if(2 * r > d)
                    build(i,j,0),build(j,i,0);
            }
        }
    memset(c,-1,sizeof(c));
    for(int i = 1;i <= n;i ++)
        if(c[i] == -1 && !dfs(i,0,0))
        {
            dfs_clear(i,0);
            if(!dfs(i,0,1))
            {
                puts("NO");
                return 0;
            }
        }
    puts("YES");
    return 0;
}
