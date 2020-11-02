#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 550010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;
const LD PI = acos(-1);

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
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

struct FFT {
	int wn[SZ],wnInv[SZ];
	void init(int n) {
		for(int i = 0;i < n;i ++) {
			wn[i] = ksm(3,(mod - 1) / n * i);
			wnInv[i] = ksm(wn[i],mod - 2);
		}
	}
	
	void Transform(int a[],int n,const int wn[]) {
		for(int i = 0,j = 0;i < n;i ++) {
			if(i > j) swap(a[i],a[j]);
			for(int k = n >> 1;(j ^= k) < k;k >>= 1);
		}
		
		for(int l = 2;l <= n;l <<= 1) {
			int m = l / 2;
			for(int *p = a;p != a + n;p += l) {
				for(int i = 0;i < m;i ++) {
					int t = 1ll * wn[n / l * i] * p[i + m] % mod;
					p[i + m] = (p[i] - t + mod) % mod;
					p[i] = (p[i] + t) % mod;
				}
			}
		}
	}
	
	void dft(int a[],int n) {
		Transform(a,n,wn);
	}
	
	void idft(int a[],int n) {
		Transform(a,n,wnInv);
		int t = ksm(n,mod - 2);
		for(int i = 0;i < n;i ++) a[i] = 1ll * a[i] * t % mod;
	}
}fft;


int mi[SZ],inv[SZ],c1[SZ],c2[SZ];

int main() {
	int n = read();
	mi[0] = 1; inv[1] = 1;
	for(int i = 1;i <= n;i ++) mi[i] = 1ll * mi[i - 1] * 2 % mod;
	for(int i = 2;i <= n;i ++) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	//for(int i = 1;i <= n;i ++) cout << inv[i] << " ";
	inv[0] = 1;
	for(int i = 1;i <= n;i ++) inv[i] = 1ll * inv[i] * inv[i - 1] % mod;
	
	for(int i = 0,t = 1;i < n;i ++) {
		c2[i] = c1[i] = read() * t % mod;
		t = 1ll * t * (i + 1) % mod;
	}
	/*for(int i = 0;i < n;i ++) cout << c1[i] << " "; puts("");
	for(int i = 0;i < n;i ++) cout << c2[i] << " "; puts("");
	for(int i = 0;i < n;i ++) cout << mi[i] << " "; puts("");
	for(int i = 0;i < n;i ++) cout << inv[i] << " "; puts("");*/
	int len = 1;
	while(len < 2 * n) len <<= 1;
	fft.init(len);
	fft.dft(c1,len);
	fft.dft(c2,len);
	for(int i = 0;i < len;i ++) c1[i] = 1ll * c1[i] * c2[i] % mod;
	fft.idft(c1,len);
	//for(int i = 0;i < 2 * n - 1;i ++) cout << c1[i] << " "; puts("");
	for(int i = n - 1;i < 2 * n - 1;i ++) {
		int x = i - n + 1;
		int d = 1ll * mi[x] * inv[x] % mod;
		//cout << d << " ";
		printf("%lld%c",1ll * c1[i] * d % mod,i == 2 * n - 2 ? '\n' : ' ');
	}
	return 0;
}
