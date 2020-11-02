#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

typedef long long LL;
const int SZ = 500010;
const int INF = 1000000010;
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

LL a,b,k,f;

LL work()
{
    LL now = b,ans = 0,pos = 0;
    for(int i = 1;i <= k;i ++)
    {
        LL d = abs(pos - f);
        if(now < d) return -1;
        if(b < (a - d)) return -1;
        if(i == k)
        {
            if(now < a) now = b - (a - d),ans ++;
            else now -= a;
        }
        else if(now < 2 * a - d) now = b - (a - d),ans ++;
        else now -= a;
        if(now < 0) return -1;
        if(pos == 0) pos = a;
        else pos = 0;
    }
    return ans;
}

int main()
{
    a = read(),b = read(),f = read(),k = read();
    cout << work() << endl;
    return 0;
}
