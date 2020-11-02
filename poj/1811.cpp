#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 1000010;
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

inline LL mul(LL x,LL y,LL mod) {
	LL tmp=(x*y-(LL)((long double)x/mod*y+1.0e-8)*mod);
	return tmp<0 ? tmp+mod : tmp;
}

LL ksm(LL a,LL b,LL mod) {
	LL ans = 1;
	while(b) {
		if(b & 1) ans = mul(ans,a,mod);
		a = mul(a,a,mod);
		b >>= 1;
	}
	return ans;
}

LL gcd(LL a,LL b) { return b == 0 ? a : gcd(b,a % b); }

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
		if(!(n & 1)) return false;
		LL x = n - 1,t = 0;
		while((x & 1) == 0) {x >>= 1; t ++;}
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
			LL d = gcd(y-x0 < 0 ? x0 - y : y - x0,x);
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

LL factor[SZ];

int main() {
	int T = read();
	while(T --) {
		LL n = read();
		if(MR :: Miller_Rabin(n)) puts("Prime");
		else {
			factor[0] = 0;
			Pr :: findfac(n,factor);
			LL ans = 1e18;
			for(int i = 1;i <= factor[0];i ++)
				ans = min(ans,factor[i]);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
