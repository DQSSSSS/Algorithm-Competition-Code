#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2100;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-12;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int f[233][233],a[233];

int main() {
	int T = read(),cc = 0;
	while(T --) {
		int n = read();
		for(int i = 1;i <= n;i ++) a[i] = read();
        for(int i = 1;i <= n;i ++) f[i][i] = 1;
        for(int i = 1;i <= n;i ++)
        	for(int j = i + 1;j <= n;j ++)
        		f[i][j] = 0;
        for(int i = n;i >= 1;i --) {
        	for(int j = i + 1;j <= n;j ++) {
                f[i][j] = f[i + 1][j] + 1;
                for(int k = i + 1;k <= j;k ++)
                    if(a[i] == a[k])
                    	f[i][j] = min(f[i][j],f[i][k - 1] + f[k + 1][j]);
        	}
        }
        printf("Case %d: %d\n",++ cc,f[1][n]);
	}
}
