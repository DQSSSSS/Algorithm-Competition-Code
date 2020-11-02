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

int a[310][310];

double ksm(double a,int b) {
    double ans = 1;
    while(b) {
        if(b & 1) ans = a * ans;
        a = a * a;
        b >>= 1;
    }
    return ans;
}

int main() {
    freopen("fetiera.in","r",stdin);

    int T = read();
    while(T --) {
        int n = read(),k = read();
        double ans = 0;
        for(int i = 1;i <= n;i ++)
            for(int j = 1; j <= n; j ++) {
                a[i][j] = read();
            }
        for(int i = 1;i <= n;i ++)
            for(int j = 1; j <= n; j ++) {
                int x = a[i][j];
                double p = (2.0*(n-i+1)*i/(n*(n+1))) * (2.0*(n-j+1)*j/(n*(n+1)));
                double d = 0;
                if(x == 1) {
                    d = (1 + ksm(1-2*p,k)) / 2;
                }
                else {
                    d = (1 - ksm(1-2*p,k)) / 2;
                }
               // cout << i << " " << j << " " << p << " " << d << endl;
                ans += d;
            }
        printf("%.5f\n",ans);
    }
}


