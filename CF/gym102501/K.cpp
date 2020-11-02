#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 100010;
const int INF = 1e9 + 10;
const int mod = 1e9+7;
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

vector<pii> G[SZ];

int n,m,s,vis[SZ],mark[SZ];

void bfs(int s) {
    for(int i = 0;i < n;i ++) vis[i] = 0;
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = 0;i < G[u].size();i ++) {
            if(G[u][i].second) {
                int v = G[u][i].first;
                if(!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    for(int i = 0;i < G[s].size();i ++) {
        int v = G[s][i].first;
        if(G[s][i].second == 0 && vis[v])
            mark[G[s][i].first] = 0;
    }
}

int main() {
    n = read(),m = read(),s = read();
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read();
        G[y].push_back({x,1});
    }
    for(int i = 0;i < G[s].size();i ++) {
        mark[G[s][i].first] = 1;
    }
    for(int cc = 1;cc <= 50;cc ++) {
        for(int i = 0;i < G[s].size();i ++) {
            G[s][i].second = rand()%2;
        }
        bfs(s);
        for(int i = 0;i < G[s].size();i ++) {
            G[s][i].second = 1;
        }
    }

    int sum = 0;
    sort(G[s].begin(),G[s].end());
    for(int i = 0;i < G[s].size();i ++) {
        int v = G[s][i].first;
        if(mark[v]) sum ++;
    }
    printf("%d\n",sum);
    for(int i = 0;i < G[s].size();i ++) {
        int v = G[s][i].first;
        if(mark[v]) printf("%d\n",v);
    }
}
