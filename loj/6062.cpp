#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 4e5 + 10;
const int mod = 1811939329;

struct segment {
	int l,r;
	LL add,Min;
}tree[SZ << 2];

void update(int p) {
	tree[p].Min = min(tree[p << 1].Min,tree[p << 1 | 1].Min);
}

void pushc(int p,LL d) {
	tree[p].Min += d;
	tree[p].add += d;
}

void pushdown(int p) {
	if(tree[p].add) {
		LL d = tree[p].add;
		pushc(p << 1,d);
		pushc(p << 1 | 1,d);
		tree[p].add = 0;
	}
}

void build(int p,int l,int r) {
	tree[p].l = l;
	tree[p].r = r;
	tree[p].add = 0;
	if(l == r) {
		tree[p].Min = -l;	
		return ;
	}
	int mid = l + r >> 1;
	build(p << 1,l,mid); build(p << 1 | 1,mid + 1,r);
	update(p);
}

void change(int p,int l,int r,LL d) {
	if(l <= tree[p].l && tree[p].r <= r) {
		pushc(p,d); return ;
	}
	pushdown(p);
	int mid = tree[p].l + tree[p].r >> 1;
	if(l <= mid) change(p << 1,l,r,d);
	if(mid < r) change(p << 1 | 1,l,r,d);
	update(p);
}

LL Ask(int p,int l,int r) {
	if(l <= tree[p].l && tree[p].r <= r) {
		return tree[p].Min;
	}
	pushdown(p);
	LL ans = 1e18;
	int mid = tree[p].l + tree[p].r >> 1;
	if(l <= mid) ans = min(ans,Ask(p << 1,l,r));
	if(mid < r) ans = min(ans,Ask(p << 1 | 1,l,r));
	return ans;
}

int n,m,k;

int Ans[SZ],a[SZ],b[SZ];

int main() {
	int T = 1;
	while(T --) {
		scanf("%d%d%d",&n,&m,&k);
		for(int i = 1;i <= m;i ++) scanf("%d",&a[i]);
		for(int i = 1;i <= n;i ++) scanf("%d",&b[i]),b[i] = k - b[i];
		sort(a + 1,a + 1 + m);
		build(1,1,m);
		int ans = 0;
		for(int i = 1;i <= m;i ++) {
			int x = lower_bound(a + 1,a + 1 + m,b[i]) - a;
			if(x <= m) change(1,x,m,1);
		}
		for(int i = 1;i <= n - m + 1;i ++) {
			if(tree[1].Min >= 0) ans ++;
			int x = lower_bound(a + 1,a + 1 + m,b[i]) - a;
			if(x <= m) change(1,x,m,-1);
			x = lower_bound(a + 1,a + 1 + m,b[i + m]) - a;
			if(x <= m) change(1,x,m,1);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/**
1
3 4 5
1 1 1
4 4 4 3
2
1 3
2 4
*/
