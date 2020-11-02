#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
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

int a[35][SZ];

struct seg {
    int l,r;
    int maxn;
}tree[35][SZ * 4];

void update(int p,int id) {
    tree[id][p].maxn = max(tree[id][p << 1].maxn,tree[id][p << 1 | 1].maxn);
}

void build(int p,int l,int r,int id) {
    tree[id][p].l = l;
    tree[id][p].r = r;
    if(l == r) {
        tree[id][p].maxn = a[id][l];
        return ;
    }
    int mid = l + r >> 1;
    build(p << 1,l,mid,id);
    build(p << 1|1,mid+1,r,id);
    update(p,id);
}

void change(int p,int pos,int sum,int id) {
    if(tree[id][p].l == tree[id][p].r) {
        tree[id][p].maxn = sum;
        return ;
    }
    int mid = tree[id][p].l + tree[id][p].r >> 1;
    if(pos <= mid) change(p << 1,pos,sum,id);
    else change(p << 1 | 1,pos,sum,id);
    update(p,id);
}

int ask(int p,int l,int r,int id) {
    if(l <= tree[id][p].l && tree[id][p].r <= r) {
        return tree[id][p].maxn;
    }
    int mid = tree[id][p].l + tree[id][p].r >> 1;
    int ans = -INF;
    if(l <= mid) ans = max(ans,ask(p << 1,l,r,id));
    if(mid < r) ans = max(ans,ask(p << 1 | 1,l,r,id));
    return ans;
}


int tmp[6];

int main() {
    int n = read(),k = read();
    int S = 1 << k; S --;
    for(int i = 1;i <= n;i ++) {
        for(int j = 0;j < k;j ++) tmp[j] = read();
        for(int j = 0;j <= S;j ++) {
            int sum = 0;
            for(int l = 0;l < k;l ++) {
                int b = (j >> l & 1) ? -1 : 1;
                sum += tmp[l] * b;
            }
            a[j][i] = sum;
        }
    }
    for(int i = 0;i <= S;i ++) build(1,1,n,i);
    int q = read();
    while(q --) {
        int opt = read();
        if(opt == 1) {
            int pos = read();
            for(int j = 0;j < k;j ++) tmp[j] = read();
            for(int j = 0;j <= S;j ++) {
                int sum = 0;
                for(int l = 0;l < k;l ++) {
                    int b = (j >> l & 1) ? -1 : 1;
                    sum += tmp[l] * b;
                }
                change(1,pos,sum,j);
            }
        }
        else {
            int l = read(),r = read();
            int ans = 0;
            for(int j = 0;j <= S;j ++) {
                int revj = S ^ j;
                if(j < revj) {
                    ans = max(ans,ask(1,l,r,j) + ask(1,l,r,revj));
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
