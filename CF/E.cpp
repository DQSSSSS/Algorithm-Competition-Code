#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

typedef long long LL;
const int SZ = 110;
const LL INF = 100000000000000010ll;
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


int dp[100][12][12][2],base[SZ],B;

void init()
{
    base[1] = 1;
    for(int i = 2;i <= 10;i ++)
        base[i] = base[i - 1] * B;
    for(int i = 0;i <= B - 1;i ++)
        dp[1][i][i][1] = 1;
    for(int len = 2;len <= 64;len ++)
        for(int x = 0;x <= B - 1;x ++)
            for(int y = 0;y <= B - 1;y ++)
                dp[len][x][y][0] += dp[len - 1][x][y][1]
}

int bits[SZ];

int calc_bits(int x)
{
    int i = 1;
    for(i = 1;x;i ++)
    {
        bits[i] = x % 10;
        x /= 10;
    }
    bits[i] = 0;
    return i - 1;
}

int calc(int n)
{
    int ans = 0;
    int len = calc_bits(n);

    for(int i = 1;i < len;i ++)
        for(int j = 1;j <= 9;j ++)
            ans += dp[i][j];
    for(int i = 1;i < bits[len];i ++)
        ans += dp[len][i];
    for(int i = len - 1;i >= 1;i --)
    {
        if(i == 1)
        {
            for(int j = 0;j <= bits[i];j ++)
                if(abs(bits[i + 1] - j) >= 2)
                    ans += dp[i][j];
        }
        else
        {
            for(int j = 0;j < bits[i];j ++)
                if(abs(bits[i + 1] - j) >= 2)
                    ans += dp[i][j];
        }
        if(abs(bits[i] - bits[i + 1]) < 2) break;
    }
    return ans;
}


int main()
{
    int T = read();
    while(T --)
    {
        B = read();
        init();
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d",calc(b + 1) - calc(a));
    }
    return 0;
}
