#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
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

LL ksm(LL a,LL b) {
	LL ans = 1;
    while(b) {
    	if(b & 1) ans = a * ans % mod;
    	a = a * a % mod;
    	b >>= 1;
    }
    return ans;
}

LL ans = 0,n,k,S;
int num[SZ];

void dfs(int d) {
	if(d == n + 1) {
        if((~(num[n] ^ num[1])) & S) {
	        ans ++;
          //  for(int i = 1;i <= n;i ++) cout << num[i] << " "; puts("");
	    }
        return ;
	}
    for(int i = 0;i < (1 << k);i ++) {
        if(d == 1 || ((~(i ^ num[d - 1])) & S)) {
            num[d] = i;
            dfs(d + 1);
        }
    }
}

void baoli() {
	for(n = 1;n <= 5;n ++,puts(""))
    	for(k = 1;k <= 5;k ++) {
    		ans = 0; S = (1 << k) - 1;
            dfs(1);
            printf("%lld %lld %lld\n",n,k,ans);
    	}
}

LL f[SZ];

LL work(LL n,LL k) {
	LL m = ksm(2,k),ans;
    f[0] = m; f[1] = m;
   	LL x = 1;
    for(int i = 2;i <= n;i ++) {
		LL d = m * x % mod;
        f[i] = f[i - 2] * (m - 1) % mod + (d - f[i - 2]) % mod * (m - 2) % mod;
        f[i] %= mod;
		(x *= m - 1) %= mod;
	}
	return (f[n] + mod) % mod;
}

int main() {
    /*for(n = 1;n <= 5;n ++) {
        for(k = 1;k <= 5;k ++) {
        	ans = 0; S = (1 << k) - 1;
            dfs(1);
            printf("%lld %lld %lld %lld\n",n,k,ans,work(n,k));
        }
    }*/
	int T = read();
	while(T --) {
		LL n = read(),k = read();
        printf("%lld\n",work(n,k));
	}
	return 0;
}
