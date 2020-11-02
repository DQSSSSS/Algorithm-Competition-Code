#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;

int dfn[SZ];
vector<int> leaf,g[SZ];

void dfs(int u,int fa) {
    dfn[++ dfn[0]] = u;
    if(g[u].size() == 1) leaf.push_back(u);
    for(int v : g[u]) {
        if(v == fa) continue;
        dfs(v,u);
    }
}


int main() {
    int n,root;
    scanf("%d%d",&n,&root);
    root ++;
    for(int i = 1;i < n;i ++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a ++; b ++;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(root,0);
    if(leaf.size() & 1) leaf.push_back(root);

    printf("%d\n",leaf.size() / 2);
    for(int i = 0;i < leaf.size() / 2;i ++) {
        printf("%d %d\n",leaf[i]-1,leaf[leaf.size()-i-1]-1);
    }

    return 0;
}

