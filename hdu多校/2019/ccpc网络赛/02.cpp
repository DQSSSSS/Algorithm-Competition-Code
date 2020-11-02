#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
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
    int l,r,mx;
}tree[SZ * 4];

void update(int p) {
    tree[p].mx = max(tree[p<<1].mx,tree[p<<1|1].mx);
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) {
        tree[p].mx = a[l];
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    update(p);
}

void change(int p,int x,int d) {
    if(tree[p].l == tree[p].r) {
        tree[p].mx = d;
        return ;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    if(x <= mid) change(p<<1,x,d);
    else change(p<<1|1,x,d);
    update(p);
}

int ask_max(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p].mx;
    }
    int mid = tree[p].l + tree[p].r >> 1,ans = 0;
    if(l <= mid) ans = max(ans,ask_max(p<<1,l,r));
    if(mid < r) ans = max(ans,ask_max(p<<1|1,l,r));
    return ans;
}

int n,m;

int ask(int p,int l,int v) {
   // printf("%d [%d,%d] %d %d\n",p,tree[p].l,tree[p].r,l,v);
    if(tree[p].l == l) {
        if(tree[p].l == tree[p].r) {
            if(tree[p].mx <= v) return -1;
        //    cout << tree[p].l << endl;
            return tree[p].l;
        }
     //   printf("%d\n",tree[p<<1].mx);
        if(tree[p<<1].mx > v) return ask(p<<1,l,v);
        int mid = tree[p].l + tree[p].r >> 1;
        return ask(p<<1|1,mid+1,v);
    }
    int mid = tree[p].l + tree[p].r >> 1;
    if(mid < l) {
        return ask(p<<1|1,l,v);
    }
    else {
        int ans = ask(p<<1,l,v);
        if(ans != -1) return ans;
        return ask(p<<1|1,mid+1,v);
    }
}

int b[SZ];

int main() {
   // freopen("02.out","w",stdout);
    int T = read();
    while(T --) {
        n = read(),m = read();
        for(int i = 1;i <= n;i ++) a[b[i] = read()] = i;
        build(1,1,n);
        int lstans = 0;
        while(m --) {
            int o = read();
            if(o == 1) {
                int x = read() ^ lstans;
                if(b[x] == 1e9) continue;
                change(1,b[x],1e9);
                b[x] = 1e9;
            }
            else {
                int r = read() ^ lstans,k = read() ^ lstans;
                int ans = ask(1,k,r);
                if(ans == -1) ans = n+1;
                printf("%d\n",lstans = ans);
            }
        }
    }
}
