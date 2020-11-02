#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

const int dx[] = {-4,-2,-2,2,2,4};
const int dy[] = {0,-6,6,-6,6,0};
const int ddx[] = {-2,-1,-1,1,1,2};
const int ddy[] = {0,-3,3,-3,3,0};

int a[6010][6010];
char mp[6010][6010];
vector<int> g[SZ];
int dist[SZ],tot;
queue<int> q;

int bfs(int s,int e) {
    for(int i = 1;i <= tot;i ++) dist[i] = -1;
    dist[s] = 0;
    while(q.size()) q.pop();
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
    return dist[e];
}

int main() {
    int T = read();
    while(T --) {
        int n = read(),m = read();
        for(int i = 1;i <= 4*n+3;i ++) {
            fgets(mp[i] + 1,6*m+10,stdin);
        }
        for(int i = 1;i <= 4*n+3;i ++) {
            for(int j = 1;j <= 6*m+3;j ++) {
                a[i][j] = 0;
            }
        }
        for(int i = 1;i <= tot;i ++) g[i].clear();
        tot = 0;

        for(int i = 3,ii = 1,j;i <= 4*n+3;i += 2,ii ++) {
            if(ii & 1) j = 5;
            else j = 11;
            for(;j <= 6*m+3;j += 12) {
                a[i][j] = ++ tot;
            }
        }

        int s,t;
        for(int i = 3,ii = 1,j;i <= 4*n+3;i += 2,ii ++) {
            if(ii & 1) j = 5;
            else j = 11;
            for(;j <= 6*m+3;j += 12) {
                if(mp[i][j] == 'S') s = a[i][j];
                if(mp[i][j] == 'T') t = a[i][j];
                for(int k = 0;k < 6;k ++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x >= 1 && x <= 4*n+3 && y >= 1 && y <= 6*m+3 && a[x][y]) {
                        if(mp[i+ddx[k]][j+ddy[k]] == ' ') {
                            g[a[i][j]].push_back(a[x][y]);
                        }
                    }
                }
            }
        }
        int ans = bfs(s,t);
        if(ans != -1) ans ++;
        printf("%d\n",ans);
    }
}

