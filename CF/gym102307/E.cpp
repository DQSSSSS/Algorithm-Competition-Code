#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 4e5 + 10;
const int INF = 1e9 + 10;
const LL mod = 1e9 + 7;
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
    int add,mx;
}tree[SZ * 4];

void update(int p) {
    tree[p].mx = max(tree[p<<1].mx,tree[p<<1|1].mx);
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].add = 0;
    if(l == r) {
        tree[p].mx = 0;
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}

void pushadd(int p,int d) {
    tree[p].mx += d;
    tree[p].add += d;
}

void pushdown(int p) {
    if(tree[p].add) {
        pushadd(p<<1,tree[p].add);
        pushadd(p<<1|1,tree[p].add);
        tree[p].add = 0;
    }
}

void change(int p,int l,int r,int d) {
    if(l<=tree[p].l && tree[p].r <= r) {
        pushadd(p,d); return ;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    if(l <= mid) change(p<<1,l,r,d);
    if(mid < r) change(p<<1|1,l,r,d);
    update(p);
}

double lsh[SZ];
pair<int,int> a[SZ];
int pos[SZ][2];
int pr[SZ];

int main() {
    int n = read(),r = read(),len = 0;
    int aa,bb,alpha;
    scanf("%d.%d",&aa,&bb);
    alpha = aa*100+bb;
    for(int i = 1;i <= n;i ++) {
        a[i].first = read();
        int x,y;
        scanf("%d.%d",&x,&y);
        a[i].second = x*100+y;
        lsh[++ len] = a[i].second;
        lsh[++ len] = a[i].second + 36000;
    }
    sort(lsh + 1,lsh + 1 + len); len = unique(lsh + 1,lsh + 1+ len) - lsh - 1;
    for(int i = 1,j = 1;i <= len;i ++) {
        while(j<i && lsh[i]-lsh[j] > alpha) j ++;
        pr[i] = j;
    }
    build(1,1,len);
    sort(a+1,a+1+n);
  /*  for(int i = 1;i <= n;i ++) printf("%d %.2f\n",a[i].first,a[i].second);
    for(int i = 1;i <= len;i ++) printf("%5.2f ",lsh[i]); puts("");
    for(int i = 1;i <= len;i ++) printf("%5d ",pr[i]); puts("");*/
    for(int i = 1;i <= n;i ++) {
        pos[i][0] = lower_bound(lsh+1,lsh+1+len,a[i].second)-lsh;
        pos[i][1] = lower_bound(lsh+1,lsh+1+len,a[i].second+36000)-lsh;
    }
    int ans = 0;
    for(int i = 1,p = 1;i <= n;i ++) {
        for(int j = 0;j < 2;j ++) {
            int x = pos[i][j];
            change(1,pr[x],x,1);
        }
        while(p <= i && a[i].first - a[p].first > r) {
            for(int j = 0;j < 2;j ++) {
                int x = pos[p][j];
                change(1,pr[x],x,-1);
            }
            p ++;
        }
        ans = max(ans,tree[1].mx);
    }
    cout << ans << endl;
}
