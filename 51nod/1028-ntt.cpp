#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 300010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;
const double PI = acos(-1);

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

struct NTTranform {
   	const int g = 3;
    int wn[SZ],wnInv[SZ];

    void init(int n) {
        for(int i = 0;i < n;i ++) {
			wn[i] = ksm(g,(mod - 1) / n * i);
			wnInv[i] = ksm(wn[i],mod - 2);
        }
    }

	void Transform(int *a,int n,int *wn) {
        int k = 0;
        while((1 << k) < n) k ++;
        for(int i = 0;i < n;i ++) {
        	int t = 0;
        	for(int j = 0;j < k;j ++)
                if(i & (1 << j)) t |= 1 << (k - j - 1);
            if(t > i) swap(a[t],a[i]);
        }
        for(int l = 2;l <= n;l *= 2) {
            int m = l / 2;
            for(int *p = a;p != a + n;p += l) {
                for(int i = 0;i < m;i ++) {
                    int t = 1ll * wn[n / l * i] * p[m + i] % mod;
                    p[m + i] = (p[i] - t) % mod;
					(p[i] += t) %= mod;
                }
            }
        }
	}
	void dft(int *a,const int n) {
        Transform(a,n,wn);
	}
	void idft(int *a,const int n) {
        Transform(a,n,wnInv);
        int t = ksm(n,mod - 2);
        for(int i = 0;i < n;i ++) a[i] = 1ll * a[i] * t % mod;
	}
}ntt;

int c1[SZ],c2[SZ];

void multiply(int *a1,int n1,int *a2,int n2,int *ans) {
	int n = 1;
    while(n < 2 * n1 || n < 2 * n2) n *= 2;
    for(int i = 0;i < n1;i ++) c1[i] = a1[i];
    for(int i = 0;i < n2;i ++) c2[i] = a2[i];
    ntt.init(n); ntt.dft(c1,n); ntt.dft(c2,n);
    for(int i = 0;i < n;i ++) c1[i] = 1ll * c1[i] * c2[i] % mod;
    ntt.idft(c1,n);
    for(int i = 0;i < n1 + n2 - 1;i ++) ans[i] = (c1[i] + mod) % mod;
}

char s1[SZ],s2[SZ];
int a[SZ],b[SZ],c[SZ];

int main() {
	scanf("%s%s",s1,s2);
    int n = strlen(s1),m = strlen(s2);
    for(int i = 0;i < n;i ++) a[i] = s1[n - i - 1] - '0';
    for(int i = 0;i < m;i ++) b[i] = s2[m - i - 1] - '0';
	multiply(a,n,b,m,c);
	for(int i = 0;i < n + m - 1;i ++) c[i + 1] += c[i] / 10,c[i] %= 10;
	int pos = c[n + m - 1] ? n + m - 1 : n + m - 2;
	for(int i = pos;i >= 0;i --) printf("%d",c[i]);
	return 0;
}

