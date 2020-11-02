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

vector<int> g[SZ];

int sz[SZ];
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

int val[SZ];

struct SegmentTree {
    vector<int> t1,t2;
    map<int,int> mp1,mp2;

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

    SegmentTree() { t1.clear(); t2.clear(); mp1.clear(); mp2.clear(); }
    SegmentTree(const vector<pii> &nodes,const vector<pii> &nodes2) {
        int n = 0,n2 = 0;
        for(int i = 0;i < nodes.size();i ++) {
            mp1[nodes[i].first] = nodes[i].second;
            if(nodes2.size()) mp2[nodes2[i].first] = nodes2[i].second;
            n = max(n,nodes[i].second);
            if(nodes2.size()) n2 = max(n2,nodes2[i].second);
        }
        t1.resize(n+2);
        if(nodes2.size()) t2.resize(n2+2);
        for(int i = 0;i < nodes.size();i ++) {
            add(t1,nodes[i].second,val[nodes[i].first]);
            if(nodes2.size()) add(t2,nodes2[i].second,val[nodes2[i].first]);
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

void change(int u,int y) {
    for(int i = 0;i < an[u].size();i ++) {
        pii p = an[u][i];
        int x = p.first,d = p.second;
        int id = st[x].mp1[u];
        st[x].add(st[x].t1,id,-val[u]);
        st[x].add(st[x].t1,id,y);
        id = st[x].mp2[u];
        st[x].add(st[x].t2,id,-val[u]);
        st[x].add(st[x].t2,id,y);
    }
    val[u] = y;
}

int main() {
    int __size__=128<<20;
    char*__p__=(char*)malloc(__size__)+ __size__;
    __asm__("movl %0, %%esp\n"::"r"(__p__));
    freopen("3730/10.in","r",stdin);
    freopen("3730/my.out","w",stdout);
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++) val[i] = read();
    for(int i = 1;i < n;i ++) {
        int x = read(),y = read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    int lstans = 0;
    for(int i = 1;i <= m;i ++) {
        int opt = read(),x = read(),y = read();
        x ^= lstans;
        y ^= lstans;
        if(opt == 1) {
            change(x,y);
        }
        else {
            printf("%d\n",lstans = ask(x,y));
        }
    }
    return 0;
}

/**
8 233
1 10 100 1000 10000 100000 1000000 10000000
1 2
1 3
2 4
2 5
3 6
3 7
3 8
0 5 3
*/
