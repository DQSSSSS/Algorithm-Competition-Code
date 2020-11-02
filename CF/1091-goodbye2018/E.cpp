#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1100010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;
const LD PI = acos(-1);

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}


LL n,a[SZ],c[SZ];

bool cmp(int a,int b) { return a > b; }


int main() {
	n = read();
	LL b = 0;
	for(LL i = 1;i <= n;i ++) {
		c[i] = read();
		b += c[i];
	}
	n ++;
	for(int d = 2;d < 5;d += 2) {
		for(int j = 1;j < n;j ++) a[j] = c[j];
		a[n] = d;
		sort(a + 1,a + 1 + n,cmp);
		bool flag = 1;
		for(int i = 1;i <= n;i ++) {	
			int x = 0,y = 0;
			for(int j = i + 1;j <= n;j ++)
				y += min(a[j],1ll*i);
			for(int j = 1;j <= i;j ++)
				x += a[j]-i+1;
			if(x > y) flag = 0;
			cout << x << " " << y << endl;
		}
		if(flag) cout << d << endl;
	}
	/*for(int d = b % 2 == 0 ? 0 : 1;d <= n;d += 2) {
		if(check(d)) printf("%d ",d);
	}*/
	return 0;
}


