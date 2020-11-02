#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UI;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 400010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 9;
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

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
    	if(b & 1) ans = a * ans % mod;
    	a = a * a % mod;
    	b >>= 1;
    }
    return ans;
}

int a[SZ];

struct haha {
	int l,r;
	pii Min,Max;
	bool rev;
}tree[SZ * 4];

void update(int p) {
	tree[p].Max = max(tree[p << 1].Max,tree[p << 1 | 1].Max);
	tree[p].Min = min(tree[p << 1].Min,tree[p << 1 | 1].Min);
	if(tree[p << 1].Min.first == tree[p << 1 | 1].Min.first)
		tree[p].Min.second = tree[p << 1 | 1].Min.second;
}

void build(int p,int l,int r) {
    tree[p].l = l; tree[p].r = r;
    if(l == r) {
        tree[p].Min = make_pair(a[l],1ll * l);
        tree[p].Max = make_pair(a[l],1ll * l);
    	return ;
    }
	int mid = l + r >> 1;
    build(p << 1,l,mid); build(p << 1 | 1,mid + 1,r);
	update(p);
}

void pushc(int p) {
    tree[p].rev ^= 1;
    swap(tree[p].Min,tree[p].Max);
    tree[p].Min.first = 1e5 - tree[p].Min.first;
    tree[p].Max.first = 1e5 - tree[p].Max.first;
}

void pushdown(int p) {
    if(tree[p].rev) {
    	pushc(p << 1);
    	pushc(p << 1 | 1);
    	tree[p].rev = 0;
    }
}

void change(int p,int x,LL d) {
    if(tree[p].l == tree[p].r) {
        tree[p].Min = make_pair(d,1ll * x);
        tree[p].Max = make_pair(d,1ll * x);
    	return ;
    }
	pushdown(p);
	int mid = tree[p].l + tree[p].r >> 1;
    if(x <= mid) change(p << 1,x,d);
    else change(p << 1 | 1,x,d);
    update(p);
}

pii ask(int p,int l,int r) {
	if(l <= tree[p].l && tree[p].r <= r) {
    	return tree[p].Max;
    }
	pushdown(p);
	pii ans = make_pair(0ll,0ll);
	int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) ans = max(ans,ask(p << 1,l,r));
    if(mid < r) ans = max(ans,ask(p << 1 | 1,l,r));
	return ans;
}

void rev(int p,int l,int r) {
	if(l <= tree[p].l && tree[p].r <= r) {
    	pushc(p);
    	return ;
    }
	pushdown(p);
	int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) rev(p << 1,l,r);
    if(mid < r) rev(p << 1 | 1,l,r);
	update(p);
}

LL x;
int getRandNum() {
	x = (100000005ll * x + 20150609) % 998244353;
	return x / 100;
}

int main() {
	int n = read(),m = read();
	x = read();
	for(int i = 1;i <= n;i ++) a[i] = getRandNum() % 100001;
	build(1,1,n);
    while(m --) {
        char opt[3];
        scanf("%s",opt);
        if(opt[0] == 'C') {
            int p = getRandNum() % n + 1,y = getRandNum() % 100001;
            change(1,p,y);
        }
        else if(opt[0] == 'R') {
        	int l = getRandNum() % n + 1,r = getRandNum() % n + 1;
        	if(l > r) swap(l,r);
        	rev(1,l,r);
        }
        else {
			int l = getRandNum() % n + 1,r = getRandNum() % n + 1;
        	if(l > r) swap(l,r);
            LL ans = 0,a = read(),b = read(),c = read();
            pii s = ask(1,l,r);
            while(233) {
                ans = max(ans,a * s.second + b * s.first + c * s.first * s.second);
                if(s.second < r) s = ask(1,s.second + 1,r);
            	else break;
            }
  			printf("%lld\n",ans);
        }
    }
    return 0;
}


