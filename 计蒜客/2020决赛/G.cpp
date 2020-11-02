#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-12;

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

int a[33][SZ];

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++) {
        int x = read();
        for(int j = 0;j < 31;j ++) {
            a[j][i] = (x>>j&1);
        }
    }
    for(int j = 0;j < 31;j ++) {
        for(int i = 1;i <= n;i ++) {
            a[j][i] = a[j][i-1] + a[j][i];
        }
    }
    while(m --) {
        int l = read(),r = read(),x = read();
        int len = r-l+1;
        LL S = 1,ans = 0;
        for(int j = 0;j < 31;j ++) {
            int B = a[j][r] - a[j][l-1];
            int A = len - B;
            LL y = (ksm(1+x,B) - ksm(1-x,B)) % mod * ksm(2,mod-2) % mod;
            LL tmp = ksm(1+x,A) * y % mod;
            (ans += S * tmp % mod) %= mod;
            S = S * 2 % mod;
        }
        ans %= mod; ans += mod; ans %= mod;
        printf("%lld\n",ans);
    }
}
