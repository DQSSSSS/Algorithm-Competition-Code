#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UI;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
const int INF = 1e9 + 10;
const LL mod = 1e9 + 7;
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

int pri[SZ],tot = 0,mu[SZ];
bool vis[SZ];

void shai(int n) {
	mu[1] = 1;
	for(int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ tot] = i,mu[i] = 1;
        for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
        	vis[m] = 1;
            if(i % pri[j] == 0) {
                mu[m] = 0;
            	break;
        	}
        	else {
				mu[m] = -mu[i];
        	}
        }
	}
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

int a[SZ],sum[SZ];

int main() {
    int T,cc = 0;
    scanf("%d",&T);
    shai(1e5);
    while(T --) {
    	int n;
    	scanf("%d",&n);
    	int minn = 1e5;
    	for(int i = 1;i <= 1e5;i ++) sum[i] = 0;
    	for(int i = 1;i <= n;i ++) {
    		scanf("%d",&a[i]);
    		minn = min(minn,a[i]);
    		sum[a[i]] ++;
       	}
       	for(int i = 1;i <= 1e5;i ++) sum[i] += sum[i - 1];
        LL ans = 0;
        for(LL d = 2;d <= minn;d ++) {
			LL tmp = 1;
            for(LL i = d;i <= 1e5;i += d)
				(tmp *= ksm(i / d,sum[min(i + d - 1,100000ll)] - sum[i - 1])) %= mod;
        	(ans += mu[d] * tmp % mod) %= mod;
        }
        ans += mod; ans %= mod;
        printf("Case #%d: %lld\n",++ cc,ans);
    }
    return 0;
}
/***
233
6
75556 46563 48668 34165 65441 45446

606400871
*/
