#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 300010;
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

LL get(LL n,LL m) {
	LL ans = 0;
	if(n > m) swap(n,m);
	if(n % 2 == 0 && m % 2 == 0) {
		if(n == 2 && m == 2) ans = 0;
		else ans = n * m;
	}
	else if(n % 2 && m % 2) {
		if(n == 1) {
			if(m == 3 || m == 1) ans = 0;
			else if(m % 6 == 1 || m % 6 == 5) {
				ans = m - 1;
			}
			else ans = m - 3;
		}
		else ans = n * m - 1;
	}
	else {
		if(n % 2 == 0) swap(n,m);
		if(n == 1) {
			if(m % 6 == 0) ans = m;
			else ans = m - 2;
		}
		else if(m == 2) {
			if(n == 1) ans = 0;
			else {
				if(n == 3 || n == 7) ans = n * m - 2;
				else ans = n * m;
			}
		}	
		else {
			ans = n * m;
		}
	}
	return ans;
}

int main() {
/*
	for(int i = 1;i <= 20;i ++,puts(""))
		for(int j = 1;j <= 20;j ++)
			printf("%4lld",get(i,j));
		*/
	LL n = read(),m = read(),ans;
	cout << get(n,m) << endl;
	return 0;
}
