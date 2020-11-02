#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2100010;
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

LL ksm(LL a,LL b,LL mod) {
	LL ans = 1;
	while(b) {
		if(b & 1) ans = a * ans % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

LD ksm(LD a,int b) {
	LD ans = 1;
	for(int i = 1;i <= b;i ++) ans = ans * a;
	return ans;
}

char get(int x) {
	if(x < 10) return x + '0';
	else return x - 10 + 'A';
}

int main() {
	int T = read(),cc = 0;
	while(T --) {
		int n = read() - 1;
		long double ans = 0;
		for(int k = 0;k <= n + 100;k ++) {
			int p1 = 8*k+1;
			int p2 = 8*k+4;
			int p3 = 8*k+5;
			int p4 = 8*k+6;
			if(k <= n)
				ans += 48 + 4.0*ksm(16,n-k,p1)/p1 - 2.0*ksm(16,n-k,p2)/p2
					-1.0*ksm(16,n-k,p3)/p3 - 1.0*ksm(16,n-k,p4)/p4;
			else
				ans += 48 + 4.0/(ksm(16,k-n)*p1) - 2.0/(ksm(16,k-n)*p2)
					-1.0/(ksm(16,k-n)*p3) - 1.0/(ksm(16,k-n)*p4);
		//	cout << ans << endl;
			while(ans > 16) ans -= 16;
		}
		//ans += 16;
//		cout << ans << endl;
		int x = ((int)(ans * 16) % 16);
		x += 16; x %= 16;
		//cout << x << endl;
		printf("Case #%d: %d %c\n",++ cc,n + 1,get(x));
	}
	return 0;
}
