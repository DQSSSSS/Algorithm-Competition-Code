#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e6 + 3;
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
    pii mx;
    int add;
}tree[SZ * 4];

void update(int p) {
    tree[p].mx = max(tree[p<<1].mx,tree[p<<1|1].mx);
}

void build(int p,int l,int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].add = 0;
    if(l == r) {
        tree[p].mx = make_pair(0,l);
        return ;
    }
    int mid = l + r >> 1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    update(p);
}

void pushadd(int p,int d) {
    tree[p].mx.first += d;
    tree[p].add += d;
}

void pushdown(int p) {
    if(tree[p].add) {
        pushadd(p<<1,tree[p].add);
        pushadd(p<<1|1,tree[p].add);
        tree[p].add = 0;
    }
}

pii ask(int p,int l,int r) {
    if(l <= tree[p].l && tree[p].r <= r) {
        return tree[p].mx;
    }
    pushdown(p);
    int mid = tree[p].l + tree[p].r >> 1;
    pii ans = make_pair(0,0);
    if(l <= mid) ans = max(ans,ask(p<<1,l,r));
    if(mid < r) ans = max(ans,ask(p<<1|1,l,r));
    return ans;
}

void change(int p,int l,int r,int d) {
    if(l>r) return ;
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

vector<int> pos[SZ];
int nx[SZ],nxk[SZ],a[SZ];
int n,C,K;

int baoli() {
    int ans = 0;
    for(int i = 1;i <= n;i ++) {
        int tim[C+2] = {};
        for(int j = i;j <= n;j ++) {
            tim[a[j]] ++;
            bool flag = 0;
            for(int k = 1;k <= C;k ++) {
                if(tim[k] && tim[k] < K) flag = 1;
            }
            if(!flag) ans = max(ans,j-i+1);
        }
    }
    return ans;
}

int main() {
    while(scanf("%d%d%d",&n,&C,&K)!=EOF) {
        for(int i = 1;i <= n;i ++) a[i] = read();
        if(K <= 1) { printf("%d\n",n); continue; }

        build(1,1,n);
        for(int i = 1;i <= C;i ++) pos[i].clear();
        for(int i = 1;i <= n;i ++) pos[a[i]].push_back(i);
        for(int i = 1;i <= C;i ++) {
            for(int j = 0;j < pos[i].size();j ++) {
                int now = pos[i][j];
                nxk[now] = j+K-1<pos[i].size() ? pos[i][j+K-1] : n+1;
                nx[now] = j+1<pos[i].size() ? pos[i][j+1] : n+1;
            }
            if(pos[i].size()) change(1,1,pos[i][0]-1,1);
            if(pos[i].size()>=K) change(1,pos[i][K-1],n,1);
            if(pos[i].size() == 0) change(1,1,n,1);
        }

     //   for(int i = 1;i <= n;i ++) printf("%d ",nx[i]); puts("");
     //   for(int i = 1;i <= n;i ++) printf("%d ",nxk[i]); puts("");

        int ans = 0;
        for(int l = 1;l <= n;l ++) {
            pii p = ask(1,l,n);
            if(p.first == C) ans = max(ans,p.second-l+1);
            change(1,l+1,nx[l]-1,1);
            if(nxk[l] <= n) change(1,nxk[l],nx[nxk[l]]-1,-1);
        }

        printf("%d\n",ans);
      //  printf("%d\n",baoli());
    }
}
/**
5 3 2
1 3 2 1 2
*/
