#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

int mask,n,m,q,a[SZ];

struct seg {
    int l,r;
    int ys[35],ys2[35],c;
}tree[SZ * 4];

void update(int p) {
    for(int i = 0;i <= mask;i ++) {
        tree[p].ys[i] = tree[p << 1].ys[tree[p << 1 | 1].ys[i]];
        tree[p].ys2[i] = tree[p << 1].ys2[tree[p << 1 | 1].ys2[i]];
    }
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) {
        int x = a[l];
        for(int i = 0;i <= mask;i ++) {
            if(x == 0 || i != mask)
                tree[p].ys[i] = (i >> 1) ^ (1 << (m-1));
            else
                tree[p].ys[i] = (i >> 1);
            if(x == 1 || i != mask)
                tree[p].ys2[i] = (i >> 1) ^ (1 << (m-1));
            else
                tree[p].ys2[i] = (i >> 1);
        }
        return ;
    }
    int mid = l + r >> 1;
    build(p << 1,l,mid);
    build(p << 1 | 1,mid + 1,r);
    update(p);
}

void push(int p) {
    for(int i = 0;i <= mask;i ++) swap(tree[p].ys[i],tree[p].ys2[i]);
    tree[p].c ^= 1;
}

void pushdown(int p) {
    if(tree[p].c) {
        push(p << 1);
        push(p << 1 | 1);
        tree[p].c = 0;
    }
}

void change(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        push(p);
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p << 1,l,r);
    if(mid < r) change(p << 1 | 1,l,r);
    update(p);
}

int ask(int p,int l,int r,int S) {
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p].ys[S];
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid && mid < r) {
        return ask(p << 1,l,r,ask(p << 1 | 1,l,r,S));
    }
    else if(l <= mid) return ask(p << 1,l,r,S);
    else if(mid < r) return ask(p << 1 | 1,l,r,S);
}

int main() {
    n = read(),m = read(),q = read();
    mask = (1 << m) - 1;
    for(int i = 1;i <= n;i ++) a[i] = read() % 2;
    build(1,1,n);
    for(int i = 1;i <= q;i ++) {
        int opt = read(),l = read(),r = read();
        if(opt == 1) {
            int d = read();
            if(d & 1) change(1,l,r);
        }
        else {
            puts(ask(1,l,r,mask) >> (m-1) & 1 ? "1" : "2");
        }
    }
    return 0;
}
