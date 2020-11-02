#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
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

int n,a[SZ],b[SZ],c[SZ];

bool can()
{
    for(int i = 1;i <= n;i ++) c[i] = a[i];
    c[1] = 0; c[2] -= b[1] + b[2];
    for(int i = 3;i <= n;i ++)
    {
        int tmp = c[i - 1];
        b[i] = tmp;
        c[i] -= b[i] + b[i - 1];
        if(tmp >= 2 || c[i] < 0) return false;
    }
    if(c[n]) return false;
    return true;
}

int main()
{
    n = read();
    for(int i = 1;i <= n;i ++)
        a[i] = read();
    int ans = 0;
    if(a[1] == 0)
    {
        b[1] = b[2] = 0;
        if(can()) ans ++;
    }
    else if(a[1] == 1)
    {
        b[2] = 0; b[1] = 1; if(can()) ans ++;
        memset(b,0,sizeof(b));
        b[1] = 0; b[2] = 1; if(can()) ans ++;
    }
    else
    {
        b[1] = b[2] = 1; if(can()) ans ++;
    }
    printf("%d\n",ans);
    return 0;
}
