#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 5e6 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int a[110][110];
int b[110][110];
int c[110][110];

int main() {
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k)) {
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= m;j ++)
                scanf("%d",&a[i][j]);
        for(int i = 1;i <= m;i ++)
            for(int j = 1;j <= k;j ++)
                scanf("%d",&b[i][j]);
        for(int i = 1;i <= k;i ++)
            for(int j = 1;j <= n;j ++)
                scanf("%d",&c[i][j]);
        int ans = 0;

        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= m;j ++)
                for(int l = 1;l <= k;l ++)
                    if(a[i][j] && b[j][l] && c[l][i])
                        ans ++;
        printf("%d\n",ans);
    }
}
