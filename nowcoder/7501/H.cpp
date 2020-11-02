#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
typedef pair<double, double> pdd;
const int SZ = 2000100;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-6;

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

const int inv2 = ksm(2,mod - 2);

LL fac[SZ],inv[SZ],invFac[SZ],mi2[SZ],A[SZ];
LL sufSum0[SZ];
LL sufSum1[SZ];
LL sufSum2[SZ];
int n;

LL C(int n,int m) {
    if(n<m) return 0;
    return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}

LL D(int n) {
    return 1ll * fac[2*n]*invFac[n] % mod * ksm(mi2[n],mod-2) % mod;
}

LL get_ans1() {
    LL ans = 0, tmp = 0;
    for(int i = 1;i <= 2*n;i ++) (tmp += 1ll*A[i]*A[i]%mod*(2*n-i)%mod)%=mod;
    for(int i = 2;i <= 2*n;i ++) (tmp += 1ll*A[i]*A[i]%mod*(i-1)%mod)%=mod;
    for(int i = 1;i <= 2*n;i ++) (tmp -= 2ll*A[i]*sufSum0[i+1]%mod)%=mod;
    ans = tmp;
    return ans * D(n-1) % mod * ksm(n,mod - 2) % mod;
}

LL getijkl() {

    LL ans = 0;
   /* for(int i = 1;i <= 2*n;i ++) {
        for(int j = i+1;j <= 2*n;j ++) {
            for(int k = j + 1;k <= 2 * n;k ++) {
                for(int l = k+1;l <= 2*n;l ++) {
                    //ans += (A[k]-A[i])*(A[l]-A[j]);
                    //ans += (A[l]-A[i])*(A[k]-A[j]);
                    //ans += (A[j]-A[i])*(A[l]-A[k]);
                 //   ans += A[i]*A[j]*2;
                    ans -= A[i]*A[l]*2;
                    ans -= A[j]*A[k]*2;
                    ans += A[k]*A[l]*2;
                }
            }
        }
    }*/
 //   return ans;

    LL ansij = 0;
    for(int i = 1;i <= 2*n;i ++) {
        LL s0 = (2ll*n*n%mod-n)%mod;
        LL s1 = (inv2-2*n)%mod;
        LL s2 = inv2;
        LL s = 0;
        (s += s0*sufSum0[i+1]%mod) %= mod;
        (s += s1*sufSum1[i+1]%mod) %= mod;
        (s += s2*sufSum2[i+1]%mod) %= mod;
        (ansij += s * A[i] % mod) %= mod;
    }
    (ans += ansij * 2 % mod) %= mod;

    LL ansil = 0;
    for(int i = 1;i <= 2*n;i ++) {
        LL s0 = (i+1ll)*(i+2ll)%mod;
        LL s1 = -(2*i+3)%mod;
        LL s2 = 1;
        LL s = 0;
        (s += s0*sufSum0[i+1]%mod) %= mod;
        (s += s1*sufSum1[i+1]%mod) %= mod;
        (s += s2*sufSum2[i+1]%mod) %= mod;
        (ansil += s * A[i] % mod) %= mod;
    }
    ansil = ansil*inv2%mod;
    (ans -= ansil * 2 % mod) %= mod;


    LL ansjk = 0;
    for(int i = 1;i <= 2*n;i ++) {
        LL s0 = (2ll*n*(i-1))%mod;
        LL s1 = -(i-1)%mod;
        LL s2 = 0;
        LL s = 0;
        (s += s0*sufSum0[i+1]%mod) %= mod;
        (s += s1*sufSum1[i+1]%mod) %= mod;
        (s += s2*sufSum2[i+1]%mod) %= mod;
        (ansjk += s * A[i] % mod) %= mod;
    }
    (ans -= ansjk * 2 % mod) %= mod;

    LL anskl = 0;
    for(int i = 3;i <= 2*n;i ++) {
        LL s0 = 1ll*i*i%mod-3*i%mod+2;
        LL s1 = 0;
        LL s2 = 0;
        LL s = 0;
        (s += s0*sufSum0[i+1]%mod) %= mod;
        (s += s1*sufSum1[i+1]%mod) %= mod;
        (s += s2*sufSum2[i+1]%mod) %= mod;
        (anskl += s * A[i] % mod) %= mod;
    }
    anskl = anskl*inv2%mod;
    (ans += anskl * 2 % mod) %= mod;

    ans += mod; ans %= mod;
    return ans;
}

LL get_ans2() {
    LL ans = 0, tmp = 0;
    ans = get_ans1() * ksm(n,mod - 2) % mod;
    tmp = getijkl() * D(n-2) % mod * 2 % mod * ksm(1ll*n*n%mod,mod - 2) % mod;
    ans += tmp; ans %= mod;
   // ans += mod; ans %= mod;
    return ans;
}


void init(int n) {
    fac[0] = 1; inv[1] = 1;
    for(int i = 1;i <= n;i ++) fac[i] = 1ll*fac[i-1]*i%mod;
    for(int i = 2;i <= n;i ++) inv[i] = (mod-1ll*mod/i*inv[mod%i]%mod)%mod;
    invFac[0] = invFac[1] = 1;
    for(int i = 2;i <= n;i ++) invFac[i] = 1ll*invFac[i-1]*inv[i]%mod;
    mi2[0] = 1;
    for(int i = 1;i <= n;i ++) mi2[i] = 2*mi2[i-1] % mod;

    sufSum0[n+1] = 0;
    for(int i = n;i >= 1;i --) sufSum0[i] = (sufSum0[i+1]+A[i])%mod;
    sufSum1[n+1] = 0;
    for(int i = n;i >= 1;i --) sufSum1[i] = (sufSum1[i+1]+1ll*A[i]*i%mod)%mod;
    sufSum2[n+1] = 0;
    for(int i = n;i >= 1;i --) sufSum2[i] = (sufSum2[i+1]+1ll*A[i]*i%mod*i%mod)%mod;
}

int main() {
    n = read();
    for(int i = 1;i <= 2*n;i ++) A[i] = read();
    sort(A+1,A+1+2*n);

    init(2*n);

    if(n == 1) {
        puts("0");
        return 0;
    }

    LL ans1 = get_ans1();
    LL ans2 = get_ans2();
  /*  printf("%lld %lld %lld %lld %lld\n",ans1,ans2,D(n),D(n-1),D(n-2));
    printf("%lld \n",11*ksm(2,mod-2)%mod);
    printf("%lld \n",ksm(2,mod-2)%mod);
    printf("%lld \n",inv2);*/
    LL ans = ksm(D(n),mod - 2) * (ans1-ans2+mod) % mod;
    ans %= mod; ans += mod; ans %= mod;
    cout << ans << endl;
}
