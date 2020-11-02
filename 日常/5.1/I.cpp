#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;

vector< pair<LL,int> > U[200010],L[200010],D[200010],R[200010];

int head[SZ],nxt[SZ],tot = 1,n,m;
LL lsh[SZ];

struct edge
{
	int t;
	LL d;
}l[SZ];

void build(int f,int t,LL d)
{
	//cout << f << " " << t << " " << d<< endl;
	l[++ tot] = (edge){t,d};
	nxt[tot] = head[f];
	head[f] = tot;
}

struct Heap
{
	int u;
	LL d;
};

bool operator <(Heap a,Heap b) { return a.d > b.d; }

priority_queue<Heap> q;
LL dist[SZ];
bool vis[SZ];

void dij(int s)
{
	for(int i = 1;i <= n;i ++) dist[i] = 1e18 + 10;
	dist[s] = 0;
	q.push((Heap){s,0});
	while(q.size())
	{
		int u = q.top().u; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = head[u];i;i = nxt[i])
		{
			int v = l[i].t;
			if(dist[v] > dist[u] + l[i].d)
			{
				dist[v] = dist[u] + l[i].d;
				q.push((Heap){v,dist[v]});
			}
		}
	}
}

void buildU(LL x,LL y,char c,int id)
{
	if(!U[x].size()) return ;
	int p = lower_bound(U[x].begin(),U[x].end(),make_pair(y,-INF)) - U[x].begin();
	p --;
	//cout << p << " " << Uid[x][p] << endl;	
	if(p < 0 || p >= U[x].size()) return ;
	build(U[x][p].second,id,lsh[y] - lsh[U[x][p].first]);
}

void buildD(LL x,LL y,char c,int id)
{
	if(!D[x].size()) return ;
	int p = upper_bound(D[x].begin(),D[x].end(),make_pair(y,INF)) - D[x].begin();
	if(p < 0 || p >= D[x].size()) return ;
	build(D[x][p].second,id,lsh[D[x][p].first] - lsh[y]);
}

void buildL(LL x,LL y,char c,int id)
{
	if(!L[y].size()) return ;
	int p = upper_bound(L[y].begin(),L[y].end(),make_pair(x,INF)) - L[y].begin();
	//cout << p << " " << L[y][p].second << " " << L[y][p].first << " "<< id << endl;
	if(p < 0 || p >= L[y].size()) return ;
	build(L[y][p].second,id,lsh[L[y][p].first] - lsh[x]);
}

void buildR(LL x,LL y,char c,int id)
{
	if(!R[y].size()) return ;
	int p = lower_bound(R[y].begin(),R[y].end(),make_pair(x,-INF)) - R[y].begin();
	p --;
	if(p < 0 || p >= R[y].size()) return ;
	build(R[y][p].second,id,lsh[x] - lsh[R[y][p].first]);
}
struct hahhhh
{
	LL x,y;
	char c;
}a[SZ];
			
int main()
{;	
	LL T;
	cin >> n >> T;
	for(int i = 1;i <= n;i ++)
	{
		LL x,y;
		char s[2];
		scanf("%I64d%I64d%s",&x,&y,s);
		char c = s[0];
		a[i] = (hahhhh){x,y,c};
		lsh[++ lsh[0]] = x;
		lsh[++ lsh[0]] = y;
	}
	sort(lsh + 1,lsh + 1 + lsh[0]);
	m = unique(lsh + 1,lsh + 1 + lsh[0]) - lsh - 1;
	for(int i = 1;i <= n;i ++)
	{
		a[i].x = lower_bound(lsh + 1,lsh + 1 + m,a[i].x) - lsh;
		a[i].y = lower_bound(lsh + 1,lsh + 1 + m,a[i].y) - lsh;
	//	cout << a[i].x << " " << a[i].y << endl;
		if(a[i].c == 'U')
			U[a[i].x].push_back(make_pair(a[i].y,i));
		if(a[i].c == 'D')
			D[a[i].x].push_back(make_pair(a[i].y,i));
		if(a[i].c == 'L')
			L[a[i].y].push_back(make_pair(a[i].x,i));
		if(a[i].c == 'R')
			R[a[i].y].push_back(make_pair(a[i].x,i));
	}
	for(int i = 1;i <= m;i ++)
		sort(U[i].begin(),U[i].end()),
		sort(R[i].begin(),R[i].end()),
		sort(L[i].begin(),L[i].end()),
		sort(D[i].begin(),D[i].end());
	for(int i = 1;i <= n;i ++)
	{
		LL x = a[i].x,y = a[i].y;
		char c = a[i].c;
	//	cout << "233 : " << i << endl;
		buildU(x,y,c,i); //puts("233");
		buildD(x,y,c,i); //puts("233");
		buildL(x,y,c,i); //puts("233");
		buildR(x,y,c,i); //puts("233");
	}
	dij(1);
//	for(int i = 1;i <= n;i ++) cout << dist[i] << " "; puts("");	
	for(int i = 1;i <= n;i ++)
	{
		LL x = lsh[a[i].x],y = lsh[a[i].y];
		if(dist[i] >= T)
			printf("%I64d %I64d\n",x,y);
		else
		{
			LL d = T - dist[i];
			if(a[i].c == 'U') y += d;
			if(a[i].c == 'L') x -= d;
			if(a[i].c == 'D') y -= d;
			if(a[i].c == 'R') x += d;
			printf("%I64d %I64d\n",x,y);
		}
	}
	return 0;
}
/*
2 1000000000000000000
1 0 U
1 3 U
*/
