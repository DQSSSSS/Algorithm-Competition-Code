#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
typedef pair<int,LL> pil;
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

int n,k;
LL a[SZ],b[SZ];
int c[SZ];

pil check(LL mid) {
    int maxk = 0;
    LL pos;
    for(int i = 1,lst = 1;i <= n;i ++) {
        LL l = a[i] - mid;
        LL r = a[i] + mid;
        while(a[lst] + mid < l) lst ++;
        int x = i - lst + 1;
        if(x > maxk) maxk = x,pos = l;
    }
    return make_pair(maxk,pos);
}

int main() {
    int T = read();
    while(T --) {
        n = read(),k = read();
        for(int i = 1;i <= n;i ++) a[i] = read();
        if(k == 0) {
            printf("%lld\n",a[1]);
            continue;
        }
        LL l = 0,r = 1e18;
        while(r - l > 1) {
            LL mid = l + r >> 1;
            if(check(mid).first >= k + 1) r = mid;
            else l = mid;
        }
        printf("%lld\n",check(r).second);
    }
}

