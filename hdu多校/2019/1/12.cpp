#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 2e6 + 10;
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
        if(b&1) ans = a * ans % mod;
        a = a *a % mod;
        b >>= 1;
    }
    return ans;
}

struct NTTranform {
   	const int g = 3;
	void Transform(int *a,int n,int opt) {
        for(int i = 0,j = 0;i < n;i ++) {
            if(i < j) swap(a[i],a[j]);
            for(int k = n >> 1;(j ^= k) < k;k >>= 1);
        }
        for(int l = 2;l <= n;l *= 2) {
            int m = l / 2;
            int wn = ksm(g,(mod-1)/l);
            if(opt == -1) wn = ksm(wn,mod - 2);
            for(int *p = a;p != a + n;p += l) {
                for(int i = 0,w = 1;i < m;i ++,w=1ll*w*wn%mod) {
                    int t = 1ll * w * p[m + i] % mod;
                    p[m + i] = (p[i] - t + mod) % mod;
					(p[i] += t) %= mod;
                }
            }
        }
	}
	void dft(int *a,const int n) {
        Transform(a,n,1);
	}
	void idft(int *a,const int n) {
        Transform(a,n,-1);
        int t = ksm(n,mod - 2);
        for(int i = 0;i < n;i ++) a[i] = 1ll * a[i] * t % mod;
	}
}ntt;

void multiply(int *a,int n,int *b,int m,int *ans) { /// need 4 times memory
    static int c1[SZ],c2[SZ];
	int len = 1;
    while(len < n + m) len *= 2;
    for(int i = 0;i < len;i ++) c1[i] = c2[i] = 0;
    for(int i = 0;i < n;i ++) c1[i] = a[i];
    for(int i = 0;i < m;i ++) c2[i] = b[i];
    ntt.dft(c1,len); ntt.dft(c2,len);
    for(int i = 0;i < len;i ++) c1[i] = 1ll * c1[i] * c2[i] % mod;
    ntt.idft(c1,len);
    for(int i = 0;i < n + m - 1;i ++) ans[i] = (c1[i] + mod) % mod;
}

int a[SZ],b[SZ],c[SZ],fac[SZ],invfac[SZ];

int C(int n,int m) {
    if(n<m) return 0;
    return 1ll * fac[n] * invfac[m] % mod * invfac[n-m] % mod;
}

int main() {
    fac[0] = 1;
    for(int i = 1;i <= 2e6;i ++) fac[i] = 1ll * i * fac[i-1] % mod;
    for(int i = 0;i <= 2e6;i ++) invfac[i] = ksm(fac[i],mod-2);
    int T = read();
    while(T --) {
        int n = read(),m = read();
        for(int i = 0;i < n;i ++) a[i] = read();
        int t[4] = {};
        for(int i = 1;i <= m;i ++) t[read()] ++;

        for(int k = 1;k <= 3;k ++) {
            if(t[k] == 0) continue;
            for(int i = 0;i < n;i ++) b[i] = c[i] = 0; b[0] = 1;
            int m = t[k];
            for(int i = 0;i < n;i += k) c[i] = C(i/k-1+m,i/k);
           // for(int i = 0;i < n;i ++) printf("%d ",b[i]); puts("");
           // for(int i = 0;i < n;i ++) printf("%d ",c[i]); puts("");
            multiply(b,n,c,n,b);
          //  for(int i = 0;i < n;i ++) printf("%d ",b[i]); puts("");
            multiply(b,n,a,n,a);
        }
        LL ans = 0;
       // for(int i = 0;i < n;i ++) printf("%d ",a[i]); puts("");
        for(int i = 0;i < n;i ++) {
            ans ^= (i+1ll) * a[i];
        }
        printf("%lld\n",ans);
    }
}

/**
2
5 2
3 2 2 4 1
2 2
*/
