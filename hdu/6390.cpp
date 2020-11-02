#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
const int INF = 1e9 + 10;
const int mod = 10007;
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

bool vis[SZ];
int pri[SZ],tot,phi[SZ],mu[SZ],f[SZ],F[SZ],inv[SZ];

void shai(int n,int mod) {
	f[1] = phi[1] = mu[1] = 1;
	tot = 0;
	for(int i = 2;i <= n;i ++) {
		if(!vis[i]) pri[++ tot] = i,phi[i] = i - 1,mu[i] = -1,inv[i] = ksm(i - 1,mod - 2,mod),f[i] = 1ll * i * inv[i] % mod;
		for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
			vis[m] = 1;
			if(i % pri[j] == 0) {
				phi[m] = phi[i] * pri[j];
				mu[m] = 0;
				f[m] = f[i];
				break;
			}
			else {
				mu[m] = -mu[i];
				phi[m] = phi[i] * (pri[j] - 1);
				f[m] = 1ll * f[i] * pri[j] % mod * inv[pri[j]] % mod;
			}
		}
		//cout << i << endl;
	}	
	for(int i = 1;i <= n;i ++) F[i] = 0;
	for(int i = 1;i <= n;i ++) {
		if(mu[i])
			for(int j = i;j <= n;j += i)
				(F[j] += mu[i] * f[j / i] % mod) %= mod;
	}
}

int baoli(int n,int m,int mod) {
	int ans = 0;
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m;j ++) {
			/*int x = phi[i * j];
			int y = phi[i] * phi[j];
			int d = __gcd(x,y);
			x /= d;
			y /= d;*/
			//cout << i << " " << j << " " << phi[i * j] << " " << phi[i] << " " << phi[j] << " " << x << "/" << y << endl;
			(ans += 1ll * phi[i * j] % mod * ksm(phi[i],mod - 2,mod) % mod * ksm(phi[j],mod - 2,mod) % mod) %= mod;
		}
	return ans;
}

int baoli2(int n,int m,int mod) {
	int ans = 0;
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m;j ++){
			if(__gcd(i,j) == 1) {ans ++; ans %= mod; continue;}
			LL t = 1;
			for(int k = 1;k <= tot;k ++) {
				int p = pri[k];
				if(p > i || p > j) break;
				if(i % p == 0 && j % p == 0)
					t = 1ll * t * p % mod * ksm(p - 1,mod - 2,mod) % mod;
			}
			(ans += t) %= mod;
		}
	return ans;
}
	
int main() {
	int T = read();
	while(T --) {
		int n = read(),m = read(),mod = read();
		if(n > m)  swap(n,m);
		shai(n,mod);
		int ans = 0;
		for(int i = 1;i <= n;i ++) {
			(ans += 1ll * F[i] * (n / i) % mod * (m / i) % mod) %= mod;
		}
		ans += mod; ans %= mod;
		//printf("%d\n",baoli(n,m,mod));
	//	printf("%d\n",baoli2(n,m,mod));
		printf("%d\n",ans);	
	}
	return 0;
}
