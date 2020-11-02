#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;
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

/**
µã·ÖÊ÷Ì×Ïß¶ÎÊ÷

*/

vector<int> g[SZ];

int sz[SZ];
bool rt[SZ];

void dfs_sz(int u,int f) {
    sz[u] = 1;
    for(int v : g[u]) {
        if(rt[v] || v == f) continue;
        dfs_sz(v,u);
        sz[u] += sz[v];
    }
}

int get_centroid(int u) {
    dfs_sz(u,0);
    int s = sz[u];
    while(1) {
        int found = 1;
        for(int v : g[u]) {
            if(rt[v] || sz[v] > sz[u]) continue;
            if(sz[v] * 2 >= s) {
                u = v;
                found = 0;
                break;
            }
        }
        if(found) return u;
    }
}

struct SegmentTree {
    struct seg {
        int l,r;
        int minn;
    };

    vector<seg> tree;
    vector<int> a;

    void update(int p) {
        tree[p].minn = min(tree[p<<1].minn,tree[p<<1|1].minn);
    }

    void build(int p,int l,int r,const vector<pii> &nodes) {
        tree[p].l = l;
        tree[p].r = r;
        if(l == r) {
            tree[p].minn = nodes[l-1].second;
            return ;
        }
        int mid = l + r >> 1;
        build(p<<1,l,mid,nodes);
        build(p<<1|1,mid+1,r,nodes);
        update(p);
    }

    int ask(int p,int l,int r) {
        if(l <= tree[p].l && tree[p].r <= r)
            return tree[p].minn;
        int mid = tree[p].l + tree[p].r >> 1,ans = 1e9;
        if(l <= mid) ans = min(ans,ask(p<<1,l,r));
        if(mid < r) ans = min(ans,ask(p<<1|1,l,r));
        return ans;
    }

    SegmentTree() { a.clear(); tree.clear(); }
    SegmentTree(const vector<pii> &nodes) {
        int n = nodes.size();
        tree.resize((n+1)*4);
        a.resize(n);
        for(int i = 0;i < nodes.size();i ++)
            a[i] = nodes[i].first;
        build(1,1,n,nodes);
    }
} st[SZ];

vector<pii> nodes;

void dfs_dist(int u,int fa,int d) {
    nodes.push_back(make_pair(u,d));
    for(int v : g[u]) {
        if(rt[v] || v == fa) continue;
        dfs_dist(v,u,d+1);
    }
}

vector<pii> an[SZ];

void process(int u) {
    nodes.clear();
    dfs_dist(u,0,0);
    for(pii p : nodes) {
        int x = p.first,dis = p.second;
        an[x].push_back(make_pair(u,dis));
    }
    sort(nodes.begin(),nodes.end());
    st[u] = SegmentTree(nodes);
}

void dfs(int u,int lst) {
    u = get_centroid(u);
    process(u);
    rt[u] = 1;
    for(int v : g[u]) {
        if(rt[v]) continue;
        dfs(v,u);
    }
}

int ask(int u,int l,int r) {
    int ans = 1e9;
    for(pii p : an[u]) {
        int x = p.first;
        int ll = lower_bound(st[x].a.begin(),st[x].a.end(),l) - st[x].a.begin() + 1;
        int rr = upper_bound(st[x].a.begin(),st[x].a.end(),r) - st[x].a.begin();
        if(ll <= rr) {
            ans = min(ans,p.second + st[x].ask(1,ll,rr));
        }
    }
    return ans;
}

int l[SZ],r[SZ],tim[SZ];

int main() {
    int T = read();
    for(int cc = 1;cc <= T;cc ++) {
        int n = read();
        for(int i = 1;i <= n;i ++) g[i].clear(),st[i] = SegmentTree(),rt[i] = 0,an[i].clear();
        for(int i = 1;i < n;i ++) {
            int x = read(),y = read();
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs(1,0);
//        for(int i = 1;i <= n;i ++) printf("%d ",fa[i].first); puts("");
 //       for(int i = 1;i <= n;i ++) printf("%d ",fa[i].second); puts("");
        int m = read();
        printf("Case %d:\n",cc);
        for(int i = 1;i <= m;i ++) {
            int opt = read();
            if(opt == 1) {
                int x = read();
                l[x] = read(),r[x] = read();
                tim[x] = cc;
            }
            else if(opt == 2) {
                int x = read();
                tim[x] = 0;
            }
            else {
                int x = read();
                int k = read();
                int ans = n;
                while(k --) {
                    int num = read();
                    if(tim[num] != cc) continue;
                //    cout << num << endl;
                    ans = min(ans,ask(x,l[num],r[num]));
                }
                if(ans == n) ans = -1;
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
/**
2
6
1 4
1 5
1 6
5 2
5 3
4
1 1 2 3
3 5 1 1
2 1
3 4 1 1
2
1 2
2
1 100000 1 1
3 2 1 100000


233
12
1 12
9 12
12 10
10 7
10 3
3 8
3 2
10 6
6 11
6 5
11 4

233

*/
