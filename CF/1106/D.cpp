#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000100;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-12;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

vector<int> g[SZ];

int path[SZ],t = 0,n,m;
bool vis[SZ];

priority_queue<int> q;

int main() {
    n = read(),m = read();
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    q.push(-1);
    while(q.size()) {
        int u = -q.top(); q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        path[++ path[0]] = u;
        for(int i = 0;i < g[u].size();i ++) {
            int v = g[u][i];
            if(vis[v]) continue;
            q.push(-v);
        }
    }
    for(int i = 1;i <= path[0];i ++) printf("%d ",path[i]);
    return 0;
}
