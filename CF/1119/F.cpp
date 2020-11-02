#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 2000010;
const LL INF = 1e18 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-12;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

double usetime = 0;

int du[SZ],fa[SZ],fadist[SZ];
vector<int> nodes[SZ],g2[SZ];
vector<pii> g[SZ];
LL f[SZ][2];

struct seg {
    int l,r,sz;
    LL sum;
}tree[SZ];
int Tcnt = 0;

struct Segment {
    int root;
    void insert(int &p,int l,int r,int x,int d) {
        if(!p) { p = ++ Tcnt; tree[p]=(seg){0,0,0,0}; }
        tree[p].sz ++;
        tree[p].sum += d;
        if(l == r) { tree[p].sum = d; return ; }
        int mid = l + r >> 1;
        if(x <= mid) insert(tree[p].l,l,mid,x,d);
        else insert(tree[p].r,mid+1,r,x,d);
    }

    void insert(int id,int x,int d) {
        if(!id) return ;
        insert(root,1,du[id],x,d);
    }

    LL ask(int l,int r,int k) {
        if(k > tree[root].sz) return INF;
        if(k <= 0) return 0;
        int p = root;
        LL ans = 0;
        while(l != r) {
            int mid = l + r >> 1;
            if(tree[tree[p].l].sz >= k)
                r = mid,p = tree[p].l;
            else
                ans += tree[tree[p].l].sum,k -= tree[tree[p].l].sz,l = mid + 1,p = tree[p].r;
        }
        ans += k * tree[p].sum;
        return ans;
    }
    LL ask(int id,int k) {
        return ask(1,du[id],k);
    }
}st[SZ];


void dfs_pre(int u,int f) {
    fa[u] = f;
    for(pii e : g[u]) {
        int v = e.first;
        if(v == f) continue;
        fadist[v] = e.second;
        dfs_pre(v,u);
    }
}

#define min(x,y) (x<y?x:y)

void dfs(int u,int x) {
    vector<pli> a;
    f[u][0] = f[u][1] = 0;
    for(pii e : g[u]) {
        int v = e.first;
        if(v == fa[u]) continue;
        if(du[v] <= x) break;
        dfs(v,x);
        a.push_back(make_pair(f[v][1]+e.second-f[v][0],v));
        f[u][1] += min(f[v][0],f[v][1]+fadist[v]);
        f[u][0] += min(f[v][0],f[v][1]+fadist[v]);
    }
    //printf("%d %d %d %d %d\n",u,x,d,q1[u].size(),q2[u].size());
    sort(a.begin(),a.end());
    LL sum = 0;
    LL minn1 = st[u].ask(u,du[u]-x-1);
    LL minn0 = st[u].ask(u,du[u]-x);
   // cout << minn0 << " " << minn1 << endl;
    for(int i = 0;i < a.size();i ++) {
        int v = a[i].second;
        sum += f[v][1]+fadist[v] - min(f[v][0],f[v][1]+fadist[v]);
        minn1 = min(minn1,sum + st[u].ask(u,du[u]-x-1-i-1));
        minn0 = min(minn0,sum + st[u].ask(u,du[u]-x-i-1));
    }
    f[u][1] += minn1;
    f[u][0] += minn0;
    f[u][1] = min(f[u][1],f[u][0]);
   // cout << u << " " << f[u][0] << " " << f[u][1] << endl;
}

bool cmp(pii a,pii b) { return du[a.first] > du[b.first]; }

int main() {
    int n = read();
    LL sum = 0;
    for(int i = 1;i < n;i ++) {
        int x = read(),y = read(),d = read();
        du[x] ++; du[y] ++;
        g[x].push_back(make_pair(y,d));
        g[y].push_back(make_pair(x,d));
        g2[x].push_back(d);
        g2[y].push_back(d);
        sum += d;
    }
    dfs_pre(1,0);
    for(int i = 1;i <= n;i ++) {
        nodes[du[i]].push_back(i);
        sort(g[i].begin(),g[i].end(),cmp);
        sort(g2[i].begin(),g2[i].end());
    }

    set<int> root;
    root.insert(1);
    for(int x = 0;x < n;x ++) {

        for(int u : nodes[x]) {
            root.erase(u);
            int y = lower_bound(g2[fa[u]].begin(),g2[fa[u]].end(),fadist[u]) - g2[fa[u]].begin() + 1;
            st[fa[u]].insert(fa[u],y,fadist[u]);
            for(pii e : g[u]) {
                if(du[e.first] > x && e.first != fa[u])
                    root.insert(e.first);
            }
        }
        LL ans = 0;
        for(int u : root) {
            dfs(u,x);
            if(u == 1) ans += f[u][0];
            else ans += min(f[u][0],f[u][1] + fadist[u]);
        }
        printf("%lld ",ans);
    }
}

/**
10
1 2 1
1 3 5
1 4 3
3 5 3
3 6 4
7 3 2
10 7 9
9 6 6
6 8 10

8
2 1 10
3 1 4
4 3 3
5 2 9
6 1 7
7 2 6
8 4 5

44 23
*/
