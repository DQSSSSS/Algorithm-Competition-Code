#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ= 1e5 + 10;

vector<int> g[SZ];
int a[SZ];
int sz[SZ],dfs_clock,trie_tot;
int rt[SZ];
int dfn[SZ];

struct Trie {
    int ch[2];
    int sz;
}tree[5000010];

void insert(int p,int lst,int &now,int x) {
    now = ++ trie_tot;
    tree[now] = tree[lst];
    tree[now].sz ++;
    if(p == -1) return ;
    int c = x >> p & 1;
    insert(p-1,tree[lst].ch[c],tree[now].ch[c],x);
}

void dfs(int u,int fa) {
    insert(30,rt[dfs_clock],rt[dfs_clock+1],a[u]);
    dfn[u] = ++ dfs_clock;
    sz[u] = 1;
    for(int v : g[u]) {
        dfs(v,u);
        sz[u] += sz[v];
    }
}

int ask(int l,int r,int x) {
    //cout << l <<" " << r <<" " << x <<  endl;
    int rl = rt[l-1],rr = rt[r];
    int ans = 0;
    for(int p = 30;p >= 0;p --) {
        int c = x >> p & 1;
        int sz = tree[tree[rr].ch[c^1]].sz - tree[tree[rl].ch[c^1]].sz;
        if(sz) {
            ans |= 1<<p,rr = tree[rr].ch[c^1],rl = tree[rl].ch[c^1];
        }
        else rr = tree[rr].ch[c],rl = tree[rl].ch[c];
    }
    return ans;
}

int main() {
    int n,q;
    while(~scanf("%d%d",&n,&q)) {
        for(int i = 1;i <= n;i ++) {
            g[i].clear();
            rt[i] = 0;
        }
        dfs_clock = 0;
        for(int i = 0;i <= trie_tot;i ++) {
            tree[i].ch[0] = 0;
            tree[i].ch[1] = 0;
            tree[i].sz = 0;
        }
        trie_tot = 0;

        for(int i = 1;i <= n;i ++) scanf("%d",&a[i]);
        for(int i = 2;i <= n;i ++) {
            int x;
            scanf("%d",&x);
            g[x].push_back(i);
        }
        dfs(1,0);
        while(q --) {
            int u,x;
            scanf("%d%d",&u,&x);
            printf("%d\n",ask(dfn[u],dfn[u]+sz[u]-1,x));
        }
    }
}


