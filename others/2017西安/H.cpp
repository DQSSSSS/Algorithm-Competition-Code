#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e5 + 10;

LL a[SZ];

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
		tree[p].Min = a[l];	
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

LL ask(int p,int l,int r) {
	if(l <= tree[p].l && tree[p].r <= r) {
		return tree[p].Min;
	}
	pushdown(p);
	LL ans = 1e18;
	int mid = tree[p].l + tree[p].r >> 1;
	if(l <= mid) ans = min(ans,ask(p << 1,l,r));
	if(mid < r) ans = min(ans,ask(p << 1 | 1,l,r));
	return ans;
}

int n,k;

int main() {
	int T;
	scanf("%d",&T);
	while(T --) {
		scanf("%d%d",&n,&k);
		for(int i = 1;i <= n;i ++) scanf("%lld",&a[i]);
		build(1,1,n);
		LL ans = 0,d = 0;
		for(int i = 1;i <= n - k + 1;i ++) {
			int r = i + k - 1;
			LL d = ask(1,i,r);
			if(d > 0) ans += d,change(1,i,r,-d);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/**
3
3 2
1 2 1
6 3
1 5 3 4 7 6
9 4
2 7 1 3 6 5 8 9 4
*/
