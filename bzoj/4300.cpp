#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 100010;
const int INF = 1e9 + 10;
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

int a[50];

int main()
{
    int n = read();
    for(int i = 1;i <= n;i ++)
    {
        int x = read(),len = 0;
        for(int j = 0;j <= 31;j ++)
            if(x >> j & 1) len = max(len,a[j] + 1);
        for(int j = 0;j <= 31;j ++)
            if(x >> j & 1) a[j] = len;
    }
    int ans = 0;
    for(int i = 0;i <= 31;i ++) ans = max(ans,a[i]);
    printf("%d\n",ans);
    return 0;
}
