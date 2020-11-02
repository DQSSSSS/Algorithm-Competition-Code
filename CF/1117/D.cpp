#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

typedef long long LL;
const int SZ = 2000010;
const LL INF = 1000000010;
const LL mod = 1e9 + 7;

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

LL n,m;

struct matrix
{
    int n,m;
    LL mp[110][110];
    matrix(int a,int b) : n(a),m(b) { memset(mp,0,sizeof(mp)); }
};

matrix operator *(const matrix &a,const matrix &b)
{
    matrix ans(a.n,b.m);
    for(int i = 0;i < ans.n;i ++)
        for(int j = 0;j < ans.m;j ++)
            for(int k = 0;k <= a.m;k ++)
                (ans.mp[i][j] += a.mp[i][k] * b.mp[k][j]) %= mod;
    return ans;
}

matrix ksm(matrix a,LL b)
{
    matrix ans(a.n,a.m);
    for(int i = 0;i < a.n;i ++) ans.mp[i][i] = 1;
    while(b)
    {
        if(b & 1) ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}

char s[SZ];

int main()
{
    n = read(),m = read();
    matrix f(m,m);
    f.mp[0][0] = f.mp[0][m-1] = 1;
    for(int i = 0;i < m - 1;i ++) {
        f.mp[i+1][i] = 1;
    }

    f = ksm(f,n);

    matrix a(m,1);
    for(int i = 0;i < m;i ++) a.mp[i][0] = 1;
    a = f * a;
    cout << a.mp[m-1][0];
    return 0;
}
