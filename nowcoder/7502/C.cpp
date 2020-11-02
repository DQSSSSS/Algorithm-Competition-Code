#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
typedef pair<double, double> pdd;
const int SZ = 200100;
const LL INF = 1e18 + 10;
const int mod = 998244353;
const LD eps = 1e-6;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int a[SZ],b[SZ];

struct haha {
    int l,r;
    LL c[2][2];
}tree[SZ * 4];

void pushup(haha &o, const haha &r, const haha &l) {
    o.c[0][0] = max(l.c[0][0]+r.c[0][0], l.c[0][1] + r.c[1][0]);
    o.c[0][1] = max(l.c[0][0]+r.c[0][1], l.c[0][1] + r.c[1][1]);
    o.c[1][0] = max(l.c[1][0]+r.c[0][0], l.c[1][1] + r.c[1][0]);
    o.c[1][1] = max(l.c[1][0]+r.c[0][1], l.c[1][1] + r.c[1][1]);
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) {
        tree[p].c[0][0] = b[l];
        tree[p].c[0][1] = a[l];
        tree[p].c[1][0] = -INF;
        return ;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    pushup(tree[p], tree[p<<1], tree[p<<1|1]);
}

void changeA(int p,int x,int d) {
    if(tree[p].l == tree[p].r) {
        tree[p].c[0][1] = d;
        return ;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    if(x <= mid) changeA(p<<1,x,d);
    else changeA(p<<1|1,x,d);
    pushup(tree[p], tree[p<<1], tree[p<<1|1]);
}

void changeB(int p,int x,int d) {
    if(tree[p].l == tree[p].r) {
        tree[p].c[0][0] = d;
        return ;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    if(x <= mid) changeB(p<<1,x,d);
    else changeB(p<<1|1,x,d);
    pushup(tree[p], tree[p<<1], tree[p<<1|1]);
}

haha ask(int p, int l, int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p];
    }
    int mid = tree[p].l + tree[p].r >> 1;
    if(r <= mid) return ask(p<<1,l,r);
    else if(mid < l) return ask(p<<1|1,l,r);
    else {
        haha ans;
        pushup(ans,ask(p<<1,l,r), ask(p<<1|1,l,r));
        return ans;
    }
}

int main() {
    int n,m;
    while(~scanf("%d%d",&n,&m)) {
        for(int i = 1;i <= n;i ++) a[i] = read();
        for(int i = 1;i <= n;i ++) b[i] = read();
        build(1,1,n);
        while(m --) {
            int o = read(), x = read();
            if(o == 1) {
                int y = read();
                changeA(1,x,y);
            } else if(o == 2) {
                int y = read();
                changeB(1,x,y);
            } else {
                haha o = ask(1,1,x);
                printf("%lld\n",max(o.c[0][0], o.c[0][1]));
            }
        }
    }
}
