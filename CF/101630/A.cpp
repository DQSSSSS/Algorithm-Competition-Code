#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
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

struct haha {
    int o,x,y;
}a[SZ];

bool check(LL x1,LL y1,LL x2,LL y2) {
    LL dx = x1 - x2;
    LL dy = y1 - y2;
    return dx * dx + dy * dy < y1 * y1;
}

struct seg {
    int l,r,mx,mn,id;
}tree[SZ * 4];

void update(int p) {
    tree[p].mx = max(tree[p<<1].mx,tree[p<<1|1].mx);
    tree[p].mn = min(tree[p<<1].mn,tree[p<<1|1].mn);
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) {
        tree[p].mx = -INF;
        tree[p].mn = INF;
        tree[p].id = -1;
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    update(p);
}

void change_mx(int p,int x,int d,int id) {
    if(tree[p].l == tree[p].r) {
        tree[p].mx = d;
        tree[p].id = id;
        return ;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    if(x <= mid) change_mx(p<<1,x,d,id);
    else change_mx(p<<1|1,x,d,id);
    update(p);
}

void change_mn(int p,int x,int d,int id) {
    if(tree[p].l == tree[p].r) {
        tree[p].mn = d;
        tree[p].id = id;
        return ;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    if(x <= mid) change_mn(p<<1,x,d,id);
    else change_mn(p<<1|1,x,d,id);
    update(p);
}

int ask_mx(int p,int l,int r,int x,int y) {
    if(l > r) return -1;
    if(tree[p].mx <= x) return -1;
    if(tree[p].l == tree[p].r) {
        int id = tree[p].id;
        if(check(a[id].x,a[id].y,x,y)) return id;
        return -1;
    }
    int mid = tree[p].l + tree[p].r >> 1,ans = -1;
    if(l <= mid) ans = ask_mx(p<<1,l,r,x,y);
    if(mid < r && ans == -1) ans = ask_mx(p<<1|1,l,r,x,y);
    return ans;
}

int ask_mn(int p,int l,int r,int x,int y) {
    if(l > r) return -1;
    if(tree[p].mn >= x) return -1;
    if(tree[p].l == tree[p].r) {
        int id = tree[p].id;
        if(check(a[id].x,a[id].y,x,y)) return id;
        return -1;
    }
    int mid = tree[p].l + tree[p].r >> 1,ans = -1;
    if(l <= mid) ans = ask_mn(p<<1,l,r,x,y);
    if(mid < r && ans == -1) ans = ask_mn(p<<1|1,l,r,x,y);
    return ans;
}

int lsh[SZ];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        a[i].o = read();
        a[i].x = read();
        a[i].y = read();
        lsh[++ lsh[0]] = a[i].x;
        if(a[i].o == 1)
            lsh[++ lsh[0]] = a[i].x - a[i].y,
            lsh[++ lsh[0]] = a[i].x + a[i].y;
    }
    sort(lsh+1,lsh+1+lsh[0]);
    lsh[0] = unique(lsh+1,lsh+1+lsh[0]) - lsh - 1;
    build(1,1,lsh[0]);
    for(int i = 1;i <= n;i ++) {
        int pos = lower_bound(lsh+1,lsh+1+lsh[0],a[i].x) - lsh;
        if(a[i].o == 1) {
            change_mx(1,pos,a[i].x+a[i].y,i);
            change_mn(1,pos,a[i].x-a[i].y,i);
        }
        else {
            int id = -1;
            id = ask_mx(1,1,pos,a[i].x,a[i].y);
            if(id == -1) id = ask_mn(1,pos+1,lsh[0],a[i].x,a[i].y);
            if(id != -1) {
                pos = lower_bound(lsh+1,lsh+1+lsh[0],a[id].x) - lsh;
                change_mx(1,pos,-INF,-1);
                change_mn(1,pos,INF,-1);
            }
            printf("%d\n",id);
        }
    }
}
