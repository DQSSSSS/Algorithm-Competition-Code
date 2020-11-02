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

const LL p1 = 691504013;
const LL p2 = 308495997;
LL np1,np2;

LL mi1[SZ],mi2[SZ];
int a[SZ];

struct haha {
	int l,r;
	LL sum;
    LL a1,a2;
}tree[SZ * 4];

void update(int p) {
	tree[p].sum = (tree[p << 1].sum + tree[p << 1 | 1].sum) % mod;
}

void build(int p,int l,int r) {
    tree[p].l = l; tree[p].r = r;
    if(l == r) {
        tree[p].sum = a[l];
    	return ;
    }
	int mid = l + r >> 1;
    build(p << 1,l,mid); build(p << 1 | 1,mid + 1,r);
	update(p);
}

void pushc(int p,LL a1,LL a2) {
    (tree[p].a1 += a1) %= mod;
    (tree[p].a2 += a2) %= mod;
    int len = tree[p].r - tree[p].l + 1;
    (tree[p].sum += a1 * (1 - mi1[len]) % mod * np1 % mod) %= mod;
    (tree[p].sum -= a2 * (1 - mi2[len]) % mod * np2 % mod) %= mod;
}

void pushdown(int p) {
    if(tree[p].a1 || tree[p].a2) {
    	pushc(p << 1,tree[p].a1,tree[p].a2);
    	int len = tree[p << 1].r - tree[p << 1].l + 1;
    	pushc(p << 1 | 1,tree[p].a1 * mi1[len] % mod,tree[p].a2 * mi2[len] % mod);
    	tree[p].a1 = 0; tree[p].a2 = 0;
    }
}

void change(int p,int l,int r,LL a1,LL a2) {
    if(l == tree[p].l && tree[p].r == r) {
        pushc(p,a1,a2);
    	return ;
    }
	pushdown(p);
	int mid = tree[p].l + tree[p].r >> 1;
    if(mid < l) change(p << 1 | 1,l,r,a1,a2);
    else if(r <= mid) change(p << 1,l,r,a1,a2);
    else {
        change(p << 1,l,mid,a1,a2);
        change(p << 1 | 1,mid + 1,r,a1 * mi1[mid - l + 1] % mod,a2 * mi2[mid - l + 1] % mod);
    }
    update(p);
}

LL ask(int p,int l,int r) {
	if(l <= tree[p].l && tree[p].r <= r) {
    	return tree[p].sum;
    }
	pushdown(p);
	LL ans = 0;
	int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) (ans += ask(p << 1,l,r)) %= mod;
    if(mid < r) (ans += ask(p << 1 | 1,l,r)) %= mod;
	return ans;
}


int main() {
	np1 = ksm(1 - p1 + mod,mod - 2);
	np2 = ksm(1 - p2 + mod,mod - 2);
	int n = read(),m = read();
	for(int i = 1;i <= n;i ++) a[i] = read();
	mi1[0] = mi2[0] = 1;
	for(int i = 1;i <= n;i ++) mi1[i] = mi1[i - 1] * p1 % mod;
	for(int i = 1;i <= n;i ++) mi2[i] = mi2[i - 1] * p2 % mod;
	build(1,1,n);
    while(m --) {
        int opt = read(),l = read(),r = read();
        if(opt == 1) {
			change(1,l,r,276601605ll * 691504013 % mod,276601605ll * 308495997 % mod);
        }
        else {
        	LL ans = ask(1,l,r);
        	ans += mod; ans %= mod;
			printf("%lld\n",ans);
        }
        //for(int i = 1;i <= n;i ++) cout << ask(1,i,i) << " "; puts("");
    }
    return 0;
}
/**
383008016

276601605*(691504013^n-308495997^n)
*/
