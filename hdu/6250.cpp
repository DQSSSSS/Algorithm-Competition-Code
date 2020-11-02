#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 110;
const int INF = 1e9 + 10;
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

void gauss(double g[][SZ],int n,double ans[SZ]) {
	int now = 1;
	for(int i = 1;i < n;i ++) {
		int to;
		for(to = now;to < n;to ++)
			if(fabs(g[to][i]) > eps) break;
		if(to >= n) break;
		if(to != now) 
			for(int j = 1;j <= n;j ++)
				swap(g[to][j],g[now][j]);
		double t = g[now][i];
		for(int j = 1;j <= n;j ++) g[now][j] /= t;
		
		for(int j = 1;j < n;j ++) 
			if(j != now) {
				double num = g[j][i];
				for(int k = 1;k <= n;k ++)
					g[j][k] -= num * g[now][k];
			}
		now ++;
	}
	for(int i = 1;i < n;i ++) ans[i] = g[i][n];
}
	
double now[SZ],a[SZ][SZ],g[SZ][SZ],A[SZ];

bool check(int n) {
	for(int i = 1;i <= n + 1;i ++)
		for(int j = i + 1;j <= n + 1;j ++) {
			double t = 0;
			for(int k = 1;k <= n;k ++) {
				double d = a[i][k] - a[j][k];
				t += d * d;
			}
			if(fabs(t - 1) > eps) return false;
		}
	return true;
}

int main() {
	int T = read(),cc = 0;
	while(T --) {
		memset(a,0,sizeof a);
		memset(g,0,sizeof g);
		int n = read(),m = read(),mm = m;
		for(int i = 1;i <= m;i ++)
			for(int j = 1;j <= n;j ++)
				scanf("%lf",&a[i][j]);
		if(m == 0) {
			m ++;
			a[1][1] = 1;
			for(int j = 2;j <= n;j ++) a[1][j] = 0;
		}
		for(int i = m + 1;i <= n + 1;i ++) {
			for(int k = 1;k <= n + 1;k ++) now[k] = 0;
			for(int j = 1;j < i;j ++)
				for(int k = 1;k <= n;k ++)
					now[k] += a[j][k];
			for(int k = 1;k <= n;k ++)
				now[k] /= (i - 1);
			memset(g,0,sizeof g);
			for(int j = 1;j < i;j ++)
				for(int k = 1;k <= n;k ++)
					g[j][k] = a[j][k] - now[k];
			for(int j = 1;j <= n + 2;j ++)
				g[i][j] = 1;
			
			/*for(int j = 1;j <= n + 2;j ++,puts(""))
				for(int k = 1;k <= n + 2;k ++)
					cout << g[j][k] << " ";*/
			double len1 = 0;
			for(int j = 1;j <= n;j ++) len1 += g[i - 1][j] * g[i - 1][j];
			len1 = sqrt(1 - len1);
			gauss(g,n + 2,A);
			
			/*for(int j = 1;j <= n + 2;j ++,puts(""))
				for(int k = 1;k <= n + 2;k ++)
					cout << g[j][k] << " ";*/
			
			double len2 = 0;
			for(int j = 1;j <= n;j ++) len2 += A[j] * A[j];
			len2 = sqrt(len2);
			for(int j = 1;j <= n;j ++) A[j] = A[j] / len2 * len1;
			for(int j = 1;j <= n;j ++) a[i][j] = A[j] + now[j];
		}
		//if(!check(n)) puts("fuck");
		printf("Case #%d: %d\n",++ cc,n + 1 - mm);
		for(int i = mm + 1;i <= n + 1;i ++) {
			for(int j = 1;j <= n;j ++) {
				printf("%.10f%c",a[i][j],j == n ? '\n' : ' ');
			}
		}
	}
	return 0;
}
/**
233
2 2
1.0000000000 0.0000000000
2.0000000000 0.0000000000
*/
