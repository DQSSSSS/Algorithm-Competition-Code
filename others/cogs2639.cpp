#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 40010;
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
 
int a[8][SZ],f[8][SZ],B;
bitset<SZ> num[8][250];

bitset<SZ> get(int k,int pos) {
	bitset<SZ> ans; ans.reset();
	if(pos / B - 1 >= 0) ans = num[k][pos / B - 1];
	for(int i = max(1,(pos / B - 1) * B + 1);i <= pos;i ++)
		ans.set(a[k][i]);
	return ans;
}

int main() {
	freopen("partial_order_plus.in","r",stdin);
	freopen("partial_order_plus.out","w",stdout);
	int n = read(),k = read();
	B = sqrt(n);
	for(int i = 0;i <= k;i ++) {
		for(int j = 1;j <= n;j ++) {
			if(i == 0) { a[i][j] = f[i][j] = j; continue; }
			f[i][j] = read();
			a[i][f[i][j]] = j;
		}
	}
	
	for(int j = 0;j <= k;j ++) {
		bitset<SZ> tmp; tmp.reset();
		for(int i = 1;i <= n;i ++) {
			tmp.set(a[j][i]);
			if(i == n || i / B != (i + 1) / B) num[j][i / B] = tmp;
		}
	}
	
	LL ans = 0;
	
	for(int i = 1;i <= n;i ++) {
		bitset<SZ> w; w.set();
		for(int j = 0;j <= k;j ++) {
			w &= get(j,f[j][i] - 1);
		}
		ans += w.count();
	}
	cout << ans << endl;
	return 0;
}
