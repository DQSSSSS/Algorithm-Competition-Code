#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2500010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;
const double PI = acos(-1);

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
    	if(b & 1) ans = a * ans % mod;
		a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void fwt(int *a,int n,int opt) {
	for(int i = 1;i < n;i <<= 1) {
        for(int j = 0,p = i << 1;j < n;j += p) {
            for(int k = 0;k < i;k ++) {
                LL x = a[j + k],y = a[i + j + k];
                a[j + k] = (x + y) % mod;
                a[i + j + k] = (x - y) % mod;
            	if(opt == -1)
                    a[j + k] = 1ll * a[j + k] * 500000004 % mod,
                    a[i + j + k] = 1ll * a[i + j + k] * 500000004 % mod;
            }
        }
	}
}

int a[SZ];

int main() {
	int n = read(),m = read();
	int len = 1; while(len <= m) len *= 2;
    for
    return 0;
}

