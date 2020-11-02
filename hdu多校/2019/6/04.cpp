#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
const LL INF = 1e18 + 10;
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

LL a[SZ],b[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 1;i <= n;i ++) a[i] = read(),b[i] = read();
        LL p = 0,q = 1;
        for(int i = 1;i <= n;i ++) {
            LL fm = a[i] + b[i];
            LL fz = a[i] * b[i];
            LL Mp = p * fm + q * fz;
            LL Mq = q * fm;

            LL d = __gcd(Mp,Mq);
            Mp /= d; Mq /= d;
            printf("%lld/%lld\n",Mp,Mq);
            p = Mp; q = Mq;
        }
    }
}
