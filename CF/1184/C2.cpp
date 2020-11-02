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

struct seg {
    int l,r,mx,add;
}tree[SZ * 4];

void update(int p) {
    tree[p].mx = max(tree[p<<1].mx,tree[p<<1|1].mx);
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) return ;
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

struct haha {
    int pos,x,y,d;
}l[SZ];

bool cmp(haha a,haha b) { return a.pos < b.pos; }

int lsh[SZ];

int main() {
    int n = read(),m = read(),tot = 0;
    for(int i = 1;i <= n;i ++) {
        int a = read(),b = read(),x,y;
        x = a + b; y = a - b;
        l[++ tot] = (haha){x-m,y-m,y+m,1};
        l[++ tot] = (haha){x+m+1,y-m,y+m,-1};
     //   cout << x << " " << y << endl;
    }

   // for(int i = 1,lst = 1;i <= tot;i ++)
    //    printf("%d %d %d %d\n",l[i].pos,l[i].x,l[i].y,l[i].d);

    for(int i = 1;i <= tot;i ++) {
        lsh[++ lsh[0]] = l[i].x;
        lsh[++ lsh[0]] = l[i].y;
    }
    sort(lsh+1,lsh+1+lsh[0]);
    lsh[0] = unique(lsh+1,lsh+1+lsh[0])-lsh-1;
    for(int i = 1;i <= tot;i ++) {
        l[i].x = lower_bound(lsh+1,lsh+1+lsh[0],l[i].x)-lsh;
        l[i].y = lower_bound(lsh+1,lsh+1+lsh[0],l[i].y)-lsh;
    }

    int ans = 0;
    build(1,1,lsh[0]);
    sort(l+1,l+1+tot,cmp);


    for(int i = 1,lst = 1;i <= tot;i ++) {
        if(i == tot || l[i+1].pos != l[i].pos) {
            for(int j = lst;j <= i;j ++) {
                change(1,l[j].x,l[j].y,l[j].d);
            }
            ans = max(ans,tree[1].mx);
            lst = i + 1;
        }
    }
    cout << ans << endl;
}
