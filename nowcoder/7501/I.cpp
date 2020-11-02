#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 2e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

char mp[1010][1010];

void getNext(int x,int y,int &nx,int &ny) {
    if(mp[x][y] == 'W') nx=x-1,ny=y;
    if(mp[x][y] == 'A') nx=x,ny=y-1;
    if(mp[x][y] == 'S') nx=x+1,ny=y;
    if(mp[x][y] == 'D') nx=x,ny=y+1;
}

int n,m;

bool isin(int x,int y) {
    return x>=1&&x<=n&&y>=1&&y<=m;
}

int id(int x,int y) {
    return (x-1)*m+y;
}

bool vis[SZ];
vector<int> G[SZ];

void addEdge(int x,int y) {
    G[x].push_back(y);
}

void dfs(int s) {
    vis[s] = 1;
    for(int v : G[s]) {
        if(vis[v]) continue;
        dfs(v);
    }
}

int main() {
    n = read(),m = read();
    for(int i = 1;i <= n;i ++) {
        scanf("%s",mp[i]+1);
    }

    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            int x,y;
            getNext(i,j,x,y);
            if(isin(x,y)) {
                addEdge(id(x,y),id(i,j));
            } else {
                addEdge(0,id(i,j));
            }
        }
    }

    dfs(0);
    int ans = 0;
    for(int i = 1;i <= n*m;i ++) {
        if(vis[i]) ans ++;
    }
    cout << ans << endl;
}
