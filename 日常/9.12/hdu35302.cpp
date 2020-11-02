#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const int INF = 1000000010;

LL read()
{
    char a = getchar();
    LL n = 0; bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int n,L,R,a[SZ];

int stx[SZ][22],stn[SZ][22];

void get_st()
{
    for(int i = 1;i <= n;i ++)
        stx[i][0] = stn[i][0] = a[i];
    for(int j = 1;j <= log2(n);j ++)
        for(int i = 1;i <= n;i ++)
            stx[i][j] = max(stx[i][j - 1],stx[i + (1 << (j - 1))][j - 1]),
            stn[i][j] = min(stn[i][j - 1],stn[i + (1 << (j - 1))][j - 1]);
}

int ask(int l,int r)
{
    int k = log2(r - l + 1);
    int maxn = max(stx[l][k],stx[r - (1 << k) + 1][k]);
    int minn = min(stn[l][k],stn[r - (1 << k) + 1][k]);
    return maxn - minn;
}

bool checkR(int mid)
{
    for(int i = 1;i <= n - mid + 1;i ++)
    {
        int l = i,r = i + mid - 1;
        int d = ask(l,r);
        if(d <= R) return true;
    }
    return false;
}

int divR()
{
    int l = 1,r = n + 1;
    while(r - l > 1)
    {
        int mid = l + r >> 1;
        if(checkR(mid)) l = mid;
        else r = mid;
    }
    return l;
}



bool checkL(int mid)
{
    for(int i = 1;i <= n - mid + 1;i ++)
    {
        int l = i,r = i + mid - 1;
        int d = ask(l,r);
        if(d >= L) return true;
    }
    return false;
}

int divL()
{
    int l = 0,r = n;
    while(r - l > 1)
    {
        int mid = l + r >> 1;
        if(checkL(mid)) r = mid;
        else l = mid;
    }
    return r;
}

int main()
{
    while(~scanf("%d%d%d",&n,&L,&R))
    {
        for(int i = 1;i <= n;i ++)
            scanf("%d",&a[i]);
        get_st();
        int ansR = divR(),ansL = divL();
        if(ansL > ansR) puts("0");
        else printf("%d\n",ansR);
    }
    return 0;
}
/*
5 1 7
1 9 1 9 2

*/
