#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 2e6 + 10;
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

char s[SZ];
LL f[SZ][2];

int main() {
    int T = read();
    while(T --) {
        int n = read(),a = read(),b = read();
        scanf("%s",s);
        f[0][1] = 1e18;
        f[0][0] = b;
        for(int i = 1;i <= n;i ++) {
            if(s[i-1] == '0') {
                f[i][0] = min(f[i-1][0]+a+b,f[i-1][1]+2*a+b);
                f[i][1] = min(f[i-1][0]+2*a+2*b,f[i-1][1]+a+2*b);
            }
            else {
                f[i][0] = 1e18;
                f[i][1] = f[i-1][1]+a+2*b;
            }
        }
        printf("%lld\n",f[n][0]);
    }
}
