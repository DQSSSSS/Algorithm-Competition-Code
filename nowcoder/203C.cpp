#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = acos(-1);
const int SZ = 1000010;
const LL INF = 1e18;

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

int tot = 1,nxt[SZ],head[SZ];

void build(int f,int t,LL d,LL c) {
	l[++ tot] = (edge){f,t,d,c};
	nxt[tot] = head[f];
	head[f] = tot;
}

void insert(int f,int t,LL d,LL c) {
	build(f,t,d,c); build(t,f,0,-c);
}

int pre[SZ];
LL dist[SZ];
bool use[SZ];
queue<int> q;

bool spfa(int s,int e) {
	for(int i = 1;i <= e;i ++) dist[i] = -INF,pre[i] = 0;
	q.push(s);
	use[s] = 1;
	dist[s] = 0;
	while(q.size()) {
		int u = q.front(); q.pop();
		use[u] = 0;
		for(int i = head[u];i;i = nxt[i]) {
			int v = l[i].t;
			if(l[i].d && dist[v] < dist[u] + l[i].c) {
				dist[v] = dist[u] + l[i].c;
				pre[v] = i;
				if(!use[v]) use[v] = 1,q.push(v);
			}
		}	
	}
	return dist[e] > 0;
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

int main() {
	int n1 = read(),n2 = read(),m = read();
	int s = (n1+n2+2*m)+1,e = s + 1;
	for(int i = 1;i <= n1;i ++) insert(s,i,1,0);
	for(int i = 1;i <= n2;i ++) insert(i+n1,e,1,0);
	for(int i = 1;i <= m;i ++) {
		int a = read(),b = read(),c = read(),d = read(),e = read();
		insert(a,i+n1+n2,1,0);
		insert(b,i+n1+n2,1,0);
		insert(i+n1+n2,i+n1+n2+m,1,e);
		insert(i+n1+n2+m,c+n1,1,0);
		insert(i+n1+n2+m,d+n1,1,0);
	}
	printf("%lld\n",EK(s,e));
	return 0;
}
