#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 100010;
const LL INF = 1e18 + 10;
const int mod = 998244353;
const LD eps = 1e-8;
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

LL work(char c,LL a,LL b) {
	LL ans = 0;
	if(c == '+') ans = a + b;
	if(c == '-') ans = a - b;
	if(c == '*') ans = a * b;
	if(c == '/') ans = a / b;
	return ans;
}

LL f[7][1010][2],a[SZ];
char s[SZ];

int main() {
	int T = read();
	while(T --) {
		int n = read(),m = read();
		LL x = read();
		for(int i = 1;i <= n;i ++) a[i] = read();
		scanf("%s",s + 1);
		for(int j = 0;j <= m;j ++)
			for(int i = 0;i <= n;i ++)
				f[j][i][0] = INF,f[j][i][1] = -INF;
		for(int i = 0;i <= n - m;i ++)
			f[0][i][0] = f[0][i][1] = x;
		for(int i = 1;i <= m;i ++) {
			for(int j = 1;j <= n;j ++) {
				LL a = f[i - 1][j - 1][0];
				LL b = f[i - 1][j - 1][1];
				if(a == INF) {
					f[i][j][0] = f[i][j - 1][0];
					f[i][j][1] = f[i][j - 1][1];
					continue;
				}
				assert(b != -INF);
				LL c = ::a[j];
				a = work(s[i],a,c);
				b = work(s[i],b,c);
				f[i][j][0] = min(f[i][j - 1][0],min(a,b));
				f[i][j][1] = max(f[i][j - 1][1],max(a,b));
			}
		}
		/*for(int i = 0;i <= m;i ++,puts(""))
			for(int j = 0;j <= n;j ++)
				cout << f[i][j][0] << " ";*/
		printf("%lld\n",f[m][n][1]);
	}
	return 0;
}
