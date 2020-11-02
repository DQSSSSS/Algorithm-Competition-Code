#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 200010;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}

struct node {
    int l,r;
    LL sum;
    int c;
}tree[2][SZ * 4];

vector<LL> g[2];
LL val[SZ],a[2][SZ];

void build(int p,int l,int r,int id) {
    tree[id][p].l = l;
    tree[id][p].r = r;
    tree[id][p].c = -1;
    if(l == r) {
        tree[id][p].sum = a[id][l];
        return ;
    }
    int mid = l + r >> 1;
    build(p << 1,l,mid,id);
    build(p << 1|1,mid+1,r,id);
    tree[id][p].sum = tree[id][p<<1].sum + tree[id][p << 1 | 1].sum;
}

void push(int p,int d,int id) {
    tree[id][p].sum = d * (tree[id][p].r - tree[id][p].l + 1);
    tree[id][p].c = d;
}

void pushdown(int p,int id) {
    if(tree[id][p].c != -1) {
        push(p<<1,tree[id][p].c,id);
        push(p<<1|1,tree[id][p].c,id);
        tree[id][p].c = -1;
    }
}

int ask(int p,int l,int r,int id) {
    if(l > r) return 0;
    if(l <= tree[id][p].l && tree[id][p].r <= r) {
        return tree[id][p].sum;
    }
    pushdown(p,id);
    int mid = tree[id][p].l + tree[id][p].r >> 1,ans = 0;
    if(l <= mid) ans += ask(p << 1,l,r,id);
    if(mid < r) ans += ask(p << 1 | 1,l,r,id);
    return ans;
}

void change(int p,int l,int r,int id,int d) {
    if(l > r) return ;
    if(l <= tree[id][p].l && tree[id][p].r <= r) {
        push(p,d,id);
        return ;
    }
    pushdown(p,id);
    int mid = tree[id][p].l + tree[id][p].r >> 1,ans = 0;
    if(l <= mid) change(p << 1,l,r,id,d);
    if(mid < r) change(p << 1 | 1,l,r,id,d);
    tree[id][p].sum = tree[id][p<<1].sum + tree[id][p << 1 | 1].sum;
}

int main() {

    int n = read(),q = read(),x = read();
    for(int i = 1;i <= n;i ++) {
        val[i] = read();
        if(val[i] <= x) {
            LL x = val[i];
            if(g[0].size()) x += g[0][g[0].size()-1];
            a[0][i] = 1,g[0].push_back(x);
        }
        else {
            LL x = val[i];
            if(g[1].size()) x += g[1][g[1].size()-1];
            a[1][i] = 1,g[1].push_back(x);
        }
    }
    /*
    for(int i = 1;i <= n;i ++) cout << a[0][i] << " "; puts("");
    for(int i = 1;i <= n;i ++) cout << a[1][i] << " "; puts("");
    for(int i = 0;i < g[0].size();i ++) cout << g[0][i] << " "; puts("");
    for(int i = 0;i < g[1].size();i ++) cout << g[1][i] << " "; puts("");
*/

    build(1,1,n,0);
    build(1,1,n,1);
    int len0 = g[0].size()-1;
    int len1 = g[1].size()-1;
    while(q --) {
        int p = read(),l = read(),r = read();
        if(p == 1) {
            LL ans = 0;
            LL num11 = ask(1,1,l-1,0),num21 = ask(1,1,r,0);
            LL num12 = ask(1,1,l-1,1),num22 = ask(1,1,r,1);
            if(num21) ans+=g[0][num21-1];
            if(num11) ans-=g[0][num11-1];
            if(num22) ans+=g[1][num22-1];
            if(num12) ans-=g[1][num12-1];
            printf("%lld\n",ans);
        }
        else if(p == 2){
            int sum0 = ask(1,l,r,0);
            int sum1 = ask(1,l,r,1);
            change(1,l,r,0,0); change(1,l,l+sum0-1,0,1);
            change(1,l,r,1,0); change(1,r-sum1+1,r,1,1);
        }
        else {
            int sum0 = ask(1,l,r,1);
            int sum1 = ask(1,l,r,0);
            change(1,l,r,1,0); change(1,l,l+sum0-1,1,1);
            change(1,l,r,0,0); change(1,r-sum1+1,r,0,1);
        }
    }
    return 0;
}
