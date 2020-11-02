#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200010;
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

ULL hs[SZ],h[SZ],mi[SZ];

ULL get(ULL h[],int l,int r) {
	if(l > r) return 0;
	return h[r] - h[l - 1] * mi[r - l + 1];
}

int id[SZ],f[15][SZ];
char s[SZ],s2[SZ];

int main() {
	mi[0] = 1;
	for(int i = 1;i <= 1e5;i ++) mi[i] = mi[i - 1] * 2333;
	scanf("%s",s + 1);
	int len = strlen(s + 1); s[++ len] = '?';
	for(int i = 1;i <= len;i ++) hs[i] = hs[i - 1] * 2333 + s[i];
	for(int i = 1;i <= len;i ++) if(s[i] == '*' || s[i] == '?') id[++ id[0]] = i;
	int T = read();
	while(T --) {
		scanf("%s",s2 + 1);
		int n = strlen(s2 + 1); s2[++ n] = '#';
		for(int i = 1;i <= n;i ++) h[i] = h[i - 1] * 2333 + s2[i];
		for(int i = 1;i <= id[0];i ++) 
			for(int j = 1;j <= n;j ++) 
				f[i][j] = 0;
		f[0][0] = 1;
		for(int i = 1;i <= id[0];i ++) {
			int len,L,R = id[i] - 1;
			if(i == 1) len = id[i] - 1,L = 1;
			else len = id[i] - id[i - 1] - 1,L = id[i - 1] + 1;
			//cout << i << " " << len << " " << L << " " << R << endl;
			if(s[id[i]] == '?') {
				for(int j = 0;j + len + 1<= n;j ++) {
					if(!f[i - 1][j]) continue;
				//	cout << j + 1 <<" " << j + len << endl;
					if(get(h,j+1,j+len) == get(hs,L,R)) 
						f[i][j + len + 1] = 1;
				}
			}
			else {
				for(int j = 0;j + len + 1 <= n;j ++) {
					if(!f[i - 1][j]) continue;
					if(get(h,j+1,j+len) == get(hs,L,R)) {
						for(int k = j + len;k <= n;k ++)
							f[i][k] = 1;
						break;
					}
				}
			}
		}	
		/*for(int j = 0;j <= n;j ++) cout << s2[j] << " "; puts("");
		for(int i = 1;i <= id[0];i ++,puts(""))
			for(int j = 0;j <= n;j ++)
				cout << f[i][j] << " ";*/
		puts(f[id[0]][n] ? "YES" : "NO");
	}
	return 0;
}
