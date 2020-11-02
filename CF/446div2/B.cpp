#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
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

int a[SZ],n;
int b[SZ];

int main()
{
    n = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    for(int i = 1;i <= n;i ++)
    {
        int l = max(1,i - a[i]);
        b[l] --; b[i] ++;
    }
    for(int i = 1;i <= n;i ++) b[i] += b[i - 1];
    int ans = 0;
    for(int i = 1;i <= n;i ++)
        if(b[i] >= 0) ans ++;
    printf("%d\n",ans);
    return 0;
}
