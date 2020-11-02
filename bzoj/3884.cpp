#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1e7 + 10;
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

LL ksm(LL a,LL b,LL mod) {
	LL ans = 1;
    while(b) {
    	if(b & 1) ans = a * ans % mod;
 		a = a * a % mod;
 		b >>= 1;
    }
    return ans;
}

const int MAXN = 1e7;
int phi[SZ];
int pri[SZ],tot;
bool vis[SZ];

void shai(int n) {
	phi[1] = 1;
    for(int i = 2;i <= n;i ++) {
    	if(!vis[i]) pri[++ tot] = i,phi[i] = i - 1;
    	for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i % pri[j] == 0) {
                phi[m] = phi[i] * pri[j];
                break;
            }
            else {
                phi[m] = phi[i] * phi[pri[j]];
            }
    	}
    }
}

LL dfs(LL n,LL p) {
    if(p == 1) return 0;
    LL k = 0;
    while(p % 2 == 0) p /= 2,k ++;
    LL ans = dfs(n,phi[p]);
    ans -= k; ans = (ans % phi[p] + phi[p]) % phi[p];
    ans = ksm(n,ans,p) % p;
    return ans << k;
}

int main() {
	shai(MAXN);
    int T = read();
    while(T --) {
        LL p = read();
        printf("%lld\n",dfs(2,p));
    }
    return 0;
}
