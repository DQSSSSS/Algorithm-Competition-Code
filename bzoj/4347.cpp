#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1048600;
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

int f[11][SZ],a[500010],g[SZ];

int main() {
    int n = read(),d = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    sort(a + 1,a + 1 + n);
    f[0][0] = 1;
    for(int i = 1;i <= n;i ++) {
        int tmp = log2(a[i]),maxlim = 1 << (tmp + 1);
    	for(int k = 0;k < maxlim;k ++) g[k] = f[d - 1][k];
    	for(int j = d - 1;j >= 0;j --) {
            for(int k = 0;k < maxlim;k ++) {
                if(k > (k ^ a[i])) continue;
                int *p = j == 0 ? g : f[j - 1];
                int now0 = f[j][k],now1 = f[j][k ^ a[i]];
                int lst0 = p[k],lst1 = p[k ^ a[i]];
                f[j][k] = (lst0 + now1) % mod;
                f[j][k ^ a[i]] = (lst1 + now0) % mod;
            }
    	}
    }
    int ans = f[0][0];
    if(n % d == 0) ans --;
    ans += mod; ans %= mod;
    cout << ans << endl;
    return 0;
}
