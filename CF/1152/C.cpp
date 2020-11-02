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

vector<LL> g;
LL a,b,maxlcm = 1e18,ans = 1e18;

void work(LL d) {
    LL bb = (b+d-1) / d * d;
    LL k = bb - b;
    LL lcm = (a+k)/__gcd(a+k,b+k)*(b+k);
    //cout << d << " " << k << " " << lcm << " " << maxlcm << endl;
    if(lcm < maxlcm) {
        maxlcm = lcm;
        ans = k;
    }
    else if(lcm == maxlcm) {
        ans = min(ans,k);
    }
}

int main() {
    a = read(),b = read();
    if(a == b) { puts("0"); return 0; }
    if(a < b) swap(a,b);
    LL d = a - b;
    for(LL i = 1;i * i <= d;i ++) {
        if(d % i == 0) {
            work(i);
            work(d / i);
        }
    }
    cout << ans << endl;
    return 0;
}


