#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 5e6 + 10;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

bool vis[SZ];
int pri[SZ];
int mu[SZ],g[SZ];

void shai(int n,int mod) {
    mu[1] = 1;
    int tot = 0;
    for(int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ tot] = i,mu[i] = -1;
        for(int j = 1,m;j <= tot && (m=i*pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i % pri[j] == 0) {
                mu[m] = 0;
                break;
            }
            else {
                mu[m] = -mu[i];
            }
        }
    }
    for(int i = 1;i <= n;i ++) {
        if(mu[i]) {
            for(int j = i;j <= n;j += i) {
                (g[j] += mu[i] * j / i) %= mod;
            }
        }
    }
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

int get_phi(int p) {
    int ans = p;
    for(int i = 2;i * i <= p;i ++) {
        if(p % i == 0) {
            while(p % i == 0) p /= i;
            ans = 1ll * ans / i * (i-1);
        }
    }
    if(p != 1) ans = 1ll * ans / p * (p-1);
    return ans;
}

int work(char s[],int mod) {
    int len = strlen(s),phi = get_phi(mod);
    bool flag = 1;
    int ans = 0;
    for(int i = 0;i < len;i ++) {
        int x = s[i] - '0';
        if(ans * 10ll + x >= phi) flag = 0;
        ans = (ans * 10ll + x) % phi;
    }
    if(!flag) ans += phi;
    return ans;
}

int f(int x,int T,int mod) {
    return (1ll * x * (x+1) / 2 % mod * 2 * T % mod + x) % mod;
}

char m[SZ];

int main() {
    int n = read();
    scanf("%s",m);
    int mod = read();
    int mi = work(m,mod);

    shai(1e6,mod);
    int ans = 0;
    for(int i = 1;i <= n;i ++) {
        (ans += g[i] * ksm(f(n/i,i,mod),mi,mod) % mod) %= mod;
    }
    ans += mod; ans %= mod;
    cout << ans << endl;
}
/**
5 5 10627
*/
