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

LL pri[] = {0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47}; //15

LL n,ans = 0,t = 0;
int use[50];

void dfs(int pos,LL d,LL now)
{
    //cout <<d << " " << now <<endl;
    if(d > t || (d == t && now < ans)) t = d,ans = now;
    if(pos == 16) return ;
    LL a = 1;
    for(int i = 0;;i ++)
    {
        if(now * a > n) break;
        dfs(pos + 1,d * (i + 1),now * a);
        a *= pri[pos];
    }
}

LL D(LL x)
{
    LL ans = 0;
    for(LL i = 1;i <= sqrt(x);i ++)
        if(x % i == 0) ans += i * i == x ? 1 : 2;
    return ans;
}

bool check(LL x)
{
    LL Dx = D(x),t = 0;
    for(int i = 1;i < x;i ++)
    {
        if(D(i) > Dx) t ++;
        if(t == 2) return false;
    }
    return true;
}

int main()
{
//    freopen("biao.txt","w",stdout);
    //n = read();
    for(n = 1;n <= 1000;n ++)
    {
        if(check(n)) cout << n << " " << D(n) <<endl;
    }
    return 0;
}

/*
2^4*3^2*5

2^3*3*5*7
20000000000000
*/
