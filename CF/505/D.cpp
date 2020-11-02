#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 810;
const int INF = 1e9 + 10;
const int mod = 998244353;
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
/// 0:L  1:R
int f[SZ][SZ][2],g[SZ][SZ],a[SZ];

int main() {
	int n = read();
	for(int i = 1;i <= n;i ++) a[i] = read();
    for(int i = 1;i <= n;i ++) {
    	for(int j = 1;j <= n;j ++)
    		if(__gcd(a[i],a[j]) > 1)
    			g[i][j] = 1;
    }

    for(int i = n;i >= 1;i --) {
    	for(int j = i;j <= n;j ++) {
            for(int k = i;k <= j;k ++) {
				bool bz = 0,by = 0;
                if(k == i || f[i][k - 1][1]) bz = 1;
                if(k == j || f[k + 1][j][0]) by = 1;
				if(bz && by) {
					if(i == 1 || g[k][i - 1]) f[i][j][0] = 1;
					if(j == n || g[k][j + 1]) f[i][j][1] = 1;
				}
			}
    	}
    }
    puts(f[1][n][0] ? "Yes" : "No");
    return 0;
}
