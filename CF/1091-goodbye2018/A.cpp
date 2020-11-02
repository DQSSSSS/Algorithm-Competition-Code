#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1100010;
const int INF = 1e9 + 10;
const int mod = 7340033;
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


int main() {
	int y = read(),b = read(),r = read(),ans = 0;
	for(int i = 0;i <= y;i ++)
		for(int j = 0;j <= b;j ++)
			for(int k = 0;k <= r;k ++)
				if(j == i + 1 && k == j + 1)
					ans = 3 * j;
	cout << ans << endl;
	return 0;
}
