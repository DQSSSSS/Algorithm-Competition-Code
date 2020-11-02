#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 100100;
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

struct matrix {
    int a[3][3];
    void read() {
        for(int i = 0;i < 3;i ++)
            for(int j = 0;j < 3;j ++)
                a[i][j] = ::read();
    }
    LL get_sum() {
        LL ans = 0;
        for(int i = 0;i < 3;i ++)
            for(int j = 0;j < 3;j ++)
                (ans += a[i][j]) %= mod;
        return ans;
    }
    void init(int x) {
        memset(a,0,sizeof(a));
        for(int i = 0;i < 3;i ++) a[i][i] = x;
    }
    void print() {
        for(int i = 0;i < 3;i ++,puts(""))
            for(int j = 0;j < 3;j ++)
                cout << a[i][j] << " ";
        puts("");
    }
}a[SZ];

matrix operator *(const matrix &a,const matrix &b) {
    matrix ans;
    (ans.a[0][0] =
        (1ll* a.a[0][0] * b.a[0][0] +
        1ll* a.a[0][1] * b.a[1][0] +
        1ll* a.a[0][2] * b.a[2][0])
        % mod) %= mod;
    (ans.a[0][1] =
        (1ll* a.a[0][0] * b.a[0][1] +
        1ll* a.a[0][1] * b.a[1][1] +
        1ll* a.a[0][2] * b.a[2][1])
        % mod) %= mod;
    (ans.a[0][2] =
        (1ll* a.a[0][0] * b.a[0][2] +
        1ll* a.a[0][1] * b.a[1][2] +
        1ll* a.a[0][2] * b.a[2][2])
        % mod) %= mod;

    (ans.a[1][0] =
        (1ll* a.a[1][0] * b.a[0][0] +
        1ll* a.a[1][1] * b.a[1][0] +
        1ll* a.a[1][2] * b.a[2][0])
        % mod) %= mod;
    (ans.a[1][1] =
        (1ll* a.a[1][0] * b.a[0][1] +
        1ll* a.a[1][1] * b.a[1][1] +
        1ll* a.a[1][2] * b.a[2][1])
        % mod) %= mod;
    (ans.a[1][2] =
        (1ll* a.a[1][0] * b.a[0][2] +
        1ll* a.a[1][1] * b.a[1][2] +
        1ll* a.a[1][2] * b.a[2][2])
        % mod) %= mod;

    (ans.a[2][0] =
        (1ll* a.a[2][0] * b.a[0][0] +
        1ll* a.a[2][1] * b.a[1][0] +
        1ll* a.a[2][2] * b.a[2][0])
        % mod) %= mod;
    (ans.a[2][1] =
        (1ll* a.a[2][0] * b.a[0][1] +
        1ll* a.a[2][1] * b.a[1][1] +
        1ll* a.a[2][2] * b.a[2][1])
        % mod) %= mod;
    (ans.a[2][2] =
        (1ll* a.a[2][0] * b.a[0][2] +
        1ll* a.a[2][1] * b.a[1][2] +
        1ll* a.a[2][2] * b.a[2][2])
        % mod) %= mod;
    return ans;
}

matrix ksm(matrix a,int b) {
    if(b == 1) return a;
    b --;
    matrix ans = a;
    while(b) {
        if(b & 1) ans = a * ans;
        a = a * a;
        b >>= 1;
    }
    return ans;
}

struct seg {
    int l,r;
    bool c;
    matrix p,sum;
}tree[SZ * 4];

void update(int p) {
    tree[p].sum = tree[p << 1].sum * tree[p <<1 | 1].sum;
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) {
        tree[p].sum = a[l];
        return ;
    }
    int mid = l +r >> 1;
    build(p << 1,l,mid);
    build(p << 1|1,mid+1,r);
    update(p);
}

void push(int p,const matrix &tmp) {
    tree[p].sum = ksm(tmp,tree[p].r - tree[p].l + 1);
    tree[p].p = tmp;
    tree[p].c = 1;
}

void pushdown(int p) {
    if(tree[p].c) {
        push(p << 1,tree[p].p);
        push(p << 1|1,tree[p].p);
        tree[p].c = 0;
    }
}

matrix ask(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p].sum;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >>1;
    matrix ans; ans.init(1);
    if(l <= mid) ans = ans * ask(p << 1,l,r);
    if(mid < r) ans = ans * ask(p << 1 | 1,l,r);
    return ans;
}

void change(int p,int l,int r,const matrix &d) {
    if(l <= tree[p].l && tree[p].r <= r) {
        push(p,d);
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >>1;
    if(l <= mid) change(p << 1,l,r,d);
    if(mid < r) change(p << 1 | 1,l,r,d);
    update(p);
}


int main() {
    int n = read(),m = read();
    for(int i = 1;i < n;i ++) {
        a[i].read();
    }
    build(1,1,n-1);
    while(m --) {
        int opt = read(),l = read(),r = read();
        if(opt == 2) {
            matrix tmp = ask(1,l,r-1);
            //tmp.print();
            LL sum = tmp.get_sum();
            printf("%lld\n",sum);
        }
        else {
            matrix tmp; tmp.read();
            change(1,l,r,tmp);
        }
    }
    return 0;
}
