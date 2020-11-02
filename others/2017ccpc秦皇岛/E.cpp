#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 300010;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

int f[SZ][4][4],ch[5][5];
char s[SZ];

int getnxt(char c) {
	return c == 'C' ? 0 : 1;
}

int main(){
	int T = read();
	ch[0][0] = 1; ch[1][0] = 2; ch[2][0] = 2; ch[3][0] = 1;
	ch[0][1] = 0; ch[1][1] = 0; ch[2][1] = 3; ch[3][1] = 0;
	while(T --) {
		int n = read();
		scanf("%s",s + 1);
		for(int i = 0;i <= n;i ++)
			for(int j = 0;j < 4;j ++)
				for(int k = 0;k < 4;k ++)
					f[i][j][k] = -INF;
		for(int i = 0,s = 0;i < 4;i ++,s += i - 1) {
			f[0][i][i] = -s;
			//cout << i << " " << -s << endl;
		}
		for(int i = 1;i <= n;i ++) {
			int nx = getnxt(s[i]);
			for(int j = 0;j < 4;j ++)
				for(int k = 0;k < 4;k ++) {
					int d = 0;
					if(j == 3 && nx == 0) d = 1;
					f[i][ch[j][nx]][k] = max(f[i][ch[j][nx]][k],f[i - 1][j][k] + d);
				}
			for(int j = 0;j < 4;j ++)
				for(int k = 1;k < 4;k ++)
					for(int c = 0;c <= 1;c ++) {
						int d = 0;
						if(j == 3 && c == 0) d = 1;
						f[i][ch[j][c]][k] = max(f[i][ch[j][c]][k],f[i][j][k - 1] - (k - 1) + d);
					}
		}
		int ans = 0;
		for(int j = 0;j < 4;j ++)
			for(int k = 0;k < 4;k ++)
				ans = max(ans,f[n][j][k]);
		printf("%d\n",ans);
	}
	return 0;
}	
