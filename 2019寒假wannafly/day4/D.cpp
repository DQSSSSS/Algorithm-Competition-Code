#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 800100;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}


int main() {
    int n = read(),m = read();
    LL ans = n * (m-1) + (n - 1) * m;
    n -= 2; m -= 2;
    if(n % 2 == 0 && m % 2 == 0)  ans += n + m;
    else if(n % 2 == 1 && m % 2 == 1) ans += max(0,n - 1) + max(0,m - 1) + 4;
    else {
        if(n % 2 == 0) swap(n,m);
        if(m >= 2) ans += m + n + 2;
        else ans += n;
    }
    cout << ans << endl;
    return 0;
}
