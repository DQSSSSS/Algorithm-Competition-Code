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

struct haha {
	int s,t,op;
	LL w;
    void Read() { s = read(),t = read(),w = read(),op = read(); }
}a[233];

struct edge {
	int f,t;
	LL d,c;
}l[SZ];

int tot = 1,head[SZ],nxt[SZ];

void build(int f,int t,LL d,LL c) {
	l[++ tot] = (edge){f,t,d,c};
	nxt[tot] = head[f];
	head[f] = tot;
}

void insert(int f,int t,LL d,LL c) {
	build(f,t,d,c); build(t,f,0,-c);
}

LL dist[SZ],pre[SZ];
bool use[SZ];
queue<int> q;

bool spfa(int s,int e) {
    q.push(s);
    use[s] = 0;
    for(int i = 1;i <= e;i ++) dist[i] = -INF,pre[i] = 0;
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
    return dist[e] > -INF;
}

LL EK(int s,int e) {
    LL ans = 0;
    while(spfa(s,e)) {
        LL maxflow = INF;
        for(int i = pre[e];i;i = pre[l[i].f])
        	maxflow = min(maxflow,l[i].d);
        for(int i = pre[e];i;i = pre[l[i].f])
            ans += l[i].c * maxflow,l[i].d -= maxflow,l[i ^ 1].d += maxflow;
    }
    return ans;
}

int n,m,K,W;

void init() {
	for(int i = 1;i <= m * 2 + 3;i ++)
		head[i] = 0;
	tot = 1;
}

int main() {
    int T = read();
    while(T --) {
		n = read(),m = read(),K = read(),W = read();
		init();
        for(int i = 1;i <= m;i ++) {
            a[i].Read();
            insert(i,i + m,1,a[i].w);
        }
        for(int i = 1;i <= m;i ++)
        	for(int j = 1;j <= m;j ++) {
                if(i == j) continue;
                if(a[i].t <= a[j].s) {
                	if(a[i].op == a[j].op)
						insert(i + m,j,1,-W);
					else
						insert(i + m,j,1,0);
                }
        	}
        int s1 = 2 * m + 1,s = s1 + 1,t = s + 1;
		insert(s,s1,K,0);
        for(int i = 1;i <= m;i ++) insert(s1,i,INF,0);
        for(int i = 1;i <= m;i ++) insert(i + m,t,INF,0);
        printf("%lld\n",EK(s,t));
    }
    return 0;
}
