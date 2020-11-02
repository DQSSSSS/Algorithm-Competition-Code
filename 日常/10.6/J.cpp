#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<ctime>
#include<bitset>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
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

int n,q;
LL a[SZ],st[SZ][22];

void get_st()
{
    for(int i = 1;i <= n;i ++)
        st[i][0] = a[i];
    for(int j = 1;j <= log2(n);j ++)
        for(int i = 1;i <= n;i ++)
            st[i][j] = min(st[i][j - 1],st[i + (1 << (j - 1))][j - 1]);
}

LL ask_min(int l,int r)
{
    int k = log2(r - l + 1);
    return min(st[l][k],st[r - (1 << k) + 1][k]);
}

int Div(int l,int r,LL d)
{
    int L = l;
    while(r - l > 1)
    {
        int mid = l + r >> 1;
        if(ask_min(L,mid) > d) l = mid;
        else r = mid;
    }
    return r;
}

int main()
{
    n = read(),q = read();
    for(int i = 1;i <= n;i ++)
        a[i] = read();
    get_st();
    while(q --)
    {
        LL sum = read();
        int l = read(),r = read();
        int pos = l;
        sum %= a[pos];
        while(233)
        {
            if(ask_min(pos,r) > sum) break;
            pos = Div(pos,r,sum);
            //cout << pos << endl;
            sum %= a[pos];
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
