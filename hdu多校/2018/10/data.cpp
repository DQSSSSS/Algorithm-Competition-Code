#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 100010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;

int randint() {
	return rand() << 16 | rand();
}

int randlr(int l,int r) {
	return randint() % (r - l + 1) + l;
}

int main() {
	freopen("hh.in","w",stdout);
	srand(time(0));
	int n = 1e5;
	cout << n << endl;
    for(int i = 2;i <= n;i ++)
    	cout << randlr(1,i-1)<< " ";
    puts("");
    for(int i = 1;i <= n;i ++)
    	cout << randlr(1,100) << " ";
}
