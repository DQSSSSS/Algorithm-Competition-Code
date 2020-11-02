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

LL ksm(LL a,LL b) {
	LL ans = 1;
    while(b) {
    	if(b & 1) ans = a * ans %mod;
    	a = a * a %mod;
    	b >>= 1;
    }
    return ans;
}

LL f[2][3],dp[2][3],A[2][3];

void update() {
    memcpy(f,dp,sizeof dp);
    memset(dp,0,sizeof dp);
    for(int i = 0;i <= 1;i ++)
    	for(int j = 0;j <= 2;j ++)
    		for(int a = 0;a <= 1;a ++)
                for(int b = 0;b <= 2;b ++)
                    (dp[min(i + a,1)][min(j + b,2)] += f[i][j] * A[a][b] % mod) %= mod;
    memset(A,0,sizeof A);
}

int main() {
    int T = read();
    while(T --) {
        LL a = read(),b = read();
        LL c = read(),d = read();

        memset(dp,0,sizeof dp);
        dp[0][0] = ksm(2,a);
        A[0][0] = 1; A[0][1] = b; A[0][2] = (ksm(2,b) - b - 1) % mod; update();
        A[0][0] = 1; A[1][0] = (ksm(2,c) - 1) % mod; update();
        A[0][0] = 1; A[1][1] = d; A[1][2] = (ksm(2,d) - d - 1) % mod; update();
		LL ans = ((ksm(2,a+b+c+d) - dp[1][2]) % mod + mod) % mod;
        printf("%lld\n",ans);
    }
    return 0;
}

