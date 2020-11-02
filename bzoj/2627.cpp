#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 5010;
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

inline LL mul(LL x,LL y,LL z) {
    return (x*y-(LL)(((long double)x*y+0.5)/(long double)z)*z+z)%z;
}

LL ksm(LL a,LL b,LL mod) {
	LL ans = 1;
	while(b){
		if(b & 1) ans = mul(a,ans,mod);
		a = mul(a,a,mod);
		b >>= 1;
	}
	return ans;
}	

LL ksm(LL a,LL b) {
	LL ans = 1;
	while(b){
		if(b & 1) ans = a * ans % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}	

LL gcd(LL a,LL b) { return b == 0 ? a : gcd(b,a % b); }

int C[3100][3100],B[3100],inv[3100];

void pre() {
	C[0][0] = 1;
	for(int i = 1;i <= 3010;i ++) {
		C[i][0] = 1;
		for(int j = 1;j <= i;j ++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}
	inv[1] = 1;B[0] = 1;
	for(int i = 2;i <= 3010;i ++) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	for(int i = 1;i <= 3009;i ++) {
		for(int j = 0;j <= i - 1;j ++)
			(B[i] += 1ll * C[i + 1][j] * B[j] % mod) %= mod;
		B[i] = -1ll * B[i] * inv[i + 1] % mod;
	}
}

namespace pre_mi {
	int a[3100];
	void pre_poly(int m) {
		for(int i = 1;i <= m + 1;i ++) a[i] = 0;
		int x = ksm(m + 1,mod - 2);
		for(int k = 1;k <= m + 1;k ++) a[k] = 1ll * C[m + 1][m + 1 - k] * B[m + 1 - k] % mod * x % mod;
		if(m) a[m] ++;
	}
	LL mi(int n,int m) {
		pre_poly(m);
		LL ans = 0;
		for(int k = 1;k <= m + 1;k ++) {
			(ans += a[k] * ksm(n,k) % mod) %= mod;
		}
		ans += mod; ans %= mod;
		return ans;
	}
}

namespace MR {
	bool check(LL a,LL n,LL x,LL t) {
		LL ans = ksm(a,x,n),lst = ans;
		for(int i = 1;i <= t;i ++) {
			ans = mul(ans,ans,n);
			if(ans == 1 && lst != 1 && lst != n - 1) return true;
			lst = ans;
		}
		if(ans != 1) return true;
		return false;
	}	
	const int S = 8;
	bool Miller_Rabin(LL n) {
		if(n < 2) return false;
		if(n == 2) return true;
		if((n & 1) == 0) return false;
		LL x = n - 1,t = 0;
		while((x & 1) == 0) x >>= 1,t ++;
		for(int i = 0;i < S;i ++) {
			LL a = rand() % (n - 1) + 1;
			if(check(a,n,x,t)) return false;
		}
		return true;
	}
}

namespace Pr {
	LL Pollard_rho(LL x,LL c) {
		LL i = 1,k = 2,x0 = rand() % (x - 1) + 1,y = x0;
		while(1) {
			i ++;
			x0 = (mul(x0,x0,x) + c) % x;
			LL d = gcd(abs(y-x0),x);
			if(d != 1 && d != x) return d;
			if(y == x0) return x;
			if(i == k) y = x0,k <<= 1;
		}
	}
	
	void findfac(LL n,LL factor[]) {
		if(n == 1) return ;
		if(MR :: Miller_Rabin(n)) {
			factor[++ factor[0]] = n;
			return ;
		}
		LL p = n;
		while(p >= n) p = Pollard_rho(n,rand() % (n - 1) + 1);
		findfac(p,factor); findfac(n/p,factor); 
	}
}

LL baoli(int n,int x,int y) {
	LL ans = 0;
	for(int i = 1;i <= n;i ++) {
		int gcd = __gcd(i,n),lcm = n / gcd * i;
		(ans += ksm(gcd,x) * ksm(lcm,y) % mod) %= mod;
	}
	return ans;
}

LL factor[SZ],c[SZ],mi[SZ],mi2[110][SZ];

int main() {
	pre();
	int T = read();
	while(T --) {
		LL n = read(),x = read(),y = read();
		factor[0] = 0;
		pre_mi :: pre_poly(y); Pr :: findfac(n,factor);
		sort(factor + 1,factor + 1 + factor[0]);
		factor[0] = unique(factor + 1,factor + 1 + factor[0]) - factor - 1;
		LL tn = n;
		for(int i = 1;i <= factor[0];i ++) {
			c[i] = 0;
			LL p = factor[i];
			while(tn % p == 0) tn /= p,c[i] ++;
			p%=mod; factor[i] = p;
			mi[i] = y-x>=0?ksm(p,y-x):ksm(ksm(p,x-y),mod-2);
			if(x-(y+1)>=0) mi2[i][y + 1] = ksm(p,x-(y+1));
			else mi2[i][y + 1] = ksm(ksm(p,(y+1)-x),mod - 2);
			for(int k = y;k >= 1;k --) {
				mi2[i][k] = mi2[i][k + 1] * p % mod;
			}
		}
		n %= mod;
		LL ans = 0,nmi = n;
		for(int k = 1;k <= y + 1;k ++) {
			LL t = 1;
			for(int i = 1;i <= factor[0];i ++) {
				LL p = factor[i],C = c[i];
				p = mi2[i][k];
				LL tmp = 0,pp = p;
				while(C --) (tmp += pp) %= mod,(pp *= p) %= mod;
				(tmp *= 1 - mi[i]) %= mod;
				tmp ++;
				(t *= tmp) %= mod;
			}
			(ans += t * pre_mi :: a[k] % mod * nmi % mod) %= mod;
			(nmi *= n) %= mod;
		}	
		(ans *= ksm(n,y)) %= mod;
		ans += mod; ans %= mod;
		printf("%lld\n",ans);
	}
	return 0;
}
