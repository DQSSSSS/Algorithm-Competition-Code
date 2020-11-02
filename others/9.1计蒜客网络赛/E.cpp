#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 2e6 + 10;
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

LL f[2][1050010];
int a[22],b[22],c[22],er[1050010];
queue<int> q;

int main() {
	for(int S = 0;S < (1 << 20);S ++) {
		int cnt = 0;
		for(int i = 1;i <= 20;i ++)
			if((S >> (i - 1)) & 1) cnt ++;
		er[S] = cnt;
	}
	int n;
	while(~scanf("%d",&n)) {
		for(int i = 1;i <= n;i ++) g[i].clear();
		for(int i = 1;i <= n;i ++) {
			a[i] = read(),b[i] = read();
			int k = read(),x = 0;
			rd[i] = k;
			while(k --) {
				int d = read();
				x |= (1 << (d - 1));
				g[d].push_back(i);
			}
			c[i] = x;
		}
		for(int S = 0;S < (1 << n);S ++)
			f[0][S] = -INF;
		f[0][0] = 0;
		for(int i = 1;i <= n;i ++) {
			int cur = i & 1,lst = cur ^ 1;
			for(int S = 0;S < (1 << n);S ++) f[cur][S] = -INF;
			for(int S = 0;S < (1 << (i - 1));S ++) {
				int cnt = er[S] + 1;
				if(!((S >> (i - 1)) & 1) && (S & c[i]) == c[i])
					f[cur][S | (1 << (i - 1))] = max(f[cur][S | (1 << (i - 1))],f[lst][S] + 1ll * a[i] * cnt + b[i]);
			}
		}
		LL ans = 0;
		for(int S = 0;S < (1 << n);S ++) ans = max(ans,f[n & 1][S]);
		printf("%lld\n",ans);
	}
    return 0;
}
