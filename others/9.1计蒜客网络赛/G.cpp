#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1e5 + 10;
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

int a[SZ];

struct seg {
	int l,r;
    int minn;
}tree[SZ * 4];

void update(int p) {
    tree[p].minn = min(tree[p << 1].minn,tree[p << 1 | 1].minn);
}

void build(int p,int l,int r) {
	tree[p].l = l; tree[p].r = r;
	if(l == r) {
		tree[p].minn = a[l] == 0 ? INF : a[l];
		return ;
	}
	int mid = l + r >> 1;
	build(p << 1,l,mid); build(p << 1 | 1,mid + 1,r);
	update(p);
}

void work(int p,int &ans1,int &ans2) {
    if(tree[p].l == tree[p].r) {
    	ans1 -= tree[p].minn;
    	ans2 ++;
    	tree[p].minn = INF;
    	return ;
    }
    int x = tree[p << 1].minn;
    if(x <= ans1) work(p << 1,ans1,ans2);
    else work(p << 1 | 1,ans1,ans2);
    update(p);
}

int Ask(int p,int x) {
    if(tree[p].l == tree[p].r) {
    	return tree[p].minn == INF ? -1 : tree[p].minn;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    if(x <= mid) return Ask(p << 1,x);
    else return Ask(p << 1 | 1,x);
//    update(p);
}

struct haha {
	int x,ans1,ans2,id;
}ask[SZ];

bool cmp(haha a,haha b) { return a.x < b.x; }
bool cmp2(haha a,haha b) { return a.id < b.id; }

int main() {
	int n = read(),m = read();
   	for(int i = 1;i <= n;i ++) a[i] = read();
    build(1,1,n);
    int q = read();
    for(int i = 1;i <= q;i ++) ask[i].x = read(),ask[i].id = i;
    sort(ask + 1,ask + 1 + q,cmp);
    int ans1 = 0,ans2 = 0;
	for(int j = 1,i = 1;;j ++) {
		if(tree[1].minn < INF)
			ans1 += m;
		while(tree[1].minn <= ans1) {
	        work(1,ans1,ans2);
	    }
	   // for(int k = 1;k <= n;k ++) cout << Ask(1,k) << " "; puts("");
	   // cout << j << " " << ans1 << " " << ans2 << endl;
        while(i <= q && ask[i].x == j)
        	ask[i].ans1 = ans1,ask[i].ans2 = ans2,i ++;
		if(i > q) break;
	}
	sort(ask + 1,ask + 1 + q,cmp2);
    for(int i = 1;i <= q;i ++) {
    	printf("%d %d\n",ask[i].ans2,ask[i].ans1);
    }
	return 0;
}
