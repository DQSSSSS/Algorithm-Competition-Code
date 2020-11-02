#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int size=2000010;
const int INF=233333333;
int head[size],nxt[size];
ll dist1[size],dist2[size];
int tot=0,n,m;
struct edge{
	int f,t,d;
}l[size];

void build(int f,int t,int d)
{
	nxt[++tot]=head[f];
	head[f]=tot;
}
bool use[size];
queue<int> q;
void spfa1(int s)
{
	memset(dist1,63,sizeof(dist1));
	use[s]=1;
	dist1[s]=0;
	while(!q.empty()) q.pop();
	q.push(s);
	while(q.size())
	{
		int f=q.front(); q.pop();
		use[f]=0;
		for(int i=head[f];i;i=nxt[i])
		{
			int v=l[i].t;
			if(dist1[v]>dist1[f]+l[i].d)
			{
				dist1[v]=dist1[f]+l[i].d;
				if(!use[v])
				{
					use[v]=1;
					q.push(v);
				}				
			}
		}
	}
	//for(int i=1;i<=n;i++) cout<<dist1[i]<<" ";puts("");
}
void spfa2(int s)
{
	memset(dist2,63,sizeof(dist2));
	use[s]=1;
	dist2[s]=0;
	while(!q.empty()) q.pop();
	q.push(s);
	while(q.size())
	{
		int f=q.front(); q.pop();
		use[f]=0;
		for(int i=head[f];i;i=nxt[i])
		{
			int v=l[i].t;
			if(dist2[v]>dist2[f]+l[i].d)
			{
				dist2[v]=dist2[f]+l[i].d;
				if(!use[v])
				{
					use[v]=1;
					q.push(v);
				}				
			}
		}
	}
	//for(int i=1;i<=n;i++) cout<<dist2[i]<<" ";puts("");	
}
void init()
{
	memset(head,0,sizeof(head));
	memset(nxt,0,sizeof(nxt));
	memset(use,0,sizeof(use));
	memset(l,0,sizeof(l));
	tot=0;	
}

int main()
{
	freopen("9dora.in","r",stdin);
	freopen("9dora.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&l[i].f,&l[i].t,&l[i].d);
			build(l[i].f,l[i].t,l[i].d);
		}
		spfa1(1);
		memset(head,0,sizeof(head));
		memset(nxt,0,sizeof(nxt));
		tot=0;		
		for(int i=1;i<=m;i++)
		{
			build(l[i].t,l[i].f,l[i].d);
			swap(l[i].f,l[i].t);
		}
		spfa2(1);
		ll ans=0;
		for(int i=1;i<=n;i++)
			ans+=dist1[i]+dist2[i];
		printf("%lld\n",ans);
	}
	return 0;
}
