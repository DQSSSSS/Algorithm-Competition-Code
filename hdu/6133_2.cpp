#include<stdio.h>
#include<vector>
#include<algorithm>
#define N 100005
using namespace std;
typedef long long ll;
int a[N],b[N];
vector<int>vt[N];
ll tree[N*18],ans[N*18];
int size[N*18],root[N],lchild[N*18],rchild[N*18];
int tot,top;
void insert(int L,int R,int x,int root)
{
    ans[root]=tree[root]=b[x];
    size[root]=1;
    lchild[root]=rchild[root]=0;
    if(L==R)return ;
    int mid=L+R>>1;
    if(x<=mid)insert(L,mid,x,lchild[root]=++tot);
    else insert(mid+1,R,x,rchild[root]=++tot);
}
int Merge(int root1,int root2)
{
    if(!root1) return root2;
    if(!root2) return root1;
    lchild[root1]=Merge(lchild[root1],lchild[root2]);
    rchild[root1]=Merge(rchild[root1],rchild[root2]);
    tree[root1]+=tree[root2];
    size[root1]+=size[root2];
    if(!lchild[root1]&&!rchild[root1])ans[root1]=(tree[root1]/size[root1]+tree[root1])*size[root1]/2;
    else ans[root1]=ans[lchild[root1]]+ans[rchild[root1]]+tree[lchild[root1]]*size[rchild[root1]];
    return root1;
}
void dfs(int u,int fa)
{
    int pos=lower_bound(b+1,b+top,a[u])-b;
    insert(1,top-1,pos,root[u]=++tot);
    for(int i=0;i<vt[u].size();i++)
    {
        int to=vt[u][i];
        if(to==fa)continue;
        dfs(to,u);
        Merge(root[u],root[to]);
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("std.txt","w",stdout);

    int T;
    scanf("%d",&T);
    while(T--)
    {
        tot=0;
        for(int i=0;i<100005;i++)vt[i].clear(),ans[i]=tree[i]=size[i]=0;
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(b+1,b+n+1);
        top=unique(b+1,b+n+1)-b;
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            vt[u].push_back(v);
            vt[v].push_back(u);
        }
        dfs(1,1);
        for(int i=1;i<=n;i++)printf("%lld ",ans[root[i]]);
        printf("\n");
    }
}
