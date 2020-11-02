#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2010;
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

const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,-1,1};

char mp[SZ][SZ];
int dist[SZ][SZ],vis[SZ][SZ];
int n,m,L,R;

struct Heap{ int x,y,d1,d2; };
bool operator <(Heap a,Heap b) { 
	return a.d1 + a.d2 > b.d1 + b.d2;
}
priority_queue<Heap> q;

void bfs(int sx,int sy) {
	vis[sx][sy] = 1;
	q.push((Heap){sx,sy,0,0});
	while(q.size()) {
		Heap u = q.top(); q.pop();
		for(int i = 0;i < 4;i ++) {
			int x = u.x + dx[i];
			int y = u.y + dy[i];
			if(x < 1 || x > n || y < 1 || y > m || vis[x][y] || mp[x][y] == '*') continue;
			int d1 = 0,d2 = 0;
			if(i == 2) d1 = 1;
			if(i == 3) d2 = 1;
			if(u.d1 + d1 <= L && u.d2 + d2 <= R) {
				vis[x][y] = 1;
				q.push((Heap){x,y,u.d1+d1,u.d2+d2});
			}
		}
	}
}	

int main() {
	n = read(),m = read();
	int r = read(),c = read();
	L = read(),R = read();
	for(int i = 1;i <= n;i ++) scanf("%s",mp[i] + 1);
	bfs(r,c);
	int ans = 0;
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m;j ++)
			if(vis[i][j])
				ans ++;
	cout << ans << endl;
	return 0;
}

