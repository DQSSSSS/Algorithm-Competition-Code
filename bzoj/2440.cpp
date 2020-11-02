#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 100010;
const int INF = 1e9 + 10;
const int mod = 999911659;
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

int mu[SZ],pri[SZ],tot;
bool vis[SZ];

void shai(int n) {
    mu[1] = 1;
    for(int i = 2;i <= n;i ++) {
    	if(!vis[i]) pri[++ tot] = i,mu[i] = -1;
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

LL check(int n) {
	LL ans = 0;
	for(int i = 1;i <= sqrt(n);i ++) {
        ans += 1ll * mu[i] * (n / (i * i));
	}
	return ans;
}

LL n;

LL div() {
    LL l = 0,r = 2 * n;
    while(r - l > 1) {
    	LL mid = l + r >> 1;
        if(check(mid) < n) l = mid;
        else r = mid;
    }
    return r;
}

int main() {
	shai(1e5);
	int T = read();
    while(T --) {
        n = read();
        printf("%lld\n",div());
    }
    return 0;
}
/**
233
1000000000
*/
