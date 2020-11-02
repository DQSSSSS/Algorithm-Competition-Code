#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1100010;
const int INF = 1e9 + 10;
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


LL n,num[100000000],tot = 0,ans[SZ];

int a[233];
bool use[233];

void dfs(int d) {
	if(d == n + 1) {
		for(int i = 1;i <= n;i ++) num[++ tot] = a[i];
		return ;
	}
	for(int i = 1;i <= n;i ++) {
		if(!use[i]) {
			use[i] = 1;
			a[d] = i;
			dfs(d + 1);
			use[i] = 0;
		}
	}
}

LL f[SZ];

int main() {
	n = read();
	f[1] = 1;
	LL jc = 1;
	for(LL i = 2;i <= n;i ++) {
		(jc *= i) %= mod;
		f[i] = (i * f[i-1]% mod + jc-i) % mod;
	}
	cout << f[n] << endl;
	return 0;
}

