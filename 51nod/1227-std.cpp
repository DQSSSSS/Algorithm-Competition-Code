#include<map>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const long long Mod=1e9+7;
const long long inv=500000004;
const long long inv6=166666668;
int a,b,prm[5000010];
bool ext[5000010];
long long ans,phi[5000010];
map<long long,long long> rec;
void get_prime(int N){
    phi[1]=1;
    for (int i=2;i<=N;i++){
        if (ext[i]==false){
            prm[++prm[0]]=i;phi[i]=i-1;
        }
        for (int j=1;j<=prm[0];j++){
            if ((long long)i*prm[j]>N) break;
            ext[i*prm[j]]=true;
            if (i%prm[j]==0){
                phi[i*prm[j]]=phi[i]*prm[j];break;
            }else phi[i*prm[j]]=phi[i]*phi[prm[j]];
        }
    }
    for (int i=1;i<=N;i++) phi[i]=phi[i]*i%Mod;
    for (int i=1;i<=N;i++) phi[i]=(phi[i]+phi[i-1])%Mod;
}
long long S(long long l,long long r){
    long long s1=r*(r+1)/2;
    long long s2=(l-1)*l/2;
    return (s1-s2)%Mod;
}
long long Sumphi(long long n){
    if (n<=5000000) return phi[n];
    if (rec[n]!=0) return rec[n];
    long long sum=n*(n+1)%Mod;
    sum=sum*(2*n+1)%Mod;
    sum=sum*inv6%Mod;
    for (long long i=2,tail;i<=n;i=tail+1){
        tail=n/(n/i);
        sum=(sum-S(i,tail)*Sumphi(n/i)%Mod)%Mod;
    }
    return rec[n]=sum;
}
long long Getans(int n){
    long long sum=0;
    for (long long i=1,tail;i<=n;i=tail+1){
        tail=n/(n/i);
        sum=(sum+(tail-i+1)*Sumphi(n/i)%Mod)%Mod;
    }
    return ((sum+n)*inv)%Mod;
}
int main()
{
    get_prime(5000000);
    scanf("%d%d",&a,&b);
    ans=(Getans(b)-Getans(a-1))%Mod;
    printf("%I64d\n",(ans+Mod)%Mod);
    return 0;
}
