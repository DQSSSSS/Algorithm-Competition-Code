#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

typedef long long LL;
const int SZ = 1010;
const LL INF = 1000000010;
const LL mod = 1000000007;
const double eps = 1e-8;

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

double ans[SZ];
int n;
void gauss(double g[SZ][SZ],double ans[SZ])
{
    int now = 1;
    for(int i = 1;i <= n;i ++)
    {
        int to = 1;
        for(to = now;to <= n;to ++)
            if(fabs(g[to][i]) > eps)
                break;
        if(to > n) continue;

        if(to != now)
            for(int j = 1;j <= n + 1;j ++)
                swap(g[to][j],g[now][j]);

        double x = g[now][i];
        for(int j = 1;j <= n + 1;j ++)
            g[now][j] /= x;

        for(int j = 1;j <= n;j ++)
            if(j != now)
            {
                double x = g[j][i];
                for(int k = i;k <= n + 1;k ++)
                    g[j][k] -= g[now][k] * x;
            }
        now ++;
    }
    for(int i = 1;i <= n;i ++)
        ans[i] = g[i][n + 1];
}

double g[SZ][SZ],a[SZ][SZ];

int main()
{
    
    return 0;
}
