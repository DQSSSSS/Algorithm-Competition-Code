#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 500010;
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

int bits[510][510],n;

void Add(int x,int y,int d) {
	for(int i = x;i <= n;i += i & -i)
		for(int j = y;j <= n;j += j & -j)
			bits[i][j] += d;
}

int Ask(int x,int y) {
	int ans = 0;
	for(int i = x;i > 0;i -= i & -i)
		for(int j = y;j > 0;j -= j & -j)
			ans += bits[i][j];
	return ans;
}

int Ask(int x1,int y1,int x2,int y2) {
	int a = Ask(x2,y2);
	int b = Ask(x2,y1 - 1);
	int c = Ask(x1 - 1,y2);
	int d = Ask(x1 - 1,y1 - 1);
	return a-b-c+d;
}

struct haha {
	int type,x1,y1,x2,y2,k,id;
}a[SZ],tmpl[SZ],tmpr[SZ];

int Ans[SZ];

void solve(int vl,int vr,int l,int r) {
	if(vl > vr || l > r) return ;
	if(vl == vr) {
		for(int i = l;i <= r;i ++) 
			if(a[i].type == 2) Ans[a[i].id] = vl;
		return ;
	}
	int vm = vl + vr >> 1;
	int pl = 0,pr = 0;
	for(int i = l;i <= r;i ++) {
		if(a[i].type == 1) {
			if(a[i].k <= vm) Add(a[i].x1,a[i].y1,1),tmpl[++ pl] = a[i];
			else tmpr[++ pr] = a[i];
		}
		else {
			int x = Ask(a[i].x1,a[i].y1,a[i].x2,a[i].y2);
			if(a[i].k <= x) tmpl[++ pl] = a[i];
			else a[i].k -= x,tmpr[++ pr] = a[i];
		}
	}
	for(int i = 1;i <= pl;i ++) if(tmpl[i].type == 1) Add(tmpl[i].x1,tmpl[i].y1,-1);
	for(int i = 1;i <= pl;i ++) a[l + i - 1] = tmpl[i];
	for(int i = 1;i <= pr;i ++) a[l + pl + i - 1] = tmpr[i];
	solve(vl,vm,l,l+pl-1); solve(vm+1,vr,l+pl,r);
}

int main() {
	n = read();
	int q = read();
	int tot = 0;
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= n;j ++) {
			int x = read();
			a[++ tot] = (haha){1,i,j,0,0,x,0};
		}
	for(int i = 1;i <= q;i ++){
		int x1 = read(),y1 = read(),x2 = read(),y2 = read(),k = read();
		a[++ tot] = (haha){2,x1,y1,x2,y2,k,i};
	}
	solve(0,1e9+1,1,tot);
	for(int i = 1;i <= q;i ++) printf("%d\n",Ans[i]);
	return 0;
}
