#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 3000100;
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

int f[22][SZ],a[22];
int g[22][SZ];

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b&1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int main() {
    cout << 970000007ll * 404 % mod << endl;
    int T = read();
    while(T --) {
        int n = read(),m = read();
        for(int i = 1;i <= n;i ++) {
            a[i] = read();
        }
        for(int i = 0;i <= n;i ++)
            for(int j = 0;j <= m+1;j ++)
                f[i][j]=g[i][j]=0;
        f[0][0] = 1;
        for(int j = 0;j <= m+1;j ++) g[0][j] = 1;

        for(int i = 1;i <= n;i ++) {
            for(int j = 0;j <= m;j ++) {
                int x = j<=a[i]?0:g[i-1][j-a[i]-1];
                (f[i][j] = (g[i-1][j] - x)%mod) %= mod;
            }
            g[i][0] = f[i][0];
            for(int j = 1;j <= m+1;j ++)
                g[i][j] = (g[i][j-1] + f[i][j]) % mod;
        }
        for(int i = 0;i <= n;i ++) {
            for(int j = 0;j <= m;j ++) {
                printf("%3d",f[i][j]);
            }
            puts("");
        }
        int ans = 0;
        for(int i = 0;i <= m;i ++) (ans += f[n][i]) %= mod;
        int mu = 1;
        for(int i = 1;i <= n;i ++) mu = 1ll * mu * (a[i]+1) % mod;
        cout << ans << endl;
        printf("%d\n",1ll * ans * ksm(mu,mod-2)%mod);
    }
}

