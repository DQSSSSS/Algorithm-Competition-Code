#include<bits/stdc++.h>
using namespace std;

typedef __int128 LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e5 + 10;
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

LL exgcd(LL a,LL b,LL &x,LL &y) {
    if(b == 0) {
        x = 1; y = 0;
        return a;
    }
    LL d = exgcd(b,a%b,x,y);
    LL t = x; x = y; y = t - a / b * y;
    return d;
}

LL MulMod(LL a,LL b,LL p) {
    return a*b%p;
}

LL m;

LL excrt(LL *r,LL *a,int n) { // x%a=r
    for(int i = 1;i <= n;i ++) {
        for(int j = i+1;j <= n;j ++) {
            LL d = __gcd(a[i],a[j]);
            if(r[i]%d!=r[j]%d) return -1;
       }
    }
    LL R = r[1], M = a[1];
    for(int i = 2;i <= n;i ++) {
        LL a2 = r[i],b2 = a[i],x,y,d;
        d = exgcd(M,b2,x,y);
        LL c = a2 - R;
       // if (c%d) return -1;
        LL k1 = c/d*x,t = b2/d;
        k1 = (k1%t+t)%t;
        R = M*k1+R;
        M = M/d*b2;
        if(R > m) return -2;
    }
    return R;
}

LL r[SZ],a[SZ];

int main() {
    int n;
    while(~scanf("%d",&n)) {
        m = read();
        for(int i = 1;i <= n;i ++) {
            a[i] = read();
            r[i] = read();
        }
        LL ans = excrt(r,a,n);
        if(ans == -1) puts("he was definitely lying");
        else if(ans == -2) puts("he was probably lying");
        else cout << (long long)ans <<endl;
    }
}
