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

struct haha {
    int x1,x2,y1,y2;
    LL ans1,ans2;
}a[SZ];

LL xj(haha a,haha b) {
    int x1 = max(a.x1,b.x1),x2 = min(a.x2,b.x2);
    int y1 = max(a.y1,b.y1),y2 = min(a.y2,b.y2);
    if(x1<=x2&&y1<=y2) return (x2-x1+1ll)*(y2-y1+1);
    return 0;
}

int main() {
    freopen("D.in","r",stdin);
    freopen("B.out","w",stdout);
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 1;i <= n;i ++) {
            a[i].x1 = read()+1; a[i].y1 = read()+1;
            a[i].x2 = read(); a[i].y2 = read();
            a[i].ans1 = 0;
            a[i].ans2 = 0;
        }
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= n;j ++) {
                if(j == i) continue;
                LL x = xj(a[i],a[j]);
                if(x) a[i].ans1 ++,a[i].ans2 += x;
            }
        }

        for(int i = 1;i <= n;i ++)
            printf("%lld %lld\n",a[i].ans1,a[i].ans2);
    }
}
