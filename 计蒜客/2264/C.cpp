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

LL a[SZ],b[SZ],n,m,k;

LL check(LL x) {
    LL ans = 0;
    for(int i = 1,r = m;i <= n;i ++) {
        while(r >= 1 && x - a[i] < b[r]) r --;
        ans += r;
    }
    return ans;
}

int main() {
    n = read(),m = read(),k = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    for(int i = 1;i <= m;i ++) b[i] = read();
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
   // for(int i = 1;i <= 10;i ++) cout << check(i) << endl;
    LL l = 1,r = 2e9+1;
    while(r-l>1) {
        LL mid = l + r >> 1;
        if(check(mid) >= k) r = mid;
        else l = mid;
    }
    cout << r << endl;
}
