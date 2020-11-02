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

int bits[SZ],n;

void add(int x,int d) {
	for(int i = x;i <= n;i += i & -i)
		bits[i] += d;
}

int ask(int x) {
	int ans = 0;
	for(int i = x;i > 0;i -= i & -i)
		ans += bits[i];
	return ans;
}

LL ans;

const int LEFT = 0;
const int RIGHT = 1;

struct haha {
	int a,b,c,d,flag;
}a[SZ],b[SZ],tmp[SZ];

void cdq2(int l,int r) {
	if(l == r) return ;
	int mid = l + r >> 1;
	cdq2(l,mid); cdq2(mid + 1,r);
	int pl = l,pr = mid + 1,p = l;
	while(pl <= mid || pr <= r) {
		if(pr > r || (pl <= mid && b[pl].c <= b[pr].c)){
			if(b[pl].flag == LEFT) add(b[pl].d,1);
			tmp[p ++] = b[pl ++];
		}
		else {
			if(b[pr].flag == RIGHT) ans += ask(b[pr].d);
			tmp[p ++] = b[pr ++];			
		}
	}
	for(int i = l;i <= r;i ++) {
		if(i <= mid && b[i].flag == LEFT) add(b[i].d,-1);
		b[i] = tmp[i];
	}
	//for(int i = 1;i <= n;i ++) assert(!bits[i]);
}

void cdq1(int l,int r) {
	if(l == r) return ;
	int mid = l + r >> 1;
	cdq1(l,mid); cdq1(mid + 1,r);
	int pl = l,pr = mid + 1,p = l;
	while(pl <= mid || pr <= r) {
		if(pr > r || (pl <= mid && a[pl].b <= a[pr].b)){
			a[pl].flag = LEFT;
			b[p ++] = a[pl ++];
		}
		else {
			a[pr].flag = RIGHT;
			b[p ++] = a[pr ++];			
		}
	}
	for(int i = l;i <= r;i ++) a[i] = b[i];
	cdq2(l,r);
	//cout << l << " " << r << " " << ans << endl;
}

int main() {
	freopen( "partial_order.in", "r", stdin );
	freopen( "partial_order.out", "w", stdout );
	n = read();
	for(int i = 1;i <= n;i ++) a[i].a = i,a[i].b = read();
	for(int i = 1;i <= n;i ++) a[i].c = read();
	for(int i = 1;i <= n;i ++) a[i].d = read();
	cdq1(1,n);
	printf("%lld\n",ans);
	return 0;
}
/**
5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
*/
