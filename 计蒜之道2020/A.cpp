#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1000010;
const LL INF = 1e18 + 10;
const LL mod = 998244353;

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
    double a,dm;
    scanf("%lf%lf",&a,&dm);
    int n = read();
    double b = 0,s = 0;
    while(n --) {
        double x;
        scanf("%lf",&x);
        if(x >= 0) b += x;
        else s -= x;
        printf("%.3f\n",max(b,1.0)/max(s,1.0)*dm);
    }
}
