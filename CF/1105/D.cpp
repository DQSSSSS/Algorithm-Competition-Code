#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1010;
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

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

struct haha {
    int x,y,s;
};

queue<haha> q[11];
int dist[11][SZ][SZ],s[11],n,m,p;
char maps[SZ][SZ];
bool vis[SZ][SZ];

bool isin(int x,int y) { return x >= 1 && x <= n && y >= 1 && y <= m; }

int ans[22];

bool bfs(queue<haha> &q,int s,int id) {
    if(q.empty()) return false;
    int d = q.front().s;
    int fuck = 0;
    while(q.size()) {
        haha u = q.front();
        if(u.s == d + s) break;
        q.pop();
        for(int i = 0;i < 4;i ++) {
            int nx = u.x + dx[i];
            int ny = u.y + dy[i];
            if(isin(nx,ny) && maps[nx][ny] == '.' && !vis[nx][ny]) {
                ans[id] ++;
                fuck = 1;
                vis[nx][ny] = 1;
                q.push((haha){nx,ny,u.s+1});
            }
        }
    }
    if(!fuck) return false;
    return true;
}

int main() {
    n = read(),m = read(),p = read();
    for(int i = 1;i <= p;i ++) s[i] = read();
    for(int i = 1;i <= n;i ++) scanf("%s",maps[i] + 1);
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            if(maps[i][j] != '.' && maps[i][j] != '#') {
                int id = maps[i][j] - '0';
                q[id].push((haha){i,j,0});
                ans[id] ++;
            }
        }
    }
    while(233) {
        bool fuck = 0;
        for(int k = 1;k <= p;k ++)
            if(bfs(q[k],s[k],k)) fuck = 1;
        if(!fuck) break;
    }
    for(int k = 1;k <= p;k ++) cout << ans[k] << " ";
}
/***=
3 4 4
1 1 1 1
.#..
#...
1234

*/
