#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000100;
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

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int n;
LL m,k;
LL a[SZ];

int main() {
    n = read(),m = read(),k = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    sort(a + 1,a + 1 + n);
    LL x = a[n],y = a[n - 1];

    LL ans = 0;
    int d =  m / (k + 1); m %= k + 1;
    ans = x * k * d + y * d + m * x;
    cout << ans << endl;

    return 0;
}
