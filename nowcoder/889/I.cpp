#include<bits/stdc++.h>
using namespace std;

typedef __int128 LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
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

struct node {
    LL f;
};
struct LO {
    const LL inv2 = (1e9+8)/2;
    LL F1(LL n) {
        n %= mod;
        return n * (n+1) % mod * inv2 % mod;
    }
    node solve(LL a,LL b,LL c,LL n) {
        LL f;
        if(a == 0) {
            n %= mod;
            f = (b/c%mod) * (n+1) % mod;
        }
        else if(a>=c || b>=c) {
            node t = solve(a%c,b%c,c,n);
            f = (t.f + F1(n)*(a/c%mod)%mod + ((n+1)%mod)*(b/c%mod)%mod) % mod;
      }
        else {
            LL m = ((__int128)a*n+b)/c;
            node t = solve(c,c-b-1,a,m-1);
            m %= mod;
            f = ((n%mod)*m%mod - t.f) % mod;
        }
        f += mod; f %= mod;
        return (node){f};
    }
}lo;

int main() {
    LL n = read(),m = read(),ans = 0;
    for(LL i = 0;i <= 50;i ++) {
        if(m >> i & 1) {
            LL t = lo.solve(m,0,1ll<<i,n).f - lo.solve(m,0,2ll<<i,n).f * 2;
            t %= mod; t += mod; t %= mod;
            (ans += t * (1ll<<i) % mod) %= mod;
        }
    }
    cout << (long long)ans << endl;
}
