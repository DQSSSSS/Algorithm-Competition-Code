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

int a[10000010];

int main() {
    int n = read();
    LL ans = 1e18;
    int f,t;
    for(int i = 1;i <= n;i ++) {
        LL x = read();
        if(a[x] && ans > x) ans = x,f = a[x],t = i;
        a[x] = i;
    }
    for(int i = 1;i <= 1e7;i ++) {
        LL y = 0,x;
        for(int j = i;j <= 1e7;j += i) {
            if(a[j]) {
                if(y == 0) y = j,x = a[j];
                else {
                    if(1ll*y*j/i < ans) {
                        ans = 1ll*y*j/i;
                        f = x; t = a[j];
                    }
                    break;
                }
            }
        }
    }
    if(f>t) swap(f,t);
    cout << f << " " << t << endl;
}
