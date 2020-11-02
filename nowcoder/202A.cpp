#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 500010;
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

int a[4100][66];
int c[4100][11][260];
int er[4100][11];
int ee[4100][66];

char str[4100];

int main() {
	int n = read(),m = read(),k = read();
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j <= m;j ++) scanf("%x",&a[i][j]);
		for(int j = 1,s = 0,p = 0;j <= m;j ++) {
			s ++;
			if(j == m || j % 8 == 0) {
				p ++;
				for(int k = 0;k < (1 << s);k ++) {
					int t = 0;
					for(int l = 0;l < s;l ++)
						if(k >> l & 1)
							t += a[i][j-l];
					c[i][p][k] = t;
					//cout << i << " " << p << " " << k << " " << t << endl;
				}
				s = 0;
			}
		}
	}
	for(int i = 1;i <= k;i ++) {
		scanf("%s",str + 1);
		for(int j = 1,s = 0,p = 0;j <= m;j ++) {
			ee[i][j] = str[j] - '0';
			s = s << 1 | (str[j] - '0');
			//cout << i << " " << j << " " << s << endl;
			if(j == m || j % 8 == 0)
				er[i][++ p] = s,s = 0;
		}
	}
	
	int p = m / 8 + (m % 8 != 0);
	
	int ans = 0;
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= k;j ++) {
			int tmp = 0;
			for(int l = 1;l <= p;l ++)
				tmp += c[i][l][er[j][l]];
			ans ^= tmp;
			//cout << tmp << " ";
		}
	/*puts("");
	int ans2 = 0;
	for(int i = 1;i <= n;i ++,puts(""))
		for(int j = 1;j <= k;j ++) {
			int tmp = 0;
			for(int l = 1;l <= m;l ++)
				tmp += a[i][l] * ee[j][l];
			ans2 ^= tmp;
			cout << tmp << " ";
		}*/
	cout << ans << endl;
	//cout << ans2 << endl;
	return 0;
}
