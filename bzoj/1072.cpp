#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int SZ = 110;
const int INF = 1e7 + 10;
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

char s[22];
int d;
int f[2010][1010],t[22],fac[22];

int main()
{
    int T = read();
    fac[0] = 1;
    for(int i = 1;i <= 10;i ++) fac[i] = fac[i - 1] * i;
    while(T --)
    {
        scanf("%s",s);
        d = read();
        int n = strlen(s);
        memset(t,0,sizeof(t));
        for(int i = 0;i < n;i ++)
            t[s[i] - '0'] ++;

        int MAXC = 1 << n;
        memset(f,0,sizeof(f));
        f[0][0] = 1;
        for(int S = 0;S < MAXC;S ++)
        {
            for(int i = 0;i < d;i ++)
            {
                for(int j = 0;j < n;j ++)
                {
                    if(S & (1 << j)) continue;
                    f[S | (1 << j)][(i * 10 + s[j] - '0') % d] += f[S][i];
                }
            }
        }
        LL ans = f[MAXC - 1][0];
        for(int i = 0;i <= 9;i ++)
            ans /= fac[t[i]];
        printf("%d\n",ans);
    }
    return 0;
}
