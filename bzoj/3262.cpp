#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200010;
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

int bits[SZ],n,len;

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
	int x,y,z,ans,val;
}a[SZ],tmp[SZ];

bool cmp(haha a,haha b) { 
	if(a.x != b.x) return a.x < b.x; 
	if(a.y != b.y) return a.y < b.y; 
	return a.z < b.z;
}

void cdq(int l,int r) {
	if(l >= r) return ;
	int mid = l + r >> 1;
	cdq(l,mid); cdq(mid + 1,r);
	int pl = l,pr = mid + 1,p = l;
	while(pl <= mid || pr <= r) {
		if(pr > r || (pl <= mid && a[pl].y <= a[pr].y)) {
			Add(a[pl].z,a[pl].val); 
			tmp[p ++] = a[pl ++];
		}
		else {
			a[pr].ans += Ask(a[pr].z); 
			tmp[p ++] = a[pr ++];
		}
	}
	for(int i = l;i <= r;i ++) {
		if(i <= mid) Add(a[i].z,-a[i].val);
		a[i] = tmp[i];
	}
}

int tong[SZ];

int main() {
	n = read(),len = read() + 1;
	for(int i = 1;i <= n;i ++) {
		a[i].x = read(),a[i].y = read(),a[i].z = read();
	}
	sort(a + 1,a + 1 + n,cmp);
	int tot = 0;
	for(int i = 1,j;i <= n;i = j) {
		a[++ tot] = a[i];
		int t = 0;
		for(j = i;j <= n && a[i].x == a[j].x && a[i].y == a[j].y && a[i].z == a[j].z;j ++) {
			t ++;
		}
		a[tot].val = t;
	}
	swap(n,tot);
	cdq(1,n);
	for(int i = 1;i <= n;i ++) {
		int x = a[i].val;
		a[i].ans += x - 1;
		tong[a[i].ans] += x;
	}
	for(int i = 0;i < tot;i ++) printf("%d\n",tong[i]);
	return 0;
}
/**
5 3
1 1 1
1 1 1
1 2 1
1 1 2
1 1 2
*/
