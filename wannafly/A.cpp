#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

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
	int f,t,d,c;
}l[SZ];

vector<int> g[SZ];
int tot = 1;

void build(int f,int t,int d,int c) {
    l[++ tot] = (edge){f,t,d,c};
    g[f].push_back(tot);
}

void insert(int f,int t,int d,int c) {
	build(f,t,d,c); build(t,f,0,-c);
}

int dist[SZ],pre[SZ];
queue<int> q;
bool use[SZ];

bool spfa(int s,int e) {
    for(int i = 1;i <= e;i ++) dist[i] = INF,pre[i] = 0;
    dist[s] = 0;
    q.push(s);
    use[s] = 1;
    while(q.size()) {
    	int u = q.front(); q.pop();
        use[u] = 0;
        for(int i = 0;i < g[u].size();i ++) {
			int id = g[u][i],v = l[id].t;
            if(l[id].d && dist[v] > dist[u] + l[id].c) {
            	dist[v] = dist[u] + l[id].c;
            	pre[v] = id;
                if(!use[v])
                	use[v] = 1,q.push(v);
            }
        }
    }
    return dist[e] != INF;
}

int EK(int s,int e) {
    int ans = 0;
    while(spfa(s,e)) {
        int flow = INF;
        for(int i = pre[e];i;i = pre[l[i].f])
			flow = min(flow,l[i].d);
		for(int i = pre[e];i;i = pre[l[i].f])
            ans += flow * l[i].c,l[i].d -= flow,l[i ^ 1].d += flow;
    }
    return ans;
}

int main() {
	int n = read(),m = read(),s = n + m + 1,e = s + 1;
    for(int i = 1;i <= n;i ++) {
    	int a = read(),b = read();
        insert(i,a + n,1,0);
        insert(i,b + n,1,0);
        insert(s,i,1,0);
	}
    for(int i = 1;i <= m;i ++)
		for(int j = 1;j <= n;j ++)
            insert(i + n,e,1,2 * j - 1);
   	printf("%d\n",EK(s,e));
	return 0;
}
