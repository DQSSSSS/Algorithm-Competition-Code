#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 3e5 + 10;
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
    int l,r;
    while(~scanf("%d%d",&l,&r)) {
        if(l == 0) break;
        double ans = 0;
        for(int i = l;i <= r;i ++) {
            double tmp = 1e9 / pow(i,2.0/3);
            ans += tmp / 3;
        }
        int d = 15 + 9;
        while(ans > 0 && ans >= 10) ans /= 10,d --;
        while(ans < 0) ans *= 10,d ++;

        int x = ans * 100000 + 0.5;
        printf("%d.%05dE-%03d\n",x/100000,x%100000,d);
    }
}
/**
2000010000 2000000000
*/
