#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 500010;
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

const int dx[] = {-1,-1,1,1,2,2,-2,-2};
const int dy[] = {2,-2,2,-2,1,-1,1,-1};

struct haha { int x,y,id,now; };

int a[22][22];
int dist[22][22][5][110],n;
int use[22][22][5][110];
queue<haha> q;

bool isin(int x,int y) { return x >= 1 && x <= n && y >= 1 && y <= n; }

int main() {
	n = read();
	int sx,sy,ex,ey;
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j <= n;j ++) {
			a[i][j] = read();
			if(a[i][j] == 1) sx = i,sy = j;
			if(a[i][j] == n*n) ex = i,ey = j;
		}
	}	
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= n;j ++)
			for(int k = 1;k <= 3;k ++)
				for(int l = 1;l <= n*n;l ++)
					dist[i][j][k][l] = INF;
	
	for(int i = 1;i <= 3;i ++) 
		dist[sx][sy][i][1] = 0,q.push((haha){sx,sy,i,1}),use[sx][sy][i][1] = 1;
	while(q.size()) {
		haha u = q.front(); q.pop();
		use[u.x][u.y][u.id][u.now] = 0;
		if(u.id == 1)
			for(int i = 0;i < 8;i ++) {
				int x = u.x + dx[i];
				int y = u.y + dy[i];
				if(isin(x,y)) {
					haha nx = (haha){x,y,u.id,u.now};
					if(a[x][y] == nx.now + 1) nx.now ++;
					if(dist[x][y][nx.id][nx.now] <= dist[u.x][u.y][u.id][u.now] + 1000) continue;
					dist[x][y][nx.id][nx.now] = dist[u.x][u.y][u.id][u.now] + 1000;
					if(!use[x][y][nx.id][nx.now]) {
						q.push(nx);
						use[x][y][nx.id][nx.now] = 1;
					}
				}
			}
		else if(u.id == 2) {
			for(int i = 1;i <= n;i ++) {
				int x = i,y = u.y;	
				haha nx = (haha){x,y,u.id,u.now};
				if(a[x][y] == nx.now + 1) nx.now ++;
				if(dist[x][y][nx.id][nx.now] <= dist[u.x][u.y][u.id][u.now] + 1000) continue;
				dist[x][y][nx.id][nx.now] = dist[u.x][u.y][u.id][u.now] + 1000;
				if(!use[x][y][nx.id][nx.now]) {
					q.push(nx);
					use[x][y][nx.id][nx.now] = 1;
				}
			}
			for(int i = 1;i <= n;i ++) {
				int x = u.x,y = i;	
				haha nx = (haha){x,y,u.id,u.now};
				if(a[x][y] == nx.now + 1) nx.now ++;
				if(dist[x][y][nx.id][nx.now] <= dist[u.x][u.y][u.id][u.now] + 1000) continue;
				dist[x][y][nx.id][nx.now] = dist[u.x][u.y][u.id][u.now] + 1000;
				if(!use[x][y][nx.id][nx.now]) {
					q.push(nx);
					use[x][y][nx.id][nx.now] = 1;
				}
			}
		}
		else {
			int sum = u.x + u.y;
			for(int i = 1;i <= n;i ++) {
				int x = sum - i,y = i;
				if(!isin(x,y)) continue;	
				haha nx = (haha){x,y,u.id,u.now};
				if(a[x][y] == nx.now + 1) nx.now ++;
				if(dist[x][y][nx.id][nx.now] <= dist[u.x][u.y][u.id][u.now] + 1000) continue;
				dist[x][y][nx.id][nx.now] = dist[u.x][u.y][u.id][u.now] + 1000;
				if(!use[x][y][nx.id][nx.now]) {
					q.push(nx);
					use[x][y][nx.id][nx.now] = 1;
				}
			}
			sum = u.x - u.y;
			for(int i = 1;i <= n;i ++) {
				int x = sum + i,y = i;
				if(!isin(x,y)) continue;	
				haha nx = (haha){x,y,u.id,u.now};
				if(a[x][y] == nx.now + 1) nx.now ++;
				if(dist[x][y][nx.id][nx.now] <= dist[u.x][u.y][u.id][u.now] + 1000) continue;
				dist[x][y][nx.id][nx.now] = dist[u.x][u.y][u.id][u.now] + 1000;
				if(!use[x][y][nx.id][nx.now]) {
					q.push(nx);
					use[x][y][nx.id][nx.now] = 1;
				}
			}
		}
		for(int i = 1;i <= 3;i ++) {
			int x = u.x,y = u.y,id = i;
			haha nx = (haha){x,y,id,u.now};
			if(dist[x][y][nx.id][nx.now] <= dist[u.x][u.y][u.id][u.now] + 1001) continue;
			dist[x][y][nx.id][nx.now] = dist[u.x][u.y][u.id][u.now] + 1001;
			if(!use[x][y][nx.id][nx.now]) {
				q.push(nx);
				use[x][y][nx.id][nx.now] = 1;
			}
		}
	}
	int ans = INF;
	for(int i = 1;i <= 3;i ++) ans = min(ans,dist[ex][ey][i][n*n]);
	cout << ans / 1000 << " " << ans %1000 << endl;
	return 0;
}
