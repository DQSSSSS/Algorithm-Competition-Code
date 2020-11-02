#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 100010;
const int INF = 1e9 + 10;
const int mod = 10007;
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

char s[SZ];

int main() {
	int n = read();
	scanf("%s",s);
	int x = 0;
	for(int i = 0;i < n;i ++) {
		if(s[i] == '8') x ++;
	}
	int y = n - x,ans = 0;
	while(x) {
		if(y < 10) {
			if(x >= 10 - y + 1) {
				x -= 10 - y + 1;
				y = 0;
				ans ++;
			}
			else break;
		}
		else {
			x --;y -= 10; ans ++;
		}
	}
	cout << ans << endl;
	return 0;
}

