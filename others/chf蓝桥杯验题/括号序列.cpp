#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2e7 + 10;
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

LL ksm(LL a,LL b) {
    LL ans = 1 % mod;
    while(b) {
        if(b & 1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

LL k,q;
LL fac[SZ],facinv[SZ],mi[SZ],inv[SZ],h[SZ];

void init(int n) {
    mi[0] = 1;
    fac[0] = 1;
    for(int i = 1;i <= n;i ++) {
        mi[i] = mi[i - 1] * k % mod;
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[1] = 1;
    for(int i = 2;i <= n+1;i ++) {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
    h[0] = 1; h[1] = 1;
    for(int i = 2;i <= n;i ++) {
        h[i] = h[i - 1] * (4 * i - 2) % mod * inv[i + 1] % mod;
    }
    facinv[n] = ksm(fac[n],mod - 2);
    for(int i = n-1;i >= 0;i --) facinv[i] = facinv[i + 1] * (i + 1) % mod;
}

LL C(LL n,LL m) {
    return fac[n] * facinv[m] % mod * facinv[n-m] % mod;
}

LL get_ans(LL n) {
    LL ans = 0;
    for(int i = 0;i * 2 <= n;i ++) {
        LL a = (n-2*i+1)*mi[n-2*i]%mod;
        LL b = C(n,2*i) * h[i] % mod * mi[i] % mod;
        ans += a * b % mod;
        ans %= mod;
        ///cout << a << " " << b << endl;
        //printf("%lld %lld %lld\n",C(n,2*i),h[i],mi[i]);
    }
    return ans;
}

int main() {
    k = read(),q = read();
    init(1e7);
    while(q --) {
        int n = read();
        cout << get_ans(n) << endl;
    }
    return 0;
}
