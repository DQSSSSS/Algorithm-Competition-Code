#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000100;
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
        if(b & 1) ans = ans * a %mod;
        a = a *a % mod;
        b >>= 1;
    }
    return ans;
}

const int ni6 = 166374059;
const int ni2 = 499122177;


LL presum1(LL n) {
    return n * (n + 1) / 2 % mod;
}
LL presum2(LL n) {
    return n * (n + 1) % mod * (2 * n + 1) % mod * ni6 % mod;
}

LL asksum1(LL l,LL r) { return (presum1(r) - presum1(l-1)) % mod; }
LL asksum2(LL l,LL r) { return (presum2(r) - presum2(l-1)) % mod; }


LL getfm(LL n) {
    LL a = (n + 1) * n % mod * n % mod * ni2 % mod;
    a += n * (n + 1) % mod;
    a += ni2 * presum2(n) % mod;
    a += (-n - 3 * ni2 % mod) * presum1(n);
    a %= mod; a += mod; a %= mod;
    return a;
}

int main() {
    cout << 29*ksm(6,mod-2)%mod << endl;
    LL ans = 0;
    for(int i = 1;i <= 5;i ++)
        for(int j = i;j <= 5;j ++)
            ans += j - i + 1;
            cout << ans << endl;
    cout << getfm(5) << endl;
}
