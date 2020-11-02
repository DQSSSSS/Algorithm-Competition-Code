#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
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
    vector<pii> lst;
}tree[SZ * 4];

int lsh[SZ];

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) return ;
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}

void change(int p,int l,int r,int u,int v) {
    if(l <= tree[p].l && tree[p].r <= r) {
        tree[p].lst.push_back(make_pair(u,v));
        return ;
    }
    int mid = tree[p].l + tree[p].r >>1;
    if(l <= mid) change(p<<1,l,r,u,v);
    if(mid < r) change(p<<1|1,l,r,u,v);
}

struct bcj {
    int x,y,u,v;
};

int ans = 0;
stack<bcj> S;

int fa[SZ],sz[SZ],n;

int find(int x) { return x == fa[x] ? x : find(fa[x]); }

void merge(int x,int y) {
    int u = find(x),v = find(y);
    if(u == v) return ;
    if(sz[u] > sz[v]) swap(u,v),swap(x,y);
   // printf("merge:%d-%d\n",x,y);
    fa[u] = v; sz[v] += sz[u];
    S.push((bcj){x,y,u,v});
}

void dfs(int p) {
   // printf("[%d,%d]\n",tree[p].l,tree[p].r);
    for(int i = 0;i < tree[p].lst.size();i ++) {
        merge(tree[p].lst[i].first,tree[p].lst[i].second);
    }
    if(tree[p].l == tree[p].r) {
        int l = tree[p].l;
        if(find(1) == find(n)) {
          //  printf("success:%d %d\n",l,lsh[l+1]-lsh[l]);
            ans += lsh[l+1]-lsh[l];
        }
    }
    else {
        dfs(p<<1);
        dfs(p<<1|1);
    }
    for(int i = tree[p].lst.size()-1;i >= 0;i --) {
        if(S.size()) {
            int x = tree[p].lst[i].first,y = tree[p].lst[i].second;
            int xx = S.top().x,yy = S.top().y;
            if(x>y) swap(x,y);
            if(xx>yy) swap(xx,yy);
          //  printf("%d %d %d %d\n",x,y,xx,yy);
            if(x == xx && y == yy) {
           //     printf("del:%d-%d\n",x,y);
                bcj p = S.top(); S.pop();
                fa[p.u] = p.u;
                fa[p.v] = p.v;
                sz[p.v] -= sz[p.u];
            }
        }
    }
}

struct haha {
    int u,v,l,r;
}E[SZ];

int main() {
    n = read();
    int m = read();
    for(int i = 1;i <= n;i ++) fa[i] = i,sz[i] = 1;
    for(int i = 1;i <= m;i ++) {
        E[i].u = read();
        E[i].v = read();
        E[i].l = read();
        E[i].r = read();
        lsh[++ lsh[0]] = E[i].l;
        lsh[++ lsh[0]] = E[i].r;
        lsh[++ lsh[0]] = E[i].r+1;
    }
    sort(lsh+1,lsh+1+lsh[0]); lsh[0] = unique(lsh+1,lsh+1+lsh[0])-lsh-1;
    build(1,1,lsh[0]);
    for(int i = 1;i <= m;i ++) {
        E[i].l = lower_bound(lsh+1,lsh+1+lsh[0],E[i].l)-lsh;
        E[i].r = lower_bound(lsh+1,lsh+1+lsh[0],E[i].r)-lsh;
        change(1,E[i].l,E[i].r,E[i].u,E[i].v);
    }
    dfs(1);
    printf("%d\n",ans);
}

/**
5 5
1 2 1 9
2 3 1 7
3 5 2 9
2 4 1 8
4 5 3 9
*/
