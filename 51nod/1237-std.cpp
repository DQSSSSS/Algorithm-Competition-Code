#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include <tr1/unordered_map>
typedef long long ll;
using namespace std;
using namespace std::tr1;

const int maxn=10000000;

int prime[1000000],num;
int vst[maxn+5],phi[maxn+5];

const ll P=1e9+7;
const ll inv=500000004;

inline void Pre(){
  phi[1]=1;
  for (int i=2;i<=maxn;i++){
    if (!vst[i]) prime[++num]=i,phi[i]=i-1;
    for (int j=1;j<=num && (ll)i*prime[j]<=maxn;j++){
      vst[i*prime[j]]=1;
      if (i%prime[j]==0){
	phi[i*prime[j]]=phi[i]*prime[j];
	break;
      }else
	phi[i*prime[j]]=phi[i]*phi[prime[j]];
    }
  }
  for (int i=1;i<=maxn;i++) (phi[i]+=phi[i-1])%=P;
}

unordered_map<ll,int> S;

inline int Sum(ll n){
  if (n<=maxn) return phi[n];
  if (S.find(n)!=S.end()) return S[n];
  int tem=(ll)(n%P)*((n+1)%P)%P*inv%P; ll l,r;
  for (l=2;l*l<=n;l++) (tem+=P-Sum(n/l))%=P;
  for (ll t=n/l;l<=n;l=r+1,t--)
    r=n/t,(tem+=P-(ll)(r-l+1)*Sum(t)%P)%=P;
  return S[n]=tem;
}

int main(){
  ll n; int Ans=0;
  Pre();
  scanf("%lld",&n);
  for (ll i=1,j;i<=n;i=j+1){
    j=n/(n/i);
    (Ans+=((n/i)%P)*((n/i)%P)%P*(Sum(j)+P-Sum(i-1))%P)%=P;
  }
  printf("%d\n",Ans);
  return 0;
}
