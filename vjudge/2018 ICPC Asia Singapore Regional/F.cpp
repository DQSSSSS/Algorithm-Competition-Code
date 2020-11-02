#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;

struct seg {
    int l,r,mn;
}tree[SZ * 4];

void update(int p) {
    tree[p].mn = min(tree[p<<1].mn,tree[p<<1|1].mn);
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    if(l == r) {
        tree[p].mn = INF;
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    update(p);
}

void change(int p,int x,int d) {
    if(tree[p].l == tree[p].r) {
        tree[p].mn = min(tree[p].mn,d);
        return ;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    if(x <= mid) change(p<<1,x,d);
    else change(p<<1|1,x,d);
    update(p);
}

int ask(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p].mn;
    }
    int mid = tree[p].l + tree[p].r >> 1;
    int ans = INF;
    if(l <= mid) ans = min(ans,ask(p<<1,l,r));
    if(mid < r) ans = min(ans,ask(p<<1|1,l,r));
    return ans;
}

vector<int> g[SZ];
vector<pii> a[SZ];

int main() {
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++) {
        int x;
        scanf("%d",&x);
        g[x].push_back(i);
    }
    build(1,1,n);
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j < g[i].size();j ++) {
            int l = g[i][j-1];
            int r = g[i][j];
            a[l].push_back(make_pair(r,i));
        }
    }

    pii ans = make_pair(INF,INF);
    for(int i = 1;i <= n;i ++) {
        for(pii p : a[i]) {
            int y = p.second;
            int l = i + 1,r = p.first - 1;
            if(l <= r) {
                int x = ask(1,l,r);
                pii tmp = make_pair(x,y);
                if(tmp < ans) ans = tmp;
            }
            change(1,r+1,y);
        }
    }

    if(ans.first == INF) return puts("-1"),0;
    printf("%d %d\n",ans.first,ans.second);
}
