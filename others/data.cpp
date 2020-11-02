#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
const int INF = 1e9 + 10;
const int mod = 10007;
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

int randlr(int l,int r) {
	int x = rand() << 16 | rand();
	return x % (r - l + 1) + l;
}

int main() {
	srand(time(0));
	freopen("1629.in","w",stdout);
	//while(233) {
		int T = 10;
		cout << T << endl;
		while(T --) {
			int n = 1000,m = 1000,q = 1000;
			printf("%d %d %d\n",n,m,q);
			for(int i = 1;i <= m;i ++) {
				int x = randlr(1,n);
				int y = randlr(1,n);
				printf("%d %d\n",x,y);
			}
			
			for(int i = 1;i <= q;i ++) {
				int x = randlr(1,n);
				int y = randlr(1,n);
				if(x > y) swap(x,y);
				printf("%d %d\n",x,y);
			}
		}
	//	system("hiho1629.exe");
	//}
	return 0;
}
