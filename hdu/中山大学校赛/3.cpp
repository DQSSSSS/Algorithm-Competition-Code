#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 5e5 + 10;
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

int main() {
    int n,m;
    while(~scanf("%d%d",&n,&m)) {
        for(int i = 1;i <= n;i ++) scanf("%*s");
        LL ans = 0,tmp1 = 0,tmp2 = 0,tmp3 = 0,tmp4 = 0,tmp5 = 0;
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= m;j ++) {
                LL x = i * j;
                ans += x;
                tmp1 += i*j*(n-i)*(m-j)*2;
                tmp4 += (i+j-2) * (n-i+1) * (m-j+1);
                tmp5 += i * (i-1) * j * (j - 1);
            }
        for(int i = 1;i < n;i ++) tmp2 += i * (n-i)*(n-i-1)/2; tmp2 *= m * (m+1) / 2;
        for(int i = 1;i < m;i ++) tmp3 += i * (m-i)*(m-i-1)/2; tmp3 *= n * (n+1) / 2;

        //cout << tmp4 << endl;
        for(int i = 1;i <= n;i ++) tmp4 += i * (i-1) * m * (m+1) / 2;
        for(int i = 1;i <= m;i ++) tmp4 += i * (i-1) * n * (n+1) / 2;

        //cout << ans << " " << tmp1 << " " << tmp2 << " " << tmp3 << " " << tmp4 << endl;
        ans = ans * (ans-1) / 2 + 1 - tmp1 *2 - tmp2 * 2 - tmp3 * 2 - tmp4 + ans - tmp5 * 2;
        printf("%lld\n",ans);
    }
}
/**
100 100
3247

1 4
16
*/
