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

int a[SZ],nx[SZ],pr[SZ],nxx[SZ];

struct seg {
    int l,r;
    int add,maxn;
}tree[SZ * 4];

void update(int p) {
    tree[p].maxn = max(tree[p<<1].maxn,tree[p<<1|1].maxn);
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].add = 0;
    tree[p].maxn = 0;
    if(l == r) return ;
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}

void pushadd(int p,int d) {
    tree[p].add += d;
    tree[p].maxn += d;
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

int ask(int p,int x) {
    if(tree[p].l == tree[p].r) return tree[p].maxn;
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(x <= mid) return ask(p<<1,x);
    else return ask(p<<1|1,x);
}

map<int,int> mp,fst,lst;

int main() {
    int T = read();
    for(int cc = 1;cc <= T;cc ++) {
        int n = read(),m = read();
        for(int i = 1;i <= n;i ++) nxx[i] = pr[i] = nx[i] = 0;
        for(int i = 1;i <= n;i ++) a[i] = read();
        mp.clear(); fst.clear(); lst.clear();
        for(int i = n;i >= 1;i --) {
            int x = a[i];
            if(mp[x] == 0) fst[x] = i;
            if(mp[x] > m) nx[i] = pr[nx[lst[x]]];
            mp[x] ++;
            if(mp[x] == m + 1) nx[i] = fst[x];
            nxx[i] = lst[x];
            pr[lst[x]] = i;
            lst[x] = i;
        }

        build(1,1,n);
        mp.clear();
        for(int i = 1;i <= n;i ++) {
            int x = a[i];
            mp[x] ++;
            if(mp[x] <= m) change(1,i,n,1);
            if(mp[x] == m + 1) {
                change(1,i,n,-m);
            }
        }

       // for(int i = 1;i <= n;i ++) printf("%d ",nx[i]); puts("");
        int ans = 0;
        for(int i = 1;i <= n;i ++) {
            //for(int j = 1;j <= n;j ++) printf("%d%c",ask(1,j)," \n"[j==n]);
            ans = max(ans,tree[1].maxn);
            if(nx[i]) {
                change(1,i,nx[i]-1,-1);
                if(nxx[nx[i]]) change(1,nx[i],nxx[nx[i]]-1,m);
                else change(1,nx[i],n,m);
            }
            else {
                change(1,i,n,-1);
            }
        }
        printf("Case #%d: %d\n",cc,ans);
    }
}
