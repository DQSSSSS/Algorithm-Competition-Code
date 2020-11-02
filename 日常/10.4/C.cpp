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

struct point
{
    LL x,y;
    void print() { cout << x << " " << y << endl; }
}p[SZ];

point operator -(point a,point b)
{
    return (point){a.x - b.x,a.y - b.y};
}

LL operator *(point a,point b)
{
    return a.x * b.y - a.y * b.x;
}

bool operator !=(point a,point b)
{
    return a.x != b.x || a.y != b.y;
}

struct vec
{
    point x,y;
    void print() { x.print(); y.print(); puts(""); }
}vc[SZ];

bool xj(vec a,vec b)
{
    //a.print(); b.print();
    //puts("*****");
    if(((b.y - b.x) * (a.y - b.x)) * ((b.y - b.x) * (a.x - b.x)) > 0) return false;
    if(((a.y - a.x) * (b.y - a.x)) * ((a.y - a.x) * (b.x - a.x)) > 0) return false;
    return true;
}


int head[SZ],nxt[SZ],to[SZ],tot = 1;

void build(int f,int t)
{
    to[++ tot] = t;
    nxt[tot] = head[f];
    head[f] = tot;
}

int c[SZ];

bool dfs(int u,int fa,int col)
{
    c[u] = col;
    for(int i = head[u];i;i = nxt[i])
    {
        int v = to[i];
        if(v == fa) continue;
        if(c[v] != -1)
        {
            if(c[v] == col) return false;
        }
        else
        {
            if(!dfs(v,u,col ^ 1)) return false;
        }
    }
    return true;
}

int main()
{
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++)
        p[i].x = read(),p[i].y = read();
    for(int i = 1;i <= m;i ++)
    {
        int id = read(),x = read(),y = read();
        point px = p[id],py = (point){x,y};
        vc[i] = (vec){px,py};
    }
    for(int i = 1;i <= m;i ++)
        for(int j = i + 1;j <= m;j ++)
            if(vc[i].x != vc[j].x && xj(vc[i],vc[j]))
        //        cout << i << " " << j << endl,
                build(i,j),build(j,i);
    bool flag = 0;
    memset(c,-1,sizeof(c));
    for(int i = 1;i <= m;i ++)
        if(c[i] == -1 && !dfs(i,0,0))
            { flag = 1; break; }
    if(flag) puts("impossible");
    else puts("possible");
    return 0;
}
