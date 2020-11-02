#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 510;
const LL INF = 1e18;
const int mod = 1e9 + 7;
const LD eps = 1e-7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int one[SZ],zero[SZ];
int f0[SZ][SZ],f1[SZ][SZ];
int s0[SZ],s1[SZ];

int main() {
	int n = read();// + 2;
	for(int i = 1;i <= n;i ++) {
		one[i] = read();
		zero[i] = 1000 - one[i];
	}
	//one[1] = 0; zero[1] = 1000;
	//zero[n] = 0; one[n] = 1000;
	LL ans = 0;
	for(int k = 1;k <= n;k ++) {
		memset(f0,0,sizeof f0); memset(s0,0,sizeof s0);
		memset(f1,0,sizeof f1); memset(s1,0,sizeof s1);
		f0[0][0] = 1;
		for(int i = 1;i <= k;i ++) ///i个数
			for(int j = 0;j <= i;j ++) { ///j个0
				int cnt = 2 * j - i;
				if(cnt < 0) continue;
				(f0[i][j] += 1ll * f0[i - 1][j - 1] * zero[k-i+1] % mod) %= mod;
				(f0[i][j] += 1ll * f0[i - 1][j] * one[k-i+1] % mod) %= mod;
			}
		f1[0][0] = 1;
		for(int i = 1;i <= n-k;i ++) ///i个数
			for(int j = 0;j <= i;j ++) { ///j个1
				int cnt = 2 * j - i;
				if(cnt <= 0) continue;
				(f1[i][j] += 1ll * f1[i - 1][j - 1] * one[k+i] % mod) %= mod;
				if(cnt) (f1[i][j] += 1ll * f1[i - 1][j] * zero[k+i] % mod) %= mod;
			}
		for(int j = 0;j <= k;j ++) (s0[j] += f0[k][j]) %= mod;
		for(int j = 0;j <= n-k;j ++) (s1[j] += f1[n-k][j]) %= mod;
		
		for(int i = 0;i <= k;i ++)
			for(int j = 0;j <= n - k;j ++)	
				(ans += 1ll * (i) * (i + j) % mod * s0[i] % mod * s1[j] % mod) %= mod;
		
		/*for(int i = 1;i <= k;i ++,puts("")) ///i个数
			for(int j = 0;j <= i;j ++)
				cout << f0[i][j] << " ";
		puts("----");
		
		for(int i = 1;i <= n-k;i ++,puts("")) ///i个数
			for(int j = 0;j <= i;j ++)
				cout << f1[i][j] << " ";
		puts("----");
		
		cout << k << endl;
		for(int i = 0;i <= k;i ++) cout << s0[i] << " "; puts("");
		for(int i = 0;i <= n-k;i ++) cout << s1[i] << " "; puts("");
		cout << ans << endl;
		puts("");*/
	}
	printf("%lld\n",ans);
	return 0;
}
/**
5
0 0 0 0 0

2
1 1
3950001
*/
