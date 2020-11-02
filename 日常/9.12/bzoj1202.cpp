#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1000000010;

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

int d[SZ],l[SZ],r[SZ],n,m,fa[SZ],val[SZ];

int find(int x)
{
    if(x == fa[x]) return x;
    int f = find(fa[x]);
    val[x] += val[fa[x]];
    return fa[x] = f;
}

bool check()
{
    for(int i = 1;i <= m;i ++)
    {
        int u = l[i],v = r[i],dd = d[i];
        int x = find(u),y = find(v);
        if(x != y)
        {
            fa[y] = x;
            val[y] = dd - val[v] + val[u];
        }
        else if(val[v] - val[u] != dd)
            return false;
    }
    return true;
}

int main()
{
    int T = read();
    while(T --)
    {
        n = read(),m = read();
        for(int i = 0;i <= n;i ++) fa[i] = i,val[i] = 0;
        for(int i = 1;i <= m;i ++)
            l[i] = read() - 1,r[i] = read(),d[i] = read();
        if(check()) puts("true");
        else puts("false");
    }
    return 0;
}
