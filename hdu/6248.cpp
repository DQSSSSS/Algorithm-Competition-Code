#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 300010;
const LL INF = 1e18;
const int mod = 998244353;
const LD eps = 1e-10;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

namespace dcx {
	int n,m,id[2010];
	double a[50][1100];
	void pivot(int l,int e) {
		swap(id[n + l],id[e]);
		double t = a[l][e]; a[l][e] = 1;
		for(int j = 0;j <= n;j ++) a[l][j] /= t;
		for(int i = 0;i <= m;i ++) {
			if(i != l && fabs(a[i][e]) > eps) {
				t = a[i][e]; a[i][e] = 0;
				for(int j = 0;j <= n;j ++)
					a[i][j] -= a[l][j] * t;
			}
		}
	}
	bool init() {
		while(233) {
			int e = 0,l = 0;
			for(int i = 1;i <= m;i ++)
				if(a[i][0] < -eps && !l)
					l = i;
			if(!l) break;
			for(int j = 1;j <= n;j ++)
				if(a[l][j] < -eps && !e)
					e = j;
			if(!e) {return false; }
			pivot(l,e);
		}
		return true;
	}
	
	bool simplex() {
		for(int i = 1;i <= n + m;i ++) id[i] = i;
		if(!init()) return false;
		while(233) {
			int l = 0,e = 0;
			double Min = 1e100;
			for(int j = 1;j <= n;j ++)
				if(a[0][j] > eps) { e = j; break; }
			if(!e) break;
			for(int i = 1;i <= m;i ++)
				if(a[i][e] > eps && a[i][0] / a[i][e] < Min)
					Min = a[i][0] / a[i][e],l = i;
			if(!l) { return false; }
			pivot(l,e);
		}
		return true;
	}
	void print() {
		cout << n << " " << m << endl;
		for(int i = 0;i <= m;i ++,puts("")) {
			for(int j = 1;j <= n;j ++)
				printf("%10.5f",a[i][j]);
			printf("%10.5f",a[i][0]);
		}
	}
}

int g[22][1110],a[SZ];
int S[1110];

int main() {
//	srand(time(0));
	//freopen("in.in","r",stdin);freopen("my.out","w",stdout);
	int T = read(),cc = 0;
	while(T --) {
		dcx :: n = dcx :: m = 0;
		memset(dcx::id,0,sizeof dcx::id);
		memset(dcx::a,0,sizeof dcx::a);
		memset(a,0,sizeof a);
		memset(S,0,sizeof S);
		memset(g,0,sizeof g);
		int n = read(),m = read();
		for(int i = 1;i <= n;i ++) a[i] = read();
		/*if(cc == 84) {
			cout << n << " " << m << endl;
			for(int i = 1;i <= n;i ++) cout << a[i] << " "; puts("");
		}*/
		for(int S = 1;S < (1 << n);S ++) {
			int sum = 0;
			for(int i = 0;i < n;i ++) 
				if(S >> i & 1)
					sum += a[i + 1];
			if(sum > m) continue;
			dcx::n ++;
			for(int i = 0;i < n;i ++) 
				if(S >> i & 1)
					g[i + 1][dcx::n] = 1,::S[dcx::n] ++;
		//	cout << dcx :: n << " " << S << " " << ::S[dcx::n] << endl;
		}
	/*	for(int i = 1;i <= n;i ++,puts(""))
			for(int j = 1;j <= dcx :: n;j ++)
				cout << g[i][j] << " ";*/
		for(int i = 1;i <= dcx::n;i ++) dcx::a[0][i] = 1.0 * S[i];
		for(int i = 1;i <= n;i ++) {
			dcx::m ++;
			dcx :: a[dcx::m][0] = 0;
			for(int j = 1;j <= dcx :: n;j ++) {
				dcx::a[dcx::m][j] = -1.0*S[j] / n;
				if(g[i][j]) dcx::a[dcx::m][j] += 1;
			}
			
			dcx::m ++;
			dcx :: a[dcx::m][0] = 0;
			for(int j = 1;j <= dcx :: n;j ++) {
				dcx::a[dcx::m][j] = -1.0*S[j] / n;
				if(g[i][j]) dcx::a[dcx::m][j] += 1;
				dcx::a[dcx::m][j] *= -1;
			}
		}
			dcx :: m ++;
			dcx :: a[dcx :: m][0] = 1;
			for(int j = 1;j <= dcx :: n;j ++) dcx :: a[dcx::m][j] = 1;
			dcx :: m ++;
			dcx :: a[dcx :: m][0] = -1;
			for(int j = 1;j <= dcx :: n;j ++) dcx :: a[dcx::m][j] = -1;
		
		//dcx::print();999
		/*if(dcx::simplex()) {
			//for(int i = 1;i <= dcx::m;i ++) ans[dcx::id[dcx::n + i]] = dcx::a[i][0];
			//for(int i = 1;i <= dcx::n;i ++) cout << ans[i] << " "; puts("");
		}
		else puts("fuck"),assert(0);*/
		bool flag = 0;
		if(!dcx::simplex()) flag = 1;
		double ans = max(0.0,-dcx::a[0][0] / n);
		if(flag) ans = 0;
		printf("Case #%d: %.6f\n",++ cc,ans);
	}
	return 0;
}
/**
Case #1: 0.16666667
Case #2: 0.14285714
Case #3: 0.33333333
Case #4: 0.25000000
Case #5: 0.50000000
Case #6: 0.22222222
Case #7: 1.00000000
Case #8: 0.16666667
Case #9: 0.33333333
Case #10: 0.21428571

*/
