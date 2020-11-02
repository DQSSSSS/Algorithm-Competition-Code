#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200010;
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

LL ksm(LL a,LL b) {
	LL ans = 1;
	while(b) {
		if(b & 1) ans = a * ans % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}


int main() {
	LL ni8 = 125000001,ni4 = 250000002;
	int T = read();
	while(T --) {
		LL n = read(),d = read();
		if(d == 1) printf("%lld\n",(n + 2) * ni4 % mod);
		else printf("%lld\n",(3 * n + 6) % mod * ni8 % mod);
	}
	return 0;
}

