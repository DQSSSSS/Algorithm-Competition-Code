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
        if(b&1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

const int MAXN = 1e6;

bool vis[SZ];
int pri[SZ],tot;
int mu[SZ];
int sf[SZ];

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
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= n/i;j ++) {
            (sf[i*j] += 1ll * mu[i] * j * j % mod) %= mod;
        }
    }
    for(int i = 1;i <= n;i ++) (sf[i] += sf[i-1]) %= mod;
}

LL f2(LL n) {
    n %= mod;
    return n * (n+1)%mod * (2*n+1) % mod * 166666668 % mod;
}

unordered_map<int,int> mp;

int dfs(int n) {
    if(n <= MAXN) return sf[n];
    if(mp.count(n)) return mp[n];
    int ans = f2(n);
    for(int i = 2,r;i <= n;i = r + 1) {
        r = n / (n / i);
        (ans -= dfs(n/i) * (r-i+1ll) % mod) %= mod;
    }
    return mp[n] = ans;
}

int k,kp;

LL work(LL x) {
    if(x == 1) return kp-1;
    return x*(1-ksm(x,k))%mod*ksm(1-x,mod-2)%mod-x;
   // LL ans = 0;
   // for(int i = 2;i <= k;i ++) (ans += ksm(x,i))%=mod;
    //return ans;
}

LL baoli(LL n,LL k) {
    LL ans = 0;
    for(int j = 2;j <= k;j ++) {
        for(int i = 1,r;i <= n;i = r + 1) {
            r = n / (n / i);
            (ans += 1ll * ksm(n/i,j) * (dfs(r) - dfs(i-1)) % mod) %= mod;
        }
    }
    ans += mod; ans %= mod;
    return ans;
}

char S[SZ];

int main() {
    shai(MAXN);
    int T = read();
    while(T --) {
        int n = read();
        scanf("%s",S);
        int len = strlen(S);
        k = 0,kp = 0;
        for(int i = 0;i < len;i ++) {
            k = (k*10ll+S[i]-'0')%(mod-1);
            kp = (kp*10ll+S[i]-'0')%(mod);
        }

        int ans = 0;
        for(int i = 1,r;i <= n;i = r + 1) {
            r = n / (n / i);
            (ans += 1ll * work(n/i) * (dfs(r) - dfs(i-1)) % mod) %= mod;
        }
        ans += mod; ans %= mod;
        printf("%d\n",ans);
       // printf("%lld\n",baoli(n,k));
    }
}
