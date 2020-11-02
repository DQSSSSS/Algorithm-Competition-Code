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

int f[35][1010],tmp[35][1010];

int main() {
    //f[0][0] = 1; tmp[0][0] = 1;
    //f[0][1] = 1; tmp[0][1] = 1;
    for(int k = 0;k <= 33;k ++) f[k][0] = 1;
    for(int k = 1;k <= 33;k ++) {
        for(int i = 0;i <= 1000;i ++) {
            for(int j = 0;j <= i;j ++)
	            (tmp[k][i] += 1ll * f[k - 1][j] * f[k - 1][i - j] % mod) %= mod;
        }
        for(int i = 1;i <= 1000;i ++) {
            for(int j = 0;j < i;j ++) {
                (f[k][i] += 1ll * tmp[k][j] * tmp[k][i - j - 1] % mod) %= mod;
            }
        }
    }
  /*  for(int i = 0;i <= 5;i ++,puts(""))
    	for(int j = 0;j <= 5;j ++)
    		cout << f[i][j] << " ";
   	puts("");
    for(int i = 0;i <= 5;i ++,puts(""))
    	for(int j = 0;j <= 5;j ++)
    		cout << tmp[i][j] << " ";*/
    int q = read();
    while(q --) {
    	int n = read(),m = read(),t = 0;
    	while(n && (n & 1)) {
			n >>= 1; t ++;
    	}
    	if(n == 0) t --;
    	printf("%d\n",f[t][m]);
    }
    return 0;
}
