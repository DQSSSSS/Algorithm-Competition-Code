#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e5 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

char s[SZ];

struct seg {
    int l,r;
    int sum,c;
}tree[27][SZ * 4];

void update(int id,int p) {
    tree[id][p].sum = tree[id][p<<1].sum + tree[id][p<<1|1].sum;
}

void build(int id,int p,int l,int r) {
    tree[id][p].l = l;
    tree[id][p].r = r;
    tree[id][p].c = -1;
    if(l == r) {
        tree[id][p].sum = s[l] - 'a' == id;
        return ;
    }
    int mid = l + r >> 1;
    build(id,p<<1,l,mid);
    build(id,p<<1|1,mid+1,r);
    update(id,p);
}

void pushc(int id,int p,int d) {
    tree[id][p].c = d;
    tree[id][p].sum = d * (tree[id][p].r - tree[id][p].l + 1);
}

void pushdown(int id,int p) {
    if(tree[id][p].c != -1) {
        pushc(id,p<<1,tree[id][p].c);
        pushc(id,p<<1|1,tree[id][p].c);
        tree[id][p].c = -1;
    }
}

void change(int id,int p,int l,int r,int d) {
    if(l>r) return ;
    if(l <= tree[id][p].l && tree[id][p].r <= r) {
        pushc(id,p,d);
        return ;
    }
    pushdown(id,p);
    int mid = tree[id][p].l + tree[id][p].r >> 1;
    if(l <= mid) change(id,p<<1,l,r,d);
    if(mid < r) change(id,p<<1|1,l,r,d);
    update(id,p);
}

int ask(int id,int p,int l,int r) {
    if(l>r) return 0;
    if(l <= tree[id][p].l && tree[id][p].r <= r) {
        return tree[id][p].sum;
    }
    pushdown(id,p);
    int mid = tree[id][p].l + tree[id][p].r >> 1,ans = 0;
    if(l <= mid) ans += ask(id,p<<1,l,r);
    if(mid < r) ans += ask(id,p<<1|1,l,r);
    return ans;
}

int main() {
    int n = read(),q = read();
    scanf("%s",s+1);
    for(int i = 0;i < 26;i ++) build(i,1,1,n);
    while(q --) {
        int l = read(),r = read(),d = read();
        if(d == 1) {
            int now = l;
            for(int i = 0;i < 26;i ++) {
                int sum = ask(i,1,l,r);
                change(i,1,l,r,0);
                change(i,1,now,now+sum-1,1);
                now += sum;
            }
        }
        else {
            int now = l;
            for(int i = 25;i >= 0;i --) {
                int sum = ask(i,1,l,r);
                change(i,1,l,r,0);
                change(i,1,now,now+sum-1,1);
                now += sum;
            }
        }
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 0;j < 26;j ++) {
            int sum = ask(j,1,i,i);
            if(sum) putchar(j+'a');
        }
    }
}
