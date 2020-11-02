#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1e6 + 10;
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
        if(b & 1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int a[SZ],n,b[SZ];

int main() {
   // cout << ksm(3,mod-2) << endl;
   // cout << ((ksm(15,mod-2) - ksm(24,mod-2))% mod + mod) % mod << endl;
    while(~scanf("%d",&n)) {
        for(int i = 1;i <= n;i ++) {
            a[i] = read();
        }
        b[1] = 1;
        for(int i = 2;i <= n;i ++) {
            b[i] = 0;
            for(int j = 1;j < i;j ++) {
                LL x = a[j],y = a[i];
                LL d = ksm((-x*x+y*y)%mod,mod-2) % mod;
         //       cout << -b[j] << " " << d << endl;
                (b[i] -= 1ll * b[j] * d % mod) %= mod;
                b[j] = 1ll * b[j] * d % mod;
            }
          //  for(int j = 1;j <= n;j ++) printf("%d ",b[j]); puts("");
        }
        LL ans = 0;
      //  cout << ksm(-16,mod-2)+mod << endl;
       // for(int i = 1;i <= n;i ++) cout << b[i] << endl;
        for(int i = 1;i <= n;i ++) {
            (ans += 1ll * b[i] * ksm(a[i],mod-2) % mod) %= mod;
        }
        (ans *= ksm(2,mod-2)) %= mod;
        ans += mod; ans %= mod;
        printf("%lld\n",ans);
    }
}
