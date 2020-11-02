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

struct haha {
    int l,r;
    int c,rev,x;
}tree[SZ * 4];

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].c = -1;
    if(l == r) return ;
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}

void pushrev(int p) {
    tree[p].rev ^= 1;
    //tree[p].c ^= 1;
    tree[p].x ^= 1;
}

void pushc(int p,int d) {
    tree[p].rev = 0;
    tree[p].c = d;
    tree[p].x = d;
}

void pushdown(int p) {
    if(tree[p].c != -1) {
        pushc(p<<1,tree[p].c);
        pushc(p<<1|1,tree[p].c);
        tree[p].c = -1;
    }
    if(tree[p].rev) {
        pushrev(p<<1);
        pushrev(p<<1|1);
        tree[p].rev = 0;
    }
}

void change(int p,int l,int r,int d) {
    if(l > r) return ;
    if(l <= tree[p].l && tree[p].r <= r) {
        pushc(p,d);
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p<<1,l,r,d);
    if(mid < r) change(p<<1|1,l,r,d);
}

void reverse(int p,int l,int r) {
    if(l > r) return ;
    if(l <= tree[p].l && tree[p].r <= r) {
        pushrev(p);
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) reverse(p<<1,l,r);
    if(mid < r) reverse(p<<1|1,l,r);
}

int ask(int p,int x) {
    if(tree[p].l == tree[p].r) return tree[p].x;
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(x <= mid) return ask(p<<1,x);
    else return ask(p<<1|1,x);
}

int a[SZ];
const int maxn = 1e5;

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    build(1,-maxn,maxn);
    while(m --) {
        char s[2];
        scanf("%s",s);
        int x = read();
        if(s[0] == '<') {
            if(x > 0) {
                change(1,-maxn,-x,1); change(1,x,maxn,0);
                reverse(1,-x+1,x-1);
            }
            else {
                change(1,-maxn,x-1,1); change(1,-x+1,maxn,0);
            }
        }
        else {
            if(x < 0) {
                change(1,-maxn,x,0); change(1,-x,maxn,1);
                reverse(1,x+1,-x-1);
            }
            else {
                change(1,-maxn,-x-1,0); change(1,x+1,maxn,1);
            }
        }

    }
    for(int i = 1;i <= n;i ++)
        printf("%d ",a[i] * (ask(1,a[i]) == 1 ? -1 : 1));
    return 0;
}
