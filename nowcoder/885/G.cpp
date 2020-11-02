#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 6e6 + 10;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

int f[3010][3010][2];
int h[3010][3010];
int P[3010];
int g[3010][2];
char s[SZ],t[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read(),m = read();
        scanf("%s%s",s+1,t+1);
        for(int i = 1;i <= n;i ++) {
            f[i][1][0] = s[i] > t[1];
            f[i][1][1] = s[i] == t[1];
            h[i][1] = s[i] != '0';
        }
        for(int j = 2;j <= m;j ++) {
            for(int i = 1;i <= n;i ++) {
                g[i][0] = (g[i-1][0] + f[i][j-1][0]) % mod;
                g[i][1] = (g[i-1][1] + f[i][j-1][1]) % mod;
            }
            for(int i = 1;i <= n;i ++) {
                if(s[i] > t[j]) {
                    f[i][j][0] = (g[i-1][0] + g[i-1][1]) % mod;
                    f[i][j][1] = 0;
                }
                else if(s[i] == t[j]) {
                    f[i][j][0] = g[i-1][0];
                    f[i][j][1] = g[i-1][1];
                }
                else {
                    f[i][j][0] = g[i-1][0];
                    f[i][j][1] = 0;
                }
            }
        }
        for(int l = 2;l <= n;l ++) {
            for(int i = 1;i <= n;i ++) (P[i] = P[i-1] + h[i][l-1]) %= mod;
            for(int i = 1;i <= n;i ++) {
                h[i][l] = P[i-1];
            //    cout << h[i][l] << " ";
            }
           // puts("");
        }
        int ans = 0;
        for(int i = 1;i <= n;i ++) (ans += f[i][m][0]) %= mod;
        for(int i = 1;i <= n;i ++)
            for(int l = m+1;l <= n;l ++)
                (ans += h[i][l]) %= mod;
        printf("%d\n",ans);
    }
}
