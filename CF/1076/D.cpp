#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000100;
const LL INF = 1e18 + 10;
const int mod = 998244353;
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

int n,m,k;
LL dist[SZ];
bool vis[SZ];
struct edge {
    int t,d,id;
};

vector<edge> g[SZ];

struct Heap {
    int u; LL d;
};

bool operator <(Heap a,Heap b) { return a.d > b.d; }

priority_queue<Heap> q;
int pre[SZ];

void dij(int s) {
    for(int i = 1;i <= n;i ++) dist[i] = INF;
    dist[s] = 0;
    q.push((Heap){s,0});
    while(q.size()) {
        int u = q.top().u; q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = 0;i < g[u].size();i ++) {
            int v = g[u][i].t;
            if(dist[v] > dist[u] + g[u][i].d) {
                dist[v] = dist[u] + g[u][i].d;
                pre[v] = g[u][i].id;
                q.push((Heap){v,dist[v]});
            }
        }
    }
}

vector<int> ans;

void dfs(int u) {
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i].t;
        if(k) {
          //  cout << k << " " << u << " " << v << endl;
            k --;
            ans.push_back(g[u][i].id);
        }
        else return ;
        dfs(v);
    }
}

struct haha {
    int f,t;
}l[SZ];

int main() {
    n = read(),m = read(),k = read();
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read(),z = read();
        g[x].push_back((edge){y,z,i});
        g[y].push_back((edge){x,z,i});
        l[i].f = x;
        l[i].t = y;
    }
    dij(1);
    for(int i = 1;i <= n;i ++) g[i].clear();
    for(int i = 2;i <= n;i ++) {
        int x = l[pre[i]].f;
        int y = l[pre[i]].t;
        if(x == i) x = y;
        g[x].push_back((edge){i,0,pre[i]});
    }
    dfs(1);
    cout << ans.size() << endl;
    for(int i = 0;i < ans.size();i ++) cout << ans[i] << " ";
    return 0;
}
