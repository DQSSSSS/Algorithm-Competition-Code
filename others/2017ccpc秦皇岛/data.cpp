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

int randint() {
	return (rand() << 16 | rand());
}

int randlr(int l,int r) {
	return randint() % (r - l + 1) + l;
}

int main() {
	freopen("H.in","w",stdout);
	srand(time(0));
	int T = 10;
	cout << T << endl;
	while(T --) {
		int n = randlr(1,3000),k = rand() % (n);
		cout << n << " " << k << endl;
		for(int i = 1;i <= n;i ++) {
			int x = randlr(1,1000000);
			printf("%d ",x);
		}
		puts("");
	}
	return 0;
}
