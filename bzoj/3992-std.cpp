#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=16384,K=13;
int n,m,x,S,i,j,k,q[500],ind[N],a[N],b[N],P=1004535809,G=3,g[K+1],ng[K+1],inv[N+1];
inline int pow(int a,int b,int P){int t=1;for(;b;b>>=1,a=(ll)a*a%P)if(b&1)t=(ll)t*a%P;return t;}
inline void NTT(int*a,int n,int t){
  for(int i=1,j=0;i<n-1;i++){
    for(int s=n;j^=s>>=1,~j&s;);
    if(i<j){int k=a[i];a[i]=a[j];a[j]=k;}
  }
  for(int d=0;(1<<d)<n;d++){
    int m=1<<d,m2=m<<1,_w=t==1?g[d]:ng[d];
    for(int i=0;i<n;i+=m2)for(int w=1,j=0;j<m;j++){
      int&A=a[i+j+m],&B=a[i+j],t=(ll)w*A%P;
      A=B-t;if(A<0)A+=P;
      B=B+t;if(B>=P)B-=P;
      w=(ll)w*_w%P;
    }
  }
  if(t==-1)for(int i=0,j=inv[n];i<n;i++)a[i]=(ll)a[i]*j%P;
}
int getG(int n){
  int i,j,t=0;
  for(i=2;i<n-1;i++)if((n-1)%i==0)q[t++]=i;
  for(i=2;;i++){
    for(j=0;j<t;j++)if(pow(i,q[j],n)==1)break;
    if(j==t)return i;
  }
}
int main(){
  for(g[K]=pow(G,(P-1)/N,P),ng[K]=pow(g[K],P-2,P),i=K-1;~i;i--)g[i]=(ll)g[i+1]*g[i+1]%P,ng[i]=(ll)ng[i+1]*ng[i+1]%P;
  for(inv[1]=1,i=2;i<=N;i++)inv[i]=(ll)(P-inv[P%i])*(P/i)%P;
  scanf("%d%d%d%d",&n,&m,&x,&S);
  for(G=getG(m),i=0,j=1;i<m-1;i++,j=(j*G)%m)ind[j]=i;
  while(S--){
    scanf("%d",&i);
    if(i)a[ind[i]]=1;
  }
  std::cout << G <<std::endl;
  for(int i = 0;i <m;i ++) cout << ind[i] << " "; puts("");
  for(m--,k=1;k<m;k<<=1);k<<=1;
  b[0] = 1;
  for(;n;n>>=1){
    if(n&1){
    for(int i = 0;i < k;i ++) cout << a[i] << " "; puts("");
    for(int i = 0;i < k;i ++) cout << b[i] << " "; puts("");
      NTT(a,k,1);
      NTT(b,k,1);
      for(i=0;i<k;i++)b[i]=(ll)b[i]*a[i]%P;
      NTT(b,k,-1);
      for(i=m;i<k;i++)b[i%m]=(b[i%m]+b[i])%P,b[i]=0;
      for(int i = 0;i < k;i ++) cout << b[i] << " "; puts("");
    }
    for(int i = 0;i < k;i ++) cout << a[i] << " "; puts("");
    for(int i = 0;i < k;i ++) cout << a[i] << " "; puts("");
    NTT(a,k,1);
    for(i=0;i<k;i++)a[i]=(ll)a[i]*a[i]%P;
    NTT(a,k,-1);
    for(i=m;i<k;i++)a[i%m]=(a[i%m]+a[i])%P,a[i]=0;
    for(int i = 0;i < k;i ++) cout << a[i] << " "; puts("");

  }
  for(int i = 0;i < k;i ++) cout << b[i] << " "; puts("");
  return printf("%d",b[ind[x]]),0;
}
