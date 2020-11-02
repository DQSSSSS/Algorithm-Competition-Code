#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
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

LL k;

LL dfs(LL n,LL m,LL a,LL b) {
	if(n < k) return 0;
	LL ans = 0;
	
	LL mres = (n - b) / (k - b) * m;
	
	if(b < k) {
		if(n >= k) ans += n * m / k;
		return ans;
	}
	else {
		return (a * b + n * m) / k;
	}
}

int main() {
	LL t = read(),n = read(),a = read(),b = read();
	k = read();
	LL ji = (n + 1) / 2,ou = n - ji;
	if(n < k) { puts("0"); return 0; }
	if(a < b) swap(ji,ou),swap(a,b);
	printf("%lld\n",min(dfs(n,b,a-b,ji),t));
	return 0;
}
