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

int n,m,p,nxt[SZ];

void get_nxt(char s[])
{
    nxt[0] = nxt[1] = 0;
    for(int i = 1;i < m;i ++)
    {
        int j = nxt[i];
        while(j && s[j] != s[i]) j = nxt[j];
        nxt[i + 1] = s[i] == s[j] ? j + 1 : 0;
    }
}

struct matrix
{
    int n,m;
    int mp[30][30];
    matrix(int a,int b) : n(a),m(b) { memset(mp,0,sizeof(mp)); }
};

matrix operator *(const matrix &a,const matrix &b)
{
    matrix ans(a.n,b.m);
    for(int i = 0;i < ans.n;i ++)
        for(int j = 0;j < ans.m;j ++)
            for(int k = 0;k <= a.m;k ++)
                (ans.mp[i][j] += a.mp[i][k] * b.mp[k][j]) %= p;
    return ans;
}

matrix ksm(matrix a,int b)
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
    n = read(),m = read(),p = read();
    scanf("%s",s);

    get_nxt(s);
    matrix f(m,m);
    for(int i = 0;i < m;i ++)
    {
        for(int c = '0';c <= '9';c ++)
        {
            int j = i;
            while(j && s[j] != c) j = nxt[j];
            if(s[j] == c) j ++;
            if(j != m) f.mp[i][j] ++;
        }
    }

    f = ksm(f,n);
    int ans = 0;
    for(int i = 0;i < m;i ++) (ans += f.mp[0][i]) %= p;
    printf("%d\n",ans);
    return 0;
}
