#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int SZ = 110;
const int INF = 1e7 + 10;
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

int n;
int a[SZ];
LL f[SZ][SZ];

int main()
{
    n = read(),m = read(),k = read();
    if(m == 1)
    {
        for(int i = 1;i <= n;i ++) a[i] = read();
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= k;j ++)
                f[i][j] = max(f[i - 1][j]
    }
    return 0;
}
