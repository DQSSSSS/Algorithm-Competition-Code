#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 8e6 + 10;
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
        if(b&1) ans = a * ans %mod;
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

int a[SZ];

int main() {
    int n = read(),k = read();
    for(int i = 1;i <= k;i ++) {
        a[read()] = 1;
    }
    int len = 1;
    while(len < 9*n) len *= 2;
    ntt.dft(a,len);
    for(int i = 0;i < len;i ++) a[i] = ksm(a[i],n/2);
    ntt.idft(a,len);
    int ans = 0;
    for(int i = 0;i < len;i ++) {
        (ans += 1ll * a[i] * a[i] % mod) %= mod;
    }
    cout << ans << endl;
    return 0;
}

