#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
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

vector<int> g[SZ];

int sz[SZ],NNN;
bool rt[SZ];

void dfs_sz(int u,int f) {
    sz[u] = 1;
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i];
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
        for(int i = 0;i < g[u].size();i ++) {
            int v = g[u][i];
            if(rt[v] || sz[v] > sz[u]) continue;
            if(sz[v] * 2 >= s) {
                u = v;
                found = 0;
                break;
            }
        }
        if(found) return u;
    }
    assert(0);
}

struct SegmentTree {
    vector<int> t1,t2;

    void add(vector<int> &tree,int x,int d) {
        int n = tree.size()-1;
        x ++;
        if(x >= tree.size()) return ;
        for(int i = x;i <= n;i += i & -i) tree[i] += d;
    }

    int ask(vector<int> &tree,int x) {
        int ans = 0;
        x ++;
        x = min(x,(int)tree.size()-1);
        for(int i = x;i > 0;i -= i & -i) ans += tree[i];
        return ans;
    }

    SegmentTree() { t1.clear(); t2.clear();  }
    SegmentTree(const vector<pii> &nodes,const vector<pii> &nodes2) {
        int n = 0,n2 = 0;
        for(int i = 0;i < nodes.size();i ++) {
            n = max(n,nodes[i].second);
            if(nodes2.size()) n2 = max(n2,nodes2[i].second);
        }
        t1.resize(n+2);
        if(nodes2.size()) t2.resize(n2+2);
        for(int i = 0;i < nodes.size();i ++) {
          //  printf("%d %d %d\n",nodes[i].first,NNN,nodes[i].first <= NNN);
            add(t1,nodes[i].second,nodes[i].first <= NNN);
            if(nodes2.size()) add(t2,nodes2[i].second,nodes2[i].first <= NNN);
        }
    }
} st[SZ];

vector<pii> nodes,nodes2;
int mark[SZ];

void dfs_dist(int u,int fa,int d,int c) {
    mark[u] = c;
    nodes.push_back(make_pair(u,d));
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i];
        if(rt[v] || v == fa) continue;
        dfs_dist(v,u,d+1,c);
    }
}

void dfs_dist2(int u,int fa,int d) {
    nodes2.push_back(make_pair(u,d));
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i];
        if(rt[v] || v == fa) continue;
        dfs_dist2(v,u,d+1);
    }
}

vector<pii> an[SZ];

void process(int u,int lst) {
    nodes.clear();
    nodes2.clear();
    dfs_dist(u,0,0,u);
    for(int i = 0;i < g[lst].size();i ++) {
        int v = g[lst][i];
        if(mark[v] == u) {
            dfs_dist2(v,0,1);
            break;
        }
    }
    for(int i = 0;i < nodes.size();i ++) {
        pii p = nodes[i];
        int x = p.first,dis = p.second;
        an[x].push_back(make_pair(u,dis));
    }
    //printf("%d\n",u);
    st[u] = SegmentTree(nodes,nodes2);
}

void dfs(int u,int lst) {
    u = get_centroid(u);
    process(u,lst);
    rt[u] = 1;
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i];
        if(rt[v]) continue;
        dfs(v,u);
    }
}

int ask(int u,int k) {
    int ans = 0;
    for(int i = 0;i < an[u].size();i ++) {
        pii p = an[u][i];
        int x = p.first,d = p.second;
        if(k >= d) ans += st[x].ask(st[x].t1,k - d);
        if(i && k >= an[u][i-1].second) ans -= st[x].ask(st[x].t2,k - an[u][i-1].second);
    }
    return ans;
}

int top[SZ],dfs_clock,deep[SZ],son[SZ],fa[SZ];

void dfs_lca1(int u,int f) {
    deep[u] = deep[f] + 1;
    fa[u] = f;
    sz[u] = 1;
    son[u] = 0;
    for(int v : g[u]) {
        if(v == f) continue;
        dfs_lca1(v,u);
        sz[u] += sz[v];
        if(!son[u] || sz[son[u]] < sz[v]) son[u] = v;
    }
}

void dfs_lca2(int u,int topu) {
    dfn[u] = ++ dfs_clock;
    top[u] = topu;
    if(!son[u]) return ;
    dfs_lca2(son[u],topu);
    for(int v : g[u]) {
        if(v == f || v == son[u]) continue;
        dfs_lca2(v,u);
    }
}

int ask_lca(int x,int y) {
    while(top[x]^top[y]) deep[top[x]]<deep[top[y]]?y=fa[top[y]]:x=fa[top[x]];
    return deep[x]<deep[y]?x:y;
}

int main() {
    int T = read();
    while(T --) {
        int n = read();
        int m = read();
        NNN = n;
        for(int i = 1;i <= 2*n;i ++) {
            rt[i] = 0;
            g[i].clear();
            an[i].clear();
            mark[i] = 0;
            st[i] = SegmentTree();
            for(int j = 0;j <= 20;j ++) anc[i][j] = 0;
        }

        for(int i = 1;i < n;i ++) {
            int x = read(),y = read();
            g[x].push_back(i+n);
            g[i+n].push_back(x);
            g[y].push_back(i+n);
            g[i+n].push_back(y);
        }
        dfs(1,0);
        dfs_lca1(1,0);
        dfs_lca2(1,1);

        int lstans = 0;
        for(int i = 1;i <= m;i ++) {
            int x = read(),y = read(),w = read();
            x = (x + lstans) % n + 1;
            y = (y + lstans) % n + 1;
            w = (w + lstans) % n;

            int lca = ask_lca(x,y),mid = -1;
            int dist = deep[x] + deep[y] - 2 * deep[lca];
            int a = 0,b = 0,c = 0;
            if(dist > 2 * w) a = ask(x,2*w),b = ask(y,2*w);
            else {
                if(deep[x] < deep[y]) swap(x,y);
                mid = x;
                dist /= 2;
                for(int j = 20;j >= 0;j --)
                    if(dist >> j & 1)
                        mid = anc[mid][j];
                a = ask(x,2*w),b = ask(y,2*w);
                c = ask(mid,(2*w-dist));
            }

          //  cout << x << " " << y << " " << w << " " << mid << " " << 2*w-dist << endl;
         //   cout << a << " " << b << " " << c << endl;
            printf("%d\n",lstans = a + b - c);
        }
    }
    return 0;
}

/**
1
5 5
1 2
2 3
2 4
3 5
1 2 1
*/
