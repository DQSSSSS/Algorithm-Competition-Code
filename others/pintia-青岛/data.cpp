#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 100010;
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

int randint() {
	return rand() << 16 | rand();
}

int a[SZ];

int main() {
	freopen("7.in","w",stdout);
	srand(time(0));
	int T = 10;
	cout << T << endl;
	while(T --) {
		int n = 100000;
		cout << n << endl;
		for(int i = 1;i <= n;i ++) cout << randint() % n + 1 << " ",a[i] = i; puts("");
		for(int i = 2;i <= n;i ++) {
			swap(a[i],a[randint() % (i - 1) + 1]);
		}
		for(int i = 1;i <= n;i ++) cout << a[i] << " "; puts("");
	}
}
