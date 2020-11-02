#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
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

LL ksm(LL a,LL b,LL p) {
	if(p == 1) return 0;
    LL ans = 1;
    while(b) {
    	if(b & 1) ans = a * ans % p;
    	a = a * a % p;
    	b >>= 1;
    }
    return ans;
}

const int MAXN = 1e7;
int phi[SZ],sphi[SZ];
int pri[SZ],tot;
bool vis[SZ];

void shai(int n = MAXN) {
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
    for(int i = 1;i <= n;i ++) sphi[i] = (sphi[i - 1] + phi[i]) % mod;
}

LL dfs(LL n,LL p) {
    if(p == 1) return 0;
    LL phi_p = phi[p];
    LL x = dfs(n,phi_p);
    return ksm(n,x + phi_p,p);
}

vector<int> fj(int n) {
	vector<int> g;
	for(int i = 1;i <= tot && pri[i] * pri[i] <= n;i ++) {
    	int p = pri[i];
    	if(n % p == 0) {
            g.push_back(p);
            while(n % p == 0) n /= p;
    	}
    }
    if(n != 1) g.push_back(n);
	return g;
}

vector<int> g;

LL S(int n,int m,int pos) {
	if(n == 1) { return sphi[m]; }
    if(m == 0) return 0;
    if(pos == g.size()) return 0;
    LL ans = 0;
	int p = g[pos];
	ans = ((p - 1) * S(n / p,m,pos + 1) % mod + S(n,m / p,pos)) % mod;
	return ans;
}

int main() {
	shai();
	int n,m,p;
	while(~scanf("%d%d%d",&n,&m,&p)) {
        g = fj(n);
		LL k = S(n,m,0);
		printf("%lld\n",dfs(k,p));
	}
	return 0;
}
