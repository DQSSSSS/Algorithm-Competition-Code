#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int read() {
	int q=0;char ch=' ';
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') q=q*10+ch-'0',ch=getchar();
	return q;
}
#define LL long long
#define pr pair<LL,int>
const int N=150005;
const LL inf=1e15;
int T,n,K,s,t,t0,t1,tot,top;
int h0[N],h1[N],pre[N],rt[N],st[N],du[N];LL dis[N];
struct edge{int w,to,ne;}e0[N<<1],e1[N<<1];
void add(int x,int y,int z) {
	e0[++t0].to=y,e0[t0].ne=h0[x],h0[x]=t0,e0[t0].w=z;
	e1[++t1].to=x,e1[t1].ne=h1[y],h1[y]=t1,e1[t1].w=z;
	++du[x];
}
void bg() {//build_graph
	s=n+1,t=n*3+1;int c0,c1,co;
	t0=t1=0;for(int i=1;i<=t;++i) h0[i]=h1[i]=du[i]=0,dis[i]=inf;
	for(int i=1;i<=n;++i) {
		c0=read(),c1=read(),co=read();
		add(n+i,i,-c0),add(n+n+i,i,-c1);
		if(i!=n) {
			add(n+i,n+i+1,0),add(n+n+i,n+n+i+1,0);
			if(co) add(i,n+n+i+1,0);
			else add(i,n+i+1,0);
		}
		else add(n,t,0),add(n+n,t,0),add(n+n+n,t,0);
	}
}
void topo() {
	top=1,st[top]=t,dis[t]=pre[t]=0;
	while(top) {
		int x=st[top--];
		for(int i=h1[x];i;i=e1[i].ne) {
			if(dis[e1[i].to]>dis[x]+e1[i].w)
				dis[e1[i].to]=dis[x]+e1[i].w,pre[e1[i].to]=x;
			--du[e1[i].to];if(!du[e1[i].to]) st[++top]=e1[i].to;
		}
	}
}
struct node{int ls,rs,d,id;LL v;}a[N*40];
int merge(int x,int y) {
	if(x*y==0) return x+y;
	if(a[x].v>a[y].v) swap(x,y);
	int o=++tot;a[tot]=a[x];
	a[o].rs=merge(a[o].rs,y);
	if(a[a[o].ls].d<a[a[o].rs].d) swap(a[o].ls,a[o].rs);
	a[o].d=a[a[o].rs].d+1;
	return o;
}
void dfs(int x) {//每个左偏树代表从i到t的路上的所有非树边
	if(pre[x]) rt[x]=rt[pre[x]];
	//cout << x << endl;
	for(int i=h0[x];i;i=e0[i].ne) {
		int v=e0[i].to;
	//	cout << v << " ";
		if(dis[v]==inf||pre[x]==v) continue;
		a[++tot]=(node){0,0,1,v,dis[v]+e0[i].w-dis[x]},rt[x]=merge(rt[x],tot);
	}
	//puts("\n----");
	for(int i=h1[x];i;i=e1[i].ne)
		if(pre[e1[i].to]==x) dfs(e1[i].to);
}
void work() {
	//for(int i = 1;i <= 3*n+1;i ++) cout << pre[i] << " "; puts("");
	//for(int i = 1;i <= 3*n+1;i ++) cout << dis[i] << " "; puts("");
	tot=0,rt[t]=0,dfs(t);//cout<<tot<<endl;
	if(K==1) {printf("%lld\n",-dis[s]);return;}
	priority_queue<pr,vector<pr >,greater<pr > > q;
	q.push(pr(dis[s]+a[rt[s]].v,rt[s]));
	while(K--) {//利用优先队列获得答案
		pr kl=q.top(); q.pop();
		if(K==1) {printf("%lld\n",-kl.first);return;}
		int u=kl.second,v=a[u].id;
		if(rt[v]) q.push(pr(kl.first+a[rt[v]].v,rt[v]));
		if(a[u].ls) q.push(pr(kl.first-a[u].v+a[a[u].ls].v,a[u].ls));
		if(a[u].rs) q.push(pr(kl.first-a[u].v+a[a[u].rs].v,a[u].rs));
	}
}
int main() {
	T=read();
	while(T--) {
		n=read(),K=read();
		bg(),topo(),work();
	}
    return 0;
}
/**
1
3 4
2 1 0
1 3 1
3 1 1
5 9 10 1 6 3 1 2 3 0
-3 -1 0 -5 -3 -3 -4 -4 -1 0
10

----
3

----
9
10
----
2

----
8
9
----
6
10
----
5
2
----
1

----
7
8
----
4
5
----
10
3
*/
