#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 5e6 + 10;
const int INF = 1e9 + 10;
const int mod = 998244353;
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
        if(b&1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

const int MAXN = 1e5;

bool vis[SZ];
int pri[SZ],tot;
int mu[SZ];

void shai(int n) {
    mu[1] = 1;
    for(int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ tot] = i,mu[i] = -1;
        for(int j = 1,m;j <= tot && (m=i*pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i%pri[j] == 0) {
                mu[m] = 0;
                break;
            }
            else {
                mu[m] = -mu[i];
            }
        }
    }
}

int inv[SZ],mi[SZ];

int get(int n,int m) {
    LL ans = 0;
    int B = ksm(2,m+1),now = 1;
    int B2 = ksm(2,m),now2 = 1;
    for(int i = 1;i <= n;i ++) {
        now = 1ll * now * B % mod;
        now2 = 1ll * now2 * B2 % mod;
        (ans += 1ll * i * m % mod * now % mod + i * mi[i] % mod * (1-now2) % mod * inv[i] %mod) %= mod;
    }
    return ans;
}

unordered_map<LL,int> mp;

void add(int n,int m,int x) {
    mp[1ll*n*100000+m] = x;
}

int ask(int n,int m) {
    return mp[1ll*n*100000+m];
}

int main() {
    shai(MAXN);
    mi[0] = 1;
    for(int i = 1;i <= 1e5;i ++) inv[i] = ksm(ksm(2,i)-1,mod-2);
    for(int i = 1;i <= 1e5;i ++) mi[i] = mi[i-1] * 2 % mod;
    int T = read();
    while(T --) {
        int n = read();
        for(int i1 = 1,r1;i1 <= n;i1 = r1 + 1) {
            r1 = n / (n / i1);
            for(int i2 = 1,r2;i2 <= n;i2 = r2 + 1) {
                r2 = n / (n / i2);
                int w1 = n / i1;
                int w2 = n / i2;
                add(w1,w2,get(w1,w2));
            }
        }
        LL ans = 0;
        for(int i = 1;i <= tot && pri[i] <= n;i ++) {
            int p1 = pri[i];
            for(int j = 1;j <= tot && pri[j] <= n;j ++) {
                int p2 = pri[j];
                (ans += (p1-1ll)*(p2-1)%mod*ksm(2,(p1-1ll)*(p2-1))%mod * ask(n/p1,n/p2) % mod)%=mod;
            }
        }
        printf("%lld\n",ans);
    }
}
