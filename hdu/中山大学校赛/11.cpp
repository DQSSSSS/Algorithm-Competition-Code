#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 5e5 + 10;
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
        tree[p].maxn = l;
        tree[p].minn = l;
        tree[p].sum = l;
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
    if(tree[p].minn >= d) return ;
    if(l <= tree[p].l && tree[p].r <= r) {
        if(tree[p].maxn <= d) {
            pushc(p,d); return ;
        }
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p<<1,l,r,d);
    if(mid < r) change(p<<1|1,l,r,d);
    update(p);
}

pll ask(int p,int l,int r) {
    if(tree[p].minn >= r) return make_pair(0,0);
    if(l <= tree[p].l && tree[p].r <= r) {
        if(tree[p].maxn <= r) {
            return make_pair(tree[p].r-tree[p].l+1,tree[p].sum);
        }
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    pll ans; ans.first = 0; ans.second = 0;
    if(l <= mid) {
        pll tmp = ask(p<<1,l,r);
        ans.first += tmp.first; ans.second += tmp.second;
    }
    if(mid < r) {
        pll tmp = ask(p<<1|1,l,r);
        ans.first += tmp.first; ans.second += tmp.second;
    }
    return ans;
}

int main() {
    int n,m;
    while(~scanf("%d%d",&n,&m)) {
        build(1,1,n);
        for(int i = 1;i <= m;i ++) {
            int l,r;
            scanf("%d%d",&l,&r);
            if(l == r) {
                puts("0"); continue;
            }
            pll p = ask(1,l,r);
            printf("%lld\n",r*p.first-p.second);
            change(1,l,r,r);
        }
    }
}
