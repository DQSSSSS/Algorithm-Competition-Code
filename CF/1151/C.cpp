#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}


LL work(LL n) {
    LL sum0 = 0,sum1 = 0;
    for(LL i = 1,x = 1,sum = 0;;i ++,x *= 2) {
        if(sum + x > n) {
            if(i & 1) sum1 += n - sum;
            else sum0 += n - sum;
            break;
        }
        sum += x;
        if(i & 1) sum1 += x;
        else sum0 += x;
    }
    return sum1%mod * (sum1%mod)%mod + sum0%mod*((sum0+1)%mod)%mod;
}

int main() {
    LL l = read(),r = read();
    cout << ((work(r) - work(l-1)) % mod + mod) % mod << endl;
}
