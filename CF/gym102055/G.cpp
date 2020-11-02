#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;

LL read(){
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

int ni6,ni2;

LL sum2(LL n) {
    return n * (n + 1) % mod * (2 * n + 1) % mod * ni6 % mod;
}

LL sum1(LL n) {
    return n * (n + 1) % mod * ni2 % mod;
}

LL sum3(LL n) {
    return sum1(n)*sum1(n)%mod;
}

int main() {
    ni6 = ksm(6,mod-2);
    ni2 = ksm(2,mod-2);
    LL ni4 = ksm(4,mod-2);
    int T = read(),cc = 0;
    while(T --) {
        int n = read(),m = read();
        LL ans = 0;
        if(n <= 2 || m <= 2) ans = 0;
        else {
            LL x = (n*((sum1(n-2)+sum2(n-2)) % mod)%mod-((sum3(n-2)+2*(sum2(n-2))+sum1(n-2))%mod))%mod;
            LL y = (m*((sum1(m-2)+sum2(m-2)) % mod)%mod-((sum3(m-2)+2*(sum2(m-2))+sum1(m-2))%mod))%mod;
            ans = x * y % mod * ni4 % mod;
        }
        ans += mod; ans %= mod;
        printf("Case %d: %lld\n",++ cc,ans);
    }
}

