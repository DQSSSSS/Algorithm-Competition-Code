#include <cstdio>
#include <cstdlib>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define sqr(q) ((q)*(q))
using namespace std;
typedef long long LL;
const int N=20000500,mo=1e9+7,M=224737;
const LL eni=500000004,sni=166666668;
LL n,ans;
bool prz[N+10];
int pr[N/2];
int phi[N+10];
int Hx[M+1][2];
int co;
int HX(LL q)
{
    int i=q%M;
    while(Hx[i][0]&&Hx[i][0]!=q)i=(i+1)%M;
    return i;
}
LL SM(LL s,LL t)
{
    if((s+t)&1)return (s+t)%mo*(((t-s+1)>>1)%mo)%mo;
    return ((s+t)>>1)%mo*((t-s+1)%mo)%mo;
}
LL PF(LL q)
{
    q%=mo;
    return q*(q+1)%mo*(2*q+1)%mo*sni%mo;
}
LL Gphi(LL q)
{
    if(q<=N)return phi[q];
    int t=HX(q);
    if(Hx[t][0])return Hx[t][1];
    Hx[t][0]=q;
    LL ans=0;
    for(LL i=2,nx;i<=q;i=nx+1)
    {
        nx=q/(q/i);
        ans=(ans+(PF(nx)-PF(i-1))*Gphi(q/i))%mo;
    }
    q%=mo;
    return Hx[t][1]=(sqr(SM(1,q))-ans)%mo;
}
int main()
{
    phi[1]=1;
    fo(i,2,N)
    {
        if(!prz[i])pr[++pr[0]]=i,phi[i]=i-1;
        fo(j,1,pr[0])
        {
            int t=pr[j]*i;
            if(t>N)break;
            prz[t]=1;
            phi[t]=phi[i]*pr[j];
            if(i%pr[j]==0)break;
            phi[t]=phi[i]*(pr[j]-1);
        }
    }
    fo(i,2,N)phi[i]=((LL)phi[i]*(sqr((LL)i)%mo)%mo+phi[i-1])%mo;
    scanf("%lld",&n);
    for(LL i=2,nx;i<=n;i=nx+1)
    {
        nx=n/(n/i);
        ans=(ans+SM(1,n/i)*(Gphi(nx)-Gphi(i-1))%mo*eni%mo)%mo;
    }
    printf("%lld\n",((ans*2+SM(1,n))%mo+mo)%mo);
    return 0;
}
