#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
#define ll long long
#define RG register
#define MAX 111111
inline int read()
{
    RG int x=0,t=1;RG char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=-1,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return x*t;
}
int n,m,V[MAX];
struct Line{int v,next;}e[MAX<<1];
int h[MAX],cnt=1;
inline void Add(int u,int v){e[cnt]=(Line){v,h[u]};h[u]=cnt++;}
/********************************************************************/
int size[MAX],dfn[MAX],top[MAX],dep[MAX],fa[MAX],tim,hson[MAX];
void dfs1(int u,int ff)
{
    fa[u]=ff;size[u]=1;dep[u]=dep[ff]+1;
    for(int i=h[u];i;i=e[i].next)
    {
        int v=e[i].v;if(v==ff)continue;
        dfs1(v,u);size[u]+=size[v];
        if(size[v]>size[hson[u]])hson[u]=v;
    }
}
void dfs2(int u,int tp)
{
    top[u]=tp;
    if(hson[u])dfs2(hson[u],tp);
    for(int i=h[u];i;i=e[i].next)
        if(e[i].v!=fa[u]&&e[i].v!=hson[u])
            dfs2(e[i].v,e[i].v);
}
int LCA(int u,int v)
{
    while(top[u]^top[v])dep[top[u]]<dep[top[v]]?v=fa[top[v]]:u=fa[top[u]];
    return dep[u]<dep[v]?u:v;
}
int Dis(int u,int v){return dep[u]+dep[v]-2*dep[LCA(u,v)];}
/********************************************************************/
bool vis[MAX];
int Fa[MAX],Size,root,mx;
void Getroot(int u,int ff)
{
    size[u]=1;int ret=0;
    for(int i=h[u];i;i=e[i].next)
    {
        int v=e[i].v;if(v==ff||vis[v])continue;
        Getroot(v,u);size[u]+=size[v];
        ret=max(ret,size[v]);
    }
    ret=max(ret,Size-size[u]);
    if(ret<mx)mx=ret,root=u;
}
void DFS(int u,int ff)
{
    vis[u]=true;Fa[u]=ff;
    for(int i=h[u];i;i=e[i].next)
    {
        int v=e[i].v;if(vis[v])continue;
        mx=Size=size[v];
        Getroot(v,u);DFS(root,u);
    }
}
/********************************************************************/
int rt[MAX<<1],tot;
struct Node{int ls,rs,v;}t[MAX<<6];
void Modify(int &x,int l,int r,int p,int w)
{
    if(!x)x=++tot;t[x].v+=w;if(l==r)return;
    int mid=(l+r)>>1;
    if(p<=mid)Modify(t[x].ls,l,mid,p,w);
    else Modify(t[x].rs,mid+1,r,p,w);
}
int Query(int x,int l,int r,int L,int R)
{
    if(!x)return 0;if(L<=l&&r<=R)return t[x].v;
    int mid=(l+r)>>1,ret=0;
    if(L<=mid)ret+=Query(t[x].ls,l,mid,L,R);
    if(R>mid)ret+=Query(t[x].rs,mid+1,r,L,R);
    return ret;
}
/********************************************************************/
void Modify(int x,int w)
{
    Modify(rt[x],0,n,0,w);
    for(int i=x;Fa[i];i=Fa[i])
    {
        int dis=Dis(x,Fa[i]);
        Modify(rt[Fa[i]],0,n,dis,w);
        Modify(rt[i+n],0,n,dis,w);
    }
}
int Query(int x,int K)
{
    int ret=Query(rt[x],0,n,0,K);
    for(int i=x;Fa[i];i=Fa[i])
    {
        int dis=Dis(x,Fa[i]);if(dis>K)continue;
        ret+=Query(rt[Fa[i]],0,n,0,K-dis);
        ret-=Query(rt[i+n],0,n,0,K-dis);
    }
    return ret;
}
/********************************************************************/
int main()
{
    int __size__=128<<20;
    char*__p__=(char*)malloc(__size__)+ __size__;
    __asm__("movl %0, %%esp\n"::"r"(__p__));
    freopen("3730/10.in","r",stdin);
    freopen("3730/std.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;++i)V[i]=read();
    for(int i=1;i<n;++i)
    {
        int u=read(),v=read();
        Add(u,v);Add(v,u);
    }
    dfs1(1,0);dfs2(1,1);
    Size=mx=n;Getroot(1,0);DFS(root,0);
    for(int i=1;i<=n;++i)Modify(i,V[i]);
    int ans=0;
    while(m--)
    {
        int opt=read(),x=read()^ans,y=read()^ans;
        if(opt==0)printf("%d\n",ans=Query(x,y));
        else Modify(x,y-V[x]),V[x]=y;
    }
    return 0;
}
