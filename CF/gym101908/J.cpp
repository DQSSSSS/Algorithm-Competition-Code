#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

const double PI = acos(-1);

int main() {
    for(int n = 3;n <= 1000;n ++) {
        double alpha = 2 * PI / n;
        double a = 2-2*cos(alpha);
        if((n-1) * a < n) cout << n << endl;
    }
}
