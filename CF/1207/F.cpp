#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 2e6 + 10;
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

LL a[SZ];
LL b[720][720];

int main() {
    int q = read();
    int B = 710;
    while(q --) {
        int o = read(),x = read(),y = read();
        if(o == 1) {
            a[x] += y;
            for(int i = 1;i <= B;i ++) b[i][x%i] += y;
        }
        else {
            if(x <= B) printf("%lld\n",b[x][y]);
            else {
                LL ans = 0;
                for(int i = y;i <= 500000;i += x)
                    ans += a[i];
                printf("%lld\n",ans);
            }
        }
    }
}
