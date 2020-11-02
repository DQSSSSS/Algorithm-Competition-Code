#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1000000010;
const int MOD = 1000000007;

LL get_ans(LL mid) {
	LL ans = 0,t = 1;
    while(mid) {
    	LL d = mid / 2,mw;
        if(mid & 1) d ++,mw = mid;
        else mw = mid - 1;
//        ans += (1 + mw) * d / 2 * t * (1 << (t - 1));
        //cout << mw << " " << d << " " << t << " " << mid << endl;
        d %= MOD;
        (ans += (1 + mw) % MOD * d % MOD * 500000004 % MOD * t % MOD * ((1ll << (t - 1)) % MOD) % MOD) %= MOD;
        mid >>= 1;
        t ++;
    }
    return ans + 1;
}

LL check(LL mid) {
	LL ans = 0,t = 1;
    while(mid) {
    	LL d = mid / 2;
        if(mid & 1) d ++;
        ans += t * d;
        mid >>= 1;
        t ++;
    }
    return ans + 1;
}

LL Div(LL n) {
    LL l = n / 2,r = n / 2 + 10000;
    while(r - l > 1) {
        LL mid = l + r >> 1;
        if(check(mid) >= n) r = mid;
		else l = mid;
    }
    return r;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T --) {
		LL n;
		scanf("%lld",&n);
		LL x = Div(n);
		LL ans = (get_ans(x) - (x * (check(x) - n) % MOD)) % MOD;
		ans += MOD; ans %= MOD;
        printf("%lld\n",ans);
    }
	return 0;
}

/*
233
1000000000000000000
*/
