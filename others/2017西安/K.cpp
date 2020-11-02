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

int n,m,k,B;

int bits[SZ];

void Add(int x,int d) {
	for(int i = x;i > 0;i ++)
}


struct haha {
	int l,r,id;
}ask[SZ];

bool cmp(haha a,haha b) { return (a.l / B == b.l / B) ? a.r < b.r : a.l < b.l; } 

int Ans[SZ],a[SZ],b[SZ];

int main() {
	int T;
	scanf("%d",&T);
	while(T --) {
		scanf("%d%d%d",&n,&m,&k); B = sqrt(n) + 1;
		for(int i = 1;i <= n;i ++) scanf("%d",&a[i]);
		for(int i = 1;i <= m;i ++) scanf("%d",&b[i]),b[i] = k - b[i];
		sort(a + 1,a + 1 + n);
		build(1,1,n);
		int q;
		scanf("%d",&q);
		for(int i = 1;i <= q;i ++) scanf("%d%d",&ask[i].l,&ask[i].r),ask[i].id = i;
		sort(ask + 1,ask + 1 + q,cmp);
		for(int i = 1,l = 1,r = 0;i <= q;i ++) {
			int L = ask[i].l,R = ask[i].r;
			//cout << L << " " << R << endl;
			while(l < L) {
				int pos = lower_bound(a + 1,a + 1 + n,b[l]) - a;
				if(pos > n) {l ++; continue;}
				Add(pos,-1);
				l ++;
			}
			while(l > L) {
				int pos = lower_bound(a + 1,a + 1 + n,b[l - 1]) - a;
				if(pos > n) {l --; continue; }
				Add(pos,1);
				l --;
			}
			while(r < R) {
				int pos = lower_bound(a + 1,a + 1 + n,b[r + 1]) - a;
				if(pos > n) {r ++; continue;}
				Add(pos,1);
				r ++;
			}
			while(r > R) {
				int pos = lower_bound(a + 1,a + 1 + n,b[r]) - a;
				if(pos > n) {r --; continue;}
				Add(pos,-1);
				r --;
			}
			//cout << tree[1].Min << endl;
			//for(int j = 1;j <= n;j ++) cout << Ask(1,j,j) << " "; puts("");
			Ans[ask[i].id] = bits[1] >= 0;
		}
		for(int i = 1;i <= q;i ++) printf("%d\n",Ans[i]);
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
