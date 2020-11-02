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
const int SZ = 1000010;
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

int bits[SZ],n,k,d;

void add(int x,int d)
{
    for(int i = x;i <= n;i += i & -i)
        bits[i] += d;
}

int ask(int x)
{
    int ans = 0;
    for(int i = x;i > 0;i -= i & -i)
        ans += bits[i];
    return ans;
}

int ask(int l,int r)
{
    return ask(r) - ask(l - 1);
}

int main()
{
    n = read(),k = read(),d = read();
    for(int i = 1;i <= k;i ++)
    {
        int x = read();
        add(x,1);
    }
    int ans = 0;
    for(int i = 1;i <= n;i ++)
    {
        int r = i + d - 1;
        if(r > n) continue;
        int sum = ask(i,r);
        if(sum == 1)
        {
            if(ask(r,r)) add(r - 1,1);
            else add(r,1);
            ans ++;
        }
        if(sum == 0) add(r,1),add(r - 1,1),ans += 2;
    }
    printf("%d\n",ans);
    return 0;
}
