#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}
struct haha {
    int d,t;
}a[SZ];

bool cmp(haha a,haha b) { return a.d < b.d; }

int main() {
    int T = read(),cc = 0;
    while(T --) {
        int n = read(),m = read();
        for(int i = 1;i <= n;i ++) a[i].d = read();
        for(int i = 1;i <= n;i ++) a[i].t = read();
        sort(a+1,a+1+n,cmp);
        int ans = 0;
        for(int i = 1;i <= n;i ++) {
            if(m - a[i].t < 0) break;
            m -= a[i].t; ans ++;
        }
        printf("Case %d: %d\n",++ cc,ans);
    }
}
