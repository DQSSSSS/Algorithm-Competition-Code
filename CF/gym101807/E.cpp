#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
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

LL a[SZ],b[SZ];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    for(int i = 1;i <= n;i ++) b[i] = i;
    do {
        LL ans = 0,flag = 0;
        for(int i = 1;i <= n;i ++) {
            ans += a[b[i]];
            if(ans < 0 || ans > 99999999) {
                flag = 1; break;
            }
        }
        if(!flag) {
            for(int i = 1;i <= n;i ++) printf("%lld\n",a[b[i]]);
            return 0;
        }
    }while(next_permutation(b+1,b+1+n));
    puts("Error");
}
