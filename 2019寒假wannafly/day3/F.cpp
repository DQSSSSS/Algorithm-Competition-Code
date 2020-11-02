#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000100;
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

const int MAXN = 1e6;

int pri[SZ],tot;
bool vis[SZ];
int mu[SZ],smu[SZ],ans[SZ],sans[SZ];

void shai(int n) {
    mu[1] = 1;
    for(int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ tot] = i,mu[i] = -1;
        for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
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
    for(int i = 1;i <= n;i ++) smu[i] = smu[i - 1] + mu[i];
    for(int i = 1;i <= n;i ++) {
        if(mu[i])
            for(int j = 1;j <= n / i;j ++)
                ans[i*j] += mu[i] * mu[j];
    }
    for(int i = 1;i <= n;i ++) sans[i] = (sans[i - 1] + ans[i]) % mod;
}

//unordered_map<LL,LL> smu2,sans2;
//unordered_map<LL,LL> fsmu2,fsans2;

LL smu2[SZ],sans2[SZ];
bool fsmu2[SZ],fsans2[SZ];

LL get_smu(LL n) {
    if(n <= MAXN) return smu[n];
    LL t = 1e10 / n;
    if(fsmu2[t]) return smu2[t];
    fsmu2[t] = 1;
    LL ans = n >= 1;
    for(LL d = 2,r;d <= n;d = r + 1) {
        r = n / (n / d);
        ans -= (r - d + 1) * get_smu(n/d);
    }
    return smu2[t] = ans;
}

LL get_sans(LL n) {
    if(n <= MAXN) return sans[n];
    LL t = 1e10 / n;
    if(fsans2[t]) return sans2[t];
    fsans2[t] = 1;
    LL ans = get_smu(n);
    for(LL d = 2,r;d <= n;d = r + 1) {
        r = n / (n / d);
        (ans -= (r - d + 1) % mod * get_sans(n/d) % mod) %= mod;
    }
    return sans2[t] = ans;
}

int main() {
    shai(MAXN);
    LL n = read();
    LL ans = 0;
    //for(LL i = 1;i <= n;i ++) cout << get_sans(i) << " "; puts("");
    //for(LL i = 1;i <= n;i ++) cout << get_smu(i) << " "; puts("");
    for(LL i = 1,r;i <= n;i = r + 1) {
        r = n / (n / i);
        LL w = n / i % mod;
        (ans += (get_sans(r) - get_sans(i - 1)) % mod * w % mod * w % mod) %= mod;
    }
    ans += mod; ans %= mod;
    printf("%lld\n",ans);
    return 0;
}
/**
10000000000
540004528
*/
