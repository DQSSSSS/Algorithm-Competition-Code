#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<int,int> pii;
typedef long long LL;
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

LL a[SZ],c[SZ];
int n;

int main()
{
    n = read();
    LL ave = 0;
    for(int i = 1;i <= n;i ++) a[i] = read(),ave += a[i];
    ave /= n;
    for(int i = 1;i <= n;i ++) c[i] = c[i - 1] + a[i] - ave;
    sort(c + 1,c + 1 + n);
    LL mid = c[(n + 1) >> 1],ans = 0;
    for(int i = 1;i <= n;i ++)
        ans += abs(c[i] - mid);
    printf("%lld\n",ans);
    return 0;
}

//-2 -1 2 1 -2 -1 2 1
//-2 -3 -1 0
