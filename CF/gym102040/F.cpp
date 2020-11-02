#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 2e4 + 10;
const int mod = 1e7 + 7;

LL read() {
    LL n = 0;
    bool flag = 0;
    char a = getchar();
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}

vector<int> g[SZ];

int dfs_clock = 0,dfn[SZ],top[SZ],sz[SZ],son[SZ],deep[SZ],fa[SZ],K;

void dfs_1(int u,int f) {
    sz[u] = 1;
    deep[u] = deep[f] + 1;
    son[u] = 0;
    fa[u] = f;
    for(int v : g[u]) {
        if(v == f) continue;
        dfs_1(v,u);
        sz[u] += sz[v];
        if(!son[u] || (sz[son[u]] < sz[v])) son[u] = v;
    }
}

void dfs_2(int u,int topu) {
    dfn[u] = ++ dfs_clock;
    top[u] = topu;
    if(son[u]) dfs_2(son[u],topu);
    for(int v : g[u]) {
        if(v == fa[u] || v == son[u]) continue;
        dfs_2(v,v);
    }
}

int ask(int x,int y) {
    int fx = top[x],fy = top[y];
    while(fx != fy) {
        if(deep[fx] < deep[fy]) swap(x,y),swap(fx,fy);
        x = fa[fx]; fx = top[x];
    }
    if(deep[x] > deep[y]) swap(x,y);
    return x;
}

int main() {
    int T = read(),cc = 0;
    while(T --) {
        int n = read();
        dfs_clock = 0;
        for(int i = 1;i <= n;i ++) g[i].clear();
        for(int i = 1;i < n;i ++) {
            int x = read(),y = read();
            g[x].push_back(y);
            g[y].push_back(x);
        }
        dfs_1(1,0);
        dfs_2(1,1);
        printf("Case %d:\n",++ cc);
        int q = read();
        while(q --) {
            K = read();
            vector<pii> tmp;
            for(int i = 1;i <= K;i ++) {
                int x = read(),y = read();
                tmp.push_back(make_pair(x,y));
            }
            int a = tmp[0].first,b = tmp[0].second,flag = 0;
            for(int i = 1;i < K;i ++) {
                int x = tmp[i].first,y = tmp[i].second;
                int ab = ask(a,b),xy = ask(x,y);
                int ax = ask(a,x),ay = ask(a,y);
                int bx = ask(b,x),by = ask(b,y);
                if(ab == xy) {
                    if(ax == by && ay == bx) a = ax,b = by;
                    else if(ax == by) a = ay,b = bx;
                    else a = ax,b = by;
                }
                else {
                    if(deep[ab] == deep[xy]) { flag = 1; break; }
                    if(deep[ab] > deep[xy]) swap(a,x),swap(b,y);
                    ab = ask(a,b),xy = ask(x,y);
                    ax = ask(a,x),ay = ask(a,y);
                    bx = ask(b,x),by = ask(b,y);
                    int a_xy = ask(a,xy),b_xy = ask(b,xy);
                    if(a_xy != xy && b_xy != xy) { flag = 1; break; }
                    if(a_xy == xy) a = ax,b = ay;
                    else a = bx,b = by;
                }
            }
            if(flag) puts("0");
            else printf("%d\n",deep[a] + deep[b] - 2 * deep[ask(a,b)] + 1);
        }
    }
    return 0;
}
