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
struct ahha {
	int opt,i,x;
}b[SZ];

int main() {
	int n = read();
	for(int i = 1;i <= n;i ++) a[i] = read();
	int d = 0,tot = 0;
	for(int i = n;i >= 1;i --) {
		int now = a[i] + d;
		int tmp = (i - 1 - now) % n;
		d += tmp;
		if(tmp < 0) tmp += n;
		if(tmp) b[++ tot] = (ahha){1,i,tmp};
	}
	b[++ tot] = (ahha){2,n,n};
	printf("%d\n",tot);
	for(int i = 1;i <= tot;i ++) {
		printf("%d %d %d\n",b[i].opt,b[i].i,b[i].x);
	}
	return 0;
}


