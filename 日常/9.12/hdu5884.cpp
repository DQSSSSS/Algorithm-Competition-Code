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


LL a[SZ],tmp[SZ],k;
int l,r,p,n;

LL get_min()
{
    if(l > r) return a[p ++];
    if(p > n) return tmp[l ++];
    return tmp[l] < a[p] ? tmp[l ++] : a[p ++];
}

LL merge(int mid)
{
    l = 1,r = 0,p = 1;
    LL ans = 0;
    if((n - 1) % (mid - 1))
    {
        LL d = 0;
        for(int j = 1;j <= (n - 1) % (mid - 1) + 1;j ++)
            d += get_min();
        tmp[++ r] = d,ans += d;
    }
    for(int j = 1;j <= (n - 1) / (mid - 1);j ++)
    {
        LL d = 0;
        for(int j = 1;j <= mid;j ++)
            d += get_min();
        tmp[++ r] = d;
        ans += d;
    }
    return ans;
}

LL div()
{
    int l = 1,r = n;
    while(r - l > 1)
    {
        int mid = l + r >> 1;
        if(merge(mid) <= k) r = mid;
        else l = mid;
    }
    return r;
}

int main()
{
    int T = read();
    while(T --)
    {
        n = read(),k = read();
        for(int i = 1;i <= n;i ++)
            a[i] = read();
        sort(a + 1,a + 1 + n);
        printf("%lld\n",div());
    }
    return 0;
}
