#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<double,double> pii;
const int SZ = 1000010;
const LL INF = 1000000010;
const LL mod = 1000000007;
const int Dx[] = {0,1,0,-1};
const int Dy[] = {1,0,-1,0};
const double eps = 1e-6;

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

int a[SZ];

int main()
{
    int T = read();
    while(T --)
    {
        int n = read();
        int j = 1;
        for(int i = 1;i <= n;i += 2)
            a[i] = j ++;
        for(int i = 2;i <= n;i += 2)
            a[i] = j ++;
        for(int i = 1;i <= n;i ++) printf("%d%c",a[i],i == n ? '\n' : ' ');
    }
    return 0;
}
/*
1 4 2 5 3 6
*/
