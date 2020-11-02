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

int main() {
    int T = read();
    while(T --) {
        LL k = read(),m = read(),ans = 2e18;
        for(LL x = 1;x <= 600;x ++) {
            LL n = k ^ x;
            if(__gcd(x,n) == 1) {
                int t = 0;
                for(LL i = 1;i <= x;i ++)
                    if(__gcd(n,i) == 1) t ++;
                if(t == m) {ans = min(ans,n);}
            }
        }
        if(ans == 2e18) ans = -1;
        printf("%lld\n",ans);
    }
}
