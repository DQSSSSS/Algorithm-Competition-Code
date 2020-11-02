#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
const int SZ = 2e5 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 +a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}

int n,m,a[SZ],id[SZ];

struct seg {
    int l,r;
    int f[20];
}tree[SZ * 4];

void update(seg &a,const seg &b,const seg &c) {
    int ans[20] = {};
    for(int i = 0;i < m;i ++)
        for(int j = 0;j < m;j ++) {
            (ans[(i+j)%m] += 1ll * b.f[i] * c.f[j] % mod) %= mod;
        }
    for(int i = 0;i < m;i ++) a.f[i] = ans[i];
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) {
        tree[p].f[0] ++;
        tree[p].f[a[l]] ++;
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    update(tree[p],tree[p<<1],tree[p<<1|1]);
}

seg ask(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p];
    }
    int mid = tree[p].l + tree[p].r >> 1;
    seg ans; memset(ans.f,0,sizeof ans.f); ans.f[0] = 1;
    if(l <= mid) update(ans,ans,ask(p<<1,l,r));
    if(mid < r) update(ans,ans,ask(p<<1|1,l,r));
    return ans;
}


int main() {
    n = read(),m = read();
    for(int i = 1;i <= n;i ++) {
        a[i] = read() % m;
    }
    build(1,1,n);
    int q = read();
    while(q --) {
        int l = read(),r = read();
        printf("%d\n",ask(1,l,r).f[0]);
    }
}

