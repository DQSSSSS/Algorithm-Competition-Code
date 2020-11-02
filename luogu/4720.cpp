#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 2e6 + 10;
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

struct Exlucas {
    inline void exgcd(LL a,LL b,LL &x,LL &y){
        if(!b) { x=1,y=0; return; }
        exgcd(b,a%b,x,y);
        LL t = x;
        x = y,y = t-(a/b)*y;
    }
    inline LL inv(LL a,LL b){
        LL x,y;
        return exgcd(a,b,x,y),(x%b+b)%b;
    }
    inline LL ksm(LL a,LL b,LL p){
        LL ans = 1;
        while(b){
            if(b&1) ans = a * ans % p;
            a = a * a % p;
            b >>= 1;
        }
        return ans;
    }
    inline LL crt(LL x,LL p,LL mod){
        return inv(p/mod,mod)*(p/mod)*x;
    }
    inline LL fac(LL x,LL a,LL b){
        if(!x) return 1;
        LL ans = 1;
        for(int i=1;i<=b;i++)
            if(i%a)
                ans = ans * i % b;
        ans = ksm(ans,x/b,b);
        for(int i=1;i<=x%b;i++)
            if(i%a)
                ans = ans * i % b;
        return ans * fac(x/a,a,b)%b;
    }
    inline LL C(LL n,LL m,LL a,LL b){
        LL N=fac(n,a,b),M=fac(m,a,b),Z=fac(n-m,a,b),sum=0;
        for(LL i=n;i;i=i/a) sum+=i/a;
        for(LL i=m;i;i=i/a) sum-=i/a;
        for(LL i=n-m;i;i=i/a) sum-=i/a;
        return N*ksm(a,sum,b)%b*inv(M,b)%b*inv(Z,b)%b;
    }
    inline LL exlucas(LL n,LL m,LL p){
        LL t = p,ans = 0;
        for(LL i = 2;i * i <= p;i ++){
            LL k = 1;
            while(t % i == 0) k *= i,t /= i;
            ans+=crt(C(n,m,i,k),p,k),ans%=p;
        }
        if(t>1) ans += crt(C(n,m,t,t),p,t),ans%=p;
        return ans % p;
    }
}exlcs;

int main() {
    LL n = read(),m = read(),p = read();
    cout << exlcs.exlucas(n,m,p) << endl;
}
