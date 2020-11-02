#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int SZ = 300010;
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

int a[SZ];

int main() {
    freopen("data.in","r",stdin);
    freopen("bl.out","w",stdout);
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 1;i <= n;i ++) {
            a[i] = read();
        }
        int q = read();
        while(q --) {
            int opt = read();
            if(opt == 1) {
                int pos = read(),x = read();
                a[pos] = x;
            }
            else {
                int l = read(),r = read(),x = read();
                LL ans = 0;
                for(int i = l,f = 0;i <= r;i ++) {
                    if(a[i] == x) f ^= 1;
                    if(f == 1) ans ++;
                }
                printf("%lld\n",ans * (r-l+2-ans));
            }
        }
    }
}
/**
1
10
1 1 1 1 1 1 1 1 1 1
1
2 1 10 1

*/
