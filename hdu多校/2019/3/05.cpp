#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 6e6 + 10;
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
        if(b&1) ans = a * ans %mod;
        a = a * a %mod;
        b >>= 1;
    }
    return ans;
}

LL k;
int MAXN;
bool vis[SZ];
int pri[SZ],g[SZ],f[SZ],h[SZ];

void shai(int n) {
    for(int i = 1;i <= n;i ++) vis[i] = 0;
    int tot = 0;
    g[1] = 1;
    for(int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ tot] = i,g[i]=-1,f[i]=ksm(i,k-1);
        for(int j = 1,m;j <= tot && (m=i*pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i%pri[j] == 0) {
                g[m] = 0;
                f[m] = 0;
                break;
            }
            else {
                g[m] = -g[i];
                f[m] = 0;
            }
        }
    }
    for(int i = 1;i <= n;i ++) g[i] *= 1ll * i*i%mod,h[i] = 0;
    for(int i = 1;i <= tot;i ++) {
        int p = pri[i];
        for(int j = 1;j <= n/p;j ++) {
            (h[p*j] += 1ll * f[p] * g[j] % mod * p % mod * p % mod) %= mod;
        }
    }
    for(int i = 1;i <= min(10,n);i ++) printf("%4d%4d%4d%4d\n",i,h[i],f[i],g[i]);
    for(int i = 1;i <= n;i ++) (h[i] += h[i-1]) %= mod;
}

LL F(LL n) {
    n %= mod;
    LL x = n * (n+1) % mod * 500000004 % mod;
    return x * x % mod;
}

unordered_map<LL,int> mp;

LL get_phi(LL n) {
    LL ans = n;
    for(int i = 1;1ll * pri[i] * pri[i] <= n;i ++) {
        int p = pri[i];
        if(n % p == 0) {
            ans = ans / p * (p-1);
            while(n%p == 0) n /= p;
        }
    }
    if(n != 1) ans = ans / n * (n-1);
    return ans;
}

bool ispri(int n) {
    if(n <= 1) return false;
    for(int i = 2;i * i <= n;i ++) {
        if(n%i==0) return false;
    }
    return true;
}

int dfs(LL n) {
    if(n <= MAXN) return h[n];
    if(mp.count(n)) return mp[n];
    int ans = 0;
    for(LL i = 1,r;i <= n;i = r + 1) {
        r = n / (n / i);
        (ans += ask_pk(n / i) * (dfs2(r) - dfs2(i-1))%mod) %= mod;
    }
    for(LL i = 2,r;i <= n;i = r + 1) {
        r = n / (n / i);
        (ans -= (F(r) - F(i-1)) * dfs(n/i) % mod) %= mod;
    }
    return mp[n] = ans;
}

int ask_mu(int n) {
    if(n == 1) return 1;
    int ans = 1;
    for(int i = 2;i * i <= n;i ++) {
        if(n % i == 0) {
            if(n/i%i == 0) return 0;
            n /= i;
            ans = -ans;
        }
    }
    if(n != 1) ans = -ans;
    return ans;
}

LL baoli(LL n,int k) {
    LL ans = 0;
    for(int d = 2;d <= n;d ++) {
        if(!ispri(d)) continue;
        for(int p = 1;p <= n/d;p ++) {
            ans += ksm(d,k+1)*p*p*ask_mu(p)*F(n/p/d);
        }
    }
    ans += mod; ans %= mod;
    return ans;
}

int main() {
    k = 2;
    shai(1e5);
    int T = read();
    while(T --) {
        LL n = read(); k = read();
        MAXN = (int)pow(n,2.0/3);
        cout << MAXN << endl;
        shai(MAXN);
        LL ans = 0;
        for(LL i = 1,r;i <= n;i = r + 1) {
            r = n / (n / i);
            (ans += (dfs(r) - dfs(i-1)) * F(n/i) % mod) %= mod;
        }
        ans += mod; ans %= mod;
        printf("%lld\n",ans);
        printf("%lld\n",baoli(n,k));
    }
}
/**
1
10 2
5 61
10 -1645
*/
