#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
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

int tmp[2333];

int main() {
	int T = read();
	while(T --) {
		int n = read();
		for(LL j = 1,t = 0;j <= 2e9;j <<= 1,t ++) tmp[t] = 0;
		for(int i = 1;i <= n;i ++) {
			int x = read();
			for(LL j = 1,t = 0;j <= 2e9;j <<= 1,t ++) {
				if(x < j && x >= (j >> 1)) {
					tmp[t] ++;
					//cout << j << " " << x << " " << (j >> 1) << endl;
					break;
				}
			}
		}
		int ans = 0;
		//for(LL j = 1,t = 0;j <= 2e9;j <<= 1,t ++) cout << tmp[t] << " "; puts("");
		for(LL j = 1,t = 0;j <= 2e9;j <<= 1,t ++)
			ans = max(ans,tmp[t]);
		printf("%d\n",ans);
	}
	return 0;
}
