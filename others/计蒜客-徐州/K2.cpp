#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1e6 + 10;
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

struct matrix {
	int n,m;
    int num[66][66];
}f,ans,A0;

matrix operator *(const matrix &a,const matrix &b) {
	matrix ans;
	memset(ans.num,0,sizeof ans.num);
	ans.n = a.n; ans.m = b.m;
    for(int i = 1;i <= ans.n;i ++)
    	for(int j = 1;j <= ans.m;j ++) {
			int t = 0;
			for(int k = 1;k <= a.m;k ++)
				t += a.num[i][k] & b.num[k][j];
            ans.num[i][j] = t & 1;
		}
	return ans;
}

int N,M,m;

int id(int x,int y) {
    return (x - 1) * M + y;
}

void print(const matrix &a) {
	for(int i = 1;i <= a.n;i ++,puts(""))
        for(int j = 1;j <= a.m;j ++)
        	cout << (a.num[i][j]) << " ";
}

int B[11][11];

int main() {
	int T = read();
    while(T --) {
        N = read(),M = read(),m = M / 2;
        int t = read();
        for(int i = 1;i <= N;i ++)
        	for(int j = 1;j <= N;j ++)
                A0.num[id(i,j)][1] = read() & 1;
		for(int i = 1;i <= M;i ++)
        	for(int j = 1;j <= M;j ++)
        		B[i][j] = read() & 1;
        memset(f.num,0,sizeof f.num);
        f.n = f.m = A0.n = N * N;
        A0.m = 1;
		for(int i = 1;i <= N;i ++)
			for(int j = 1;j <= N;j ++)
				for(int p = i - m;p <= i + m;p ++)
					for(int q = j - m;q <= j + m;q ++) {
						if(p <= 0 || q <= 0 || p > N || q > N) continue;
						int x = p - i + m + 1,y = q - j + m + 1;
						if(x <= 0 || y <= 0 || x > M || y > M) continue;
                        f.num[id(i,j)][id(p,q)] = B[x][y];
						//printf("(%d,%d)*(%d,%d)\n",p,q,x,y);
					}
		memset(ans.num,0,sizeof ans.num);
		ans.n = ans.m = N * N;
        for(int i = 1;i <= ans.n;i ++) ans.num[i][i] = 1;
        while(t) {
        	if(t & 1) ans = ans * f;
        	f = f * f;
        	t >>= 1;
        }
        for(int i = 1;i <= ans.n;i ++,puts(""))
        	for(int j = 1;j <= ans.m;j ++)
        		cout << (ans.num[i][j]) << " ";
        print(A0);
        A0 = ans * A0;
        int ans = 0;
        for(int i = 1;i <= N * N;i ++) ans += A0.num[i][1];
        printf("%d\n",ans);
    }
    return 0;
}

