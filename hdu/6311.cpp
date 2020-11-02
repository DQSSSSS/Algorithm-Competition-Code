#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
const int INF = 1e9 + 10;
const int mod = 998244353;
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
	int t,id;
};

int n,m;
vector<edge> g[SZ << 1];
vector<int> path[SZ];
int pathtot,tot;
bool vis[SZ],use[SZ << 1];
int node[SZ],du[SZ],p[SZ << 1];

void dfs1(int u,int f) {
	vis[u] = 1;
	node[++ node[0]] = u;
	for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i].t;
        if(v == f || vis[v]) continue;
        dfs1(v,u);
	}
}

void dfs(int u) {
	//cout << u << endl;
    for(int i = 0;i < g[u].size();i ++) {
        int v = g[u][i].t,id = abs(g[u][i].id);
        if(use[id]) continue;
        use[id] = 1;
        dfs(v);
        p[++ p[0]] = g[u][i].id;
    }
}

void work(int s) {
    node[0] = 0;
    dfs1(s,0);
    if(node[0] == 1) return ;
    vector<int> ji;
    for(int i = 1;i <= node[0];i ++) {
    	int u = node[i];
        if(du[u] % 2 == 1)
        	ji.push_back(u);
    }
    for(int i = 0;i < ji.size();i += 2) {
		int x = ji[i],y = ji[i + 1];
		tot ++;
		g[x].push_back((edge){y,tot});
        g[y].push_back((edge){x,-tot});
        //cout <<x << " " << y << endl;
    }
    p[0] = 0;
    dfs(s);
  //  puts("");
   // cout << s << endl;
   // for(int i = 1;i <= p[0];i ++) cout << p[i] << " "; puts("");


    int f = 0;
    for(int i = 1;i <= p[0];i ++)
        if(abs(p[i]) > m) { f = i; break; }
    pathtot ++;
    for(int i = f - 1;i >= 1;i --) {
    	path[pathtot].push_back(p[i]);
    }
    for(int i = p[0];i > f;i --) {
    	if(abs(p[i]) > m) { pathtot ++; continue; }
		path[pathtot].push_back(p[i]);
    }

}

void init() {
	for(int i = 1;i <= tot;i ++) use[i] = 0;
	for(int i = 1;i <= n;i ++) {
		vis[i] = 0,g[i].clear(),du[i] = 0;
	}
	for(int i = 1;i <= pathtot;i ++) path[i].clear();
	pathtot = 0; tot = m;
}

int main() {
    while(~scanf("%d%d",&n,&m)) {
        init();
        for(int i = 1;i <= m;i ++) {
            int x = read(),y = read();
            g[x].push_back((edge){y,i});
            g[y].push_back((edge){x,-i});
            du[x] ++; du[y] ++;
        }
        for(int i = 1;i <= n;i ++) {
            if(!vis[i]) {
				work(i);
            }
        }
        printf("%d\n",pathtot);
        for(int i = 1;i <= pathtot;i ++) {
        	printf("%d ",path[i].size());
        	for(int j = 0;j < path[i].size();j ++)
        		printf("%d%c",path[i][j]," \n"[j + 1 == path[i].size()]);
    	}
    }
    return 0;
}
