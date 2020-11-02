#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;struct Edge {
    int to,next,id;
    Edge(int _to=0,int _next=-1,int _id=0):to(_to),next(_next),id(_id) {};
} edge[maxn*2];
int head[maxn],etot;
inline void addedge(int u,int v,int id) {
    edge[++etot]=Edge(v,head[u],id);
    head[u]=etot;
}
vector<int> nodes[maxn];
int Cnt;
int dfn[maxn],low[maxn],tot;
bool Vis[maxn];
int S[maxn],top;
int id[maxn];
void tarjan(int x,int fa) {
    low[x]=dfn[x]=++tot;
    S[++top]=x;
    Vis[x]=1;
    for(register int i=head[x]; ~i; i=edge[i].next) {
        int v=edge[i].to;
        if(v==fa) {fa=0;continue;}
        if(!dfn[v]) {
            tarjan(v,x);
            low[x]=min(low[x],low[v]);
        } else if(Vis[v])
            low[x]=min(low[x],dfn[v]);
    }
    if(low[x]==dfn[x]) {
        Cnt++;
        while(1) {
            int now=S[top--];
            Vis[now]=0;
            id[now]=Cnt;
            nodes[Cnt].push_back(now);
            if(now==x) break;
        }
    }
}
int a[maxn],ans[maxn];
vector<int>v[maxn];
vector<int>edg[maxn],eid[maxn];
int summ;
bool vis[maxn];
int sz[maxn],son[maxn];
vector<int>vv;
int getid(int x) {
    return lower_bound(vv.begin(),vv.end(),x)-vv.begin()+1;
}
void init(int now,int pre=-1){
    vis[now]=1;
    sz[now]=v[now].size();
    for(int it:v[now])vv.push_back(a[it]);
    for(int to:edg[now]){
        if(to==pre)continue;
        init(to,now);
        sz[now]+=sz[to];
        if(!son[now]||sz[to]>sz[son[now]])
            son[now]=to;
    }
}
int tp[maxn],tp2[maxn],cnt[maxn],cnt2[maxn],Max=0,Max2=0;
bool big[maxn];
void update(int nows,int pre,int val){
    for(int now:v[nows]){
        tp[cnt[a[now]]]--;
        cnt[a[now]]+=val;
        tp[cnt[a[now]]]++;
        if(cnt[a[now]]>Max)
            Max=cnt[a[now]];
        if(!tp[Max])Max--;
        tp2[cnt2[a[now]]]--;
        cnt2[a[now]]-=val;
        tp2[cnt2[a[now]]]++;
        if(cnt2[a[now]]>Max2)
            Max2=cnt2[a[now]];
        if(!tp2[Max2])Max2--;
    }
    for(int to:edg[nows])
        if(to!=pre&&big[to]==0)
            update(to,nows,val);
}
void update2(int nows,int pre,int val){
    for(int now:v[nows]){
        tp2[cnt2[a[now]]]--;
        cnt2[a[now]]+=val;
        tp2[cnt2[a[now]]]++;
        if(cnt2[a[now]]>Max2)
            Max2=cnt2[a[now]];
        if(!tp2[Max2])Max2--;
    }
}
int temp;
void dfs(int now,int pre=-1,int kep=0,int id=0){
    int tid=0;
    for(register int i=0;i<edg[now].size();i++){
        int to=edg[now][i];
        if(to==son[now])tid=eid[now][i];
        if(to==pre||to==son[now])continue;
        dfs(to,now,0,eid[now][i]);
    }
    if(son[now])
        dfs(son[now],now,1,tid),big[son[now]]=1;
    update(now,pre,1);
    ans[id]=Max+Max2-temp;
    big[son[now]]=0;
    if(!kep)update(now,pre,-1);
}
void init2(int now,int pre=-1){
    for(int it:v[now])a[it]=getid(a[it]);
    update2(now,0,1);
    for(int to:edg[now]){
        if(to==pre)continue;
        init2(to,now);
    }
}
void solve(int now){
    vv.clear();
    init(now);
    for(register int i=0;i<=sz[now];i++)tp[i]=tp2[i]=cnt[i]=cnt2[i]=big[i]=0;Max=Max2=0;
    sort(vv.begin(),vv.end());
    vv.erase(unique(vv.begin(),vv.end()),vv.end());
    init2(now);
    summ+=Max2;
    temp=Max2;
    dfs(now);
}
int main()
{
    freopen("B.in","r",stdin);
    freopen("std.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(register int i=1;i<=n;i++)head[i]=-1,dfn[i]=son[i]=vis[i]=Vis[i]=0,v[i].clear(),edg[i].clear(),eid[i].clear();
        etot=tot=Cnt=top=0;
        for(register int i=1;i<=n;i++)scanf("%d",a+i);
        for(register int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(v,u,i);
            addedge(u,v,i);
        }
        for(register int i=1;i<=n;i++)if(!dfn[i])tarjan(i,0);
        for(register int i=1;i<=n;i++)v[id[i]].push_back(i);
        summ=0;
        for(register int i=1;i<=n;i++){
            for(register int j=head[i];~j;j=edge[j].next){
                int u=id[i],to=id[edge[j].to];
                if(u==to){
                    ans[edge[j].id]=0;
                    continue;
                }
                edg[u].push_back(to);eid[u].push_back(edge[j].id);
            }
        }
        for(register int i=1;i<=Cnt;i++)
            if(!vis[i])
                solve(i);
        for(register int i=1;i<=m;i++){
            if(i>1)putchar(' ');
            printf("%d",ans[i]+summ);
        }
        puts("");
    }
    return 0;
}
