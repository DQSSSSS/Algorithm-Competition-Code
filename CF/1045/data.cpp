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

int randint() {
	return rand() << 16 | rand();
}

int randlr(int l,int r) {
	return randint() % (r - l + 1) + l;
}
	
int main() {
	freopen("G.in","w",stdout);
	srand(time(0));
	int n = 1e5,k = 20;
	cout << n << " " << k << endl;
	for(int i = 1;i <= n;i ++) 
		cout << randlr(0,1e9) << " " << randlr(1e9,1e9) << " " << randlr(0,1e9) << endl;
	return 0;
}
