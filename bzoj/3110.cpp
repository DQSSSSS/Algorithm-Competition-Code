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

struct segment {
	int l,r;
	LL add,sum;
}tree[SZ << 2];

void update(int p) {
	tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
}

void pushc(int p,LL d) {
	tree[p].add += d;
	tree[p].sum += (tree[p].r - tree[p].l + 1) * d;
}

void pushdown(int p) {
	if(tree[p].add) {
		pushc(p << 1,tree[p].add);
		pushc(p << 1 | 1,tree[p].add);
		tree[p].add = 0;
	}
}

void build(int p,int l,int r) {
	tree[p].l = l;
	tree[p].r = r;
	if(l == r) {
		tree[p].sum = 0;
		return ;
	}
	int mid = l + r >> 1;
	build(p << 1,l,mid); build(p << 1 | 1,mid + 1,r);
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
		return tree[p].sum;
	}
	pushdown(p);
	int mid = tree[p].l + tree[p].r >> 1;
	LL ans = 0;
	if(l <= mid) ans += ask(p << 1,l,r);
	if(mid < r) ans += ask(p << 1 | 1,l,r);
	return ans;
}

struct haha {
	int type,l,r;
	LL k;
	int id;
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
			if(a[i].k <= vm) change(1,a[i].l,a[i].r,1),tmpl[++ pl] = a[i];
			else tmpr[++ pr] = a[i];
		}
		else {
			LL x = ask(1,a[i].l,a[i].r);
			if(a[i].k <= x) tmpl[++ pl] = a[i];
			else a[i].k -= x,tmpr[++ pr] = a[i];
		}
	}
	for(int i = 1;i <= pl;i ++) if(tmpl[i].type == 1) change(1,tmpl[i].l,tmpl[i].r,-1);
	for(int i = 1;i <= pl;i ++) a[l + i - 1] = tmpl[i];
	for(int i = 1;i <= pr;i ++) a[l + pl + i - 1] = tmpr[i];
	solve(vl,vm,l,l+pl-1); solve(vm+1,vr,l+pl,r);
}

int lsh[SZ];

int main() {
	int n = read(),m = read();
	int tot = 0;
	for(int i = 1;i <= m;i ++) {
		int opt = read(),x = read(),y = read();
		LL z = read();
		if(opt == 1) a[i] = (haha){1,x,y,z,i},lsh[++ lsh[0]] = z;
		else a[i] = (haha){2,x,y,z,++tot};
	}
	sort(lsh + 1,lsh + 1 + lsh[0]);
	lsh[0] = unique(lsh + 1,lsh + 1 + lsh[0]) - lsh - 1;
	for(int i = 1;i <= m;i ++) {
		if(a[i].type == 1) {
			a[i].k = lower_bound(lsh + 1,lsh + 1 + lsh[0],a[i].k) - lsh;
			a[i].k = lsh[0] - a[i].k + 1;
		}
	}
	build(1,1,n);
	solve(1,lsh[0],1,m);
	for(int i = 1;i <= tot;i ++) {
		int x = lsh[0] - Ans[i] + 1;
		printf("%d\n",lsh[x]);
	}
	return 0;
}
