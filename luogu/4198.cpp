#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
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

struct seg {
    int l,r;
    pii mx;
    int ans,f;
}tree[SZ * 4];

bool smaller(pii a,pii b) { return 1ll * a.first * b.second < 1ll * b.first * a.second; }

pii get_max(pii a,pii b) {
    if(smaller(a,b)) return b;
    return a;
}

int ask(int p,pii x) {
    if(tree[p].l == tree[p].r) {
        if(smaller(x,tree[p].mx)) return 1;
        return 0;
    }
    int mid = tree[p].l + tree[p].r >>1;
    if(smaller(x,tree[p<<1].mx)) return ask(p<<1,x) + tree[p<<1|1].f;
    return ask(p<<1|1,x);
}

void update(int p) {
    tree[p].mx = get_max(tree[p<<1].mx,tree[p<<1|1].mx);
    if(smaller(tree[p<<1].mx,tree[p<<1|1].mx)) {
        tree[p<<1|1].f = ask(p<<1|1,tree[p<<1].mx);
        tree[p].ans = tree[p<<1].ans + tree[p<<1|1].f;
    }
    else {
        tree[p<<1|1].f = 0;
        tree[p].ans = tree[p<<1].ans;
    }
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].mx = make_pair(0,l);
    tree[p].ans = 0;
    if(l == r) {
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1,l,mid); build(p<<1|1,mid+1,r);
}

void change(int p,int x,int y) {
    if(tree[p].l == tree[p].r) {
        tree[p].mx = make_pair(y,x);
        tree[p].ans = 1;
        return ;
    }
    int mid = tree[p].l + tree[p].r >>1;
    if(x <= mid) change(p<<1,x,y);
    else change(p<<1|1,x,y);
    update(p);
}

void dfs(int p) {
    printf("[%d,%d] ",tree[p].l,tree[p].r);
    printf("%2d/%2d%4d%4d\n",tree[p].mx.first,tree[p].mx.second,tree[p].ans,tree[p].f);
    if(tree[p].l == tree[p].r) {
        return ;
    }
    dfs(p<<1);
    dfs(p<<1|1);
}

int main() {
   // freopen("4198.in","r",stdin); freopen("my.out","w",stdout);
    int n = read(),m = read();
    build(1,1,n);
    for(int i = 1;i <= m;i ++) {
        int x = read();
        int y = read();
        change(1,x,y);
        printf("%d\n",tree[1].ans);
      //  dfs(1);
    }
}

/**
5 20
1 4
5 19
4 17
*/
