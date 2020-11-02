#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 510;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar();  }
    while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int gcd(int x,int y) { return b == 0 ? a : gcd(b,a % b); }

LL f[SZ][SZ];
bool pd[SZ][SZ];

int main()
{
    int T = read();
    while(T --)
    {
        int n = read();
        for(int i = 1;i <= n;i ++) a[i] = read();
        for(int i = 1;i <= n;i ++) b[i] = read();

        for(int i = 1;i <= n;i ++)
        {
            int x = a[i];
            if(x == 1) pd[i][i] = 1;
            for(int j = i + 1;j <= n;j ++)
            {
                x = gcd(x,a[j]);
                if(x == 1) pd[i][j] = 1;
            }
        }

        for(int i = 1;i <= n;i ++)
            f[i][i] = b[i],f[i][i + 1] = b[];

        for(int i = n;i >= 1;i --)
        {
            for(int j = i + 1;j <= n;j ++)
            {
                for(int k = i + 1;k < j;k ++)
                {

                }
            }
        }

    }
    return 0;
}
