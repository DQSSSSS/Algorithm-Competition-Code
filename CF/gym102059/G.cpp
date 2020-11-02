#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 300100;
const LL INF = 1e18;
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

LL f[SZ][11][11],w[SZ];

int main() {
   // freopen("G.in","r",stdin);
   // freopen("my.out","w",stdout);
    int n = read(),k = read();
    for(int i = 1;i <= n;i ++) w[i] = read();
    n ++; w[n] = INF;
    n ++; w[n] = 0;
    for(int i = 0;i <= n;i ++)
        for(int a = 0;a <= k;a ++)
            for(int b = 0;b <= k;b ++)
                f[i][a][b] = INF;
    f[0][0][0] = 0;
    for(int i = 0;i <= n;i ++) {
        for(int a = 0;a <= k;a ++)
            for(int b = 0;b <= k;b ++) {
                if(f[i][a][b] >= 1e18) continue;
                if(i+1<=n) {
                                f[i+1][a][b]    = min(f[i+1][a][b],f[i][a][b]+w[i+1]);
                    if(a<k)     f[i+1][a+1][b]  = min(f[i+1][a+1][b],f[i][a][b]);
                   // if(b)       f[i+1][a][b-1]  = min(f[i+1][a][b-1],f[i][a][b]);
                }
                if(i+2<=n) {
                                    f[i+2][a][b]        = min(f[i+2][a][b],f[i][a][b]+w[i+2]);
                    if(a<k)         f[i+2][a+1][b]      = min(f[i+2][a+1][b],f[i][a][b]);
                   // if(b)           f[i+2][a][b-1]      = min(f[i+2][a][b-1],f[i][a][b]);
                    if(b<k)         f[i+2][a][b+1]      = min(f[i+2][a][b+1],f[i][a][b]+w[i+1]+w[i+2]);
                    if(a<k&&b<k)    f[i+2][a+1][b+1]    = min(f[i+2][a+1][b+1],f[i][a][b]+w[i+1]);
                }
                if(i+3<=n&&i) {
                                    f[i+3][a][b]        = min(f[i+3][a][b],f[i][a][b]+w[i+3]);
                    if(a<k)         f[i+3][a+1][b]      = min(f[i+3][a+1][b],f[i][a][b]);
                    //if(b)           f[i+3][a][b-1]      = min(f[i+3][a][b-1],f[i][a][b]);
                    if(b<k)         f[i+3][a][b+1]      = min(f[i+3][a][b+1],f[i][a][b]+min(w[i+1],w[i+2])+w[i+3]);
                    if(a<k&&b<k)    f[i+3][a+1][b+1]    = min(f[i+3][a+1][b+1],f[i][a][b]+min(w[i+1],w[i+2]));
                    if(b+1<k)       f[i+3][a][b+2]      = min(f[i+3][a][b+2],f[i][a][b]+w[i+1]+w[i+2]+w[i+3]);
                    if(a<k&&b+1<k)  f[i+3][a+1][b+2]    = min(f[i+3][a+1][b+2],f[i][a][b]+w[i+1]+w[i+2]);
                }
            }
    }

    LL ans = 1e18;
    for(int i = 0;i <= k;i ++) {
        ans = min(ans,f[n][i][i]);
        //if(n>1) ans = min(ans,f[n-1][i][i]);
        //if(n>2) ans = min(ans,f[n-2][i][i]);
        //printf("%lld %lld\n",f[n-1][i][i],f[n][i][i]);
    }
    cout << ans << endl;
}

/**
7 1
2 3 100 2 1 2 100

3 1
7 8 4

9 2
6 7 7 2 2 6 7 5 4
*/
