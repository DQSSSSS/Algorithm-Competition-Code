#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 50010;
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

int main() {
	int a = read(),b = read(),c = read();
	int ans = 10000;
	for(int i = 0;i <= 100;i ++) {
		for(int j = 0;j <= 100;j ++) {
			for(int k = 0;k <= 100;k ++) {
				int d[3];
				d[0] = a + i;
				d[1] = b + j;
				d[2] = c + k;
				sort(d,d+3);
				if(d[0] + d[1] > d[2]) {
					ans = min(ans,i+j+k);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
