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


LL ans[SZ],tot;

LL work(LL n,LL i) {
	LL x = n / i - 1;
	return x * (x + 1) / 2 * i + n / i;
}

void add(LL x) {
	ans[++ tot] = x;
}

int main() {
	LL n = read();
	for(LL i = 1;i * i <= n;i ++) {
		if(n % i == 0) {
			add(work(n,i));
			if(i * i != n) add(work(n,n/i));
		}
	}
	sort(ans + 1,ans + 1 + tot);
	for(int i = 1;i <= tot;i ++) printf("%lld ",ans[i]);
	return 0;
}


