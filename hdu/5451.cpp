#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 100010;
const int INF = 1e9 + 10;
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

LL ksm(LL a,LL b,LL mod) {
	LL ans = 1 % mod;
	while(b) {
		if(b & 1) ans = a * ans % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return ans;
}

int mod;

struct haha {
	int n,m;
	int num[3][3];
	haha(){ n = m = 0; memset(num,0,sizeof num); }
	void print() { for(int i = 1;i <= n;i ++,puts("")) for(int j = 1;j <= m;j ++) cout << num[i][j] << " "; }
};

bool operator <(const haha &f,const haha &now) {
	if(now.num[1][1] != f.num[1][1]) return now.num[1][1] < f.num[1][1];
	if(now.num[1][2] != f.num[1][2]) return now.num[1][2] < f.num[1][2];
	if(now.num[2][1] != f.num[2][1]) return now.num[2][1] < f.num[2][1];
	return now.num[2][2] < f.num[2][2];
}

map<haha,bool> mp;

haha operator *(const haha &a,const haha &b) {
	haha ans;
	ans.n = a.n; ans.m = b.m;
	for(int i = 1;i <= a.n;i ++) 
		for(int j = 1;j <= b.m;j ++)
			for(int k = 1;k <= a.m;k ++)
				(ans.num[i][j] += 1ll * a.num[i][k] * b.num[k][j] % mod) %= mod;
	return ans;
}

int a[SZ],b[SZ],pre[SZ];

int main() {
	int T = read(),cc = 0;
	while(T --) {
		mp.clear();
		LL n = read(); mod = read();
		a[1] = 5 % mod,b[1] = 2 % mod;
		int t = 0;
		for(int i = 2;;i ++) {
			a[i] = (5 * a[i - 1] + 12 * b[i - 1]) % mod;
			b[i] = (2 * a[i - 1] + 5 * b[i - 1]) % mod;
			//if(i >= 11580) cout << i << " " << b[i] << endl;
			if(a[i] == a[1] && b[i] == b[1]) {
				t = i - 1;
				break;
			}
		}
		n = ksm(2,n,t);
		int Ans = a[n + 1] * 2 - 1;
		Ans %= mod; Ans += mod; Ans %= mod;
		printf("Case #%d: %d\n",++ cc,Ans);
	}
	return 0;
}

