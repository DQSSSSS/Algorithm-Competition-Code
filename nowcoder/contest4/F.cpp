#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int n,m;
char maps[2010][2010];
int a[2010][2010];
int sum[2010][2010];

int main() {
    int T = read();
    while(T --) {
    	scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i ++)
        	scanf("%s",maps[i] + 1);
       	for(int i = 1;i <= n;i ++)
    		for(int j = 1;j <= m;j ++)
                a[i][j] = (maps[i][j] == maps[n - i + 1][j]) & (maps[i][j] == maps[i][m - j + 1]) & (maps[i][j] == maps[n - i + 1][m - j + 1]);

		//for(int i = 1;i <= n;i ++,puts(""))
    	//	for(int j = 1;j <= m;j ++)
    	//		printf("%d ",a[i][j]);

		for(int i = 1;i <= n;i ++)
    		for(int j = 1;j <= m;j ++)
    			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];

		int ans = 0;
        for(int i = 2;i <= n / 2;i ++)
        	for(int j = 2;j <= m / 2;j ++) {
                int x = n - i + 1;
                int y = m - j + 1;
                int dx = x - i + 1;
                int dy = y - j + 1;
                if(sum[n][m] - (sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1]) == n * m - dx * dy)
                	ans ++;
        	}
        cout << ans << endl;
    }
    return 0;
}

/*
233
6 8
acbbbbca
dcaccacd
cdaddadc
cdaddadc
dcaccacd
acbbbbca
6 8
acbcbbca
dcaccacd
cdaddadc
cdaddadc
dcaccacd
acbbbbca
6 8
acbbbbca
dcadcacd
cdaddadc
cdaddadc
dcaccacd
acbbbbca

*/
