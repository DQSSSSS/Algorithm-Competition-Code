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

void solve(LL a,LL b,LL c,LL d,LL &x,LL &y) {
    LL z = (a+b-1)/b;
    if(z<=c/d) { x=z; y=1; return ; }
    a -= (z-1) * b; c -= (z-1) * d;
    solve(d,c,b,a,y,x);
    x += (z-1) * y;
}

LL mul(LL a,LL b,LL p) {
    LL ans = 0;
    while(b) {
        if(b&1) (ans += a) %= p;
        (a += a) %= p;
        b >>= 1;
     }
     return ans;
}

int main() {
    int T = read();
    while(T --) {
        LL p = read(),x = read();
        LL A = x-1,B = p,C = x,D = p,X,Y;
        solve(A,B,C,D,X,Y);
        X = mul(Y,x,p);
        printf("%lld/%lld\n",X,Y);
    }
}

/**
2
998244353 554580197
*/
