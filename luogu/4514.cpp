#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 2050;
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

int n,m;

struct haha {
	LL tree[SZ][SZ];
	void add(int x,int y,LL d) {
		for(int i = x;i <= n;i += i & -i)
			for(int j = y;j <= m;j += j & -j)
				tree[i][j] += d;
	}
	LL ask(int x,int y) {
		LL ans = 0;
		for(int i = x;i > 0;i -= i & -i)
			for(int j = y;j > 0;j -= j & -j)
				ans += tree[i][j];
		return ans;
	}
}A[4];

LL ask(int x,int y) {
	LL ans0 = A[0].ask(x,y) * (x + 1) * (y + 1);
	LL ans1 = A[1].ask(x,y) * (y + 1);
	LL ans2 = A[2].ask(x,y) * (x + 1);
	LL ans3 = A[3].ask(x,y);
    return ans0 - ans1 - ans2 + ans3;
}

LL ask(int a,int b,int c,int d) {
	return ask(c,d) - ask(a - 1,d) - ask(c,b - 1) + ask(a - 1,b - 1);
}

int main() {
    scanf("%*");
    n = read(),m = read();
	char opt[2];
	while(~scanf("%s",opt)) {
		int a = read(),b = read(),c = read(),d = read();
		if(opt[0] == 'L') {
			LL v = read();
    		A[0].add(a,b,v); 		A[0].add(a,d + 1,-v); 			A[0].add(c + 1,b,-v); 			A[0].add(c + 1,d + 1,v);
    		A[1].add(a,b,v*a); 		A[1].add(a,d + 1,-v*a); 		A[1].add(c + 1,b,-v*(c+1)); 	A[1].add(c + 1,d + 1,v*(c+1));
    		A[2].add(a,b,v*b); 		A[2].add(a,d + 1,-v*(d+1)); 	A[2].add(c + 1,b,-v*b); 		A[2].add(c + 1,d + 1,v*(d+1));
    		A[3].add(a,b,v*a*b); 	A[3].add(a,d + 1,-v*a*(d+1)); 	A[3].add(c + 1,b,-v*b*(c+1)); 	A[3].add(c + 1,d + 1,v*(c+1)*(d+1));
		}
		else {
			printf("%lld\n",ask(a,b,c,d));
		}
	}
	return 0;
}
