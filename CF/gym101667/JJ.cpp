#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;

struct MF {
    struct edge {
        int t;
        LL d;
        int rev;
    };
    vector<edge> G[SZ];

    void insert(int f,int t,LL d) {
        G[f].push_back((edge){t,d,(int)G[t].size()});
        G[t].push_back((edge){f,0,(int)G[f].size()-1});
    }

    int n,deep[SZ];

    bool bfs(int s,int t) {
        for(int i = 1;i <= n;i ++) deep[i] = 0;
        deep[s] = 1;
        queue<int> q; q.push(s);
        while(q.size()) {
            int u = q.front(); q.pop();
            for(edge &e : G[u]) {
                int v = e.t;
                if(e.d && !deep[v]) {
                    deep[v] = deep[u] + 1;
                    if(v == t) return true;
                    q.push(v);
                }
            }
        }
        return false;
    }

    LL dfs(int u,LL flow,int t) {
        if(flow == 0 || t == u) return flow;
        LL ans = flow;
        for(edge &e : G[u]) {
            int v = e.t;
            if(e.d && deep[v] == deep[u] + 1) {
                LL f = dfs(v,min(ans,e.d),t);
                if(f > 0) {
                    e.d -= f; G[v][e.rev].d += f;
                    ans -= f;
                    if(ans == 0) break;
                }
                else deep[v] = 0;
            }
        }
        if(ans == flow) deep[u] = 0;
        return flow - ans;
    }

    LL dinic(int s,int t) {
        LL ans = 0;
        while(bfs(s,t)) {
            LL tt = dfs(s,INF,t);
            if(tt == 0) break;
            ans += tt;
        }
        return ans;
    }

    void init(int nn) {
        n = nn;
        for(int i = 0;i <= n;i ++) G[i].clear();
    }
}mf;

int n,m,ff[SZ],tt[SZ];

int main() {
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= m;i ++) {
        scanf("%d%d",&ff[i],&tt[i]);
    }
    if(n == 2) {
        for(int i = 1;i <= m;i ++)
            if(ff[i] != tt[i])
                return puts("1"),0;
        return puts("-1"),0;
    }

    int oo = 1e5;
    for(int l = 2;l <= n;l ++) {
        for(int s = 1;s < l;s ++) {
            int t = l;
            mf.init(2*n);
            for(int i = 1;i <= n;i ++) {
                if(i==s||i==t) mf.insert(i,i+n,oo);
                else mf.insert(i,i+n,1);
            }
            for(int i = 1;i <= m;i ++) {
                int x = ff[i],y = tt[i];
                if(x == y) continue;
                mf.insert(x+n,y,oo);
                mf.insert(y+n,x,oo);
            }
            LL d = mf.dinic(s,t);
           // cout << s << " "<< t << " " << d << endl;
            if(d < n/2) return puts("-1"),0;
        }
    }
    puts("1");
}

/*

4 3
1 2
2 3
3 4

*/

