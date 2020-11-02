#include<bits/stdc++.h>
#define ll long long
#define pa pair<int,int>
using namespace std;
const int INF=5000004;
int S,T;
int n,m,ne;

inline int getpos(int x,int y){
    return (x-1)*m+y;
}
inline int id(int x,int y){
    if(x>n-1||y<1)return 0;
    return (x-1)*m+y;
}
char s[1000004];
int mp[1000004];
int h[300004];
ll dis[300004];
struct edge{
    int to,nt;
    int w;
}e[9000004];
void add(int u,int v,int w){
    cout << u << " "<< v << " " << w << endl;
    e[++ne].to=v;e[ne].w=w;
    e[ne].nt=h[u];h[u]=ne;
}
bool vis[3000004];
priority_queue<pa,vector<pa>,greater<pa> >q;
int dijkstra(int St,int Ed){
    for(int i=St;i<=Ed;i++){
        dis[i]=INF;
        vis[i]=0;
    }
    dis[St]=0;
    q.push({0,St});
    while(!q.empty()){
        int x=q.top().second;q.pop();
        if(vis[x])continue;
        vis[x]=1;
        for(int i=h[x];i;i=e[i].nt){
            if(dis[e[i].to] > dis[x] + e[i].w){
                dis[e[i].to] = dis[x] + e[i].w;
                q.push({dis[e[i].to],e[i].to});
            }
        }
    }
    return dis[Ed];
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        for(int j=1;j<=m;j++){
            mp[getpos(i,j)]=(s[j]!='#');
        }
    }
    if(n == 1) {
        int t = 0;
        for(int i = 1;i <= m;i ++) if(mp[getpos(1,i)] == 0) t ++;
        if(t) puts("0");
        else puts("1");
        return 0;
    }
    ne=0;
   /* for(int i=1;i<=n;i++,puts(""))
        for(int j=1;j<=m;j++)
            printf("%d ",mp[getpos(i,j)]);*/
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m-1;j++){
            add(id(i+1,j-1),id(i,j),mp[getpos(i+1,j)]);
        }
    }
    S=0;T=(n*m+1);
    for(int j = 1;j <= m-1;j ++) add(id(1,j),T,mp[getpos(1,j+1)]);
    for(int i = 1;i <= n-1;i ++) add(id(i,m-1),T,mp[getpos(i,m)]);
    printf("%d\n",dijkstra(S,T));
    return 0;
}
