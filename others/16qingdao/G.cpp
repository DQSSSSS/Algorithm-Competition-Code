#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const double eps = 1e-5;

LL read()
{
    LL n = 0;
    char a = getchar();
    int flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

struct edge {
	int f,t,d;
	double c;
}l[SZ];

int tot = 1,nxt[SZ],head[SZ];

void build(int f,int t,int d,double c) {
	l[++ tot] = (edge){f,t,d,c};
	nxt[tot] = head[f];
	head[f] = tot;
}

void insert(int f,int t,int d,double c) {
	build(f,t,d,c); build(t,f,0,-c);
}

double dist[110],ans = 0;
int s,e,mark[110];
queue<int> q;

bool spfa() {
	for(int i = 1;i <= e;i ++) dist[i] = -1e18,mark[i] = 0;
	dist[e] = 0; q.push(e); mark[e] = 1;
	while(q.size()) {
		int u = q.front(); q.pop();
		mark[u] = 0;
		for(int i = head[u];i;i = nxt[i]) {
			int v = l[i].t;
			if(l[i ^ 1].d && dist[v] + eps < dist[u] + l[i ^ 1].c) {
				dist[v] = dist[u] + l[i ^ 1].c;
				if(!mark[v]) mark[v] = 1,q.push(v);
			}
		}
	}
	return dist[s] > -1e18;
}

int dfs(int x,int f) {
	mark[x] = 1;
	if(x == e) return f;
	int w,used = 0;
	for(int i = head[x];i;i = nxt[i]) {
		int v = l[i].t;
		if(fabs(dist[v] - dist[x] + l[i].c) < eps && l[i].d && !mark[v]) {
			w = f - used;
			w = dfs(v,min(w,l[i].d));
			ans += w * l[i].c;
			l[i].d -= w; l[i ^ 1].d += w;
			used += w; if(used == f) return f;
		}
	}
	return used;
}

void zkw() {
	while(spfa()) {
		memset(mark,0,sizeof(mark));
		mark[e] = 1;
		while(mark[e]) {
			mark[e] = 0;
			dfs(s,1e9);
		}
	}
}

int main() {
	int T = read();
	while(T --) {
		int n,m;
		scanf("%d%d",&n,&m);	
		s = n + 1,e = s + 1;
		tot = 1;
		for(int i = 1;i <= e;i ++) head[i] = 0;
		for(int i = 1;i <= n;i ++) {
			int ss,dd;
			scanf("%d%d",&ss,&dd);
			if(ss > dd) insert(s,i,ss-dd,0);
			if(ss < dd) insert(i,e,dd-ss,0);
		}
		for(int i = 1;i <= m;i ++) {
			int u = read(),v = read(),c = read();
			double p;
			scanf("%lf",&p);
			p = log(1-p);
			if(c == 0) continue;
			insert(u,v,1,0);
			if(c > 1) insert(u,v,c-1,p);
		}
		ans = 0;
		zkw();
		printf("%.2f\n",1-exp(ans));
	}
	return 0;
}
