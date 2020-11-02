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

int e[SZ],f[SZ],t[SZ],n,tot,fa[SZ];
map<int,int> h;

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

bool check()
{
    for(int i = 1;i <= n;i ++)
    {
        int u = h[f[i]],v = h[t[i]];
        int x = find(u),y = find(v);
        if(e[i] && x != y)
            fa[x] = y;
    }
    for(int i = 1;i <= n;i ++)
    {
        int u = h[f[i]],v = h[t[i]];
        int x = find(u),y = find(v);
        if(!e[i] && x == y)
            return false;
    }
    return true;
}

int main()
{
    int T = read();
    while(T --)
    {
        h.clear();
        n = read(),tot = 0;
        for(int i = 1;i <= n;i ++)
        {
            f[i] = read(),t[i] = read(),e[i] = read();
            int u = f[i],v = t[i];
            if(!h[u]) h[u] = ++ tot;
            if(!h[v]) h[v] = ++ tot;
        }
        for(int i = 1;i <= tot;i ++) fa[i] = i;
        if(check()) puts("YES");
        else puts("NO");
    }
    return 0;
}
