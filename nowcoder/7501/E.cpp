#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
typedef pair<double, double> pdd;
const int SZ = 2000100;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-6;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

struct SEG {

    struct node {
        int l,r,ans,maxn,minn,c;
    }tree[SZ*4];

    void pushc(int p,int val) {
        tree[p].ans = val-tree[p].r+1;
        tree[p].maxn = val;
        tree[p].minn = val;
        tree[p].c = val;
    }

    void pushdown(int p) {
        if(tree[p].c) {
            pushc(p<<1,tree[p].c);
            pushc(p<<1|1,tree[p].c);
            tree[p].c = 0;
        }
    }

    void build(int p,int l,int r) {
        tree[p].l = l;
        tree[p].r = r;
        if(l == r) {
            tree[p].ans = INF;
            tree[p].maxn = 0;
            tree[p].minn = 0;
            return ;
        }
        int mid = l + r >> 1;
        build(p<<1,l,mid);
        build(p<<1|1,mid+1,r);
    }

    void change(int p,int l,int r,int val) {
        if(tree[p].minn >= val) return ;
        if(l <= tree[p].l && tree[p].r <= r) {
            if(tree[p].maxn < val) {
                pushc(p,val);
                return ;
            }
        }
        pushdown(p);
        int mid = tree[p].l + tree[p].r >> 1;
        if(l <= mid) change(p<<1,l,r,val);
        if(mid < r) change(p<<1|1,l,r,val);
        tree[p].ans = min(tree[p<<1].ans,tree[p<<1|1].ans);
        tree[p].minn = min(tree[p<<1].minn,tree[p<<1|1].minn);
        tree[p].maxn = max(tree[p<<1].maxn,tree[p<<1|1].maxn);
    }
}seg;

int main() {
    int n = read(),m = read();
    vector<pii> a;
    for(int i = 1;i <= n;i ++) {
        a.push_back({read(),i});
    }
    sort(a.begin(),a.end());
    seg.build(1,1,n);
    for(int i = 0,j = 0;i < n;i ++) {
        if(i+1 == n || a[i].first != a[i+1].first) {
            int ans = 0,l = 1;
            while(j <= i) {
                int id = a[j].second;
             //   printf("[%d,%d] %d\n",l,id,a[i].first);
                seg.change(1,l,id,id);
                l = id + 1;
                j ++;
            }
            if(l <= n) seg.change(1,l,n,INF);
            printf("%d ",seg.tree[1].ans);
        }
    }
}
/*
7 4
1 2 2 4 3 3 1
*/
