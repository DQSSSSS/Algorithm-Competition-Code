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

LL a[SZ];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    LL ans = 0,t = 0;
    for(int i = 1;i <= n;i ++) {
        while(t && a[i] >= 2) a[i] -= 2,t --,ans ++;
        ans += a[i] / 3; a[i] %= 3;
        t += a[i];
    }
    cout << ans << endl;
}
