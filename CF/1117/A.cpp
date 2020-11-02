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

int n,a[SZ];
LL sum[SZ];
LL ans = 0;
double f[SZ],b[SZ];

int main() {
    n = read();
    int maxn = 0;
    for(int i = 1;i <= n;i ++) a[i] = read(),maxn = max(maxn,a[i]);

    int t = 0,ans = 0;
    for(int i = 1;i <= n;i ++) {
        if(a[i] == maxn) ans = max(ans,++ t);
        else t = 0;
    }
    cout << ans << endl;

    return 0;
}
