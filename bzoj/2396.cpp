#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<ctime>
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

int n;

struct matrix
{
    int n,m;
    LL mp[1010][1010];
    matrix() {}
    matrix(int a,int b) : n(a),m(b) { memset(mp,0,sizeof(mp)); }
    void rd()
    {
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= m;j ++)
                mp[i][j] = read();
    }
}a,b,c,f,t1,t2,t3;

matrix operator *(const matrix &a,const matrix &b)
{
    matrix ans(a.n,b.m);
    for(int i = 1;i <= ans.n;i ++)
        for(int j = 1;j <= ans.m;j ++)
            for(int k = 1;k <= a.m;k ++)
                ans.mp[i][j] += a.mp[i][k] * b.mp[k][j];
    return ans;
}

bool operator ==(const matrix &a,const matrix &b)
{
    if(a.n != b.n || a.m != b.m) return false;
    for(int i = 1;i <= a.n;i ++)
        for(int j = 1;j <= a.m;j ++)
            if(a.mp[i][j] != b.mp[i][j])
                return false;
    return true;
}

int main()
{
    srand(19260817);
    int n;
    while(~scanf("%d",&n))
    {
        a.n = a.m = n;
        b.n = b.m = n;
        c.n = c.m = n;
        f.n = n,f.m = 1;
        a.rd(); b.rd(); c.rd();
        for(int i = 1;i <= n;i ++) f.mp[i][1] = rand();
        t1 = b * f;
        t2 = a * t1;
        t3 = c * f;
        if(t2 == t3) puts("Yes");
        else puts("No");
    }
    return 0;
}
