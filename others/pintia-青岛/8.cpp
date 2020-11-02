#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
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

char s[SZ];
int n;

LL calc(int f) {
	int x = 0,lst = 0;
	LL ans = 0;
	for(int i = 1,now = f,t = 0;i <= n;i ++,now ^= 1) {
		int c = s[i] - '0';
		if(c == now) lst ++;
		else t ++,x += i,lst = 0;
		if(i % 2 == f) ans += x;
	}
	return ans;
}

int main() {
	int T = read();
	while(T --) {
		scanf("%s",s + 1);
		n = strlen(s + 1);
		LL ans = 0;
		for(int i = 1;i <= n;i ++) ans += 1ll * (i + 1) * i / 2;
		cout << ans << endl;
		for(int i = 1;i <= n;i ++) {
			if(s[i] == '1') ans += 1ll * (i - 1) / 2 * (n - i + 1);
			else ans += 1ll * (i + 1) / 2  * (n - i + 1);
			cout << ans << endl;
		}
//		ans += ji + ou;
		printf("%lld\n",ans);
	}
	return 0;
}
