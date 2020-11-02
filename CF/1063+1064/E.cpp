#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2010;
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

int get() {
	char s[11];
	scanf("%s",s);
	if(s[0] == 'w') return 1;
	else return 0;
}

int main() {
	int n = read();
	if(n == 1) {
		puts("0 0"); fflush(stdout);
		puts("1 1 1 0"); fflush(stdout);
		return 0;
	}
	puts("0 0"); fflush(stdout);
	int c1 = get();
	printf("%d %d\n",1000000000,1000000000); fflush(stdout);
	int c2 = get();
	if(c1 != c2) {
		int lx = 0,ly = 0;
		int rx = 1000000000,ry = 1000000000;
		for(int i = 3;i <= n;i ++) {
			int mx = lx + rx >> 1;
			int my = ly + ry >> 1;
			printf("%d %d\n",mx,my); fflush(stdout);
			int mc = get();
			if(mc == c2) rx = mx,ry = my;
			else lx = mx,ly = my;
		}
		int mx = lx + rx >> 1;
		int my = ly + ry >> 1;
		printf("%d %d %d %d\n",mx,my,1000000000,0); fflush(stdout);
	}
	else {
		int lx = 0,rx = 1000000000;
		for(int i = 3;i <= n;i ++) {
			int mx = lx + rx >> 1;
			printf("%d %d\n",mx,0); fflush(stdout);
			int mc = get();
			if(mc != c2) rx = mx;
			else lx = mx;
		}
		int mx = lx + rx >> 1;
		printf("%d %d %d %d\n",mx,0,1000000000,1000000000-1); fflush(stdout);
	}
	return 0;
}
