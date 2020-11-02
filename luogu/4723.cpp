#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
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
        a = a * a % mod;
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

void inverse(int *a,int n,int *b) { /// need 4 times memory
    static int A[SZ];
    b[0] = ksm(a[0],mod-2);
    for(int l = 2;l < n*2;l <<= 1) {
        for(int i = 0;i < l;i ++) A[i] = a[i];
        for(int i = l;i < l*2;i ++) A[i] = 0;
        for(int i = l/2;i < l*2;i ++) b[i] = 0;
        ntt.dft(A,l*2); ntt.dft(b,l*2);
        for(int i = 0;i < l*2;i ++) b[i] = (b[i]*2-1ll*A[i]*b[i]%mod*b[i]%mod+mod)%mod;
        ntt.idft(b,l*2);
    }
}

void divide(int *a,int n,int *b,int m,int *D) { /// need 4 times memory
    static int bni[SZ];
    if(n<m) { D[0]=0; return ; }
    reverse(a,a+n); reverse(b,b+m);
    inverse(b,n-m+1,bni);
    multiply(a,n-m+1,bni,n-m+1,D);
    reverse(D,D+n-m+1);
    reverse(a,a+n); reverse(b,b+m);
}

void modular(int *a,int n,int *b,int m,int *R) { /// need 4 times memory
    static int D[SZ],c[SZ];
    if(n<m) { for(int i = 0;i < n;i ++) R[i] = a[i]; return ; }
    divide(a,n,b,m,D);
    multiply(b,m,D,n-m+1,c);
    for(int i = 0;i < m-1;i ++) R[i] = (a[i] - c[i] + mod) % mod;
    R[m-1] = 0;
}

// f:长度为k的线性递推式，a：初始k项。求第n项
int get_nth(int f[],int a[],int k,int n) {
    if(n<k) return a[n];
    static int ff[SZ],G[SZ],Ans[SZ];
    for(int i = 1;i <= k;i ++) ff[k-i] = (mod - f[i])%mod;
    ff[k] = 1;
    G[1] = 1; Ans[0] = 1;
    while(n) {
        if(n&1) {
            multiply(Ans,k,G,k,Ans),modular(Ans,2*k-1,ff,k+1,Ans);
        }
        multiply(G,k,G,k,G);
        modular(G,2*k-1,ff,k+1,G);
        n >>= 1;
    }
    int ans = 0;
    for(int i = 0;i < k;i ++) (ans += 1ll * a[i] * Ans[i] % mod) %= mod;
    ans += mod; ans %= mod;
    return ans;
}

int n, k;
int f[SZ],a[SZ];

int main(){
    //freopen("testdata (4).in","r",stdin);
    n = read(), k = read();
    for(int i = 1;i <= k;i ++) f[i] = read();
    for(int i = 0;i < k;i ++) a[i] = read();
    cout << get_nth(f,a,k,n);
    return 0;
}
