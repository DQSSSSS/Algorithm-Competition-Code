#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 4e5 + 10;
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
    int l,r;
}l[SZ];

int lsh[SZ];
vector<int> Add[SZ],Del[SZ];

struct seg {
    int l,r;
    int maxn,add;
}tree[SZ * 4];

void update(int p) {
    tree[p].maxn = max(tree[p<<1].maxn,tree[p<<1|1].maxn);
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) {
        tree[p].maxn = 0;
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    update(p);
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

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        int u = read(),v = read();
        int x = read(),y = read();
        lsh[++ lsh[0]] = l[i].l = y;
        lsh[++ lsh[0]] = l[i].r = v;
    }
    sort(lsh + 1,lsh + 1 + lsh[0]);
    lsh[0] = unique(lsh + 1,lsh + 1 + lsh[0]) - lsh - 1;

    for(int i = 1;i <= n;i ++) {
        l[i].l = lower_bound(lsh + 1,lsh + 1 + lsh[0],l[i].l) - lsh;
        l[i].r = lower_bound(lsh + 1,lsh + 1 + lsh[0],l[i].r) - lsh;
    }

    build(1,1,lsh[0]);
    for(int i = 1;i <= n;i ++) {
        Add[l[i].l].push_back(l[i].r);
        Del[l[i].r].push_back(l[i].l);
        change(1,l[i].l,l[i].r,1);
    }

    int ans = tree[1].maxn,d = 0;
    for(int i = 1;i <= lsh[0];i ++) {
        d += Add[i].size();
        for(int r : Add[i]) {
            change(1,i,r,-1);
        }
        ans = max(ans,d + tree[1].maxn);
        d -= Del[i].size();
    }
    cout << ans << endl;
    return 0;
}
