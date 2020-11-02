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

struct haha {
    LL x,y;
}a[SZ];

bool cmp(haha a,haha b) {
    return a.x-a.y > b.x-b.y;
}

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) a[i].x = read(),a[i].y = read();
    sort(a+1,a+1+n,cmp);
    LL ans = 0;
    for(int i = 1;i <= n;i ++) {
        ans += a[i].x * (i-1) + a[i].y * (n-i);
    }
    cout << ans << endl;
}
