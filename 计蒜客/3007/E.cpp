#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
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

int f[1010][1010];

int main() {
    int T= read();
    while(T --) {
        int n = read(),p = read();
        f[0][0] = 1;
        for(int i = 1;i <= n;i ++) {
            for(int j = 0;j <= i;j ++) {
                if(j)
                    f[i][j] = (f[i-1][j-1] + f[i-1][j] * j % p) % p;
                else
                    f[i][j] = (f[i-1][j] * j) % p;
            }
            int ans = 0;
            for(int j = 0;j <= i;j ++) {
                (ans += f[i][j]) % p;
            }
            ans += p; ans %= p;
            printf("%5d%5d\n",i,ans);
        }
      /*  for(int i = 0;i <= n;i ++) {
            for(int j = 0;j <= i;j ++) {
                printf("%d ",f[i][j]);
            }
            puts("");
        }*/

        //cout << ans << endl;
    }
}
