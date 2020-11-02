#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=1e5+10;
const int mod=1e9;
const LL INF=1e16;

struct Node{LL x,y; int to,id;}f[MAXN];
vector< pair<int,LL> > edge[MAXN];
int n,len;
LL m,dis[MAXN];

bool cmp(const Node &a,const Node &b){return (a.id<b.id);}
bool cmp1(const Node &a,const Node &b){return (a.x<b.x || (a.x==b.x && a.y<b.y));}
bool cmp2(const Node &a,const Node &b){return (a.x<b.x || (a.x==b.x && a.y>b.y));}
bool cmp3(const Node &a,const Node &b){return (a.y<b.y || (a.y==b.y && a.x<b.x));}
bool cmp4(const Node &a,const Node &b){return (a.y<b.y || (a.y==b.y && a.x>b.x));}

void link(int a,int b,LL c){
    //cout<<a<<' '<<b<<" "<<c<<endl;
    edge[a].push_back(make_pair(b,c));
}

int vis[MAXN];
queue<int> q;

void SPFA(int s){
	for(int i=1;i<=n;i++){
		dis[i]=1000000000000000001;
		vis[i]=0;
	}
	q.push(s); dis[s]=0;
	while(!q.empty()){
		int u=q.front(); q.pop(); vis[u]=0;
		for(int j=0;j<edge[u].size();j++){
			int v=edge[u][j].first; LL val=edge[u][j].second;
			if (dis[u]+val>=dis[v]) continue;
			dis[v]=dis[u]+val;
			if (vis[v]==0){
				vis[v]=1; q.push(v);
			}
		}
	}
}

int main(){
	freopen("haha.txt","r",stdin);
	freopen("std.txt","w",stdout);
    scanf("%d%lld",&n,&m); len=4*n;
    for(int i=1;i<=n;i++){
        int a,b,c; char ch; scanf("%d%d %c",&a,&b,&ch);
        if (ch=='U') c=1;if (ch=='D') c=2;if (ch=='L') c=3;if (ch=='R') c=4;
        f[i].x=a; f[i].y=b; f[i].to=c; f[i].id=i;
    }
    sort(f+1,f+n+1,cmp1);
    int pos=-1;
    for(int i=1;i<=n;i++){
        if (pos!=-1 && f[pos].x==f[i].x) link(f[pos].id,f[i].id,abs(f[i].y-f[pos].y));
        if (f[i].to==1) pos=i;
    }
    sort(f+1,f+n+1,cmp2);
    pos=-1;
    for(int i=1;i<=n;i++){
        if (pos!=-1 && f[pos].x==f[i].x) link(f[pos].id,f[i].id,abs(f[i].y-f[pos].y));
        if (f[i].to==2) pos=i;
    }
    sort(f+1,f+n+1,cmp3);
    pos=-1;
    for(int i=1;i<=n;i++){
        if (pos!=-1 && f[pos].y==f[i].y) link(f[pos].id,f[i].id,abs(f[i].x-f[pos].x));
        if (f[i].to==4) pos=i;
    }
    sort(f+1,f+n+1,cmp4);
    pos=-1;
    for(int i=1;i<=n;i++){
        if (pos!=-1 && f[pos].y==f[i].y) link(f[pos].id,f[i].id,abs(f[i].x-f[pos].x));
        if (f[i].to==3) pos=i;
    }
    SPFA(1);
    //for(int i=1;i<=n;i++) cout<<i<<' '<<dis[i]<<endl;
    //return 0;
    sort(f+1,f+n+1,cmp);
    for(int i=1;i<=n;i++){
        LL d=max(0LL,m-dis[i]);
        if (f[i].to==1) f[i].y+=d;
        if (f[i].to==2) f[i].y-=d;
        if (f[i].to==3) f[i].x-=d;
        if (f[i].to==4) f[i].x+=d;
        printf("%lld %lld\n",f[i].x,f[i].y);
    }
    return 0;
}
