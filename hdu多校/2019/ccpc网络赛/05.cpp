#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 5e6 + 10;
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
        if(b&1) ans = a * ans;
        a = a * a;
        b >>= 1;
    }
    return ans;
}

LL ksm(LL a,LL b,LL p) {
    LL ans = 1;
    while(b) {
        if(b&1) ans = a * ans % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

const int MAXN = 5e6;
const int ni2 = (mod+1)/2;
const int ni6 = ksm(6,mod-2,mod);

bool vis[SZ];
int pri[SZ],tot,mu[SZ],smud[SZ];

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
    for(int i = 1;i <= n;i ++) smud[i] = (smud[i-1] + i * mu[i]) % mod;
}

LL f1(LL n) {
    n %= mod;
    return n * (n + 1) % mod * ni2 % mod;
}

LL f2(LL n) {
    n %= mod;
    return n * (n + 1) % mod * (2*n+1) % mod * ni6 % mod;
}

LL f3(LL n) {
    return f1(n) * f1(n) % mod;;
}

unordered_map<int,int> smd;

int dfs(int n) {
    if(n <= MAXN) return smud[n];
    if(smd.count(n)) return smd[n];
    LL ans = 1;
    for(int i = 2,r;i <= n;i = r + 1) {
        r = n / (n / i);
        (ans -= dfs(n/i) * (f1(r) - f1(i-1)) % mod) %= mod;
    }
    smd[n] = ans;
    return ans;
}


LL baoli(int n,int a,int b) {
    LL ans = 0;
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= i;j ++) {
            if(__gcd(i,j) == 1) {
                LL t = __gcd(ksm(i,a)-ksm(j,a),ksm(i,b)-ksm(j,b));
             //   printf("%d %d %3lld\n",i,j,t);
                ans += t;
            }
        }
    }
    return ans;
}

LL S(LL n) {
    return ni2 * (f2(n) - f1(n)) % mod;
}

LL work1(int n) {
    LL ans = 0;
    for(int i = 1,r;i <= n;i = r + 1) {
        r = n / (n / i);
        (ans += (dfs(r) - dfs(i-1)) * S(n/i) % mod) %= mod;
    }
    ans += mod; ans %= mod;
    return ans;
}


int main() {
    shai(MAXN);
    int T = read();
    while(T --) {
        int n = read(),a = read(),b = read();
        printf("%lld\n",work1(n));
    }
}
