#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2e5 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int a[22];

int main() {
    int T = read(),w = read();
    while(T --) {
        puts("200"); fflush(stdout);
        LL x = read();
        a[4] = x >> 50 & 127;
        a[5] = x >> 40 & 127;
        a[6] = x >> 33 & 127;

        puts("50"); fflush(stdout);
        LL y = read();
        y -= a[4] * (1ll<<(50/4));
        y -= a[5] * (1ll<<(50/5));
        y -= a[6] * (1ll<<(50/6));
        a[1] = y >> 50 & 127;
        a[2] = y >> 25 & 127;
        a[3] = y >> 16 & 127;
        for(int i = 1;i <= 6;i ++)
            printf("%d ",a[i]); puts(""); fflush(stdout);
        read();
    }
}
