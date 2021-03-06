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

int mi[SZ];

int main()
{
    mi[0] = 1;
    for(int i = 1;i <= 100000;i ++) mi[i] = mi[i - 1] * 2 % 7;
    int T = read();
    for(int cc = 1;cc <= T;cc ++)
    {
        int n = read();
        int ans = 0;
        for(int i = 1;i <= n;i ++)
        {
            if((mi[i] - 1) % 7 == 0) ans ++;
        }
        printf("Case #%d: %d\n",cc,ans);
    }
    return 0;
}
