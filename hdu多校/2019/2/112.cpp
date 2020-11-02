#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e5 + 10;
const int INF = 1e9 + 10;
const int mod = 1e6 + 3;
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
    int l,r;
    pii mx;
}tree[SZ * 4];

void update(int p) {
    tree[p].mx = max(tree[p<<1].mx,tree[p<<1|1].mx);
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) {
        tree[p].mx = make_pair(a[l],l);
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    update(p);
}

pii ask(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p].mx;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    pii ans = make_pair(0,0);
    if(l <= mid) ans = max(ans,ask(p<<1,l,r));
    if(mid < r) ans = max(ans,ask(p<<1|1,l,r));
    return ans;
}

void change(int p,int x,int d) {
    if(x <= tree[p].l && tree[p].r <= x) {
        tree[p].mx = make_pair(d,x);
        return ;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    if(x <= mid) change(p<<1,x,d);
    else change(p<<1|1,x,d);
    update(p);
}

LL ask(int l,int r) {
    if(r-l+1<3) return -1;
    LL a = -INF,b = -INF,c = -INF;
    int len = min(50,r-l+1);
    LL ans = -1;
    vector<pii> g;
    while(len --) {
        a = b; b = c;
        pii p = ask(1,l,r); g.push_back(p);
        c = p.first;
        change(1,p.second,-INF);
        if(a != -INF && c+b>a) { ans = a+b+c; break; }
    }
    for(pii p : g) {
        change(1,p.second,p.first);
    }
    return ans;
}

int main() {
    int n,q;
    while(scanf("%d%d",&n,&q)!=EOF) {
        for(int i = 1;i <= n;i ++) {
            a[i] = read();
        }
        build(1,1,n);
        while(q --) {
            int l = read(),r = read();
            printf("%lld\n",ask(l,r));
        }
    }
}
