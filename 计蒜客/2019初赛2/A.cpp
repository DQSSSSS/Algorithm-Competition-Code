#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 332748118;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

LL ask(LL n,LL m) {
    n %= mod; m %= mod;
    return (n * m % mod * (n + 1) % mod + n * m % mod * (m + 1) % mod - n * m % mod * 2 % mod) % mod;
}

int main() {
    LL a = read(),b = read(),c = read(),d = read();
    LL ans = ask(b,d) - ask(b,c-1) - ask(a-1,d) + ask(a-1,c-1);
    ans %= mod; ans += mod; ans %= mod;
    printf("%lld\n",ans);
    return 0;
}
