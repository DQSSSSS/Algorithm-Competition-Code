#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
const LL INF = 1e18;
const int mod = 998244353;
const LD eps = 1e-7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int L[SZ],R[SZ],a[SZ],stL[SZ][22],stR[SZ][22];
int S[SZ];

int main() {
	int n = read(),m = read(),q = read();
	for(int i = 1;i <= n;i ++) {
		a[i] = read();
		if(a[i] % 2 == 0) L[i] = i,R[i] = n + 1;
		else L[i] = 0,R[i] = i;
	}
	int top = 0;
	for(int i = 1;i <= n;i ++) {
		if(a[i] % 2 == 0) {
			S[++ top] = i;
		}
		else {
			if(top && a[S[top]] / 2 == a[i] / 2)
				L[i] = S[top],R[S[top]] = i,top --;
			else S[++ top] = i;
		}
	}

	/*for(int i = 1;i <= n;i ++) cout << a[i] / 2 << " "; puts("");
	for(int i = 1;i <= n;i ++) cout << L[i] << " "; puts("");
	for(int i = 1;i <= n;i ++) cout << R[i] << " "; puts("");*/
	for(int i = 1;i <= n;i ++) stL[i][0] = L[i];
	for(int i = 1;i <= n;i ++) stR[i][0] = R[i];
	
	for(int j = 1;j <= log2(n);j ++)
		for(int i = 1;i <= n;i ++)
			stL[i][j] = min(stL[i][j - 1],stL[i + (1 << (j - 1))][j - 1]),
			stR[i][j] = max(stR[i][j - 1],stR[i + (1 << (j - 1))][j - 1]);
		
	while(q --) {
		int l = read(),r = read();
		int k = log2(r - l + 1);
		int x1 = min(stL[l][k],stL[r - (1 << k) + 1][k]);
		int x2 = max(stR[l][k],stR[r - (1 << k) + 1][k]);
		//cout << x1 << " " << x2 << endl;
		if((r - l + 1) % 2 == 0 && l == x1 && x2 == r)
			puts("Yes");
		else 
			puts("No");
	}
	return 0;
}
/**
0 1 2 3 
*/
