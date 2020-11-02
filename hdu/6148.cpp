#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
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

LL f[110][11][2];
///长为i 首位j j后面是不是递减

void init() {
    for(int i = 0;i <= 9;i ++) f[1][i][0] = 1;
    for(int i = 2;i <= 100;i ++)
        for(int j = 0;j <= 9;j ++)
            for(int k = 0;k <= 9;k ++) {
               	if(j < k) {
                    (f[i][j][0] += f[i - 1][k][0]) %= mod;
               	}
               	else if(j == k){
					(f[i][j][0] += f[i - 1][k][0]) %= mod;
					(f[i][j][1] += f[i - 1][k][1]) %= mod;
               	}
               	else {
                    (f[i][j][1] += f[i - 1][k][0] + f[i - 1][k][1]) %= mod;
               	}
            }
}

int num[110];

LL ask(char s[]) {
	int n = strlen(s);
	if(n == 1) { return s[0] - '0'; }
	for(int i = 0;i < n;i ++) num[n - i] = s[i] - '0';
    LL ans = 0;
    for(int i = 1;i < n;i ++)
    	for(int j = 1;j <= 9;j ++)
    		(ans += f[i][j][0] + f[i][j][1]) %= mod;
    for(int i = 1;i < num[n];i ++) (ans += f[n][i][0] + f[n][i][1]) %= mod;
    bool flag = 0; ///1表示递增
    int x = num[n];
   // cout << ans << endl;
    for(int i = n - 1;i >= 1;i --) {

    	if(flag && num[i + 1] > num[i])
    		break;

		if(i != 1) {
			for(int j = flag ? x : 0;j < num[i];j ++) {
				if(flag) (ans += f[i][j][0]) %= mod;  ///增
				else {
					if(j <= x) (ans += f[i][j][0] + f[i][j][1]) %= mod;
					else (ans += f[i][j][0]) %= mod;
				}
			}
		}
		else {
			for(int j = flag ? x : 0;j <= num[i];j ++) {
				if(flag) (ans += f[i][j][0]) %= mod;  ///增
				else {
					if(j <= x) (ans += f[i][j][0] + f[i][j][1]) %= mod;
					else (ans += f[i][j][0]) %= mod;
				}
			}
		}

		//cout << i << " " << ans << " " << x << " " << flag<< endl;


    	if(x < num[i]) { flag = 1,x = num[i]; }
        if(x > num[i]) { flag = 0,x = num[i]; }
    }
    return ans;
}

char s[110];

int main() {
	//freopen("in.in","r",stdin);
	//freopen("my.out","w",stdout);
	init();
    int T = read();
    while(T --) {
    	scanf("%s",s);
        printf("%lld\n",ask(s));
    }
    return 0;
}
