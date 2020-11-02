#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
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

int main() {
	int T = read();
	while(T --) {
		ULL a,b,c,d;
		cin >> a >> b >> c >> d;
		ULL ans = a + b + c + d;
		bool f = 0;
		if(a || b || c || d) f = 1;
		if(f && ans == 0) puts("18446744073709551616");
		else cout << ans << endl;
	}
	return 0;
}
