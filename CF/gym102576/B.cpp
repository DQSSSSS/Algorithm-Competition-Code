#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
const int INF = 1e9 + 10;
const int mod = 1e9+7;
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

LL sum[SZ];
int a[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 0;i <= (1<<20);i ++) sum[i] = 0;
        for(int i = 1;i <= n;i ++) {
            int x = a[i] = read();
            sum[x] ++;
        }
        for(int j = 0;j < 20;j ++) {
            for(int S = 0;S < (1<<20);S ++) {
                if(S >> j & 1) {
                    sum[S] += sum[S^(1<<j)];
                }
            }
        }
        LL ans = 0;
        for(int i = 1;i <= n;i ++) ans += sum[a[i]];
        printf("%lld\n",ans);
    }
}

/*
2
3
1 5 6
3
1 1 1
*/
