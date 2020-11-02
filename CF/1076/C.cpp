#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
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
        double d;
        scanf("%lf",&d);
        if(d*d-4*d < -eps) puts("N");
        else {
            double b = d + sqrt(d*d-4*d); b /= 2;
            double a = d - b;
            printf("Y %.10f %.10f\n",b,a);
        }
    }
    return 0;
}
