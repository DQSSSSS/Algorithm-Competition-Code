#include<bits/stdc++.h>
using namespace std;

typedef unsigned int UI;
typedef unsigned long long ULL;
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 10000010;
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

UI b[SZ];
LL a[SZ];

int main() {
	int T = read();
	while(T --) {
		int n = read();
		LL l = read(),r = read();
		UI x = read(),y = read(),z = read();
		b[1] = read(),b[2] = read();
		for(int i = 3;i <= n;i ++) b[i] = b[i - 2] * x + b[i - 1] * y + z;
		for(int i = 1;i <= n;i ++) a[i] = (LL)b[i] % (r - l + 1) + l;
		LL ans = 5e18;
		//for(int i = 1;i <= n;i ++) printf("%lld ",a[i]); puts("");
		for(int i = 1,zero = 0;i <= n;i ++) {
			if(a[i] == 0) zero = 1;
			if(a[i] > 0 && zero) ans = 0;
		}
		for(int i = n,zero = 0;i >= 1;i --) {
			if(a[i] == 0) zero = 1;
			if(a[i] < 0 && zero) ans = 0;
		}
		LL minn = a[1];
		for(int i = 2;i <= n;i ++) {
			if(a[i] > minn) ans = min(ans,a[i] * minn);
			minn = min(a[i],minn);
		}
		LL maxfu = 1;
		for(int i = n;i >= 1;i --) {
			if(a[i] < 0) {
				if(maxfu == 1) maxfu = a[i];
				else {
					if(maxfu > a[i])
						ans = min(ans,maxfu * a[i]);
					maxfu = max(maxfu,a[i]);
				}
			}
		}
		LL minz = -1;
		for(int i = 1;i <= n;i ++) {
			if(a[i] > 0) {
				if(minz == -1) minz = a[i];
				else {
					if(minz < a[i])
						ans = min(ans,minz * a[i]);
					minz = min(minz,a[i]);
				}
			}
		}
		if(ans != 5e18) printf("%lld\n",ans);
		else puts("IMPOSSIBLE");
	}
	return 0;
}
