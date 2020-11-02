#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 35010 + 10;

vector<int> g[SZ];
int dist[SZ],n,m,k;

int bfs(int s) {
    for(int i = 1;i <= n;i ++) dist[i] = -1;
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int v : g[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    int id = 0;
    for(int i = 1;i <= n;i ++) {
        if(id == 0 || dist[i] > dist[id]) id = i;
    }
    return id;
}

int main() {
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i <= m;i ++) {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int d = 0;
    for(int i = 1;i <= n;i ++) {
        int e = bfs(i);
        d = max(d,dist[e]);
    }
    if(n >= 2&& d <= n - k) {
        printf("%d\n",n);
        for(int i = 1;i <= n;i ++) printf("%d ",i);
        return 0;
    }
    puts("0");
}

/*
7 6 2
1 2
2 3
3 4
4 5
5 6
6 7
*/
