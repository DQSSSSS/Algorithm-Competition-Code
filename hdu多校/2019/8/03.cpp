#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
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

LL get(LL n,int x) {
    LL ans = 0;
    while(n) {
        if(n%10==x) ans ++;
        n /= 10;
    }
    return ans;
}

int main() {
    LL ans = 900000000;
    for(LL i = 999999999+1;;i ++) {
        ans += get(i,1);
        if((LL)(pow(10,get(i,9))+eps) == i+1)
            printf("%lld %lld\n",i,ans);
    }
}

/**
9 1
99 20
999 300
9999 4000
99999 50000
999999 600000
9999999 7000000
99999999 80000000
999999999 900000000
*/
