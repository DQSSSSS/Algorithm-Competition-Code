#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1e7 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;
const LD PI = acos(-1);

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

const int MAXN = 1e7;
int pri[SZ],tot,psum[SZ],b[SZ];
bool vis[SZ];

void shai(int n = MAXN) {
    for(int i = 2;i <= n;i ++) {
    	if(!vis[i]) pri[++ tot] = i;
        for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
        	vis[m] = 1;
            if(i % pri[j] == 0)
                break;
        }
    }
    for(int i = 1;i <= tot;i ++) {
        int p = pri[i];
        for(LL j = 1,s = 1;j <= n;j *= p,(s += j) %= mod)
            psum[j] = s;
        b[p] = 1;
    }
}

void get(int x) {
	for(int i = 1;pri[i] * pri[i] <= x;i ++) {
		int p = pri[i];
        if(x % p == 0) {
        	int d = 1;
			while(x % p == 0) x /= p,d *= p;
            b[p] = 1ll * b[p] * psum[d] % mod;
        }
	}
	if(x != 1) {
        b[x] = 1ll * b[x] * psum[x] % mod;
	}
}

int main() {
    shai();
    int n = read();
    for(int i = 1;i <= n;i ++) {
    	int x = read();
        get(x);
    }
    LL ans = 1;
    for(int i = 1;i <= tot;i ++) {
    	int p = pri[i];
        LL tmp = b[p] - 1;
        tmp = tmp * (p - 1) % mod * ksm(p,mod - 2) % mod;
        tmp ++;
        ans = ans * tmp % mod;
    }
    ans += mod; ans %= mod;
    printf("%lld\n",ans);
	return 0;
}
