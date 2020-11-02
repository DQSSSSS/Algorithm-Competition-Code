#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef double LD;
typedef pair<LL,LL> pii;
const int SZ = 2100010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-12;
const LD PI = acos(-1);

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

LL f[310][310];
LL g[310][310];
LL a[310],b[310];

int main() {
	int T = read();
	while(T --) {
		int n = read();
		for(int i = 1;i <= n;i ++) a[i] = read();
		for(int i = 1;i <= n;i ++) b[i] = read();
		for(int i = 1;i <= n;i ++) {
			for(int j = i;j <= n;j ++)
				f[i][j] = -INF,g[i][j] = 0;
			f[i][i - 1] = 0;
		}
		for(int i = 1;i < n;i ++) g[i][i + 1] = __gcd(a[i],a[i + 1]) > 1;
		for(int i = n;i >= 1;i --) {
			for(int j = i + 3;j <= n;j += 2) {
				if(g[i + 1][j - 1] && __gcd(a[i],a[j]) > 1) g[i][j] = 1;
				else
					for(int k = i + 1;k < j;k += 2)
						g[i][j] |= g[i][k] & g[k + 1][j];
			}
		}
		//cout << g[1][n] <<endl;
		for(int i = n;i >= 1;i --) {
			for(int j = i + 1;j <= n;j ++) {
				if(g[i][j]) {
					LL d = 0;
					for(int k = i;k <= j;k ++)
						d += b[k];
					f[i][j] = d;
				}
				else {
					for(int k = i;k < j;k ++)
						f[i][j] = max(f[i][j],max(0ll,f[i][k]) + max(0ll,f[k + 1][j]));
				}
			}
		}
		printf("%lld\n",f[1][n]);
	}
	return 0;
}
/**
1
6
7 3 9 4 16 49
1 1 1 1 1 1
*/
