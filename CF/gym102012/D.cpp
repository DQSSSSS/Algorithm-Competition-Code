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

int a[SZ];
int f[210][210];
int g[210][210];
char mp[210][210];

int main() {
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 1;i <= n;i ++) a[i] = read();
        for(int i = 1;i <= n;i ++) {
            scanf("%s",mp[i]+1);
            for(int j = 1;j <= n;j ++) {
                f[i][j] = 0;
            }
        }
        int ans = 0;
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= n;j ++) {
                for(int k = 1;k <= n;k ++) {
                    g[j][k] = mp[a[j]][a[i]] == '1' ? f[j][k] : 0;
                    (g[j][k] += ((g[j-1][k] + g[j][k-1])%mod - g[j-1][k-1]+mod)% mod) %= mod;
                }
            }

            for(int j = 1;j <= n;j ++) {
                for(int k = 1;k <= n;k ++) {
                    if(a[i] == a[j] && a[j] == a[k]) {
                        (f[j][k] += 1 + g[j-1][k-1]) %= mod;
                        (ans += 1 + g[j-1][k-1]) %= mod;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}
