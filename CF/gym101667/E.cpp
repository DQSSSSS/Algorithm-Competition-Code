#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 3e5 + 10;
const int INF = 1e9 + 10;

struct MF {
    struct edge {
        int t,d,rev;
    };
    vector<edge> G[SZ];

    void insert(int f,int t,int d) {
        G[f].push_back((edge){t,d,(int)G[t].size()});
        G[t].push_back((edge){f,d,(int)G[f].size()-1});
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

    int dfs(int u,int flow,int t) {
        if(flow == 0 || t == u) return flow;
        int ans = flow;
        for(edge &e : G[u]) {
            int v = e.t;
            if(e.d && deep[v] == deep[u] + 1) {
                int f = dfs(v,min(ans,e.d),t);
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

    int dinic(int s,int t) {
        int ans = 0;
        while(bfs(s,t)) {
            int tt = dfs(s,INF,t);
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


int n,m,Ans[SZ];
struct edge {
    int f,t,d,id;
}e[SZ];

int work(int id) {
    mf.init(n);
  //  cout << id << endl;
    for(int i = 1;i <= m;i ++) {
        if(e[i].d < e[id].d) {
            mf.insert(e[i].f,e[i].t,1);
        //    mf.insert(e[i].t,e[i].f,1);
       //     printf("%d %d\n",e[i].f,e[i].t);
        }
    }
    return mf.dinic(e[id].f,e[id].t);
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= m;i ++) {
        scanf("%d%d%d",&e[i].f,&e[i].t,&e[i].d);
        e[i].id = i;
    }
    int ans = 0;
   // work(m);
    for(int i = 1;i <= m;i ++) ans += Ans[e[i].id] = work(i);
   // for(int i = 1;i <= m;i ++) printf("%d ",Ans[i]); puts("");
    cout << ans << endl;
}
