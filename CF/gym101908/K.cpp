#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

struct seg {
    int l,r;
    double c[3];
    double minn;
    bool flag;
}tree[SZ * 4];

void update(int p) {
    tree[p].minn = min(tree[p<<1].minn,tree[p<<1|1].minn);
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].flag = 0;
    tree[p].c[0] = 1;
    tree[p].c[1] = 1;
    tree[p].c[2] = 1;
    if(l == r) {
        tree[p].minn = a[l].x * a[l].x + a[l].y * a[l].y;
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    update(p);
}

void pushc(int p,double d[3]) {
    for(intree[p].c += d;
    tree[p].sum += d * (tree[p].r - tree[p].l + 1);
}

void pushdown(int p) {
    if(tree[p].add) {
        pushadd(p<<1,tree[p].add);
        pushadd(p<<1|1,tree[p].add);
        tree[p].add = 0;
    }
}

void change(int p,int l,int r,int d) {
    if(l <= tree[p].l && tree[p].r <= r) {
        pushadd(p,d);
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p<<1,l,r,d);
    if(mid < r) change(p<<1|1,l,r,d);
    update(p);
}

int ask(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p].sum;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1,ans = 0;
    if(l <= mid) ans += ask(p<<1,l,r);
    if(mid < r) ans += ask(p<<1|1,l,r);
    return ans;
}

int main() {

}
