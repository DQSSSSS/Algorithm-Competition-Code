#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 50010;
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

pii num[7][SZ];
int a[SZ][7];
int n,m,B;

bitset<SZ> BIT[6][233];

bitset<SZ> get(int k,int pos) {
	bitset<SZ> ans; ans.reset();
	if(pos / B - 1 >= 0) ans = BIT[k][pos / B - 1];
	for(int i = max(1,(pos / B - 1) * B + 1);i <= pos;i ++)
		ans.set(num[k][i].second);	
	return ans;
}

int main() {
	int T = read();
	while(T --) {
		n = read(),m = read(); B = sqrt(n);
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= 5;j ++) {	
				a[i][j] = read();
				num[j][i] = make_pair(a[i][j],i);
			}
		for(int i = 1;i <= 5;i ++)
			sort(num[i] + 1,num[i] + 1 + n);
		for(int j = 1;j <= 5;j ++) {
			bitset<SZ> w; w.reset();
			for(int i = 1;i <= n;i ++) {
				w.set(num[j][i].second);
				if(i == n || i / B != (i + 1) / B) BIT[j][i / B] = w;
			}
		}
		
		int q = read();
		int lstans = 0;
		while(q --) {
			bitset<SZ> ans; ans.set();
			for(int i = 1;i <= 5;i ++) {
				int x = read() ^ lstans;
				int id = upper_bound(num[i] + 1,num[i] + 1 + n,make_pair((LL)x,(LL)INF)) - num[i];
				id --;
				ans &= get(i,id);
			}
			printf("%d\n",lstans = ans.count());
		}
	}
	return 0;
}
