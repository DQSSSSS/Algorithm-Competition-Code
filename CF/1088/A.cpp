#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = acos(-1);
const int SZ = 510010;

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
	int n = read();
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j <= n;j ++) {
			if(i * j > n && i % j == 0 && i / j < n) {
				cout << i << " " << j << endl;
				return 0;
			}
		}
	}
	puts("-1");
	return 0;
}
