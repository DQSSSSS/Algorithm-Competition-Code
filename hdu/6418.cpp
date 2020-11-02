#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
const int INF = 1e9 + 10;
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


int main() {
    int T = read();
    while(T --) {
        LL a = read(),b = read(),c = read();
        LL d = read(),e = read(),f = read();
        LL n = a + b + c;
        LL fz = a * (e - f) + b * (f - d) + c * (d - e);
        LL fm = n;
       	LL dd = __gcd(fz,fm);
        fz /= dd; fm /= dd;
        if(fm < 0) fz = -fz,fm = -fm;
        if(fm == 1) printf("%lld\n",fz);
        else printf("%lld/%lld\n",fz,fm);
    }
    return 0;
}
