#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 5e6 + 10;
const LL INF = 1e9 + 10;
const LD eps = 1e-8;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

const int MAXN = 210;

struct max_flow {

    struct edge {
        int t;
        LL d;
        int rev;
    };
    vector<edge> G[MAXN];

    void insert(int f,int t,LL d) {
        G[f].push_back((edge){t,d,(int)G[t].size()});
        G[t].push_back((edge){f,0,(int)G[f].size()-1});
    }

    int n,deep[MAXN];
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
        if(u == t || flow == 0) return flow;
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
            LL tmp = dfs(s,INF,t);
            if(tmp == 0) break;
            ans += tmp;
        }
        return ans;
    }

    void init(int nn) {
        n = nn;
        for(int i = 0;i <= nn;i ++) G[i].clear();
    }
}mf;

int X1[SZ],X2[SZ];
int Y1[SZ],Y2[SZ];
int mp[111][111];
int lshx[111];
int lshy[111];

int main() {
    int n = read(),m = read();
    for(int i = 1;i <= m;i ++) {
        X1[i] = read(),Y1[i] = read();
        X2[i] = read()+1,Y2[i] = read()+1;
        lshx[++ lshx[0]] = X1[i];
        lshx[++ lshx[0]] = X2[i];
        lshy[++ lshy[0]] = Y1[i];
        lshy[++ lshy[0]] = Y2[i];
    }
    lshx[++ lshx[0]] = n+1;
    lshy[++ lshy[0]] = n+1;
    sort(lshx+1,lshx+1+lshx[0]); lshx[0] = unique(lshx+1,lshx+1+lshx[0])-lshx-1;
    sort(lshy+1,lshy+1+lshy[0]); lshy[0] = unique(lshy+1,lshy+1+lshy[0])-lshy-1;
    for(int i = 1;i <= m;i ++) {
        int lx = lower_bound(lshx+1,lshx+1+lshx[0],X1[i]) - lshx;
        int rx = lower_bound(lshx+1,lshx+1+lshx[0],X2[i]) - lshx-1;

        int ly = lower_bound(lshy+1,lshy+1+lshy[0],Y1[i]) - lshy;
        int ry = lower_bound(lshy+1,lshy+1+lshy[0],Y2[i]) - lshy-1;

        for(int x = lx;x <= rx;x ++)
            for(int y = ly;y <= ry;y ++)
                mp[x][y] = 1;
    }
    int s = lshx[0] + lshy[0] + 1,e = s + 1;
    mf.init(e);
    for(int i = 1;i < lshx[0];i ++) mf.insert(s,i,lshx[i+1]-lshx[i]);
    for(int i = 1;i < lshy[0];i ++) mf.insert(i+lshx[0],e,lshy[i+1]-lshy[i]);
    for(int i = 1;i < lshx[0];i ++)
        for(int j = 1;j < lshy[0];j ++)
            if(mp[i][j])
                mf.insert(i,j+lshx[0],INF);
    cout << mf.dinic(s,e);
}
