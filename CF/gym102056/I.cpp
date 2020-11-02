#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

LL a[110],b[110],c[110];
LL f[110][10010];
LL g[110][10010];

int main() {
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 1;i <= n;i ++) {
            a[i] = read();
            b[i] = read();
            c[i] = read();
        }
        for(int j = 0;j <= n;j ++) {
            for(int k = 0;k <= n*(n+1)/2;k ++) {
                f[j][k] = -1e18;
            }
        }
        f[0][0] = 0;
        for(int i = n+1;i >= 2;i --) {
            for(int j = 0;j <= n;j ++) {
                for(int k = 0;k <= n*(n+1)/2;k ++) {
                    g[j][k] = f[j][k];
                    f[j][k] = -1e18;
                }
            }
            for(int j = 0;j <= n-i+1;j ++) {
                for(int k = 0;k <= n*(n+1)/2;k ++) {
                    f[j+1][k+(i-1)] = max(f[j+1][k+(i-1)],g[j][k] + a[i-1]);
                    f[j][k] = max(f[j][k],g[j][k] + b[i-1] * k - b[i-1] * (i-1) * j);
                    f[j][k] = max(f[j][k],g[j][k] + c[i-1] * j);
                }
            }
        }
        LL ans = 0;
        for(int j = 0;j <= n;j ++) {
            for(int k = 0;k <= n*(n+1)/2;k ++) {
                ans = max(ans,f[j][k]);
            }
        }
        printf("%lld\n",ans);
    }
}
