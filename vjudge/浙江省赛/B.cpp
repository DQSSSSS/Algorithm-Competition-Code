#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}

int a[SZ];
int b[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read();
        LL x1 = read(),y1 = read();
        for(int i = 1;i <= n;i ++) a[i] = read(),b[a[i]] ++;
        LL x2 = 0,y2 = 0;
        for(int i = 1;i <= n;i ++) x2 += 1ll * i * a[i];
        for(int i = 1;i <= n;i ++) y2 += 1ll * i * a[i] * a[i];
        LL dx = x2 - x1,dy = y2 - y1;
        if(dx == 0) {
            if(dy != 0) puts("0");
            else {
                LL ans = 0;
                for(int i = 1;i <= n;i ++) {
                    ans += 1ll * (b[a[i]] - 1);
                }
                printf("%lld\n",ans / 2);
            }
        }
        else if((y2 - y1) % (x2 - x1) != 0) puts("0");
        else {
            LL k = (y2 - y1) / (x2 - x1);
            LL ans = 0;
            for(int i = 1;i <= n;i ++) {
                if(2*a[i]-k == 0) continue;
                LL x = i-dx/(2*a[i]-k);
                if(x >= 1 && x <= n)
                    ans += a[x] == k-a[i];
            }
            printf("%lld\n",ans / 2);
        }
        for(int i = 1;i <= n;i ++) b[a[i]] = 0;
    }
}
