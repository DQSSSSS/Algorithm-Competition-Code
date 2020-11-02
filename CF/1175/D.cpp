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

LL a[SZ],b[SZ];

int main() {
    int n = read(),k = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    for(int i = n;i >= 1;i --) b[i] = b[i+1] + a[i];
    //for(int i = 1;i <= n;i ++) printf("%lld ",b[i]); puts("");
    LL ans = b[1]; k --;
    sort(b+2,b+1+n);
    for(int i = n,t = 1;t <= k;i --,t ++) {
        ans += b[i];
    }
    cout << ans << endl;
}

/**
5 1
-1 -2 5 -4 8

*/
