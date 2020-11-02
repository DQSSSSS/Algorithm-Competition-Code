#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
const LL INF = 1e15 + 10;
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


struct node {
    LL f,g,h;
};

struct LO {

    const LL inv2 = 499122177;
    const LL inv6 = 166374059;

    LL F1(LL n) {
        n %= mod;
        return n * (n+1) % mod * inv2 % mod;
    }

    LL F2(LL n) {
        n %= mod;
        return n * (n+1) % mod * (2*n+1) % mod * inv6 % mod;
    }

    node solve(LL a,LL b,LL c,LL n) {
        LL f,g,h;
        if(a == 0) {
            n %= mod;
            f = (b/c%mod) * (n+1) % mod;
            g = (b/c%mod) * (b/c%mod)%mod * (n+1) % mod;
            h = (b/c%mod) * F1(n) % mod;
        }
        else if(a>=c || b>=c) {
            node t = solve(a%c,b%c,c,n);
            f = (t.f + F1(n)*(a/c%mod)%mod + ((n+1)%mod)*(b/c%mod)%mod) % mod;
            g = (F2(n)*(a/c%mod)%mod*(a/c%mod)%mod + ((n+1)%mod)*(b/c%mod)%mod*(b/c%mod)%mod + t.g
                  + 2*F1(n)*(a/c%mod)%mod*(b/c%mod)%mod + 2*(a/c%mod)*t.h%mod + 2*(b/c%mod)*t.f%mod) % mod;
            h = (t.h + F2(n)*(a/c%mod)%mod + F1(n)*(b/c%mod)%mod) % mod;
        }
        else {
            LL m = (a*n+b)/c;
            node t = solve(c,c-b-1,a,m-1);
            m %= mod;
            f = (n*m%mod - t.f) % mod;
            g = (2*n*F1(m)%mod - 2*(t.h+t.f) - f) % mod;
            h = (F1(n)*m%mod - (t.g+t.f)*inv2%mod) % mod;
        }
        f += mod; f %= mod;
        g += mod; g %= mod;
        h += mod; h %= mod;
        return (node){f,g,h};
    }
}lo;

int main() {
    int T = read();
    while(T --) {
        LL n = read(),a = read(),b = read(),c = read();
        node ans = lo.solve(a,b,c,n);
        printf("%lld %lld %lld\n",ans.f,ans.g,ans.h);
    }
}
