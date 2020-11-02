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

int a[SZ];

int main() {
	int n = read(),k = read();
	for(int i = 1;i <= n;i ++) a[i] = read();
	sort(a + 1,a + 1 + n);
	int p = 1;
	while(k --) {
		while(p <= n && a[p] - a[p - 1] == 0) p ++;
		if(p == n + 1) {puts("0"); continue;}
		printf("%d\n",a[p] - a[p - 1]);
		p ++;
	}
	return 0;
}

