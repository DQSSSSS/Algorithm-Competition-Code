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

int mod;

struct haha {
	int n,m;
	int num[3][3];
	haha(){ n = m = 0; memset(num,0,sizeof num); }
	void print() { for(int i = 1;i <= n;i ++,puts("")) for(int j = 1;j <= m;j ++) cout << num[i][j] << " "; }
};

haha operator *(const haha &a,const haha &b) {
	haha ans;
	ans.n = a.n; ans.m = b.m;
	for(int i = 1;i <= a.n;i ++) 
		for(int j = 1;j <= b.m;j ++)
			for(int k = 1;k <= a.m;k ++)
				(ans.num[i][j] += 1ll * a.num[i][k] * b.num[k][j] % mod) %= mod;
	return ans;
}

int main() {
	int T = read();
	while(T --) {
		int A = read(),B = read();
		LL n = read() - 1;
		mod = read();
		haha ans,A0,f;
		f.n = f.m = 2;
		f.num[1][1] = A; f.num[1][2] = B;
		f.num[2][1] = 1; f.num[2][2] = A;
		ans.n = 2; ans.m = 2;
		for(int i = 1;i <= ans.n;i ++) ans.num[i][i] = 1;
		while(n) {
			if(n & 1) ans = ans * f;
			f = f * f;
			n >>= 1;
		}
		//ans.print();
		A0.n = 2; A0.m = 1;
		A0.num[1][1] = A;
		A0.num[2][1] = 1;
		ans = ans * A0;
		int Ans = ans.num[2][1];
		for(int i = 2;i * i <= B;i ++) {
			if(B % (i * i) == 0) {
				while(B % (i * i) == 0) B /= i * i,Ans = 1ll * Ans * i % mod;
			}
		}
		printf("%d %d %d\n",1,Ans,B);
	}
	return 0;
}
