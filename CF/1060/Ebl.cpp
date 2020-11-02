#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 400010;
const int INF = 1e9 + 10;
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

struct edge{ int f,t,id; };

vector<edge> g[SZ];

LL dist[SZ],use[SZ],pre[SZ];
int n;

queue<int> q;

void spfa(int s) {
	for(int i = 1;i <= n;i ++) dist[i] = n,pre[i] = 0;
	dist[s] = 0; use[s] = 1;
	q.push(s);
	while(q.size()) {
		int u = q.front(); q.pop();
		use[u] = 0;
		for(int i = 0;i < g[u].size();i ++) {
			int v = g[u][i].t;
			if(dist[v] > dist[u] + 1) {
				dist[v] = dist[u] + 1;
				pre[v] = g[u][i].id;
				if(!use[v]) q.push(v),use[v] = 1;
			}
		}
	}
}

int ff[SZ],tt[SZ],tot,tong[SZ];

int main() {
	//freopen("E.in","r",stdin);
	//freopen("Estd.out","w",stdout);
	n = read();
	for(int i = 1;i < n;i ++) {
		int x = read(),y = read();
		ff[i] = x; tt[i] = y;
		g[x].push_back((edge){x,y,i});
		g[y].push_back((edge){y,x,i});
	}
	for(int u = 1;u <= n;u ++) {
		int len = g[u].size();
		for(int i = 0;i < len;i ++) {
			for(int j = 0;j < i;j ++) {
				int x = g[u][i].t;
				int y = g[u][j].t;
				ff[(++ tot) + (n - 1)] = x;
				tt[tot + n - 1] = y;
			}
		}
	}
	for(int i = 1;i <= tot;i ++) {
		int x = ff[i + n - 1],y = tt[i + n - 1];
		g[x].push_back((edge){x,y,i+n-1});
		g[y].push_back((edge){y,x,i+n-1});
	}
	LL ans = 0;
	//for(int i = 1;i <= tot + n - 1;i ++) cout << ff[i] << " " << tt[i] << endl;
	for(int i = 1;i <= n;i ++) {
		spfa(i);
		//for(int j = 1;j <= n;j ++) cout << pre[j] << " "; puts("");
		for(int j = 1;j <= n;j ++) {
			ans += dist[j];
			/*for(int x = pre[j];x;x = pre[ff[x]]) {
				tong[x] ++;
				cout << x << endl;
			}*/
		}
	}
	for(int u = 1;u <= n;u ++) {
		int len = g[u].size();
		for(int i = 0;i < len;i ++) {
			int v = g[u][i].t;
			//if(v < u) cout << v << " " << u << " " << tong[g[u][i].id] / 2 << " " << g[u][i].id << endl; 
		}
	}
	cout << ans / 2 << endl;
	return 0;
}
/**

7
1 2
1 3
2 4
2 5
2 6
2 7

*/
