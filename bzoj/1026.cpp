#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

LL dp[22][11];

void init()
{
    for(int i = 0;i <= 9;i ++) dp[1][i] = 1;
    for(int i = 2;i <= 11;i ++)
        for(int j = 0;j <= 9;j ++)
            for(int k = 0;k <= 9;k ++)
                if(abs(j - k) >= 2)
                    dp[i][j] += dp[i - 1][k];
}

int a[22];

int get_bits(int x)
{
    if(x == 0) { a[1] = 0; return 1; }
    int len = 0;
    while(x) a[++ len] = x % 10,x /= 10;
    return len;
}

LL ask(int x)
{
    int len = get_bits(x);
    LL ans = 0;
    for(int i = 1;i < len;i ++)
        for(int j = 1;j <= 9;j ++)
            ans += dp[i][j];
    for(int i = 1;i < a[len];i ++)
        ans += dp[len][i];
    for(int i = len - 1;i >= 1;i --)
    {
        for(int j = 0;j < a[i];j ++)
            if(abs(j - a[i + 1]) >= 2)
                ans += dp[i][j];
        if(abs(a[i] - a[i + 1]) < 2) break;
    }
    return ans;
}


int main()
{
    init();
    int a = read(),b = read();
    printf("%lld\n",ask(b + 1) - ask(a));
    return 0;
}
