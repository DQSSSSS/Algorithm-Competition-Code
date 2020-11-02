#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

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

int n;
LL c,sum[SZ],a[SZ],q[SZ],f[SZ];

double calc(int i,int j)
{
    double y1 = f[i] + a[i] * a[i] + 2 * c * a[i];
    double y2 = f[j] + a[j] * a[j] + 2 * c * a[j];
    return (y1 - y2) / ((double)a[i] - a[j]);
}

int main()
{
    n = read(),c = read() + 1;
    for(int i = 1;i <= n;i ++)
    {
        int x = read();
        sum[i] = sum[i - 1] + x;
        a[i] = i + sum[i];
    }
    int t = 0,w = 0;
    for(int i = 1;i <= n;i ++)
    {
        while(t < w && calc(q[t],q[t + 1]) <= 2 * a[i]) t ++;
        int x = q[t];
        f[i] = f[x] + (a[i] - a[x] - c) * (a[i] - a[x] - c);
        while(t < w && calc(q[w - 1],q[w]) > calc(q[w],i)) w --;
        q[++ w] = i;
    }
    printf("%lld\n",f[n]);
    return 0;
}
