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
const int SZ = 1010;
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
bool cc[SZ][SZ],zt[SZ];

int main()
{
    int T = read();
    while(T --)
    {
        int n = read(),m = read();
        for(int i = 1;i <= m;i ++)
        {
            int pos = read(),c = read(),d = read();
            int l = max(pos - d,1),r = min(pos + d,n);
            for(int j = max(1,l);j <= min(r,n);j ++)
                zt[j] = cc[j][c] ? 0 : 1;
            for(int j = max(1,l);j <= min(r,n);j ++)
                cc[j][c] = 1;
        }
        int ans = 0;
        for(int i = 1;i <= n;i ++)
            if(!zt[i]) ans ++;
        cout << ans << endl;
    }
    return 0;
}
