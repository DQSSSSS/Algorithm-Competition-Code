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

pii p[SZ];

int head[SZ],nxt[SZ],tot = 1,to[SZ];

void build(int f,int t)
{
    to[++ tot] = t;
    nxt[tot] = head[f];
    head[f] = tot;
}

int dfs_clock = 0,dfn[SZ],low[SZ];
int sccnum[SZ],scccnt = 0;
stack<int> S;

void tarjan(int u)
{
    dfn[u] = low[u] = ++ dfs_clock;
    S.push(u);
    for(int i = head[u];i;i = nxt[i])
    {
        int v = to[i];
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(!sccnum[v])
        {
            low[u]= min(low[u],dfn[v]);
        }
    }
    if(low[u] == dfn[u])
    {
        scccnt ++;
        while(233)
        {
            int x = S.top(); S.pop();
            sccnum[x] = scccnt;
            if(x == u) break;
        }
    }
}


bool check()
{
    for(int i = 1;i <= m;i ++)
        for(int j = i + 1;j <= m;j ++)
        {
            if(p[i].x == p[j].x)
            {
                int d = abs(p[i].y - p[j].y) - 1;
                if(2 * r > d)
                {
                    build(i,j + m);
                    build(j,i + m);
                }
            }
            if(p[i].y == p[j].y)
            {
                int d = abs(p[i].x - p[j].x) - 1;
                if(2 * r > d)
                {
                    build(i + m,j);
                    build(j + m,i);
                }
            }
        }
    for(int i = 1;i <= 2 * m;i ++)
        if(!dfn[i])
            tarjan(i);
    for(int i = 1;i <= m;i ++)
        if(sccnum[i] == sccnum[i + m])
            return false;
    return true;
}

int main()
{
    n = read(),r = read(),m = read();
    for(int i = 1;i <= m;i ++)
        p[i].x = read(),p[i].y = read();
    puts(check() ? "YES" : "NO");
    return 0;
}
