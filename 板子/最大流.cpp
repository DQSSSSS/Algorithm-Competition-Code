#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 4001000;
const int INF = 1e9 + 10;
const int mod = 998244353;
const double PI = acos(-1);

LL read() {
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a <= '9' && a >= '0') n = n * 10 +a - '0',a = getchar();
	if(flag) n = -n;
	return n;
}

const int MAXN = 110;

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

int main() {
    int n = read(),m = read(),s = read(),e = read();
    mf.init(n);
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read();
        LL z = read();
        mf.insert(x,y,z);
    }
    printf("%lld\n",mf.dinic(s,e));
    return 0;
}
