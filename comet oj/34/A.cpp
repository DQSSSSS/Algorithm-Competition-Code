#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;
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

LL pri[SZ],tot;
bool vis[SZ];

void shai(int n) {
    for(int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ tot] = i;
        for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i % pri[j] == 0) break;
        }
    }
}

int main() {
    shai(2e5);
    int T = read();
    while(T --) {
        LL n = read();
        LL x = sqrt(n);
        if(x * x == n) puts("infty");
        else if(n % 4) puts("0 0");
        else {
            n /= 4;
            LL m = n;
            LL ans1 = 1,ans2 = 1;
            for(LL i = 1;pri[i] * pri[i] <= n;i ++) {
                int p = pri[i];
                if(n % p == 0) {
                    int t = 0;
                    while(n % p == 0) n /= p,t ++;

                    ans1 *= t + 1;
                    LL tmp = 0;
                    for(LL j = 0,d = 1;j <= t;j ++,d *= p) (tmp += d) %= mod;
                    (ans2 *= tmp) %= mod;
                   // cout << p << " " << t << " " << tmp << endl;
                }
            }
            if(n != 1) {
                ans1 *= 2;
                (ans2 *= n + 1) %= mod;
            }
            (ans2 *= m) %= mod;
            printf("%lld %lld\n",ans1 / 2,ans2);
        }
    }
}
