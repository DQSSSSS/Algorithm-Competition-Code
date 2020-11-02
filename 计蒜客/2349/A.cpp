#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 998244353;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

long long inv(long long x) {
    long long b = mod - 2, ans = 1;
    while(b) {
        if(b & 1) {
            ans = ans * x % mod;
       }
        x = x * x % mod;
        b >>=1;
   }
    return ans;
}

LL jc(LL n) {
    LL ans = 1;
    for(int i = 2;i <= n;i ++) ans = ans * i % mod;
    return ans;
}

int main() {
    int n = read(),m = read();
    LL ans = jc(n*m) * inv(jc(n)) % mod * inv(jc(m)) % mod;
    cout << ans << endl;
}
