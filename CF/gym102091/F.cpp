#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 3e5 + 10;
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
    LL ans = 1;
    while(b) {
        if(b & 1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

const int p = 23;

int ni2;
LL mi[110];

void init() {
    for(LL i = 1,j = 0;i <= 1e18 / p;i *= p,j ++) {
        mi[j] = i;
    }
    ni2 = ksm(2,mod-2);
}

int lg(LL n) {
    LL j = 0;
    for(LL i = 1;i <= 1e18 / p;i *= p,j ++)
        if(mi[j] > n) return j - 1;
    return j-1;
}

LL work(LL m,LL k) {
    return (2*(m%mod)*(k%mod)%mod-(k%mod)*(k%mod)%mod+k%mod)%mod*ni2%mod;
}

unordered_map<LL,LL> mp;

LL dfs(LL n) {
    if(n < p) return 0;
    if(mp.count(n)) return mp[n];
    LL m = mi[lg(n)];
    LL t = (n + 1) / m;
    LL a = t%mod*((t+1)%mod)%mod*ni2%mod * dfs(m-1)%mod;
    LL b = t%mod*((t-1)%mod)%mod*ni2%mod * (m%mod)%mod*((m-1)%mod)%mod*ni2%mod;
    LL c = 0,d = 0;
    if((n+1)%m) {
        c = (t+1)%mod*dfs(n%m)%mod;
        d = t%mod*work(m-1,(n+1)%m)%mod;
    }
    return mp[n] = (a+b+c+d)%mod;
}

int main() {
    init();
    int T = read(),cc = 0;
    while(T --) {
        LL n = read();
        LL ans = (dfs(n)+mod)%mod;
        printf("Case %d: %lld\n",++cc,ans);
    }
}
