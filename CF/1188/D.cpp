#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
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

pll a[SZ];
LL f[SZ],g[SZ];

LL get(LL x) {
    LL ans = 0;
    while(x) ans += x & 1,x >>= 1;
    return ans;
}

void print(LL x) {
    for(int i = 63;i >= 0;i --) {
        if(x>>i&1)
            printf("%d",x>>i&1);
        else
            printf(" ");
    }
    printf("|");
}

LL get_low(LL x,LL k) {
    return x % (1ll << k);
}

int k;

bool cmp(pll a,pll b) {
    LL msk = 1ll << k; msk --;
    LL x = a.first & msk;
    LL y = b.first & msk;
    return x == y ? a.second < b.second : x > y;
}

int main() {
    int n = read();
    LL maxn = 0;
    for(int i = 1;i <= n;i ++) a[i].first = read(),maxn = max(maxn,a[i].first);
    for(int i = 1;i <= n;i ++) a[i].first = maxn - a[i].first,a[i].second = i;

   // for(int i = 1;i <= n;i ++) print(a[i].first),puts("");
    for(int i = 1;i <= n;i ++) f[i] = 1e18;
    for(k = 0;k < 63;k ++) {
        sort(a+1,a+1+n,cmp);
        int oneall = 0,one = 0,zero = 0;
        for(int i = 1;i <= n;i ++) oneall += a[i].first>>k&1;
        for(int i = 0;i <= n;i ++) g[i] = 1e18;
        for(int i = 1;i <= n;i ++) {
            if(a[i].first>>k&1) one ++; else zero ++;

            /// 0
            g[one] = min(g[one],f[i] + oneall - one + zero);

            /// 1
            g[i+oneall-one] = min(g[i+oneall-one],f[i] + one + n-oneall-zero);
        }
        g[0] = min(g[0],f[0]+oneall);
        g[oneall] = min(g[oneall],f[0]+n-oneall);
//        cout << k << " "<< tot <<endl;
      //  for(int i = 1;i <= n+1;i ++) printf("%lld ",f[i]); puts("");
     //   for(int i = 1;i <= n+1;i ++) printf("%lld ",a[i].second); puts("");
     //   for(int i = 1;i <= n+1;i ++) printf("%lld ",g[i]); puts("");
        for(int i = 0;i <= n;i ++) f[i] = g[i];
    }
    cout << f[0] << endl;
}
