#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int SZ = 40010;
const int INF = 1e9 + 10;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar();  }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int m,n;
LL val[SZ];
int pre[SZ];

double f[110][SZ];

int main()
{
    m = read(),n = read();
    for(int i = 0;i < n;i ++)
    {
        val[i] = read();
        int x;
        while(scanf("%d",&x) && x) pre[i] |= 1 << (x - 1);
    }
    for(int i = m;i >= 1;i --)
        for(int S = 0;S < (1 << n);S ++)
        {
            for(int j = 0;j < n;j ++)
            {
                if((pre[j] & S) == pre[j])
                    f[i][S] += max(f[i + 1][S],f[i + 1][S | (1 << j)] + val[j]);
                else
                    f[i][S] += f[i + 1][S];
            }
            f[i][S] /= n;
        }
    printf("%.6f\n",f[1][0]);
    return 0;
}
