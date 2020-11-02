#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;
const LD PI = acos(-1);

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
}l[50010];

int tot,nxt[50010],head[SZ];

void build(int f,int t,LL d,LL c) {
	l[++ tot] = (edge){f,t,d,c};
	nxt[tot] = head[f];
	head[f] = tot;
}

void insert(int f,int t,LL d,LL c) {
	build(f,t,d,c); build(t,f,0,-c);
}

LL dist[SZ],ans = 0;
queue<int> q;
int mark[SZ],s,e;

bool spfa()
{
    memset(mark,0,sizeof(mark));
    memset(dist,-1,sizeof(dist));
    q.push(e); mark[e] = 1,dist[e] = 0;
    while(q.size())
    {
        int u = q.front(); q.pop();
        mark[u] = 0;
        for(int i = head[u];i;i = nxt[i])
        {
            int v = l[i].t;
            if(l[i ^ 1].d && dist[u] + l[i ^ 1].c > dist[v])
            {
                dist[v] = dist[u] + l[i ^ 1].c;
                if(!mark[v])
                    mark[v] = 1,q.push(v);
            }
        }
    }
    return dist[s] != -1;
}
LL dfs(int x,LL f)
{
    mark[x] = 1;
    if(x == e) return f;
    LL w,used = 0;
    for(int i = head[x];i;i = nxt[i])
    {
        int v = l[i].t;
        if(dist[v] == dist[x] - l[i].c && l[i].d && !mark[v])
        {
            w = f - used;
            w = dfs(v,min(w,l[i].d));
            ans += w * l[i].c;
            l[i].d -= w;l[i ^ 1].d += w;
            used += w; if(used == f) return f;
        }
    }
    return used;
}
void zkw()
{
    while(spfa())
    {
        memset(mark,0,sizeof(mark));
        mark[e] = 1;
        while(mark[e])
        {
            mark[e] = 0;
        //    puts("233");
            dfs(s,INF);
        }
    }
}

struct haha{
	int l,r;
	LL w;
}a[SZ];

bool cmp(haha a,haha b) { return a.l < b.l; }

int n,k,m;

void init() {
	tot = 1;
	for(int i = 1;i <= 2 * m + 5;i ++) head[i] = 0;
	ans = 0;
}

int lsh[SZ];

int main(){
	int T = read();
	while(T --) {
		n = read(),k = read(),m = read();
		lsh[0] = 0;
		init();
		for(int i = 1;i <= m;i ++) {
			a[i].l = read(),a[i].r = read() + 1,a[i].w = read();
			lsh[++ lsh[0]] = a[i].l;
			//lsh[++ lsh[0]] = a[i].l + 1;
			lsh[++ lsh[0]] = a[i].r;
			//lsh[++ lsh[0]] = a[i].r + 1;
		}
		sort(lsh + 1,lsh + 1 + lsh[0]);
		int len = unique(lsh + 1,lsh + 1 + lsh[0]) - lsh - 1;
		s = len + 1,e = s + 1;
		for(int i = 1;i <= m;i ++) {
			a[i].l = lower_bound(lsh + 1,lsh + 1 + len,a[i].l) - lsh;
			a[i].r = lower_bound(lsh + 1,lsh + 1 + len,a[i].r) - lsh;
			insert(a[i].l,a[i].r,1,a[i].w);
		}
		insert(s,1,k,0); insert(len,e,k,0);
		for(int i = 1;i < len;i ++) insert(i,i+1,INF,0);
		zkw();
		printf("%lld\n",ans);
	}
	
	return 0;
}
