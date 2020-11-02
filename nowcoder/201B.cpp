#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
const LL INF = 1e18;
const int mod = 998244353;
const LD eps = 1e-7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

const double gen2 = sqrt(2);
int n,m,c;
double a[22][22];

struct hh{double d; int x,y;};
vector<hh> g;
bool operator <(hh a,hh b) { return a.d < b.d; }
int nx1[SZ],nx2[SZ];

struct haha {
	int i,j,id;
	double getrst() { return g[id].d; }
	bool can(int dx,int dy) {
		if(dx == 0 && dy == 0) return false;
		if(i + dx < 1 || i + dx > n) return false;
		if(j + dy < 1 || j + dy > m) return false;
		if(dx == 0 || dy == 0) return getrst() + eps >= 1-eps;
		return getrst() + eps >= gen2-eps;
	}
	haha getnxtnode(int dx,int dy) {
		if(dx == 0 || dy == 0) return (haha){i+dx,j+dy,nx1[id]};
		return (haha){i+dx,j+dy,nx2[id]};
	}
	void print() { printf("[%d,%d] %d+%dx ",i,j,g[id].x,g[id].y); }
}p[SZ];

double dist[22][22][2010];

bool vis[22][22][2010];
struct Heap{ haha u; double d; };
bool operator <(Heap a,Heap b) { return a.d > b.d; }
priority_queue<Heap> q;


double dij(int si,int sj,int sid) {
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m;j ++)
			for(int k = 0;k < g.size();k ++)
				dist[i][j][k] = INF;
	dist[si][sj][sid] = 0;
	q.push((Heap){(haha){si,sj,sid},0});
	double ans = INF;
	while(q.size()) {
		haha now = q.top().u; q.pop();
		if(vis[now.i][now.j][now.id]) continue;
		vis[now.i][now.j][now.id] = 1;
		if(now.i == n && now.j == m) { ans = dist[now.i][now.j][now.id]; break; }
		int t = 0;
		for(int dx = -1;dx <= 1;dx ++)
			for(int dy = -1;dy <= 1;dy ++) {
				if(!now.can(dx,dy)) continue;
				haha nx = now.getnxtnode(dx,dy);
				if(dist[nx.i][nx.j][nx.id] > dist[now.i][now.j][now.id] + eps) {
					dist[nx.i][nx.j][nx.id] = dist[now.i][now.j][now.id];
					q.push((Heap){nx,dist[nx.i][nx.j][nx.id]});
					t ++;
				}
			}
		for(int i = now.id + 1;i < min((int)g.size(),now.id+2);i ++) {
			double d = (g[i].d-now.getrst())*a[now.i][now.j];
			haha nx = (haha){now.i,now.j,i};
			if(dist[nx.i][nx.j][nx.id] > dist[now.i][now.j][now.id] + d + eps) {
				dist[nx.i][nx.j][nx.id] = dist[now.i][now.j][now.id] + d;
				q.push((Heap){nx,dist[nx.i][nx.j][nx.id]});
				t ++;
			}	
		}
	}
	return ans;
}

int main() {
	//freopen("B.in","r",stdin);	freopen("B.out","w",stdout);
	n = read() + 1,m = read() + 1,c = read();
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m;j ++)
			scanf("%lf",&a[i][j]);
	for(int x = -40;x <= 40;x ++)
		for(int y = -20;y <= 20;y ++) {
			double now = x + gen2 * y;
			if(now >= -eps && now <= c+eps) {
				g.push_back((hh){now,x,y});
			}
		}
	sort(g.begin(),g.end());
	for(int i = 0;i < g.size();i ++){
		for(int j = 0;j < i;j ++) {
			if(abs(g[i].d - g[j].d - 1) < eps) nx1[i] = j;
			if(abs(g[i].d - g[j].d - gen2) < eps) nx2[i] = j;
		}
	}
	printf("%.6f\n",dij(1,1,0));
	return 0;
}
/**
2 2 2
3 10 7 
8 5 2 
6 8 6 

*/
