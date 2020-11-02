#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
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

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b&1) ans = a * ans % mod;
         a = a * a % mod;
         b >>= 1;
    }
    return ans;
}

LL inv(LL x) { return ksm(x,mod-2); }

struct frac {
    int x,y;
    frac(LL _x=0,LL _y=1):x(_x),y(_y) { }
    int getval() { return 1ll*x*inv(y)%mod; }
};

bool operator <(const frac &a,const frac &o) { return a.x*o.y<a.y*o.x; }


int jf1(frac &ll,frac &rr) {
    if(rr<ll) return 0;
    LL l = ll.getval();
    LL r = rr.getval();
    return (r*r-l*l)%mod*inv(2)%mod;
}

int jf2(frac &ll,frac &rr) {
    if(rr<ll) return 0;
    LL l = ll.getval();
    LL r = rr.getval();
    return (r*r%mod*r-l*l%mod*l)%mod*inv(3)%mod;
}

LL a,b,c,d;

LL f(int w) {
    frac L,R;
    LL ans1,ans2,ans3,ans4;

    L = max(frac(c,1),frac(b,w+1)); R = min(frac(d,1),frac(a,w));
    ans1 = (b-a) * jf1(L,R) % mod;

//    L = b*w>a*(w+1)? (c*(w+1)>b?c:b*inv(w+1)) : (c*w>a?c:a*inv(w));
    L = max( max(frac(c,1),frac(b,w+1)),frac(a,w) );
    R = min(frac(d,1),frac(b,w));
    ans2 = (b*jf1(L,R)%mod - w*jf2(L,R)%mod) % mod;

    L = max(frac(c,1),frac(a,w+1));
  //  R = b*w<a*(w+1)? (c*(w+1)<b?c:b*inv(w+1)) : (c*w<a?c:a*inv(w));
    R = min( min(frac(d,1),frac(b,w+1)),frac(a,w) );
    ans3 = ((w+1)*jf2(L,R)%mod - a*jf1(L,R)%mod) % mod;

    //L = c*w>a ? c : a*inv(w); R = d*(w+1)>b ? d : b*inv(w+1);
    L = max(frac(c,1),frac(a,w)); R = min(frac(d,1),frac(b,w+1));
    ans4 = jf2(L,R);

    return (ans1+ans2+ans3+ans4)%mod;
}

int main() {
    int T = read();
    while(T --) {
        a = read(); b = read(); c = read(); d = read();
        int ans = 0;
        for(int w = a/d;w <= b/c;w ++) {
            cout << w << " " << f(w) << endl;
            (ans += 1ll * w * f(w) % mod) %= mod;
        }
       // ans = 1ll * ans * inv(b-a) % mod;
        ans = ((a+b)*inv(2) - ans) % mod;
        ans += mod; ans %= mod;
        printf("%d\n",ans);
    }
}
