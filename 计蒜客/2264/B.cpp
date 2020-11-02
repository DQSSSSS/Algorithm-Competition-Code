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

int n,m;

struct haha {
    int r[SZ],c[SZ],d1[SZ],d2[SZ];
    int setxy(int x,int y) {
        int ans = 0;
        ans = max(ans,++ r[x]);
        ans = max(ans,++ c[y]);
        ans = max(ans,++ d1[x-y+n]);
        ans = max(ans,++ d2[x+y]);
        return ans;
    }
}a[2];

int main() {
    n = read(),m = read();
    bool cur = 0;
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read();
        int ans = a[cur].setxy(x,y);
        if(ans == n) {
            if(cur == 0) {
                printf("%d milk!",i);
                return 0;
            }
            else {
                printf("%d juice!",i);
                return 0;
            }
        }
        cur ^= 1;
    }
    printf("%d drawn!",m);
}
