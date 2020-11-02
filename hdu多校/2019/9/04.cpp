#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 5e7 + 10;
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

const int MAXN = 5e7;

bool vis[SZ];
int pri[SZ],tot,phi[SZ],sum_phi[SZ];

void shai(int n) {
    phi[1] = 1;
    for(int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ tot] = i,phi[i] = i - 1;
        for(int j = 1,m;j <= tot && (m=i*pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i%pri[j] == 0) {
                phi[m] = phi[i] * pri[j];
                break;
            }
            else {
                phi[m] = phi[i] * (pri[j] - 1);
            }
        }
    }
    for(int i = 1;i <= n;i ++) sum_phi[i] = (sum_phi[i-1] + phi[i]) % mod;
}

LL f1(LL n) {
    n %= mod;
    return n * (n + 1) % mod * ((mod+1)/2) % mod;
}

unordered_map<LL,LL> mp;

LL dfs(LL n) {
    if(n <= MAXN) return sum_phi[n];
    if(mp.count(n)) return mp[n];
    LL ans = f1(n);
    for(LL i = 2,r;i <= n;i = r + 1) {
        r = n / (n / i);
        (ans -= dfs(n / i) * (r-i+1) % mod) %= mod;
    }
    ans += mod; ans %= mod;
    return ans;
}


LL work3(LL n) {
    LL ans = 0;
    for(LL a = 2,r;a * a <= n;a = r + 1) {
        r = sqrt(n/(n/a/a));
        (ans += (dfs(r) - dfs(a-1)) * ((n/a/a) % mod) % mod) %= mod;
    }
    ans += mod; ans %= mod;
    return ans;
}

LL work0(LL n) {
    LL ans = f1(n);
    for(LL a = 2;;a ++) {
        LL now = a * a;
        if(now > n / a) break;
        now *= a;
        while(1) {
            (ans += phi[a] * ((n / now)%mod) % mod) %= mod;
            if(now > n / a) break;
            now *= a;
        }
    }
    return ans;
}

int main() {
    shai(MAXN);
    int T = read();
    while(T --) {
        LL n = read();
        LL ans3 = work3(n);
        LL ans0 = work0(n);
        LL ans = (ans3 + ans0) % mod;
        printf("%lld\n",ans);
     //   printf("0:%lld 3:%lld\n",ans0,ans3);
    }
}

