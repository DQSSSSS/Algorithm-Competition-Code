#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 5e5 + 10;
const int mod = 1e9 + 7;
const int INF = 1e9 + 10;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a<'0'||a>'9') { if(a=='-') flag=1; a=getchar(); }
    while(a>='0'&&a<='9') { n=n*10+a-'0'; a=getchar(); }
    if(flag) n=-n;
    return n;
}

const int MAXN = 200010;
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

int n,m;

int id(int i,int j) {
    return (i-1)*m+j;
}

char mp[33][33];

int main() {
    n = read(),m = read();
    for(int i = 1;i <= n;i ++) scanf("%s",mp[i]+1);
    int s = n*m+1;
    int t = s+1;
    int tot1 = 0;
    int tot2 = 0;
    mf.init(t);
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++) {
            if(i+j&1) {
                if(mp[i][j] == 'o') mf.insert(s,id(i,j),1),tot1 ++;
                else mf.insert(s,id(i,j),2),tot1 += 2;
                if(i<n) mf.insert(id(i,j),id(i+1,j),INF);
                if(j<m) mf.insert(id(i,j),id(i,j+1),INF);
                if(i>1) mf.insert(id(i,j),id(i-1,j),INF);
                if(j>1) mf.insert(id(i,j),id(i,j-1),INF);
            }
            else {
                if(mp[i][j] == 'o') mf.insert(id(i,j),t,1),tot2 ++;
                else mf.insert(id(i,j),t,2),tot2 += 2;
            }
        }
    LL ans = mf.dinic(s,t);
    if(tot1 != tot2 || tot1 != ans) puts("N");
    else puts("Y");
}
