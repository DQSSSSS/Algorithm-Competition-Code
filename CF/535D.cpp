#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
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

LL ksm(LL a,LL b) {
	LL ans = 1;
	while(b) {
		if(b & 1) ans = a * ans % mod;
		a = a *a % mod;
		b >>= 1;
	}
	return ans;
}

char s[SZ];

int z[SZ],n;

void get_z(char s[]) {
	n = strlen(s + 1);
	int l = 1,r = 0;
	for(int i = 2;i <= n;i ++) {
		if(i >= l + r) {
			int h = 0;
			while(i + h <= n && s[i + h] == s[1 + h]) h ++;
			z[i] = h;
		}
		else {
			int k = i - l + 1;
			if(i + z[k] < l + r) z[i] = z[k];
			else {
				int h = r - i + 1;
				while(i + h <= n && s[i + h] == s[1 + h]) h ++;
				z[i] = h;
			}
		}	
		if(i + z[i] > l + r) l = i,r = z[i];
	}
}

int a[SZ];

int main() {
	int m = read(),k = read();
	scanf("%s",s + 1); n = strlen(s + 1);
	get_z(s);
	LL len = 1ll * k * n;
	//for(int i = 1;i <= n;i ++) cout << z[i] << " "; puts("");
	for(int i = 1;i <= k;i ++) {
		a[i] = read();
		if(i > 1) {
			int d = a[i] - a[i - 1] + 1;
			if(d <= n) {
				if(z[d] < n - d + 1) { puts("0"); return 0; }
				len -= n - d + 1;
			}
		}
	}
	//cout << len << endl;
	cout << ksm(26,m-len) << endl;
	return 0;
}
