#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1e6 + 10;
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

const int MAXN = 1e6;
int mu[SZ];
int pri[SZ / 10],tot;
bool vis[SZ];

void shai(int n) {
    mu[1] = 1;
    for(register int i = 2;i <= n;i ++) {
    	if(!vis[i]) pri[++ tot] = i,mu[i] = -1;
    	for(register int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
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

LL getF_baoli(LL n) {
	LL ans = 0;
	for(LL i = 1;i <= n;i ++)
		for(LL j = 1;j <= i;j ++)
            if(i * j / __gcd(i,j) == n) ans ++;
	return ans;
}

LL get(LL n) {
	LL ans = 0;
    for(LL i = 1;i * i * i <= n;i ++) {
        for(LL j = i + 1;j * j * i <= n;j ++) {
            ans += (n / i / j - j) * 6; /// i < j < k
            ans += 3; ///i < j = k
        }
    	ans += (n / i / i - i) * 3;  ///i = j < k
    	ans += 1; ///i = j = k
    }
    return ans;
}

LL work(LL n) {
	LL ans = 0;
    for(LL d = 1;d * d <= n;d ++) {
    	if(mu[d])
	        ans += mu[d] * get(n / d / d);
    }
    return ans + n >> 1ll;
}

int main() {
	shai(MAXN);
    LL a = read(),b = read();
    printf("%lld\n",work(b) - work(a - 1));
    return 0;
}
/**
100000000000 100000000000

50 100
395

F(1000) = 25
*/
