#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int n;
LL x[SZ],p[SZ],c[SZ],s[SZ],f[SZ],sp[SZ];

int q[SZ],t = 0,w = 0;

double xl(int j,int k)
{
    return (f[j] + s[j] - f[k] - s[k]) / (double)(sp[j] - sp[k]);
}

int main()
{
    n = read();
    for(int i = 1;i <= n;i ++)
    {
        x[i] = read(),p[i] = read(),c[i] = read();
        s[i] = s[i - 1] + x[i] * p[i];
        sp[i] = sp[i - 1] + p[i];
    }
/*    for(int i = 1;i <= n;i ++) f[i] = INF;
    for(int i = 1;i <= n;i ++)
        for(int j = 0;j < i;j ++)
            f[i] = min(f[i],f[j] + x[i] * (sp[i] - sp[j]) - s[i] + s[j] + c[i]);
*/
    for(int i = 1;i <= n;i ++)
    {
        while(t < w && xl(q[t],q[t + 1]) < x[i]) t ++;
        int j = q[t];
        f[i] = f[j] + x[i] * (sp[i] - sp[j]) - s[i] + s[j] + c[i];
        while(t < w && xl(q[w - 1],q[w]) > xl(q[w],i)) w --;
        q[++ w] = i;
    }
    printf("%lld\n",f[n]);
    return 0;
}
/*
10
0 6 9
1 6 300
3 200 10
5 9 40
10 10 9
20 2333 90
21 6 1
33 50 10
55 9 233
40 9 9
*/
