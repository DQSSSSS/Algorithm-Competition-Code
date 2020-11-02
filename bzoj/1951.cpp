#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 100010;
const int INF = 1e9 + 10;
const int mod = 999911659;
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

LL ksm(LL a,LL b,LL mod) {
	LL ans = 1;
	while(b) {
		if(b & 1) ans = ans * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

LL exgcd(LL a,LL b,LL &x,LL &y) {
    if(b == 0) {
        x = 1; y = 0;
        return a;
    }
    LL d = exgcd(b,a % b,x,y);
    LL t = x;
    x = y; y = t - a / b * y;
    return d;
}

LL Mod[] = {0,2,3,35617,4679};
int fac[SZ],inv[SZ];

LL C(LL n,LL m,LL p) {
    if(n < m) return 0;
    if(n < p && m < p) return 1ll * fac[n] * inv[m] % p * inv[n - m] % p;
    return C(n / p,m / p,p) * C(n % p,m % p,p) % p;
}

LL work(LL m[],LL a[],int n) {
    LL A = a[1],M = m[1],x,y;
   // for(int i = 1;i <= n;i ++) cout << a[i] <<endl;
    for(int i = 2;i <= n;i ++) {
        LL d = exgcd(M,m[i],x,y);
        if((a[i] - A) % d) return -1;
        x *= (a[i] - A) / d;
        LL t = m[i] / d; x = (x % t + t) % t;
        A = M * x + A; M = M / d * m[i]; A %= M;
    }
    return (A + M) % M;
}


LL a[SZ];

int main() {
	LL n = read(),g = read();
    for(int k = 1;k <= 4;k ++) {
        LL p = Mod[k];
     //   cout << p <<endl;
        fac[0] = 1;
        for(int i = 1;i < p;i ++) fac[i] = 1ll * fac[i - 1] * i % p;
        inv[p - 1] = ksm(p - 1,p - 2,p);
        inv[0] = 1;
        for(int i = p - 2;i >= 1;i --) inv[i] = 1ll * inv[i + 1] * (i + 1) % p;
    //    for(int i = 1;i <= 10;i ++) cout << fac[i] << " "; puts("");
     //   for(int i = 1;i <= 10;i ++) cout << inv[i] << " "; puts("");
		for(LL d = 1;d * d <= n;d ++) {
			if(n % d == 0) {
		//		cout << n << " " << d << " " << p << " " << C(n,d,p) << endl;
		//		cout << n << " " << n / d << " " << p << " " << C(n,n / d,p) << endl;
				(a[k] += C(n,d,p)) %= p;
				if(d * d != n) (a[k] += C(n,n / d,p)) %= p;
			}
		}
    }
    LL ans = work(Mod,a,4) + 999911658;
    printf("%lld\n",ksm(g,ans,mod));
	return 0;
}
