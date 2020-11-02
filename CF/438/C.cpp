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


bitset<SZ> a[11];

int main()
{
    int n = read(),k = read();
    int ans;
    for(int i = 1;i <= n;i ++)
        for(int j = 0;j < k;j ++)
        {
            int x = read();
            if(x)
                a[j + 1].set(i);
        }
    ans = a[1];
    for(int i = 2;i <= n;i ++) ans &= a[i];
    if(!ans) puts("YES");
    else puts("NO");
    return 0;
}
