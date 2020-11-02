#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
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
    LL maxn,minn,sum,c;
}tree[SZ * 4];

void update(int p) {
    tree[p].maxn = max(tree[p<<1].maxn,tree[p<<1|1].maxn);
    tree[p].minn = min(tree[p<<1].minn,tree[p<<1|1].minn);
    tree[p].sum = tree[p<<1].sum + tree[p<<1|1].sum;
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].c = 0;
    if(l == r) {
        tree[p].maxn = a[l];
        tree[p].minn = a[l];
        tree[p].sum = a[l];
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    update(p);
}

void pushc(int p,LL d) {
    tree[p].maxn = tree[p].minn = tree[p].c = d;
    tree[p].sum = d * (tree[p].r - tree[p].l + 1);
}

void pushdown(int p) {
    if(tree[p].c) {
        pushc(p<<1,tree[p].c);
        pushc(p<<1|1,tree[p].c);
        tree[p].c = 0;
    }
}

void change(int p,int l,int r,LL d) {
    if(tree[p].maxn <= d) return ;
    if(l <= tree[p].l && tree[p].r <= r) {
        if(tree[p].minn >= d) {
            pushc(p,d); return ;
        }
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p<<1,l,r,d);
    if(mid < r) change(p<<1|1,l,r,d);
    update(p);
}

LL ask_max(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p].maxn;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    LL ans = 0;
    if(l <= mid) ans = max(ans,ask_max(p<<1,l,r));
    if(mid < r) ans = max(ans,ask_max(p<<1|1,l,r));
    return ans;
}

LL ask_sum(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p].sum;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    LL ans = 0;
    if(l <= mid) ans += ask_sum(p<<1,l,r);
    if(mid < r) ans += ask_sum(p<<1|1,l,r);
    return ans;
}

int main() {
    int n,m,T = read();
    while(T --) {
        n = read(),m = read();
        for(int i = 1;i <= n;i ++) a[i] = read();
        build(1,1,n);
        for(int i = 1;i <= m;i ++) {
            int opt = read(),l = read(),r = read(),t;
            if(opt == 0) t = read(),change(1,l,r,t);
            else if(opt == 1) printf("%lld\n",ask_max(1,l,r));
            else printf("%lld\n",ask_sum(1,l,r));
        }
    }
}

