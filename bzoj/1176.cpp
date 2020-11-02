#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
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

int bits[SZ],n,m,len;

void Add(int x,int d) {
	for(int i = x;i <= len;i += i & -i)
		bits[i] += d;
}

int Ask(int x) {
	int ans = 0;
	for(int i = x;i > 0;i -= i & -i) ans += bits[i];
	return ans;
}

struct haha {
	int type,x,y,d,id;
}a[SZ],tmp[SZ];

int ans[SZ];

void cdq(int l,int r) {
	if(l >= r) return ;
	int mid = l + r >> 1;
	cdq(l,mid); cdq(mid + 1,r);
	//cout << l << " "<< r << endl;
	int pl = l,pr = mid + 1,p = l;
	while(pl <= mid || pr <= r) {
		if(pr > r || (pl <= mid && a[pl].x <= a[pr].x)) {
			if(a[pl].type == 0) {
				Add(a[pl].y,a[pl].d);
			}
			tmp[p ++] = a[pl ++];
		}
		else {
			if(a[pr].type) {
				ans[a[pr].id] += a[pr].type * Ask(a[pr].y);
			}
			tmp[p ++] = a[pr ++];
		}
	}	
	for(int i = l;i <= r;i ++) {
		if(i <= mid) if(a[i].type == 0) Add(a[i].y,-a[i].d);
		a[i] = tmp[i];
	}
}

int main() {
	n = read(),m = 0,len = 500000;
	int tot = 0;
	while(233) {
		int opt = read();
		if(opt == 3) break;
		if(opt == 1) {
			int x = read(),y = read(),d = read();
			a[++ m].type = 0; a[m].x = x; a[m].y = y; a[m].d = d;
		}
		else {
			int x1 = read(),y1 = read(),x2 = read(),y2 = read();
			int id = ++ tot;
			a[++ m].type = 1; a[m].x = x2; a[m].y = y2; a[m].id = id;
			a[++ m].type = 1; a[m].x = x1 - 1; a[m].y = y1 - 1; a[m].id = id;
			a[++ m].type = -1; a[m].x = x1 - 1; a[m].y = y2; a[m].id = id;
			a[++ m].type = -1; a[m].x = x2; a[m].y = y1 - 1; a[m].id = id;
		}
	}
	cdq(1,m);
	for(int i = 1;i <= tot;i ++) printf("%d\n",ans[i]);
	return 0;
}


