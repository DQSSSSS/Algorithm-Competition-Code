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


int main() {
    freopen("baklava.in","r",stdin);
    int T = read();
    while(T --) {
        int n = read();
        double a = 180 - 360.0 / n;
        a = a * PI / 180;
        double p = sin(a/2); p *= p;
        printf("%.5f\n",10000/(1-p));
    }
}


