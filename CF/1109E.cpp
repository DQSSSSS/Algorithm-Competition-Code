#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1e5 + 10;
const int INF = 1e9 + 10;
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

int n,mod;

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void exgcd(LL a,LL b,LL &x,LL &y) {
    if(b == 0) {
        x = 1; y = 0;
        return ;
    }
    exgcd(b,a%b,x,y);
    LL t = x; x = y; y = t - a/b*y;
}

int p[10],a[SZ],tot;

struct seg {
    int l,r;
    LL sum,mu,c[10];
}tree[SZ * 4];

void update(int p) {
    tree[p].sum = (tree[p << 1].sum + tree[p << 1 | 1].sum) % mod;
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].c[0] = 1;
    tree[p].mu = 1;
    if(l == r) {
        tree[p].sum = a[l] % mod;
        for(int i = 1;i <= tot;i ++) {
            while(a[l] % ::p[i] == 0)
                a[l] /= ::p[i],tree[p].c[i] ++;
        }
        tree[p].c[0] = a[l];
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    update(p);
}

void pushc(int p,LL tmp[],int d) {
    (tree[p].sum *= d) %= mod;
    (tree[p].mu *= d) %= mod;
    (tree[p].c[0] *= tmp[0]) %= mod;
    for(int i = 1;i <= tot;i ++) tree[p].c[i] += tmp[i];
}

void pushdown(int p) {
    LL ans = 0;
    for(int i = 1;i <= tot;i ++) ans += tree[p].c[i];
    if(tree[p].mu != 1 || tree[p].c[0] != 1 || ans) {
        pushc(p<<1,tree[p].c,tree[p].mu);
        pushc(p<<1|1,tree[p].c,tree[p].mu);
        tree[p].c[0] = tree[p].mu = 1;
        for(int i = 1;i <= tot;i ++) tree[p].c[i] = 0;
    }
}

void Mult(int p,int l,int r,LL tmp[],int d) {
    if(l <= tree[p].l && tree[p].r <= r) {
        pushc(p,tmp,d);
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) Mult(p<<1,l,r,tmp,d);
    if(mid < r) Mult(p<<1|1,l,r,tmp,d);
    update(p);
}

void Div(int p,int x,LL tmp[]) {
    if(tree[p].l == tree[p].r) {
        (tree[p].c[0] *= tmp[0]) %= mod;
        LL ans = tree[p].c[0];
        for(int i = 1;i <= tot;i ++) {
            (ans *= ksm(::p[i],tree[p].c[i] -= tmp[i])) %= mod;
        }
        tree[p].sum = ans;
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(x <= mid) Div(p<<1,x,tmp);
    else Div(p<<1|1,x,tmp);
    update(p);
}


LL ask(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p].sum;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    LL ans = 0;
    if(l <= mid) (ans += ask(p<<1,l,r)) %= mod;
    if(mid < r) (ans += ask(p<<1|1,l,r)) %= mod;
    return ans;
}

int main() {
    n = read(),mod = read();
    for(int i = 1;i <= n;i ++) a[i] = read();

    int x = mod;
    for(int i = 2;i * i <= x;i ++) {
        if(x % i == 0) {
            p[++ tot] = i;
            while(x % i == 0) x /= i;
        }
    }
    if(x != 1) p[++ tot] = x;

    build(1,1,n);

    int q = read();
    while(q --) {
        int opt = read();
        LL a = read(),b = read();
        if(opt == 1) {
            int x = read(),xx = x;
            LL tmp[10] = {0};
            for(int i = 1;i <= tot;i ++) {
                int d = 0;
                while(x % p[i] == 0) x /= p[i],d ++;
                tmp[i] = d;
            }
            tmp[0] = x;
            Mult(1,a,b,tmp,xx);
        }
        else if(opt == 2) {
            LL tmp[10] = {0};
            for(int i = 1;i <= tot;i ++) {
                int d = 0;
                while(b % p[i] == 0) b /= p[i],d ++;
                tmp[i] = d;
            }
            LL ni,k;
            exgcd(b,mod,ni,k);
            ni %= mod; if(ni < 0) ni += mod;
            tmp[0] = ni;
            Div(1,a,tmp);
        }
        else {
            printf("%lld\n",ask(1,a,b));
        }
    }
}
/***
5 2100
1 2 3 4 5
10
1 1 2 12
3 1 2

*/
