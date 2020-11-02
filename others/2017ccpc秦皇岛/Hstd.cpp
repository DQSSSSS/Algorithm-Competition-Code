#include <bits/stdc++.h>
#define REP(i,x,y) for(int i=x;i<(y);i++)
#define maxn 3030
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,k,a[maxn],b[maxn];
bool isprime[2000010];
int prime[1000010],num_prime;
void getprime(ll n)
{
    memset(isprime,true,sizeof(isprime));
    isprime[0]=0,isprime[1]=0;
    for(int i=2;i<=n;i++){
        if(isprime[i])
            prime[num_prime++]=i;
        for(int j=0;j<num_prime&&prime[j]*i<n;j++){
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0)
                break;
        }
    }
}
int cnt,num[maxn];
struct edge{
    int u,v,cap,flow;
    edge(){}
    edge(int u,int v,int c,int f):u(u),v(v),cap(c),flow(f){}
};
vector<edge>edges;
vector<int>e[maxn];
inline void add_edge(int u,int v,int c){
    edges.push_back(edge(u,v,c,0));
    edges.push_back(edge(v,u,0,0));
    int m=edges.size();
    e[u].push_back(m-2);
    e[v].push_back(m-1);
}
int vis[maxn],dis[maxn],cur[maxn];
bool bfs(int s,int t){
    memset(vis,0,sizeof(vis));
    queue<int>que;que.push(s);vis[s]=1;dis[s]=0;
    while(!que.empty()){
        int now=que.front();que.pop();
        REP(i,0,e[now].size()){
            edge& nxt=edges[e[now][i]];
            if(!vis[nxt.v]&&nxt.cap>nxt.flow){
                vis[nxt.v]=1;
                dis[nxt.v]=dis[now]+1;
                que.push(nxt.v);
            }
        }
    }
    return vis[t];
}
int dfs(int st,int t,int low){
    if(st==t||low==0) return low;
    int flow=0,f;
    for(int& i=cur[st];i<e[st].size();i++){
        edge& nxt=edges[e[st][i]];
        if(dis[nxt.v]==dis[st]+1&&(f=dfs(nxt.v,t,min(low,nxt.cap-nxt.flow)))>0){
            nxt.flow+=f;
            edges[e[st][i]^1].flow-=f;
            flow+=f;
            low-=f;
            if(low==0) break;
        }
    }
    return flow;
}
int Dinic(int s,int t){
    int ans=0;
    while(bfs(s,t)){
        memset(cur,0,sizeof(cur));
        ans+=dfs(s,t,inf);
    }
    return ans;
}
int use[maxn];
int main()
{
	freopen("H.in","r",stdin);
	freopen("std.out","w",stdout);
	getprime(2000005);
	int TT;scanf("%d",&TT);
	while(TT--) {
		cnt=0;
		scanf("%d %d",&n,&k);
		memset(num,0,sizeof(num));memset(use,0,sizeof(use));
		edges.clear();
		for(int i=0;i<=n+1;i++) e[i].clear();
		REP(i,1,n+1) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
        b[++cnt]=a[1];int tmp=1;
        for(int i=2;i<=n;i++) {
            if(a[i]!=a[i-1]) {
                b[++cnt]=a[i];
                num[cnt-1]=tmp;
                tmp=1;
            }
            else tmp++;
        }
        if(tmp) num[cnt]=tmp;
       // for(int i=1;i<=cnt;i++) cout<<i<<" "<<b[i]<<" "<<num[i]<<endl;
        for(int i=1;i<=cnt;i++) {
            for(int j=i+1;j<=cnt;j++) {
                if(isprime[b[i]+b[j]]) {
                    use[i]=use[j]=1;
                    if(b[i]%2==1) add_edge(i,j,inf);
                    else add_edge(j,i,inf);
                }
            }
        }
        int one=0,S=0,T=cnt+1;
        for(int i=1;i<=cnt;i++) {
            if(b[i]==1) {one=1;continue;}
            if(use[i]==0) continue;
            if(b[i]%2) add_edge(S,i,num[i]);
            else add_edge(i,T,num[i]);
        }
        int ans1=Dinic(S,T),ans2=0,ans3=0,Ans=0,used=0;
        if(one) {
            add_edge(S,1,num[1]);
            ans2=Dinic(S,T);
            ans3=num[1]-ans2;
            ans2+=ans3/2;
            edges[edges.size()-2].flow+=ans3/2*2;
        }
        if(ans1+ans2>=k) Ans=2*k;
        else {
            int tmp=0,sub=k-ans1-ans2;
            for(int i=0;i<edges.size();i+=2) {
                if(edges[i].u==S&&edges[i].cap>edges[i].flow) tmp+=edges[i].cap-edges[i].flow;
                if(edges[i].v==T&&edges[i].cap>edges[i].flow) tmp+=edges[i].cap-edges[i].flow;
            }
            tmp=min(tmp,sub);
            Ans=(ans1+ans2)*2+tmp;
        }
        cout<<Ans<<endl;
    }
}
