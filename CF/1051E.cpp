#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,char> pii;
const int SZ = 2000010;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

void get_z(char s[],int z[]) {
	int n = strlen(s + 1);
	int l = 0,r = 0;
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
				int h = l + r - i + 1;
				while(i + h <= n && s[i + h] == s[1 + h]) h ++;
				z[i] = h;
			}
		}
		if(z[i] + i > l + r) l = i,r = z[i];
	}
	for(int i = 1;i <= n;i ++) cout << s[i] << " "; puts("");
	for(int i = 1;i <= n;i ++) cout << z[i] << " "; puts("");
}

int zl[SZ],zr[SZ];
LL f[SZ];

char a[SZ],l[SZ],r[SZ];

int main() {
	cout << (int)'$' << endl;
	scanf("%s%s%s",a + 1,l + 1,r + 1);
	int n = strlen(a + 1);
	int lenl = strlen(l + 1); l[lenl + 1] = '$';
	int lenr = strlen(r + 1); r[lenr + 1] = '$';
	for(int i = lenl + 2;i <= n + lenl + 1;i ++) l[i] = a[i - lenl - 1]; get_z(l,zl);
	for(int i = lenr + 2;i <= n + lenr + 1;i ++) r[i] = a[i - lenr - 1]; get_z(r,zr);
	
	int id = 1;
	
	if(a[1] == '0') {
		if(lenl == 1 && l[1] == '0') {
			while(id <= n && s[id] == '0') id ++;
			f[id - 1] = 1;
		}
		else { puts("0"); return ;}
	}
	
	f[0] = 1;
	int L = 0,R = 0;
	LL sum = 1;
	for(int i = 1;i <= n;i ++) {
		if(i < n && a[i + 1] == '0') continue;
		while(R < i - 1) {
			if(i - R > lenl) (sum += f[++ R]) %= mod;
			else if(i - R == lenl) {
				int lcp = zl[R + 2 + lenl];
				if(lcp >= i - R || l[lcp + 1] >= a[R + lcp]) (sum += f[++ R]) %= mod;
				else break;
			}
			else break;
		}
		cout << L << " " << R << endl;
		while(L < R) {
			int ll = i - L + (L != 0);
			if(ll > lenr) (sum -= f[L ++]) %= mod;
			else if(ll == lenr) {
				int lcp = zr[L + 1 + lenr + (L != '0')];
				cout << lcp << " " << ll << endl;
				cout << r[lcp + 1] << " " << a[L + lcp + (L == 0)] << endl;
				if(lcp < ll && r[lcp + 1] < a[L + lcp + (L == 0)]) (sum -= f[L ++]) %= mod;
				else break;
			}
			else break;
		}
		cout << i << " " << L << " " << R << " " << sum << endl;
		f[i] += sum;
	}
	int ans = (f[n] + mod) % mod,flag = 0;
	for(int i = id;i <= n;i ++) if(a[i] == '0') flag = 1;
	if(flag) ans ++;
	cout << ans << endl;
	return 0;
}	
