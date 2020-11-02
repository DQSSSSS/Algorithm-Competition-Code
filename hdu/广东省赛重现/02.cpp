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

LL p;

LL mul(LL a,LL b) {
    LL ans = 0;
    while(b) {
        if(b & 1) (ans += a) %= p;
        (a+=a)%=p;
        b>>=1;
    }
    return ans;
}

LL a[SZ];

int main() {
    LL k = read(),m = read(),n = read(); p = read();
    for(int i = 1;i <= k;i ++) a[i] = read();
    sort(a+1,a+1+k);
    if(n == 1) {
        k = min(k,m-1);
        LL ans = 0;
        for(int i = 1;i <= k;i ++) (ans += mul(a[i],k-i+1)) %= p;
        printf("%lld\n",ans);
    }
    else {
        k = 1;
        for(int i = 1;i <= m;i ++) k *= n; k --;
        k /= (n-1);
        LL ans = 0,mm = m;
        for(int i = k;i >= 1;) {
            m --;
            LL d = mi(n,m);
            LL sum = 0;
            while(d --) (sum += a[i --]) %= p;

        }
    }
}
