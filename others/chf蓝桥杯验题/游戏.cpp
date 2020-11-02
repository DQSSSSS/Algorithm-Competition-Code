#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2e7 + 10;
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

int main() {
    int k = read(),x = read();
    double l = 0,r = 1;
    for(int i = 1;i <= 30;i ++) {
        double mid = (l + r) / 2.0;
        double ans = x;
        for(int j = 1;j <= k;j ++) ans *= mid;
        if(ans >= 1 - 2 * mid) r = mid;
        else l = mid;
    }
    printf("%.10f\n",l);
}
