#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
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

const int MAXC = 1 << 9;

int n,m;

int get_1(int x)
{
    int ans = 0;
    for(int i = 0;i < n;i ++)
        if(x & (1 << i)) ans ++;
    return ans;
}

LL f[11][90][1550];

int main()
{
    n = read(),m = read();
    f[0][0][0] = 1;
    for(int i = 1;i <= n;i ++)
    {
        for(int S1 = 0;S1 <= (1 << n) - 1;S1 ++)
            if(!(S1 & (S1 << 1)))
                for(int S2 = 0;S2 <= (1 << n) - 1;S2 ++)
                    if(!(S2 & (S2 << 1)))
                    {
                        int n1 = get_1(S1),n2 = get_1(S2);
                        for(int k = n1 + n2;k <= m;k ++)
                            if(!((S1 << 1) & S2) && !((S1 >> 1) & S2) && !(S1 & S2))
                                f[i][k][S2] += f[i - 1][k - n2][S1];
                    }
    }
    LL ans = 0;
    for(int S = 0;S <= (1 << n) - 1;S ++) ans += f[n][m][S];
    printf("%lld\n",ans);
    return 0;
}

/*
2^4*3^2*5

2^3*3*5*7

*/
