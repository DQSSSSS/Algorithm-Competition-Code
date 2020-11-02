#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const int SZ = 100010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

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
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

void merge(int a,int b)
{
    int x = find(a),y = find(b);
    if(x != y) fa[x] = y;
}

LL x[SZ],y[SZ],z[SZ],h,r;
ULL pf(LL x) { return x * x; }

int main()
{
    int T = read();
    while(T --)
    {
        int n = read();
        h = read(),r = read();
        for(int i = 1;i <= n;i ++)
            x[i] = read(),y[i] = read(),z[i] = read();
        for(int i = 1;i <= n + 2;i ++) fa[i] = i;
        for(int i = 1;i <= n;i ++)
        {
            if(z[i] <= r) merge(i,n + 1);
            if(z[i] >= h - r) merge(i,n + 2);
        }
        for(int i = 1;i <= n;i ++)
            for(int j = i + 1;j <= n;j ++)
            {
                ULL d = pf(x[i] - x[j]) + pf(y[i] - y[j]) + pf(z[i] - z[j]);
                if(d <= pf(2 * r)) merge(i,j);
            }
        if(find(n + 1) == find(n + 2)) puts("Yes");
        else puts("No");
    }
    return 0;
}
