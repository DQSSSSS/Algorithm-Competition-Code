#include<cstdio>
#include<cstring>
#include<string>
#include <iostream>
#include<algorithm>
using namespace std;
const int maxn=200005;
int sz[200100];
struct SAM
{
  int ch[maxn][26];
  int pre[maxn],step[maxn];
  int last,id,ans;
  void init()
  {
    ans=last=id=0;
    memset(ch[0],-1,sizeof(ch[0]));
    pre[0]=-1; step[0]=0;
  }
  void Insert(int c)
  {
    int p=last,np=++id;
    step[np]=step[p]+1;
    memset(ch[np],-1,sizeof(ch[np]));
    sz[np] = 1;
    while(p!=-1&&ch[p][c]==-1)  ch[p][c]=np,p=pre[p];
    if(p==-1) pre[np]=0;
    else
      {
        int q=ch[p][c];
        if(step[q]!=step[p]+1)
          {
            int nq=++id;
            memcpy(ch[nq],ch[q],sizeof(ch[q]));
            step[nq]=step[p]+1;
            pre[nq]=pre[q];
            pre[np]=pre[q]=nq;
            while(p!=-1&&ch[p][c]==q) ch[p][c]=nq,p=pre[p];
          }
        else pre[np]=q;
      }
    last=np;

  }
}sam;
char s[100100];
int T,K, e;
struct edge{
  int from,to,n;
}a[200100];
int head[200200];

void addedge(int from, int to){
  a[++e] = (edge){from, to, head[from]};head[from] = e;
}
void dfs(int x){
  for (int i = head[x];i;i = a[i].n){
    dfs(a[i].to);
    sz[x] += sz[a[i].to];
  }
}
int main()
{
  scanf("%d",&T);
  while (T--){
    scanf("%d",&K);
    scanf("%s",s);
    memset(sz, 0, sizeof(sz));
    sam.init();
    int len = strlen(s);
    for (int i = 0; i < len; i++)
      sam.Insert(s[i] - 'a');
    e = 0;
    memset(head,0,sizeof(head));
    for (int i = 1; i <= sam.id; i++)
      addedge(sam.pre[i],i);
    dfs(0);
    long long ans = 0;
    for (int i = 0;i <= sam.id; i++)
      if (sz[i] == K) ans += sam.step[i] - sam.step[sam.pre[i]];
    cout << ans << endl;
    //    for (int i = 0;i <= sam.id; i++)
    //cerr << sam.pre[i] << ' ' << sam.ch[i][0] << ' ' << sam.ch[i][1] << ' ' << sam.step[i] << ' ' << sz[i] << endl;
  }
  return 0;
}
