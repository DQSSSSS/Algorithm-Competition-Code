#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

typedef long long LL;
const int SZ = 3000010;
const int INF = 1000000010;

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


LL a[SZ],tmp[SZ];
int l,r,p,n;

LL get_min()
{
    if(l > r) return a[p ++];
    if(p > n) return tmp[l ++];
    return tmp[l] < a[p] ? tmp[l ++] : a[p ++];
}

LL merge()
{
    LL ans = 0;
    l = 1,r = 0,p = 1;
    for(int i = 1;i <= n - 1;i ++)
    {
        LL d = get_min() + get_min();
        tmp[++ r] = d;
        ans += d;
    }
    return ans;
}

int main()
{
    n = read();
    for(int i = 1;i <= n;i ++)
        a[i] = read();
    sort(a + 1,a + 1 + n);
    printf("%lld\n",merge());
    return 0;
}
