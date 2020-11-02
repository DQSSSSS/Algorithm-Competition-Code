#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
const int N=1000010;
int n;int m;
struct data{int v;int nxt;}edge[2*N];
int alist[N];int cnt;
inline void add(int u,int v){edge[++cnt].v=v;edge[cnt].nxt=alist[u];alist[u]=cnt;}
int dfin[N];int dfou[N];int dfu;int fa[22][N];bool book[N];ll dep[N];
void dfs(int x)
{
    for(int i=0;fa[i][x];i++){fa[i+1][x]=fa[i][fa[i][x]];}//����Ԥ����
    dfin[x]=++dfu;book[x]=true;int nxt=alist[x];//��¼��ջ˳��
    while(nxt)
    {
        int v=edge[nxt].v;
        if(!book[v]){dep[v]=dep[x]+1;fa[0][v]=x;dfs(v);}
        nxt=edge[nxt].nxt;
    }dfou[x]=++dfu;return;//��¼��ջ˳��
}
inline int lca(int x,int y)//������lca
{
    if(dep[x]<dep[y])swap(x,y);int del=dep[x]-dep[y];
    for(int i=0;del;del>>=1,i++){if(del&1)x=fa[i][x];}if(x==y){return x;}
    for(int i=21;i>=0;i--){if(fa[i][x]!=fa[i][y]){x=fa[i][x],y=fa[i][y];}}
    return fa[0][x];
}
inline bool cmp(int x,int y)//��ŷ��������ıȽϺ���
{
    int key1=(x>0)?dfin[x]:dfou[-x];
    int key2=(y>0)?dfin[y]:dfou[-y];
    return key1<key2;
}
int tp[4*N];ll sum[N];ll siz[N];ll mi[N];ll ma[N];bool vis[N];
ll tot[N];stack <int> s;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++){int u;int v;scanf("%d%d",&u,&v);add(u,v);add(v,u);}
    dfs(1);//��Ԥ����
    scanf("%d",&m);
    for(int i=1;i<=n;i++){mi[i]=0x7f7f7f7f7f;}
    for(int i=1;i<=m;i++)
    {
        ll ans1=0;ll ans2=0x7f7f7f7f7f;ll ans3=0;
        int k;scanf("%d",&k);int cnt=k;
        for(int i=1;i<=k;i++)
        {scanf("%d",&tp[i]);mi[tp[i]]=0;siz[tp[i]]=1;vis[tp[i]]=true;}//����dp�ı߽�����
        sort(tp+1,tp+k+1,cmp);tp[++cnt]=-tp[1];//�����Ȱ�dfs����һ��
        for(int i=2;i<=k;i++)
        {
            int lc=lca(tp[i],tp[i-1]);tp[++cnt]=-tp[i];//����lca��ÿһ������������һ��
            if(!vis[lc]){tp[++cnt]=lc;tp[++cnt]=-lc;vis[lc]=true;}
        }
        sort(tp+1,tp+cnt+1,cmp);//ǿ�����ŷ����
        for(int i=1;i<=cnt;i++)
        {
            if(tp[i]>0){s.push(tp[i]);continue;}//������ջ
            if(tp[i]<0)
            {
                int now=s.top();s.pop();//��ջ�Ļ��������͵�ǰջ���϶��Ǹ��ӹ�ϵ����ʼdp
                if(!s.empty())//������pop�������
                {
                    int to=s.top();ll dis=(dep[now]-dep[to]);//����dis
                    sum[now]+=siz[now]*dis;//����·���θ�
                    ans1+=siz[to]*sum[now]+siz[now]*sum[to];//���´�
                    siz[to]+=siz[now];sum[to]+=sum[now];//����sum
                    mi[now]+=dis;ans2=min(ans2,mi[to]+mi[now]);mi[to]=min(mi[to],mi[now]);//����min
                    ma[now]+=dis;ans3=max(ans3,ma[to]+ma[now]);ma[to]=max(ma[to],ma[now]);//����max
                }
                siz[now]=0;sum[now]=0;mi[now]=0x7f7f7f7f7f;ma[now]=0;vis[now]=false;//��ջ��ʱ��ǵ������Ϣ
            }
        }
        printf("%lld %lld %lld\n",ans1,ans2,ans3);//�����
    }return 0;//�ݰݳ���~
}
