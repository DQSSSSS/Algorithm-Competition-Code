#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
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

struct seg {
    int l,r;
    LL add,mx;
}tree[SZ * 4];

void update(int p) {
    tree[p].mx = max(tree[p<<1].mx,tree[p<<1|1].mx);
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].add = 0;
    if(l == r) { tree[p].mx = 0; return ; }
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    update(p);
}

void pushadd(int p,int d) {
    tree[p].add += d;
    tree[p].mx += d;
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

LL ask(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p].mx;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    LL ans = 0;
    if(l <= mid) ans = max(ans,ask(p<<1,l,r));
    if(mid < r) ans = max(ans,ask(p<<1|1,l,r));
    return ans;
}

int lsh[SZ];

struct haha {
    int x,y,a,b;
}a[SZ];

bool cmpy(haha a,haha b) { return a.y == b.y ? a.x > b.x : a.y < b.y; }

int main() {
    int n;
    while(~scanf("%d",&n)) {
        LL sum = 0;
        for(int i = 1;i <= n;i ++) {
            a[i].x = read(),a[i].y = read();
            a[i].a = read(),a[i].b = read();
            sum += a[i].a;
            lsh[++ lsh[0]] = a[i].x;
        }
        sort(lsh+1,lsh+1+lsh[0]);
        lsh[0] = unique(lsh+1,lsh+1+lsh[0]) - lsh - 1;
        sort(a+1,a+1+n,cmpy);
        LL ans = sum;
        build(1,1,lsh[0]);
        for(int i = 1,j = 1;i <= n;i ++) {
            if(i == n || a[i+1].y != a[i].y) {
                LL s = 0;
                for(;j <= i;j ++) {
                    int x = lower_bound(lsh+1,lsh+1+lsh[0],a[j].x) - lsh;
                    s += a[j].b-a[j].a;
                    LL d = s + ask(1,1,x);
                    change(1,x,x,-ask(1,x,x));
                    change(1,x,x,d);
                    cout << x << " " << d << endl;
                }
                ans = max(ans,sum + tree[1].mx);
                cout << sum+tree[1].mx << endl;
            }
        }
        printf("%lld\n",ans);
    }
}
