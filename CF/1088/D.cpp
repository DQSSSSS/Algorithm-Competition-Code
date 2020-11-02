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

/// 1 : a > b
/// 0 : a = b
///-1 : a < b

int main() {
	int a = 0,b = 0,f = 0;
	printf("? %d %d\n",0,0);fflush(stdout);
	int x; scanf("%d",&x);
	f = x;
	for(int i = 29;i >= 0;i --) {
		int d = 1 << i;
		if(f == 0) {
			printf("? %d %d\n",a | d,b);fflush(stdout);
			scanf("%d",&x);
			if(x == -1) a |= d,b |= d;
		}
		else if(f == 1) {
			printf("? %d %d\n",a | d,b);fflush(stdout);
			scanf("%d",&x);
			if(x == -1) {
				printf("? %d %d\n",a | d,b | d);fflush(stdout);
				scanf("%d",&x);
				if(x == 1) a |= d,b |= d;
				else if(x == 0) a |= d,b |= d,f = 0;
				else a |= d,f = -1;
			}
			else if(x == 0) {
				a |= d; f = 0;
			}
			else {
				printf("? %d %d\n",a,b | d);fflush(stdout);
				scanf("%d",&x);
				if(x != -1) a |= d,f = x;   
			}
		}
		else {
			printf("? %d %d\n",a,b | d);fflush(stdout);
			scanf("%d",&x);
			if(x == 1) {
				printf("? %d %d\n",a | d,b | d);fflush(stdout);
				scanf("%d",&x);
				if(x == -1) a |= d,b |= d;
				else if(x == 0) a |= d,b |= d,f = 0;
				else b |= d,f = 1;
			}
			else if(x == 0) {
				b |= d; f = 0;
			}
			else {
				printf("? %d %d\n",a | d,b);fflush(stdout);
				scanf("%d",&x);
				if(x != 1) b |= d,f = x;   
			}
		}
		//cout << i << " " << a << " " << b << " " << f << endl;
	}
	printf("! %d %d\n",a,b);fflush(stdout);
	return 0;
}



