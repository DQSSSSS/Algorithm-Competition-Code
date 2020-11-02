#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;

LL read()
{
    LL n = 0;
    char a = getchar();
    int flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int f[SZ],p;

LL ksm(LL a,LL b) {
	LL ans = 1;
	while(b) {
		if(b & 1) ans = a * ans % p;
		a = a *a % p;
		b >>= 1;
	}
	return ans;
}

struct matrix {
	int n,m;
	int num[3][3];
}F,A0;

matrix operator *(matrix a,matrix b) {
	matrix ans;
	ans.n = a.n; ans.m = b.m;
	memset(ans.num,0,sizeof(ans.num));
	for(int i = 1;i <= a.n;i ++)
		for(int j = 1;j <= b.m;j ++)
			for(int k = 1;k <= a.m;k ++)
				(ans.num[i][j] += 1ll * a.num[i][k] * b.num[k][j] % p) %= p;
	return ans;
}

int get_fib(int x) {
	if(x == 0) return 0;
	if(x == 1) return 1;
	if(x == 2) return 1;
	x -= 2;
	A0.n = 2; A0.m = 1;
	A0.num[1][1] = 1;
	A0.num[2][1] = 0;
	F.n = F.m = 2;
	F.num[1][1] = 1; F.num[1][2] = 1;
	F.num[2][1] = 1; F.num[2][2] = 0;
	matrix ans = F;
	while(x) {
		if(x & 1) ans = ans * F;
		F = F * F;
		x >>= 1;
	}
	ans = ans * A0;
	cout << x << " " << ans.num[1][1] << endl;
	return ans.num[1][1];
}
	
int main() {
	int T = read();
	while(T --) {
		int x0 = read();
		p = read();
		f[0] = 0; f[1] = 1;
		for(int i = 2;i <= p;i ++) f[i] = (f[i - 1] + f[i - 2]) % p;
		
		//for(int i = 0;i <= 10;i ++) cout << get_fib(i) << " "; puts("");
		
		int ans = -1,lst = x0;
		for(int n = 1;n <= p;n ++) {
			int now;
			if(n == 1) now = get_fib(x0);
			else now = f[lst];
			cout << n << " " << now << endl;
			if(now == x0 % p) { ans = n; break; }
			lst = now;
		}
		printf("%d\n",ans);
	}
	return 0;
}
