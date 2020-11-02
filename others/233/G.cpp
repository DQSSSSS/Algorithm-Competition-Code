#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 300010;
const LL INF = 1e18 + 10;
const int mod = 10007;
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

int n,m;

struct edge {
	int t,d;
};

vector<edge> g[SZ];

LL dist[SZ];
bool use[SZ];
int t[SZ];
deque<int> q;

bool dfs(int u) {
	for(int i = 0;i < g[u].size();i ++) {
		int v = g[u][i].t;
		if(dist[v] > dist[u] + g[u][i].d) {
			dist[v] = dist[u] + g[u][i].d;
			if(!use[v]) {
				use[v] = 1;
				if(dfs(v)) return true;
				use[v] = 0;
			}
			else return true;
		}
	}
	return false;
}

int id(int x,int y) {
	return x * m + y + 1;
}

int r[510][510];
int c[510][510];

int main() {
	n = read(),m = read();
	for(int i = 0;i < n;i ++)
		for(int j = 0;j < m;j ++)
			r[i][j] = read(),c[i][j] = read();
	int s = n * m + 1;
	for(int i = 0;i < n;i ++) {
		for(int j = 0;j < m;j ++) {
			int u = id(i,j);
			int v1 = id((i+1)%n,j);
			int v2 = id(i,(j+1)%m);
			
			int R = r[(i+1)%n][j],C = c[i][(j+1)%m];
			
			g[u].push_back((edge){v1,R});
			g[v1].push_back((edge){u,-R});
			
			g[v2].push_back((edge){u,C});
			g[u].push_back((edge){v2,-C});
		/*	
			cout << u << " -> " << v1 << " " << R << endl;
			cout << v1 << " -> " << u << " " << -R << endl;
			
			cout << u << " -> " << v1 << " " << -C << endl;
			cout << v1 << " -> " << u << " " << C << endl;
			*/
			g[s].push_back((edge){u,0});
		}
	} 
	for(int i = 1;i <= s;i ++) dist[i] = INF;
	use[s] = 1; dist[s] = 0;
	if(!dfs(s)) puts("Yes");
	else puts("No");
	//for(int i = 1;i <= s;i ++) cout << t[i] << " "; puts("");
	//for(int i = 1;i <= s;i ++) cout << dist[i] << " "; puts("");
	return 0;
}
