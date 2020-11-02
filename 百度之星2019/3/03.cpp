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
int pri[SZ],tot,mu[SZ];

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

LL baoli(int n,int m) {
    LL ans = 0;
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            ans += mu[i*j/__gcd(i,j)];
        }
    }
    return ans;
}

LL work(int n,int m) {
    LL ans = 0;
    for(int d = 1;d <= n;d ++) {
        for(int p = 1;p <= d;p ++) {
            if(d%p) continue;
            for(int i = 1;i <= n/d;i ++) {
                for(int j = 1;j <= m/d;j ++) {
                    if(i*j%p) continue;
                    if(__gcd(d,i*j) == 1) {
                        ans += mu[d] * mu[i*j] * mu[p];
                    }
                }
            }
        }
    }
    return ans;
}

int main() {
    shai(MAXN);
    int T = read();
    while(T --) {
        int n = read(),m = read();
        if(n<m) swap(n,m);
        printf("%lld\n",baoli(n,m));
        printf("%lld\n",work(n,m));
    }
}
