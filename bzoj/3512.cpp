#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 1e6 + 10;
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

const int MAXN = 1e6;
int phi[SZ],w[SZ],sphi[SZ];
int pri[SZ],tot;
bool vis[SZ];

void shai(int n = MAXN) {
	phi[1] = w[1] = 1;
    for(int i = 2;i <= n;i ++) {
    	if(!vis[i]) pri[++ tot] = i,phi[i] = i - 1,w[i] = i;
    	for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i % pri[j] == 0) {
                phi[m] = phi[i] * pri[j];
                w[m] = w[i];
                break;
            }
            else {
                phi[m] = phi[i] * phi[pri[j]];
            	w[m] = w[i] * pri[j];
            }
    	}
    }
    for(int i = 1;i <= n;i ++) sphi[i] = (sphi[i - 1] + phi[i]) % mod;
}

map<int,int> mp[100010];
map<int,int> phi2,sphi2;

LL get_phi(int n) {
    if(n <= MAXN) return phi[n];
    if(phi2[n]) return phi2[n];
    LL ans = n;
    for(int i = 1;i <= tot && pri[i] * pri[i] <= n;i ++) {
    	int p = pri[i];
    	if(n % p == 0) {
            ans /= p; ans *= p - 1;
            while(n % p == 0) n /= p;
    	}
    }
    if(n != 1) ans /= n,ans *= n - 1;
    return phi2[n] = ans;
}

LL sum1(LL n) { return 1ll * n * (n + 1) / 2; }

LL get_phi_sum(int n) {
    if(n <= MAXN) return sphi[n];
    if(sphi2[n]) return sphi2[n];
    LL ans = sum1(n) % mod;
    for(int i = 2,r;i <= n;i = r + 1) {
       	r = n / (n / i);
        (ans -= get_phi_sum(n / i) * (r - i + 1) % mod) %= mod;
    }
    return sphi2[n] = ans;
}

LL S(int n,int m) {
    if(n == 1) { return get_phi_sum(m); }
    if(mp[n][m]) return mp[n][m];
    LL wn = w[n],ans = 0;
    for(int d = 1;d * d <= wn;d ++) {
        if(wn % d == 0) {
        	if(d <= m)
	            (ans += get_phi(wn / d) * S(d,m / d) % mod) %= mod;
            if(d * d != wn && wn / d <= m)
                (ans += get_phi(d) * S(wn / d,m / (wn / d)) % mod) %= mod;
        }
    }
    return mp[n][m] = ans * (n / wn) % mod;
}

LL work(int n,int m) {
	LL ans = 0;
    for(int i = 1;i <= n;i ++) {
		LL tmp = S(i,m);
		(ans += tmp) %= mod;
    }
    ans += mod; ans %= mod;
    return ans;
}

int main() {
	shai();
	int n = read(),m = read();
    printf("%lld\n",work(n,m));
	return 0;
}
