#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
const int INF = 1e9 + 10;
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

LL sum[SZ];
LL L[SZ],R[SZ];

int main() {
	int T = read();
    while(T --) {
        int n = read();
        LL fm = 1;
        LL lim1 = 0,lim2 = 0;
        for(int i = 1;i <= n;i ++) {
			L[i] = read(), R[i] = read();
            fm = fm * (R[i] - L[i] + 1ll) % mod;
        	(fm *= 2) %= mod;
        	lim1 = max(lim1,L[i]);
        	lim2 = max(lim2,R[i]);
        }
        for(LL h = lim2;h >= lim1;h --) {
            LL tmp1 = 1,tmp2 = 1;
            for(int i = 1;i <= n;i ++) {
                LL l = L[i],r = min(h,R[i]),r2 = min(h - 1,R[i]);
                if(l > r) { tmp1 = 0; }
                if(l > r2) { tmp2 = 0; }
				(tmp1 *= (2ll * h + 2 - l - r) * (r - l + 1) % mod) %= mod;
				(tmp2 *= (2ll * h + 2 - l - r2) * (r2 - l + 1) % mod) %= mod;
            }
            sum[h] = tmp1 - tmp2;
        }
		//for(LL h = 10000;h >= 1;h --) (sum[h] -= sum[h - 1]) %= mod;
		LL ans = 0;
		for(LL h = lim2;h >= lim1;h --) (ans += sum[h] % mod) %= mod;
		(ans *= ksm(fm,mod - 2)) %= mod;
    	ans += mod; ans %= mod;
    	printf("%lld\n",ans);
    }
	return 0;
}
