#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2e5 + 10;
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

struct haha {
	int u,w,num;
};

struct edge {
	int v,d;
};

queue<haha> q;
vector<int> g2[SZ];
vector<edge> g[SZ];

int t[SZ],n,m,num[SZ];
bool vis[SZ];

int spfa(int s,int e,int T) {
	if(!vis[s]) return 0;
    while(q.size()) q.pop();
    q.push((haha){s,T,1});
    for(int i = 1;i <= n;i ++) num[i] = 0,t[i] = 0;
    num[s] = 1;
    while(q.size()){
    	haha u = q.front(); q.pop();
        for(int i = 0;i < g[u.u].size();i ++) {
        	int v = g[u.u][i].v,w = g[u.u][i].d;
            if(vis[v] && u.w - w >= 0) {
				num[v] += u.num;
                q.push((haha){v,u.w - w,u.num});
                if(++ t[v] >= n) return INF;
            }
        }
    }
    //for(int i = 1;i <= n;i ++) cout << num[i] << " "; puts("");
    //for(int i = 1;i <= n;i ++) cout << vis[i] << " "; puts("");
    return num[e];
}

queue<int> que;

void bfs(int s) {
	que.push(s);
    vis[s] = 1;
    while(que.size()) {
    	int u = que.front(); que.pop();
        for(int i = 0;i < g2[u].size();i ++) {
        	int v = g2[u][i];
            if(!vis[v]) {
            	vis[v] = 1; que.push(v);
            }
        }
    }
}

void init() {
	for(int i = 1;i <= n;i ++) g[i].clear(),g2[i].clear(),vis[i] = 0;
}

int main() {
   	while(~scanf("%d%d",&n,&m)) {
        int s = read(),e = read(),k = read(),t = read();
        init();
        for(int i = 1;i <= m;i ++) {
            int x = read(),y = read(),w = read();
            g[x].push_back((edge){y,w});
            g2[y].push_back(x);
        }
        bfs(e);
        int d = spfa(s,e,t);
        if(d >= k) puts("yareyaredawa");
        else puts("Whitesnake!");
   	}
   	return 0;
}
/**
3 2
1 3 1 4
1 2 5
1 3 5
*/
