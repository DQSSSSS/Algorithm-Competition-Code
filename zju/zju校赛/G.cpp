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

LL f[SZ],z[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read(),k = read();
        f[0]=z[0]=0;
        for(int i = 1;i <= n;i ++) {
            int x = read();
            if(x < 0) f[++f[0]] = -x;
            else z[++z[0]] = x;
        }
        sort(f + 1, f + 1 + f[0]);
        sort(z + 1, z + 1 + z[0]);
       // for(int i = 1;i <= f[0];i ++) cout << f[i] << " "; puts("");
       // for(int i = 1;i <= z[0];i ++) cout << z[i] << " "; puts("");
        LL ans = 0;
        for(int i = f[0],t = 1,lst = f[0];i >= 1;i --,t ++) {
            if(i == 1 || t % k == 0) {
           //     cout << f[lst] << endl;
                ans += f[lst] * 2; lst = i - 1;
            }
        }
        for(int i = z[0],t = 1,lst = z[0];i >= 1;i --,t ++) {
            if(i == 1 || t % k == 0) {
               // cout << z[lst] << endl;
                ans += z[lst] * 2; lst = i - 1;
            }
        }
        ans -= max(f[f[0]],z[z[0]]);
        printf("%lld\n",ans);
    }
}
