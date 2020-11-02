#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
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
    ULL num[66];
}f,ans,A0;

matrix operator *(const matrix &a,const matrix &b) {
	matrix ans;
	memset(ans.num,0,sizeof ans.num);
	ans.n = a.n; ans.m = b.m;
    for(ULL i = 0;i < 64;i ++)
        for(ULL j = 0;j < 64;j ++)
        	if(a.num[i] >> j & 1)
        		ans.num[i] ^= b.num[j];
	return ans;
}

void print(const matrix &a) {
	for(int i = 0;i < a.n;i ++,puts(""))
        for(int j = 0;j < a.m;j ++)
        	cout << (a.num[i] >> j & 1) << " ";
}

int N,M,m;

ULL id(int x,int y) {
    return (x - 1) * N + y - 1;
}

ULL B[11][11];

int main() {
	int T = read();
    while(T --) {
        N = read(),M = read(),m = M / 2;
        int t = read();
        for(int i = 1;i <= N;i ++)
        	for(int j = 1;j <= N;j ++)
                A0.num[id(i,j)] = read() & 1;
		for(int i = 1;i <= M;i ++)
        	for(int j = 1;j <= M;j ++)
        		B[i][j] = read() & 1;
        memset(f.num,0,sizeof f.num);
        f.n = f.m = A0.n = N * N;
        A0.m = 1;
		for(int i = 1;i <= N;i ++)
			for(int j = 1;j <= N;j ++)
				for(int p = max(1,i - m);p <= min(N,i + m);p ++)
					for(int q = max(1,j - m);q <= min(N,j + m);q ++) {
						int x = p - i + m + 1,y = q - j + m + 1;
	                    f.num[id(i,j)] |= (ULL)B[x][y] << (ULL)id(p,q);
						//printf("(%d,%d)*(%d,%d)\n",p,q,x,y);
					}
		/*for(int i = 1;i <= N;i ++,puts(""))
			for(int j = 1;j <= N;j ++)
				cout << id(i,j) << " ";
        print(f);*/
		memset(ans.num,0,sizeof ans.num);
		ans.n = ans.m = N * N;
        for(ULL i = 0;i < ans.n;i ++) ans.num[i] = 1llu << i;
        while(t) {
        	if(t & 1) ans = ans * f;
        	f = f * f;
        	t >>= 1;
        }
        //print(ans);
        //print(A0);
        A0 = ans * A0;
        int ans = 0;
        for(int i = 0;i < N * N;i ++) ans += A0.num[i];
        printf("%d\n",ans);
    }
    return 0;
}
/**
233
8 8 1000000000
1 0 1 1 0 1 1 0
1 0 1 1 0 1 1 0
1 0 1 1 0 1 1 0
1 0 1 1 0 1 1 0
1 0 1 1 0 1 1 0
1 0 1 1 0 1 1 0
1 0 1 1 0 1 1 0
1 0 1 1 0 1 1 0
1 0 1 1 0 1 1 0
1 0 1 1 0 1 1 0
1 0 1 1 0 1 1 0
1 0 1 1 0 1 1 0
1 0 1 1 0 1 1 0
1 0 1 1 0 1 1 0
1 0 1 1 0 1 1 0
1 0 1 1 0 1 1 0

24


2
3 3 10000
1 0 1
0 1 0
1 1 1
1 1 1
1 1 1
1 1 1

1 0 0 1 1 0 0 0 0
0 1 0 1 1 1 0 0 0
0 0 1 0 1 1 0 0 0
0 0 0 1 0 0 1 1 0
0 0 0 0 1 0 1 1 1
0 0 0 0 0 1 0 1 1
0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 1
*/
