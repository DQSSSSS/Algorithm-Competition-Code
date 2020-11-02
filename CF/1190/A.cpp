#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

LL a[SZ];

int main() {
    LL n = read(),m = read(),k = read();
    for(int i = 1;i <= m;i ++) a[i] = read();
    LL x = 0,ans = 0;
    for(int pos = 1;pos <= m;) {
        LL r = ((a[pos] - x - 1) / k + 1) * k + x;
        while(pos <= m && a[pos] <= r) pos ++,x ++;
        ans ++;
    }
    cout << ans << endl;
    return 0;
}
