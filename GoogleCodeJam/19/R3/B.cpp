#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2e5 + 10;
const int mod = 1e9 + 7;

LL read(){
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
    LL sum,c;
}tree[SZ * 4];

void update(int p) {
    tree[p].sum = (tree[p<<1].sum + tree[p<<1|1].sum) % mod;
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].c = 0;
    if(l == r) {
        tree[p].sum = 0;
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    update(p);
}

void pushc(int p,LL d) {
    tree[p].sum = 1ll * d * (tree[p].r - tree[p].l + 1) % mod;
}

void pushdown(int p) {
    if(tree[p].c) {
        pushc(p<<1,tree[p].c);
        pushc(p<<1|1,tree[p].c);
        tree[p].c = 0;
    }
}

void change(int p,int l,int r,LL d) {
    if(l <= tree[p].l && tree[p].r <= r) {
        pushc(p,d); return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p<<1,l,r,d);
    if(mid < r) change(p<<1|1,l,r,d);
    update(p);
}

int ask(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p].sum;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    int ans = 0;
    if(l <= mid) (ans += ask(p<<1,l,r)) %= mod;
    if(mid < r) (ans += ask(p<<1|1,l,r)) %= mod;
    return ans;
}

int a[SZ],sum[SZ],L[SZ],R[SZ];
pii b[SZ];

int main() {
    int T = read();
    for(int cc = 1;cc <= T;cc ++) {
        int n = read();
        for(int i = 1;i <= n;i ++) a[i] = read(),sum[i] = (a[i] + sum[i-1] % mod);

        stack<int> S;
        for(int i = 1;i <= n;i ++) {
            while(S.size() && a[i] >= a[S.top()]) S.pop();
            if(S.size()) L[i] = S.top() + 1;
            else L[i] = 1;
            S.push(i);
        }

        while(S.size()) S.pop();
        for(int i = n;i >= 1;i --) {
            while(S.size() && a[i] > a[S.top()]) S.pop();
            if(S.size()) R[i] = S.top() - 1;
            else R[i] = n;
            S.push(i);
        }

        for(int i = 1;i <= n;i ++) b[i] = make_pair(a[i],i);

        sort(b+1,b+1+n);

        build(1,1,n);
        int ans = 0;
        for(int i = 1;i <= n;i ++) cout << L[i] << " " << R[i] << endl;
        for(int i = 1;i <= n;i ++) {
            int id = b[i].second;
            if(R[id]-L[id]+1 >= 3)
                (ans += (ask(1,L[id],R[id]) - (sum[R[id]] - sum[L[id]-1])) % mod) %= mod;
            change(1,L[id],R[id],b[i].first);
        }
        printf("Case #%d: %d\n",cc,ans);
    }
}
