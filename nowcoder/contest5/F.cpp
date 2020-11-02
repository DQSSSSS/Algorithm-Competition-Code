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
	int f,t;
	LL d,c;
}l[SZ];

int head[SZ],nxt[SZ],tot = 1,n;

void build(int f,int t,LL d,LL c) {
	l[++ tot] = (edge){f,t,d,c};
    nxt[tot] = head[f];
    head[f] = tot;
}

void insert(int f,int t,LL d,LL c) {
	build(f,t,d,c); build(t,f,0,-c);
}

LL dist[SZ];
int pre[SZ];
queue<int> q;
bool use[SZ];

bool spfa(int s,int e) {
	for(int i = 1;i <= 2 * n + 2;i ++) dist[i] = INF;
	dist[s] = 0;
	q.push(s);
	use[s] = 1; pre[s] = 0;
	while(q.size()) {
		int u = q.front(); q.pop();
        use[u] = 0;
        for(int i = head[u];i;i = nxt[i]) {
        	int v = l[i].t;
        	if(l[i].d && dist[v] > dist[u] + l[i].c) {
        		dist[v] = dist[u] + l[i].c;
        		pre[v] = i;
        		if(!use[v])
        			use[v] = 1,q.push(v);
        	}
        }
	}
	return dist[e] != INF;
}

LL EK(int s,int e) {
	LL ans = 0;
	while(spfa(s,e)) {
		LL maxflow = INF;
		for(int i = pre[e];i;i = pre[l[i].f])
			maxflow = min(maxflow,l[i].d);
		for(int i = pre[e];i;i = pre[l[i].f])
			ans += maxflow * l[i].c,l[i].d -= maxflow,l[i ^ 1].d += maxflow;
	}
	return ans;
}

int a[SZ][4],b[SZ][4];

int check(int x,int y) {
	int ans = 0;
	for(int i = 0;i < 4;i ++) {
		bool flag = 0;
		for(int j = 0;j < 4;j ++)
			if(a[x][i] == b[y][j])
				{flag = 1; break;}
		if(!flag) ans ++;
	}
	return ans;
}

int main() {
	n = read();
    for(int i = 1;i <= n;i ++) {
    	a[i][0] = read(); a[i][1] = read();
    	a[i][2] = read(); a[i][3] = read();
    }
    for(int i = 1;i <= n;i ++) {
    	b[i][0] = read(); b[i][1] = read();
    	b[i][2] = read(); b[i][3] = read();
    }
    int s = 2 * n + 1,e = 2 * n + 2;
    for(int i = 1;i <= n;i ++) insert(s,i,1,0);
    for(int i = 1;i <= n;i ++) insert(i + n,e,1,0);
    for(int i = 1;i <= n;i ++) {
    	for(int j = 1;j <= n;j ++) {
            int c = check(i,j);
            insert(i,j + n,1,c);
    	}
    }
    cout << EK(s,e) << endl;
	return 0;
}
