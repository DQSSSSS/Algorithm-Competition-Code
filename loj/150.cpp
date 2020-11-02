#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 4001000;
const int INF = 1e9 + 10;
const int mod = 998244353;
const double PI = acos(-1);

LL read() {
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a <= '9' && a >= '0') n = n * 10 +a - '0',a = getchar();
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

LL ksm(LL a,LL b,LL mod) {
	LL ans = 1;
    while(b) {
    	if(b & 1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

LL BSGS(LL a,LL b,LL mod) { //a^x = b (% mod)
    a %= mod; b %= mod;
    if(a == 0 && b == 0) return 1;
    else if(a == 0) return -1;
    unordered_map<int,int> h;
    LL m = ceil(sqrt(mod));
    LL amni = ksm(a,mod - m - 1,mod);
    LL t = 1;
    h[t] = 0;
    for(int i = 1;i < m;i ++) {
        t = (t * a) % mod;
        if(t != 1 && !h[t])
            h[t] = i;
    }
    for(int i = 0;i <= m - 1;i ++) {
        LL ans = h[b];
        if(b == 1 || ans)
            return i * m + ans;
        b = (b * amni) % mod;
    }
    return -1;
}

void exgcd(LL a,LL b,LL &x,LL &y) {
    if(b == 0) {
        x = 1; y = 0;
        return;
    }
    exgcd(b,a%b,x,y);
    LL t = x; x = y; y = t - a/b*y;
}

LL get_X(LL A,LL k,LL p) { // A=kx % p
    LL d = __gcd(k,p);
    A /= d; p /= d; k /= d;
    LL x,K;
    exgcd(k,p,x,K);
    return ((A*x%p)+p)%p;
}

int gen(int n,int k) { //n^(1/k)%p
    int A = BSGS(3,n,mod);
    int x = ksm(3,get_X(A,k,mod-1));
    return min(x,mod-x);
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
}

void derivative(int *a,int n,int *b) {
    b[n-1] = 0;
    for(int i = 0;i < n-1;i ++) b[i] = 1ll * a[i+1] * (i+1) % mod;
}

void integral(int *a,int n,int *b) {
    for(int i = n;i >= 0;i --) b[i] = a[i-1] * ksm(i,mod-2) % mod;
}

void ln(int *a,int n,int *b) { ///a[0]=1
    static int c1[SZ],c2[SZ],c3[SZ];
    inverse(a,n,c1);
    derivative(a,n,c2);
    multiply(c1,n,c2,n-1,c3);
    integral(c3,n+1,b);
}

void exp(int *a,int n,int *b) { ///a[0]=0
    static int c[SZ];
    b[0] = 1;
    for(int l = 2;l < n*2;l <<= 1) {
        ln(b,l,c);
        for(int i = 0;i < l;i ++) c[i] = (a[i]-c[i]+mod)%mod;
        c[0] ++; multiply(c,l,b,l,b);
    }
}

void sin(int *a,int n,int *b) { ///a[0]=0
    static int A[SZ],B[SZ],C[SZ];
    const int j = 86583718,ni2j = ksm(86583718*2%mod,mod-2);
    for(int i = 0;i < n;i ++) A[i] = 1ll * a[i] * j % mod; exp(A,n,B);
    for(int i = 0;i < n;i ++) A[i] = 1ll * a[i] * (mod-j) % mod; exp(A,n,C);
    for(int i = 0;i < n;i ++) b[i] = 1ll*(B[i]-C[i]+mod)*ni2j%mod;
}

void cos(int *a,int n,int *b) { ///a[0]=0
    static int A[SZ],B[SZ],C[SZ];
    const int j = 86583718,ni2 = ksm(2,mod-2);
    for(int i = 0;i < n;i ++) A[i] = 1ll * a[i] * j % mod; exp(A,n,B);
    for(int i = 0;i < n;i ++) A[i] = 1ll * a[i] * (mod-j) % mod; exp(A,n,C);
    for(int i = 0;i < n;i ++) b[i] = 1ll*(B[i]+C[i])*ni2%mod;
}

void tan(int *a,int n,int *b) {
    static int A[SZ],B[SZ];
    sin(a,n,A); cos(a,n,B);
    inverse(B,n,b); multiply(A,n,b,n,b);
}

void sqrt(int *a,int n,int *b) { /// b[0]=sqrt(a[0])%p  need 8 times memory
    static int c1[SZ],c2[SZ],ni2 = ksm(2,mod-2);
    b[0] = gen(a[0],2);
    for(int l = 2;l < n*2;l <<= 1) {
        inverse(b,l*2,c2);
        multiply(a,l*2,c2,l*2,c1);
        for(int i = 0;i < l*2;i ++) b[i] = 1ll*(b[i]+c1[i])*ni2%mod;
    }
}

void arcsin(int *a,int n,int *b) { ///a[0]=0
    static int c[SZ],A[SZ];
    multiply(a,n,a,n,c);
    derivative(a,n,A);
    for(int i = 0;i < n;i ++) c[i] = (mod-c[i])%mod;
    c[0] ++; sqrt(c,n,b); inverse(b,n,c);
    multiply(c,n,A,n,c); integral(c,n-1,b);
}

void arctan(int *a,int n,int *b) { ///a[0]=0
    static int c[SZ],A[SZ];
    multiply(a,n,a,n,b); derivative(a,n,A); b[0] ++;
    inverse(b,n,c); multiply(c,n,A,n,c); integral(c,n-1,b);
}

void power(int *a,int n,int k,int *b) {
    static int c[SZ],d[SZ];
    LL t = 0;
    for(int i = 0;i < n;i ++) if(a[i]) { t = i; break; }
    for(int i = 0;i < n-t;i ++) c[i] = a[i+t];

    if(t*k>=n)
        for(int i = 0;i < n;i ++) b[i] = 0;
    else {
        int x = c[0];
        for(int i = 0;i < n-t*k;i ++) c[i] = c[i] * ksm(x,mod-2) % mod;
        ln(c,n-t*k,d); /// a[0]=1的话只要这一行到exp，项数改为n即可
        for(int i = 0;i < n-t*k;i ++) d[i] = 1ll * d[i] * k % mod;
        exp(d,n-t*k,b);
        x = ksm(x,k);
        for(int i = n-1;i >= t*k;i --) b[i] = 1ll * b[i-t*k] * x % mod;
        for(int i = 0;i < t*k;i ++) b[i] = 0;
    }
}

void sqrtk(int *a,int n,int k,int *b) {
    static int c[SZ];
    int gk = gen(a[0],k);
    ln(a,n,c);
    for(int i = 1;i < n;i ++) c[i] = 1ll * c[i] * ksm(k,mod-2) % mod;
    exp(c,n,b);
    for(int i = 0;i < n;i ++) b[i] = 1ll * b[i] * gk % mod;
}

int F[SZ],a[SZ],b[SZ],c[SZ];

int main() {
    int n = read() + 1,k = read();
    for(int i = 0;i < n;i ++) F[i] = read();
    sqrtk(F,n,2,a); inverse(a,n,b); integral(b,n,a); exp(a,n,b);
    for(int i = 0;i < n;i ++) c[i] = (F[i]-b[i]+mod) % mod;
    c[0] = (c[0] + mod - F[0]) % mod; c[0] += 2; c[0] %= mod;
    ln(c,n,a); a[0] ++; power(a,n,k,b); derivative(b,n,a);
    for(int i = 0;i < n-1;i ++) printf("%d ",a[i]); puts("");
    return 0;
}
