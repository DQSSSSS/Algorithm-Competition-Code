#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 2e5 + 10;
const int mod = 1e9+7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a=='-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n=n*10+a-'0'; a = getchar(); }
    if(flag) n=-n;
    return n;
}

int mi[SZ];

struct seg {
    int l,r;
    int sum,misum;
    int x,rx,len;
}tree[SZ*4];

void update(int p) {
    tree[p].sum = (tree[p<<1].sum+tree[p<<1|1].sum) % mod;
    tree[p].misum = (tree[p<<1].misum+tree[p<<1|1].misum) % mod;
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].sum = 0;
    tree[p].misum = 0;
    tree[p].x = 0;
    tree[p].rx = 0;
    tree[p].len = 0;
    if(l == r) {
        tree[p].misum = 1;
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    update(p);
}

void pushc(int p,int x,int rx,int len) {
    tree[p].sum = (1ll*mi[len]*tree[p].sum%mod+1ll*x*(tree[p].r-tree[p].l+1)%mod
        + 1ll*rx*tree[p].misum%mod*mi[len]%mod) % mod;
    tree[p].misum = 1ll*mi[len*2]*tree[p].misum % mod;
    tree[p].x = (1ll*tree[p].x*mi[len]%mod + x) % mod;
    tree[p].rx = (tree[p].rx + 1ll*rx*mi[tree[p].len] % mod) % mod;
    tree[p].len += len;
}

void pushdown(int p) {
    if(tree[p].len) {
        pushc(p<<1,tree[p].x,tree[p].rx,tree[p].len);
        pushc(p<<1|1,tree[p].x,tree[p].rx,tree[p].len);
        tree[p].len = 0;
        tree[p].x = 0;
        tree[p].rx = 0;
    }
}

void change(int p,int l,int r,int d) {
    if(l<=tree[p].l&&tree[p].r<=r) {
        pushc(p,d,d,1);
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p<<1,l,r,d);
    if(mid < r) change(p<<1|1,l,r,d);
    update(p);
}

int ask(int p,int l,int r) {
    if(l<=tree[p].l&&tree[p].r<=r) {
        return tree[p].sum;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1,ans = 0;
    if(l <= mid) (ans += ask(p<<1,l,r)) %= mod;
    if(mid < r) (ans += ask(p<<1|1,l,r)) %= mod;
    return ans;
}

int main() {
    mi[0] = 1;
    for(int i = 1;i <= 2e5;i ++) mi[i]=mi[i-1]*10ll%mod;
    int T = read(),cc = 0;
    while(T--) {
        int n = read(),m = read();
        build(1,1,n);
        printf("Case %d:\n",++ cc);
        while(m --) {
            char s[6];
            scanf("%s",s);
            int l = read(),r = read();
            if(s[0] == 'w') {
                int d = read();
                change(1,l,r,d);
            }
            else {
                printf("%d\n",ask(1,l,r));
            }
        }
    }
}
