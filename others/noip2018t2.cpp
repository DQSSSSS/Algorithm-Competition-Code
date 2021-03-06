#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1100010;
const int INF = 1e9 + 10;
const int mod = 7340033;
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

int a[SZ],f[SZ];

int main() {
	int T = read();
	while(T --) {
		int n = read();
		for(int i = 1;i <= n;i ++) a[i] = read();
		sort(a + 1,a + 1 + n);
		int V = a[n];
		for(int i = 1;i <= V;i ++) f[i] = 0;
		f[0] = 1;
		int ans = 0;
		for(int i = 1;i <= n;i ++) {
			if(!f[a[i]]) {
				ans ++;
				for(int j = a[i];j <= V;j ++)
					f[j] |= f[j - a[i]];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
