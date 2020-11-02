#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 300100;
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

int n;
LL a,d[SZ],c[SZ];

struct seg {
    int l,r;
    LL mx,add;
}tree[SZ * 4];

void update(int p) {
    tree[p].mx = max(tree[p << 1].mx,tree[p <<1 | 1].mx);
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].add = 0;
    if(l == r) {
        tree[p].mx = 0;
        return ;
    }
    int mid = l + r >> 1;
    build(p << 1,l,mid);
    build(p << 1 | 1,mid + 1,r);
    update(p);
}

void pushc(int p,LL d) {
    tree[p].mx += d;
    tree[p].add += d;
}

void pushdown(int p) {
    if(tree[p].add) {
        pushc(p<<1,tree[p].add);
        pushc(p<<1|1,tree[p].add);
        tree[p].add = 0;
    }
}

void change(int p,int l,int r,LL d) {
    if(l <= tree[p].l && tree[p].r <= r) {
        pushc(p,d);
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p << 1,l,r,d);
    if(mid < r) change(p << 1 | 1,l,r,d);
    update(p);
}

LL ask(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p].mx;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    LL ans = -2e18;
    if(l <= mid) ans = max(ans,ask(p << 1,l,r));
    if(mid < r) ans = max(ans,ask(p << 1 | 1,l,r));
    return ans;
}

int main() {
    n = read(),a = read();
    for(int i = 1;i <= n;i ++) {
        d[i] = read();
        c[i] = read();
    }
    build(1,1,n);
    LL ans = max(0ll,a - c[n]);
    change(1,n,n,a - c[n]);
    stack<int> S;
    for(int i = n - 1;i >= 1;i --) {
        change(1,i,n,a-c[i]);

        LL x = d[i+1]-d[i];
        while(S.size() && d[S.top()+1]-d[S.top()] < x) {
            int k = S.top(); S.pop();
            int r = S.size() ? S.top() : n;
            LL dd = d[k+1]-d[k];
            change(1,k+1,r,dd*dd);
        }
        int r = S.size() ? S.top() : n;
        change(1,i+1,r,-x*x);
        S.push(i);

        LL d = ask(1,i,n);
        ans = max(ans,d);
    }
    cout << ans << endl;

    return 0;
}

