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

int h,A,B,a,b,c;

LL w(LL i,LL j) {
    long double d = B + 1.0*(A-B)*(h-i)/h;
    LL x = d / j;
  //  cout << i << " " << j << " " << x << endl;
    return x * x * j * j * j;
}

LL f[SZ];

int main() {
    while(~scanf("%d%d%d%d%d%d",&h,&A,&B,&a,&b,&c)) {
        for(int i = 1;i <= h;i ++) f[i] = -1e18;
        f[0] = 0;
        LL ans = 0;
        for(int i = 1;i <= h;i ++) {
            LL tmp = 0;
            if(i>=a) tmp = max(tmp,f[i-a]+w(i,a));
            if(i>=b) tmp = max(tmp,f[i-b]+w(i,b));
            if(i>=c) tmp = max(tmp,f[i-c]+w(i,c));
            f[i] = tmp;
            ans = max(ans,f[i]);
        }
        printf("%lld\n",ans);
    }
}

/**
100 100 50 13 11 17
500000 800000 300000 6931 11315 5000
*/
