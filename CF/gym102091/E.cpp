#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1e6 + 10;
const int mod = 998244353;
const int INF = 1e9 + 10;
const LD eps = 1e-8;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int f[110][3][3],a[110];

int main() {
    int T = read(),cc = 0;
    while(T --) {
        int n = read();
        for(int i = 1;i <= n;i ++) a[i] = read();
        sort(a + 1,a + 1 + n);
       // for(int i = 1;i <= n;i ++) cout << a[i] << " "; puts("");
        for(int i = 0;i <= n;i ++)
            for(int j = -1;j <= 1;j ++)
                for(int k = 0;k <= 2;k ++)
                    f[i][j+1][k]=-INF;
        for(int i = 1;i <= n;i ++) {
            f[i][1][0] = 1;
            f[i][0][1] = 1;
            f[i][2][1] = 1;
        }
        for(int i = 2;i <= n;i ++) {
            for(int j = -1;j <= 1;j ++) {
                for(int k = 0;k <= 2;k ++) {
                    if(j && k == 0) continue;
                    if(abs(a[i-1]+j-a[i]) <= 2)
                        f[i][1][k] = max(f[i][1][k],f[i-1][j+1][k]+1);
                    if(k < 2) {
                        if(abs(a[i-1]+j-(a[i]-1)) <= 2)
                            f[i][0][k+1] = max(f[i][0][k+1],f[i-1][j+1][k]+1);
                        if(abs(a[i-1]+j-(a[i]+1)) <= 2)
                            f[i][2][k+1] = max(f[i][2][k+1],f[i-1][j+1][k]+1);
                    }
                }
            }
        }
        /*for(int i = 1;i <= n;i ++) {
            for(int j = -1;j <= 1;j ++,puts(""))
                for(int k = 0;k <= 2;k ++) {
                    printf("%10d",f[i][j+1][k]);
                }
            puts("\n");
        }*/
        int ans = 0;
        for(int i = 1;i <= n;i ++)
            for(int j = 0;j < 3;j ++)
                for(int k = 0;k <= 2;k ++)
                    ans = max(ans,f[i][j][k]);
        printf("Case %d: %d\n",++cc,ans);
    }
    return 0;
}
