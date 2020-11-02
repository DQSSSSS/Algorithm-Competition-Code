#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 2e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

int Z[SZ],X[SZ],B[SZ],lsh[SZ];


struct seg {
    int l,r,sz;
}tree[SZ * 4];

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) {
        tree[p].sz = 1;
        return ;
    }
    int mid = l + r>> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    tree[p].sz = tree[p<<1].sz + tree[p<<1|1].sz;
}

void insert(int p,int x) {
    if(tree[p].l == tree[p].r) {
        tree[p].sz --;
        return ;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    if(x <= mid) insert(p<<1,x);
    else insert(p<<1|1,x);
    tree[p].sz = tree[p<<1].sz + tree[p<<1|1].sz;
}

int ask(int p,int l,int r) {
    if(tree[p].l == tree[p].r) {
        if(tree[p].sz) return tree[p].l;
        else return -1;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    if(l > mid) return ask(p<<1|1,l,r);
    else if(r <= mid) return ask(p<<1,l,r);
    else {
        int x = ask(p<<1,l,mid);
        if(x == -1) return ask(p<<1|1,mid+1,r);
        return x;
    }
}


int main() {
    int n = read(),q = read();
    for(int i = 1;i <= q;i ++) {
        Z[i] = read();
        X[i] = read();
        lsh[++ lsh[0]] = X[i];
        if(X[i]<n) lsh[++ lsh[0]] = X[i]+1;
    }
    sort(lsh+1,lsh+1+lsh[0]);
    lsh[0] = unique(lsh+1,lsh+1+lsh[0])-lsh-1;
    build(1,1,lsh[0]);
    for(int i = 1;i <= q;i ++) {
        X[i] = lower_bound(lsh+1,lsh+1+lsh[0],X[i])-lsh;
        if(Z[i] == 1) {
            insert(1,X[i]);
        }
        else {
            int it = ask(1,X[i],lsh[0]);
            int d = it==-1 ? -1 : lsh[it];
            printf("%d\n",d);
        }
    }
}
/**
5 3
1 5
2 5
2 1
*/
