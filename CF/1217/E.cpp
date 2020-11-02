#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 2e5 + 10;
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

int a[SZ];

struct seg {
    int l,r;
    int num[11][2];
}tree[SZ * 4];

void update(seg &p,const seg &x,const seg &y) {
    for(int i = 0;i < 9;i ++) {
        int a = x.num[i][0],b = x.num[i][1];
        int c = y.num[i][0],d = y.num[i][1];
        if(a == -1) a = 1e9;
        if(b == -1) b = 1e9;
        if(c == -1) c = 1e9;
        if(d == -1) d = 1e9;
        p.num[i][0] = min(min(a,b),min(c,d));
        if(a == p.num[i][0]) a = 1e9;
        else if(b == p.num[i][0]) b = 1e9;
        else if(c == p.num[i][0]) c = 1e9;
        else if(d == p.num[i][0]) d = 1e9;
        p.num[i][1] = min(min(a,b),min(c,d));
        if(p.num[i][0] == 1e9) p.num[i][0] = -1;
        if(p.num[i][1] == 1e9) p.num[i][1] = -1;
    }
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) {
        LL mi = 1;
        for(int i = 0;i < 9;i ++) {
            tree[p].num[i][0] = -1;
            tree[p].num[i][1] = -1;
            if(a[l] / mi % 10)
                tree[p].num[i][0] = a[l];
            mi *= 10;
        }
        return ;
    }
    int mid = l + r >>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    update(tree[p],tree[p<<1],tree[p<<1|1]);
}

seg ask(int p,int l,int r) {
        //printf("%d [%d,%d] %d %d\n",p,tree[p].l,tree[p].r,l,r);
        //for(int i = 0;i < 15;i ++) printf("%d ",tree[p].num[i][0]); puts("");
       // for(int i = 0;i < 15;i ++) printf("%d ",tree[p].num[i][1]); puts("");
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p];
    }
    int mid = tree[p].l + tree[p].r >>1;
    seg ans;
    memset(ans.num,-1,sizeof ans.num);
    if(l <= mid) update(ans,ans,ask(p<<1,l,r));
    if(mid < r) update(ans,ans,ask(p<<1|1,l,r));
    return ans;
}

void change(int p,int x,int d) {
    if(x <= tree[p].l && tree[p].r <= x) {
        LL mi = 1;
        for(int i = 0;i < 9;i ++) {
            tree[p].num[i][0] = -1;
            tree[p].num[i][1] = -1;
            if(d / mi % 10)
                tree[p].num[i][0] = d;
            mi *= 10;
        }
        return ;
    }
    int mid = tree[p].l + tree[p].r >>1;
    if(x <= mid) change(p<<1,x,d);
    else change(p<<1|1,x,d);
    update(tree[p],tree[p<<1],tree[p<<1|1]);
}

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    build(1,1,n);
    while(m --) {
        int o = read();
        if(o == 1) {
            int x = read(),d = read();
            change(1,x,d);
        }
        else {
            int l = read(),r = read();
            seg d = ask(1,l,r);
            int sum = 2e9;
            for(int i = 0;i < 9;i ++) {
                if(d.num[i][0] == -1 || d.num[i][1] == -1) continue;
                sum = min(sum,d.num[i][0]+d.num[i][1]);
            }
            if(sum == 2e9) sum = -1;
            printf("%d\n",sum);
        }
    }
}
