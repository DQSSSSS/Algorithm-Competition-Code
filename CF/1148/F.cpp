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

LL get(LL x) {
    x ^= x >> 32;
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x & 1;
}

int main() {
    int n = read();
    LL S = 0;
    for(int i = 1;i <= n;i ++) {
        a[i] = read();
        b[i] = read();
        S += a[i];
    }
    LL ans = 0;
    for(LL k = 0;k <= 62;k ++) {
        LL sum = 0;
        for(int i = 1;i <= n;i ++) {
            if((1ll<<k) <= b[i] && b[i] < (1ll<<(k+1))) {
                LL x = get(b[i] & ans);
                if(x) sum += -a[i];
                else sum += a[i];
            }
        }
        if(sum == 0) continue;
        if((sum<0) == (S<0)) ans |= 1ll << k;
    }

  /*  LL sum = 0;
    for(int i = 1;i <= n;i ++) {
        LL x = get(b[i] & ans);
        if(x) sum += -a[i];
        else sum += a[i];
    }
    cout << sum << endl;*/
    cout << ans << endl;
}
