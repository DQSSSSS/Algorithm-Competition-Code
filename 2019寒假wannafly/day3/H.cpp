#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 800100;
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

LL lsh[SZ],val1[SZ],val2[SZ];

const int ni6 = 166374059;
const int ni2 = 499122177;

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b & 1) ans = ans * a %mod;
        a = a *a % mod;
        b >>= 1;
    }
    return ans;
}

LL presum1(LL n) {
    return n * (n + 1) / 2 % mod;
}
LL presum2(LL n) {
    return n * (n + 1) % mod * (2 * n + 1) % mod * ni6 % mod;
}

LL asksum1(LL l,LL r) { return (presum1(r) - presum1(l-1)) % mod; }
LL asksum2(LL l,LL r) { return (presum2(r) - presum2(l-1)) % mod; }

struct node {
    LL ans1,ans2,t0;
};

node operator +(node a,node b) {
    return (node){(a.ans1+b.ans1)%mod,(a.ans2+b.ans2)%mod,(a.t0+b.t0)%mod};
}

node work(node tmp,LL l,LL r) {
    node ans;
    ans.t0 = 0;
    LL len = r - l;
    ans.ans1 = (tmp.ans1 - (l-1) * tmp.t0 % mod) % mod * (len+1) % mod;
    LL x = (tmp.ans1 - (l-1) * tmp.t0 % mod) %mod;
    ans.ans2 = tmp.ans2 - (l-1)*(l-1) % mod * tmp.t0 % mod - 2*(l-1) * x % mod;
    ans.ans2 %= mod;
    return ans;
}

struct seg {
    int l,r,t;
    LL ans1,ans2,t0;
}tree[SZ * 4];

void update(int p) {
    if(tree[p].t) {
        tree[p].ans1 = 0; tree[p].ans2 = 0;
        tree[p].t0 = 0;
    }
    else {
        tree[p].ans1 = (tree[p << 1].ans1 + tree[p << 1 | 1].ans1) % mod;
        tree[p].ans2 = (tree[p << 1].ans2 + tree[p << 1 | 1].ans2) % mod;
        tree[p].t0 = (tree[p << 1].t0 + tree[p << 1 | 1].t0) % mod;
    }
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].t = 0;
    if(l == r) {
        tree[p].ans1 = val1[l];
        tree[p].ans2 = val2[l];
        tree[p].t0 = (lsh[l+1] - lsh[l]) % mod;
        return ;
    }
    int mid = l + r >> 1;
    build(p <<1,l,mid);
    build(p <<1|1,mid+1,r);
    update(p);
}

void push(int p,int d) {
    tree[p].t += d;
    if(tree[p].t) {
        tree[p].ans1 = 0; tree[p].ans2 = 0;
        tree[p].t0 = 0;
    }
    else {
        if(tree[p].l == tree[p].r) {
            tree[p].ans1 = val1[tree[p].l];
            tree[p].ans2 = val2[tree[p].l];
            tree[p].t0 = (lsh[tree[p].l+1] - lsh[tree[p].l]) % mod;
        }
        else {
            tree[p].ans1 = (tree[p << 1].ans1 + tree[p << 1 | 1].ans1) % mod;
            tree[p].ans2 = (tree[p << 1].ans2 + tree[p << 1 | 1].ans2) % mod;
            tree[p].t0 = (tree[p << 1].t0 + tree[p << 1 | 1].t0) % mod;
        }
    }
}

void change(int p,int l,int r,int d) {
    if(l <= tree[p].l && tree[p].r <= r) {
        push(p,d);
        return ;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p << 1,l,r,d);
    if(mid < r) change(p << 1|1,l,r,d);
    update(p);
}

node ask(int p,int l,int r) {
    if(tree[p].t) return (node){0,0,0};
    if(l <= tree[p].l && tree[p].r <= r) {
        return (node){tree[p].ans1,tree[p].ans2,tree[p].t0};
    }
    int mid = tree[p].l + tree[p].r >> 1;
    node ans; ans.ans1 = ans.ans2 = ans.t0 = 0;
    if(l <= mid) ans = ans + ask(p << 1,l,r);
    if(mid < r) ans = ans + ask(p << 1|1,l,r);
    return ans;
}

struct haha {
    int l,r,type,pos; ///1:ins  3:del  2:ask
}a[SZ];

bool cmp(haha a,haha b) {
    if(a.pos != b.pos) return a.pos < b.pos;
    return a.type < b.type;
}

LL getfm(LL n) {
    return n * (n + 1) / 2 %mod;
}

int main() {
    //freopen("H.in","r",stdin);
    //freopen("my.out","w",stdout);
    int n = read(),m = read(),q = read(),tot = 0;
    for(int i = 1;i <= n;i ++) {
        int l = read(),r = read();
        a[++ tot] = (haha){l,r+1,2,i};
        lsh[++ lsh[0]] = l;
        lsh[++ lsh[0]] = r+1;
    }
    for(int i = 1;i <= q;i ++) {
        int lx = read(),ly = read();
        int rx = read(),ry = read();
        a[++ tot] = (haha){ly,ry+1,1,lx};
        a[++ tot] = (haha){ly,ry+1,3,rx};
        lsh[++ lsh[0]] = ly;
        lsh[++ lsh[0]] = ry+1;
    }
    sort(a + 1,a + 1 + tot,cmp);
    sort(lsh + 1,lsh + 1 + lsh[0]);
    lsh[0] = unique(lsh + 1,lsh + 1 + lsh[0]) - lsh - 1;
    for(int i = 1;i < lsh[0];i ++) {
        val1[i] = asksum1(lsh[i],lsh[i+1]-1);
        val2[i] = asksum2(lsh[i],lsh[i+1]-1);
    }
    build(1,1,lsh[0]-1);
    LL ans = 0;
    for(int i = 1;i <= tot;i ++) {
        int l = lower_bound(lsh + 1,lsh + 1 + lsh[0],a[i].l) - lsh;
        int r = lower_bound(lsh + 1,lsh + 1 + lsh[0],a[i].r) - lsh;
        if(a[i].type == 1) {
            change(1,l,r-1,1);
        }
        else if(a[i].type == 3) {
            change(1,l,r-1,-1);
        }
        else {
            node tmp = ask(1,l,r-1);
            node x = work(tmp,a[i].l,a[i].r);
            ans += (x.ans1 - x.ans2) % mod * ksm(getfm(a[i].r-a[i].l),mod-2) % mod;
            ans %= mod;
        }
    }
    ans += mod; ans %= mod;
    printf("%lld\n",ans);
    return 0;
}

