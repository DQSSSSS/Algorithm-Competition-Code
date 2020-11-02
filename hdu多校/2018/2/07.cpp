#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const int INF = 1e9 + 10;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int b[SZ];

struct haha {
	int l,r;
    LL sum;
    int add,maxd;
}tree[SZ * 4];

void update(int p) {
	tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
	tree[p].maxd = max(tree[p << 1].maxd,tree[p << 1 | 1].maxd);
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
	tree[p].add = 0;
	if(l == r) {
        tree[p].sum = 0;
        tree[p].maxd = -b[l];
		return ;
	}
    int mid = l + r >> 1;
    build(p << 1,l,mid); build(p << 1 | 1,mid +1,r);
    update(p);
}

void spread(int p) {
    if(tree[p].add) {
        tree[p << 1].add += tree[p].add;
        tree[p << 1].maxd += tree[p].add;
        tree[p << 1 | 1].add += tree[p].add;
        tree[p << 1 | 1].maxd += tree[p].add;
		tree[p].add = 0;
    }
}

void change(int p,int l,int r,int d) {
    if(l <= tree[p].l && tree[p].r <= r) {
		tree[p].add += d;
		tree[p].maxd += d;
		if(tree[p].l == tree[p].r) {
			if(tree[p].maxd >= 0)
				tree[p].sum += tree[p].maxd / b[tree[p].l] + 1,
				tree[p].maxd = tree[p].maxd % b[tree[p].l] - b[tree[p].l];
			return ;
		}
		if(tree[p].maxd < 0)
			return ;
		else {
            spread(p);
            int mid = tree[p].l + tree[p].r >> 1;
			if(l <= mid && tree[p << 1].maxd >= 0) change(p << 1,l,r,0);
			if(mid < r && tree[p << 1 | 1].maxd >= 0)  change(p << 1 | 1,l,r,0);
            update(p);
            return ;
		}
    }
    spread(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p << 1,l,r,d);
    if(mid < r)  change(p << 1 | 1,l,r,d);
	update(p);
}

LL ask(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
		if(tree[p].l == tree[p].r) {
			if(tree[p].maxd >= 0)
				tree[p].sum += tree[p].maxd / b[tree[p].l] + 1,
				tree[p].maxd = tree[p].maxd % b[tree[p].l] - b[tree[p].l];
			return tree[p].sum;
		}
        if(tree[p].maxd < 0)
			return tree[p].sum;
    }
    spread(p);
	int mid = tree[p].l + tree[p].r >> 1;
	LL ans = 0;
    if(l <= mid) ans += ask(p << 1,l,r);
    if(mid < r) ans += ask(p << 1 | 1,l,r);
	return ans;
}

LL askMaxd(int p,int l) {
    if(tree[p].l == tree[p].r) {
		if(tree[p].maxd >= 0)
            tree[p].sum += tree[p].maxd / b[tree[p].l] + 1,
            tree[p].maxd = tree[p].maxd % b[tree[p].l] - b[tree[p].l];
		return tree[p].maxd;
    }
    spread(p);
	int mid = tree[p].l + tree[p].r >> 1;
	LL ans = -INF;
    if(l <= mid) ans = max(ans,askMaxd(p << 1,l));
    else ans = max(ans,askMaxd(p << 1 | 1,l));
	return ans;
}

int main() {
	int n,m;
	while(~scanf("%d%d",&n,&m)) {
		for(int i = 1;i <= n;i ++) b[i] = read();
		build(1,1,n);
        while(m --) {
            char s[6];
			scanf("%s",s);
			int l = read(),r = read();
            if(s[0] == 'q') {
				printf("%lld\n",ask(1,l,r));
            }
            else
				change(1,l,r,1);

			//for(int i = 1;i <= n;i ++)
			//	printf("%lld ",askMaxd(1,i)); puts("");
			/*for(int i = 1;i <= n;i ++) {
				change(1,i,i,0);
                printf("%lld ",ask(1,i,i));
			}
			puts("");*/
        }
	}
	return 0;
}
