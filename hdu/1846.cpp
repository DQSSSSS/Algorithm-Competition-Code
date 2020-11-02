#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

int main() {
	int T = read();
	while(T --) {
		int n = read(),m = read();
		if(n % (m + 1)) puts("first");
		else puts("second");
	}
	return 0;
}
/*
1 2...m m+1 m+2...2m 2m+1 2m+2  2m+3...3m+2  3m+3
1 1...1 0     1...1  1     0     1  ...  1    0
*/
