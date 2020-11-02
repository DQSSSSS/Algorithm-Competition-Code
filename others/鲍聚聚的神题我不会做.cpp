#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
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

struct edge {
	int t;
	LL d;
};

vector<edge> g[SZ];

int s,t;
LL maxdist;

void dfs1(int u,int fa,LL d,bool flag) {
    if(d > maxdist) {
    	maxdist = d;
    	if(!flag) s = u;
    	else t = u;
    }
    for(int i = 0;i < g[u].size();i ++) {
    	int v = g[u][i].t;
    	if(v == fa) continue;
		dfs1(v,u,d + g[u][i].d,flag);
    }
}

int n;
LL dist[2][SZ];
bool use[SZ];
queue<int> q;

LL spfa(int s,LL dist[],int e) {
	for(int i = 1;i <= n;i ++) dist[i] = INF;
	q.push(s);
    dist[s] = 0;
	use[s] = 1;
	while(q.size()) {
		int u = q.front(); q.pop();
		use[u] = 0;
		for(int i = 0;i < g[u].size();i ++) {
			int v = g[u][i].t;
            if(dist[v] > dist[u] + g[u][i].d) {
            	dist[v] = dist[u] + g[u][i].d;
            	if(!use[v]) use[v] = 1,q.push(v);
            }
		}
	}
	return dist[e];
}

LL a[SZ];

int main() {
	int T = read();
    while(T --) {
        n = read();
        for(int i = 1;i <= n;i ++) g[i].clear();
        s = t = -1;
 		for(int i = 1;i < n;i ++) {
			int x = read(),y = read(),w = read();
			g[x].push_back((edge){y,w});
			g[y].push_back((edge){x,w});
		}
		maxdist = 0; dfs1(1,0,0,0);
		maxdist = 0; dfs1(s,0,0,1);
		spfa(s,dist[0],1);
		spfa(t,dist[1],1);
		for(int i = 1;i <= n;i ++) a[i] = max(dist[0][i],dist[1][i]);
		sort(a + 1,a + 1 + n);
		LL ans = 0;
		for(int i = 1;i <= n;i ++) {
			ans += a[i] * (n - i);
		}
        printf("%lld\n",ans);
    }
    return 0;
}
