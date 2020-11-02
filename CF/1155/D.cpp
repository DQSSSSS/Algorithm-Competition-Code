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

int n;
LL a[SZ],f[SZ][3];

int main() {
    n = read();
    LL x = read(),ans = 0;
    for(int i = 1;i <= n;i ++) {
        LL y = read();
        f[i][0] = max(y,f[i-1][0] + y);
        f[i][1] = max(x*y,max(f[i-1][0] + x * y,f[i-1][1] + x * y));
        f[i][2] = max(y,max(f[i-1][2] + y,f[i-1][1] + y));
        ans = max(ans,f[i][0]);
        ans = max(ans,f[i][1]);
        ans = max(ans,f[i][2]);
    }
    cout << ans << endl;
}
