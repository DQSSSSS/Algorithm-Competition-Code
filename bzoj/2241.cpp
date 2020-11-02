#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int SZ = 110;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int n,m;
LL a[SZ][SZ],sum = 0,S[SZ][SZ];

bool check(int r,int c)
{
    if(sum % (r * c)) return false;
    memset(S,0,sizeof(S));
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
        {
            S[i][j] += S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
            int d = a[i][j] - S[i][j];
            if(d < 0) return false;
            if(i > n - r + 1 || j > m - c + 1)
                if(d) return false;
                else continue;
            S[i][j] += d; S[i + r][j] -= d; S[i][j + c] -= d; S[i + r][j + c] += d;
        }
    return true;
}

int main()
{
    n = read(),m = read();
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
            a[i][j] = read(),sum += a[i][j];
    for(int i = n;i >= 1;i --)
        for(int j = m;j >= 1;j --)
            if(check(i,j)) { printf("%lld\n",sum / (i * j)); return 0; }
    return 0;
}
