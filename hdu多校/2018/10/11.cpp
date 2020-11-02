#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
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

LL sn[SZ],an[SZ][7];
LL sm[SZ],am[SZ][7];
LL mx[233],mn[233];

int main() {
	int T = read();
	while(T --) {
		int n = read(),m = read(),k = read();
        for(int i = 1;i <= n;i ++) {
            sn[i] = read();
            for(int j = 1;j <= k;j ++) an[i][j] = read();
        }
        for(int i = 1;i <= m;i ++) {
            sm[i] = -read();
            for(int j = 1;j <= k;j ++) am[i][j] = read();
        }

        for(int S = 0;S < (1 << k);S ++) {
            mx[S] = -1e18;
            for(int i = 1;i <= n;i ++) {
                LL x = sn[i];
                for(int j = 0;j < k;j ++) {
                    if(S & (1 << j)) x += an[i][j + 1];
                    else x -= an[i][j + 1];
                }
                mx[S] = max(mx[S],x);
            }
        }
        for(int S = 0;S < (1 << k);S ++) {
            mn[S] = 1e18;
            for(int i = 1;i <= m;i ++) {
                LL x = sm[i];
                for(int j = 0;j < k;j ++) {
                    if(S & (1 << j)) x += am[i][j + 1];
                    else x -= am[i][j + 1];
                }
                mn[S] = min(mn[S],x);
            }
        }
		LL ans = -1e18;
		for(int S = 0;S < (1 << k);S ++)
			ans = max(ans,mx[S] - mn[S]);
        printf("%lld\n",ans);
	}
	return 0;
}
