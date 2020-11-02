#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

struct edge {
	int t,d;
};

vector<edge> g[SZ];

void build(int f,int t,int d) {
	g[f].push_back((edge){t,d});
}

struct Heap{ int u,d; };
bool operator <(Heap a,Heap b) { return a.d > b.d; }
priority_queue<Heap> q;

int dist[SZ];
bool vis[SZ];

int dij(int s,int e) {
	for(int i = 1;i <= e;i ++) dist[i] = INF,vis[i] = 0;
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
				q.push((Heap){v,dist[v]});
			}
		}
	}
	return dist[e] == INF ? -1 : dist[e];
}


int n,m;

int id(int x,int y,int k,int p) {
	int ans = (x - 1) * m + y;
	ans += (n * m) * (k * 2 + p);
	return ans;
}

char mp[110][110];

int main() {
	while(~scanf("%d%d",&n,&m) && n && m) {
		for(int i = 1;i <= n;i ++) scanf("%s",mp[i] + 1);
		int s = id(n,m,5,1) + 1,e = s + 1;
		for(int i = 1;i <= e;i ++) g[i].clear();
		for(int i = 1;i <= n;i ++) {
			for(int j = 1;j <= m;j ++) {
				for(int k = 0;k <= 5;k ++) {
					for(int p = 0;p <= 1;p ++) {
						if(mp[i][j] == 'S' && k == 0 && p == 0) g[s].push_back((edge){id(i,j,k,p),0});
						if(mp[i][j] == 'T') g[id(i,j,k,p)].push_back((edge){e,0});
						for(int l = 0;l < 4;l ++) {
							int x = i + dx[l];
							int y = j + dy[l];
							if(x >= 1 && x <= n && y >= 1 && y <= m) {
								if(mp[x][y] == 'B') {
									if(k < 5) {
										if(p == 1) build(id(i,j,k,p),id(x,y,k + 1,p - 1),0);
										build(id(i,j,k,p),id(x,y,k + 1,p),1);
									}
									else {
										if(p == 1) build(id(i,j,k,p),id(x,y,k,p - 1),0);
										build(id(i,j,k,p),id(x,y,k,p),1);
									}
								}
								else if(mp[x][y] == 'P') {
									if(p == 1) build(id(i,j,k,p),id(x,y,k,p),0);
									else build(id(i,j,k,p),id(x,y,k,p + 1),1);
								}
								else if(mp[x][y] == '#') {
									if(k >= 1) {
										if(p == 1) build(id(i,j,k,p),id(x,y,k - 1,p - 1),1);
										build(id(i,j,k,p),id(x,y,k - 1,p),2);
									}
								}
								else {
									if(p == 1) build(id(i,j,k,p),id(x,y,k,p - 1),0);
									build(id(i,j,k,p),id(x,y,k,p),1);
								}
							}
						}
					}
				}
			}
		}
		int ans = dij(s,e);
/*
		for(int k = 0;k <= 5;k ++) {
			for(int p = 0;p <= 1;p ++) {
				for(int i = 1;i <= n;i ++,puts("")) {
					for(int j = 1;j <= m;j ++) {
						cout << id(i,j,k,p) << " ";
//						cout << i << " " << j << " " << k << " " << p << " "<< id(i,j,k,p) << endl;
					}
				}
				for(int i = 1;i <= n;i ++,puts("")) {
					for(int j = 1;j <= m;j ++) {
						int x = dist[id(i,j,k,p)];
						cout << (x == INF ? -1 : x) << " ";
//						cout << i << " " << j << " " << k << " " << p << " "<< id(i,j,k,p) << endl;
					}
				}
				puts("");
			}
		}*/
		printf("%d\n",ans);
	}
	return 0;
}
