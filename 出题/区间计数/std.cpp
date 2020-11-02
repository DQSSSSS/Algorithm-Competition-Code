#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int SZ = 300010;
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

struct seg {
    int l,r;
    int add;
    int mi,mit;
    int mi2,mi2t;
}tree[SZ * 4];

void update(int p) {
    vector<pii> a;
    a.push_back(make_pair(tree[p<<1].mi,tree[p<<1].mit));
    a.push_back(make_pair(tree[p<<1].mi2,tree[p<<1].mi2t));
    a.push_back(make_pair(tree[p<<1|1].mi,tree[p<<1|1].mit));
    a.push_back(make_pair(tree[p<<1|1].mi2,tree[p<<1|1].mi2t));
    sort(a.begin(),a.end());
    int f = 0;
    for(int i = 0,lst = 0;i < 4;i ++) {
        if(i == 3 || a[i].first != a[i+1].first) {
            int sum = 0;
            for(int j = lst;j <= i;j ++) sum += a[j].second;
            if(!f) {
                tree[p].mi = a[i].first;
                tree[p].mit = sum;
                f = 1;
            }
            else {
                tree[p].mi2 = a[i].first;
                tree[p].mi2t = sum;
                f = 2;
                break;
            }
            lst = i + 1;
        }
    }
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) {
        tree[p].mi2 = 1e9;
        tree[p].mit = 1;
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    update(p);
}

void pushadd(int p,int d) {
    tree[p].add += d;
    tree[p].mi += d;
    tree[p].mi2 += d;
}

void pushdown(int p) {
    if(tree[p].add) {
        pushadd(p<<1,tree[p].add);
        pushadd(p<<1|1,tree[p].add);
        tree[p].add = 0;
    }
}

void change(int p,int l,int r,int d) {
    if(l <= tree[p].l && tree[p].r <= r) {
        pushadd(p,d);
        return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p<<1,l,r,d);
    if(mid < r) change(p<<1|1,l,r,d);
    update(p);
}

int ask(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        int ans = 0;
        if(tree[p].mi == 1 || tree[p].mi == 2) ans += tree[p].mit;
        if(tree[p].mi2 == 1 || tree[p].mi2 == 2) ans += tree[p].mi2t;
        return ans;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1,ans = 0;
    if(l <= mid) ans += ask(p<<1,l,r);
    if(mid < r) ans += ask(p<<1|1,l,r);
    return ans;
}

int a[SZ],p[SZ];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        p[i] = read();
        a[p[i]] = i;
    }

    if(n == 1) return puts("0"),0;

    build(1,1,n);
    LL ans = 0;
    for(int l = n;l >= 1;l --) {
        int x = a[l];
        if(x == n) {
            if(p[x-1] > p[x]) change(1,l,p[x-1]-1,1);
            else change(1,l,n,1);
        }
        else if(x == 1) {
            if(p[x+1] > p[x]) change(1,l,p[x+1]-1,1);
            else change(1,l,n,1);
        }
        else {
            if(p[x+1] > p[x] && p[x-1] > p[x]) {
                change(1,l,min(p[x+1],p[x-1])-1,1);
                change(1,max(p[x+1],p[x-1]),n,-1);
            }
            else if(p[x+1] < p[x] && p[x-1] < p[x]) change(1,l,n,1);
            else {
                change(1,l,max(p[x+1],p[x-1])-1,1);
            }
        }

        ans += ask(1,l,n);
    }
    printf("%lld\n",ans - n);
    return 0;
}
