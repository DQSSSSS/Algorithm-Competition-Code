#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int ksm(int a,LL b) {
    int ans = 1;
    while(b) {
        if(b&1) ans = 1ll * ans * a % mod;
        a = 1ll * a * a  % mod;
        b >>= 1;
    }
    return ans;
}

int pri[SZ];
int mu[SZ];
bool vis[SZ];
int f[SZ],nf[SZ],g[SZ];

void shai(int n) {
    int tot = 0;
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

    f[0] = 0; f[1] = 1;
    for(int i = 2;i <= n;i ++) f[i] = (f[i-1] + f[i-2]) % mod;
    for(int i = 1;i <= n;i ++) nf[i] = ksm(f[i],mod-2);
    for(int i = 0;i <= n;i ++) g[i] = 1;
    for(int i = 1;i <= n;i ++) {
        if(mu[i])
            for(int j = i;j <= n;j += i) {
                int id = j / i,x;
                if(mu[i] == -1) x = nf[id];
                else x = f[id];
                g[j] = 1ll * g[j] * x % mod;
            }
    }
    for(int i = 1;i <= n;i ++) g[i] = 1ll * g[i] * g[i-1] % mod;
}

int main() {
    shai(1e6);
    int T = read();
    while(T --) {
        int n = read(),m = read();
        if(n > m) swap(n,m);
        LL ans = 1;
        for(int i = 1,r;i <= n;i = r + 1) {
            r = min(n/(n/i),m/(m/i));
            LL x = 1ll * g[r] * ksm(g[i-1],mod - 2) % mod;
            ans = 1ll * ans * ksm(x,1ll * (n/i)*(m/i)) % mod;
        }
        printf("%d\n",ans);
    }
}


