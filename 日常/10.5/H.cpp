#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<ctime>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
const int SZ = 1000010;
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

int n,m;

int head[SZ],nxt[SZ << 1],tot = 1,val[SZ];

struct edge
{
    int f,t,d;
}l[SZ << 1],E[8000010];

bool cmp(edge a,edge b) { return a.d < b.d; }


void build(int f,int t,int d)
{
    l[++ tot] = (edge){f,t,d};
    nxt[tot] = head[f];
    head[f] = tot;
}

int anc[SZ][23],amin[SZ][23],deep[SZ],vis[SZ];

void dfs(int u,int fa,int c)
{
    deep[u] = deep[fa] + 1;
    anc[u][0] = fa;
    vis[u] = c;
//    cout << u / n +1 << " " << (u-1) % n+1  << endl;
    for(int i = 1;anc[u][i - 1];i ++)
    {
        anc[u][i] = anc[anc[u][i - 1]][i - 1];
        amin[u][i] = min(amin[u][i - 1],amin[anc[u][i - 1]][i - 1]);
    }
    for(int i = head[u];i;i = nxt[i])
    {
        int v = l[i].t;
        if(v == fa) continue;
        amin[v][0] = l[i].d;
        dfs(v,u,c);
    }
}

int ask(int u,int v)
{
    int ans = min(val[u],val[v]);
    if(deep[u] < deep[v]) swap(u,v);
    if(deep[u] > deep[v])
    {
        int dd = deep[u] - deep[v];
        for(int i = 0;i <= 21;i ++)
            if(dd & (1 << i))
                ans = min(ans,amin[u][i]),u = anc[u][i];
    }
    if(u != v)
    {
        for(int i = 21;i >= 0;i --)
            if(anc[u][i] != anc[v][i])
                ans = min(ans,min(amin[u][i],amin[v][i])),
                u = anc[u][i],v = anc[v][i];
        return min(ans,min(amin[u][0],amin[v][0]));
    }
    return ans;
}

int getid(int i,int j)
{
    return (i - 1) * n + j;
}

int sum[1010][1010];
char maps[1010][1010];

int fa[SZ];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

bool check(int x,int y,int d)
{
    int m1 = min(x - 1,n - x);
    int m2 = min(y - 1,n - y);
    if(d > min(m1,m2)) return 0;
    return sum[x+d][y+d] - sum[x-d-1][y+d] - sum[x+d][y-d-1] + sum[x-d-1][y-d-1] == 0;
}

int Div(int x,int y)
{
    int l = 0,r = n + 1;
    while(r - l > 1)
    {
        int mid = l + r >> 1;
        if(check(x,y,mid)) l = mid;
        else r = mid;
    }
    return l;
}

int main()
{
    n = read();
    m = n;
    for(int i = 1;i <= n;i ++)
        scanf("%s",maps[i] + 1);
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++)
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (maps[i][j] == '#');

//    cout << check(2,2,1)<<endl;

    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++)
        {
            int u = getid(i,j);
            if(maps[i][j] == '#') val[u] = 0;
            else val[u] = Div(i,j) * 2 + 1;
        }

/*        for(int i = 1;i <= n;i ++,puts(""))
            for(int j = 1;j <= n;j ++)
                printf("%d ",val[getid(i,j)]);
                puts("");
        for(int i = 1;i <= n;i ++,puts(""))
            for(int j = 1;j <= n;j ++)
                printf("%d ",sum[i][j]);
*/
    int totm = 0;
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++)
        {
            if(maps[i][j] == '#') continue;
            for(int k = 0;k < 2;k ++)
            {
                int x = i + Dx[k];
                int y = j + Dy[k];
                int u = getid(i,j),v = getid(x,y),d = min(val[u],val[v]);
                if(x >= 1 && x <= n && y >= 1 && y <= n && maps[x][y] != '#')
                    E[++ totm] = (edge){u,v,d};
    //                cout << i <<" " <<  j << endl  << x << " " << y << " " << d << endl;
            }
        }

    sort(E + 1,E + 1 + totm,cmp);
    for(int i = 1;i <= n * n;i ++) fa[i] = i;
    for(int i = totm;i >= 1;i --)
    {
        int x = find(E[i].f),y = find(E[i].t);
        if(x != y)
            fa[x] = y,build(E[i].f,E[i].t,E[i].d),build(E[i].t,E[i].f,E[i].d);
    }

    for(int u = 1,cnt = 0;u <= n * n;u ++)
        if(!vis[u] && val[u])
            dfs(u,0,++ cnt);
    int q = read();
    while(q --)
    {
        int sx = read(),sy = read();
        int ex = read(),ey = read();
        int s = getid(sx,sy);
        int e = getid(ex,ey);
        if(s == e) printf("%d\n",val[s]);
        else if(vis[s] != vis[e]) puts("0");
        else printf("%d\n",ask(s,e));
    }
    return 0;
}
/*
7
.....#.
....#..
...#...
#......
...#...
....#..
.....#.
5
2 2 3 2

3
...
...
...
233
1

*/
