#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<vector>
#include<ctime>
#include<bitset>
#include<set>
#define x first
#define y second
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 500010;
const LL INF = 1000000010;
const LL mod = 1000000007;
const int Dx[] = {0,1,0,-1};
const int Dy[] = {1,0,-1,0};

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

int n,m,B;

struct haha
{
    int l,r,id;
    LL ans;
}ask[SZ];

bool cmp(haha a,haha b)
{
    int la = a.l / B,lb = b.l / B;
    if(la == lb) return a.r < b.r;
    return la < lb;
}

bool cmp1(haha a,haha b)
{
    return a.id < b.id;
}

LL gcd(LL a,LL b)
{
    return b == 0 ? a : gcd(b,a % b);
}

int c[SZ],a[SZ];

int main()
{
    n = read(),m = read();
    B = sqrt(n);
    for(int i = 1;i <= n;i ++) a[i] = read();
    for(int i = 1;i <= m;i ++)
        ask[i].l = read(),ask[i].r = read(),ask[i].id = i;
    sort(ask + 1,ask + 1 + m,cmp);
    LL ans = 0;
    for(int i = 1,l = 1,r = 0;i <= m;i ++)
    {
        while(l < ask[i].l)
        {
            LL x = c[a[l]];
            ans -= x * (x - 1) >> 1;
            x = -- c[a[l]];
            ans += x * (x - 1) >> 1;
            l ++;
        }
        while(l > ask[i].l)
        {
            LL x = c[a[l - 1]];
            ans -= x * (x - 1) >> 1;
            x = ++ c[a[l - 1]];
            ans += x * (x - 1) >> 1;
            l --;
        }
        while(r < ask[i].r)
        {
            LL x = c[a[r + 1]];
            ans -= x * (x - 1) >> 1;
            x = ++ c[a[r + 1]];
            ans += x * (x - 1) >> 1;
            r ++;
        }
        while(r > ask[i].r)
        {
            LL x = c[a[r]];
            ans -= x * (x - 1) >> 1;
            x = -- c[a[r]];
            ans += x * (x - 1) >> 1;
            r --;
        }
        ask[i].ans = ans;
    }
    sort(ask + 1,ask + 1 + m,cmp1);
    for(int i = 1;i <= m;i ++)
    {
        LL ans1 = ask[i].ans;
        LL len = ask[i].r - ask[i].l + 1;
        LL ans2 = len * (len - 1) >> 1;
        LL d = gcd(ans1,ans2);
        printf("%lld/%lld\n",ans1 / d,ans2 / d);
    }
    return 0;
}
