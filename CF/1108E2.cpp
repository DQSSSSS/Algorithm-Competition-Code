#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
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

int a[SZ],ll[SZ],rr[SZ];

struct seg {
    int l,r;
    int maxn,add;
}tree[SZ * 4];

void update(int p) {
    tree[p].maxn = max(tree[p << 1].maxn,tree[p << 1 | 1].maxn);
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) {
        tree[p].maxn = a[l];
        return ;
    }
    int mid = l + r >> 1;
    build(p << 1,l,mid);
    build(p << 1 | 1,mid + 1,r);
    update(p);
}

void push(int p,int d) {
    tree[p].maxn += d;
    tree[p].add += d;
}

void pushdown(int p) {
    if(tree[p].add) {
        push(p << 1,tree[p].add);
        push(p << 1 | 1,tree[p].add);
        tree[p].add = 0;
    }
}

void change(int p,int l,int r,int d) {
    if(l <= tree[p].l && tree[p].r <= r) {
        push(p,d);
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p << 1,l,r,d);
    if(mid < r) change(p << 1 | 1,l,r,d);
    update(p);
}

vector<int> ins[SZ],del[SZ];

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    build(1,1,n);
    for(int i = 1;i <= m;i ++) {
        int l = read(),r = read();
        ins[l].push_back(r);
        del[r].push_back(l);
        ll[i] = l;
        rr[i] = r;
    }
    int ans = 0,d = 0,id = 0;
    for(int i = 1;i <= n;i ++) {
        for(int j = 0;j < ins[i].size();j ++) {
            int l = i,r = ins[i][j];
            change(1,l,r,-1);
            d --;
        }
        int now = tree[1].maxn - (a[i] + d);
        if(ans < now) ans = now,id = i;
        for(int j = 0;j < del[i].size();j ++) {
            int l = del[i][j],r = i;
            change(1,l,r,1);
            d ++;
        }
    }
    cout << ans << endl;
    int t = 0;
    for(int i = 1;i <= m;i ++) {
        if(ll[i] <= id && id <= rr[i])
            t ++;
    }
    printf("%d\n",t);
    for(int i = 1;i <= m;i ++) {
        if(ll[i] <= id && id <= rr[i])
            printf("%d ",i);
    }
    return 0;
}
