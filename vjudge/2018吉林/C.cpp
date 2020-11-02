#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 2e5 + 10;

int bel[SZ],tot,sum,mark[SZ];
vector<int> g[SZ];

void dfs(int u,int c) {
    bel[u] = c;
    for(int v : g[u]) {
        dfs(v,c);
    }
}

int main() {
    int T,cc = 0;
    scanf("%d",&T);
    while(T --) {
        int n;
        scanf("%d",&n);
        for(int i = 1;i <= tot;i ++) {
            bel[i] = 0;
            mark[i] = 0;
            g[i].clear();
        }
        tot = n,sum = 0;

        priority_queue<pii> q;
        for(int i = 1;i <= n;i ++) {
            int x;
            scanf("%d",&x);
            q.push(make_pair(x,i));
        }
        while(q.size()) {
            pii p = q.top(); q.pop();
            if(p.first <= 1) { mark[p.second] = 1; sum ++; continue; }
            if(q.size()) {
                pii p2 = q.top(); q.pop();
                if(p2.first == p.first) {
                    pii ans = make_pair(p.first-1,++ tot);
                   //printf("%d -> %d\n",tot,p.second);
                   // printf("%d -> %d\n",tot,p2.second);
                    g[tot].push_back(p.second);
                    g[tot].push_back(p2.second);
                    q.push(ans);
                }
                else q.push(p2);
            }
        }
        if(sum < 2) {
            printf("Case %d: NO\n",++ cc);
        }
        else {
            printf("Case %d: YES\n",++ cc);
            int t = 0;
            for(int i = 1;i <= tot;i ++) {
                if(mark[i]) {
                    dfs(i,t);
                    if(t==0) t++;
                }
            }
            for(int i = 1;i <= n;i ++) printf("%d",bel[i]); puts("");
        }
    }
}
