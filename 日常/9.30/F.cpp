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

int a[SZ],c[SZ],n;
bool use[SZ];

bool check(LL m)
{
    bool use[23333] = {};
    for(int i = 1,j = 1;i <= n;i = j + 1)
    {
        j = i;
        while(j <= n && c[j] == c[j + 1]) j ++;
        int c1 = (a[i] - 1) / m;
        int c2 = (a[j] - 1) / m;
        if(c1 != c2 || use[c1]) return false;
        use[c1] = 1;
    }
    cout << m << endl;
    return true;
}

int main()
{
    n = read();
    for(int i = 1;i <= n;i ++)
        a[i] = read(),c[i] = read();
    int ans = 0;
    for(int m = 1;m <= a[n];m ++)
        if(check(m)) ans ++;
    cout << ans << endl;
    return 0;
}
