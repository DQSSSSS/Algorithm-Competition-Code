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

LL mod;
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

LL C[5010][5010];

LL B(LL n,LL m)
{
    if((n + m) % 2) return 0;
    LL x = (n + m) / 2;
    return C[n][x];
}

LL ksm(LL a,LL b)
{
    LL ans = 1;
    while(b)
    {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
int n;

int main()
{
    n = read(),mod = read();
    LL ans = 0;
    C[0][0] = 1;
    for(int i = 1;i <= n;i ++)
    {
        C[i][0] = 1;
        for(int j = 1;j <= i;j ++)
            (C[i][j] = C[i - 1][j] + C[i - 1][j - 1]) %= mod;
    }
    for(int i = 1;i <= n;i ++)
        for(int j = 0;j <= n;j ++)
        {
            if(abs(i) + abs(j) <= n)
            {
                LL tmp = 0;
                int a = max(abs(i),abs(j)),b = min(abs(i),abs(j));
                for(int N = a+b;N <= n;N ++)
                {
                    LL d = 1;
                    if(i && j) d = 2;
                    cout << ksm(4,n - N) << " "<< B(N,abs(i)+abs(j)) << " " << d << endl;
                    (tmp += ksm(4,n - N) * B(N,a+b) * d) %= mod;
                }
                cout << i << " "<< j << " : " << tmp << endl;
                (ans += tmp) %= mod;
            }
        }
        cout << ans <<endl;
    (ans = ans * 4 + ksm(4,n)) % mod;
    cout << ans <<endl;
    return 0;
}

/*

3 23333

*/
