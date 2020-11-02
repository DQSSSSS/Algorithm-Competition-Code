#include<stdio.h>
#include<map>
#include<iostream>
using namespace std;
#define ll long long
#define mod 1000000007
#define T 1000000
int pr[1000010],mu[1000010],f[1000010];
bool np[1000010];
int ad(int a,int b){return(a+b)%mod;}
int de(int a,int b){return(a-b)%mod;}
int mul(int a,int b){return a*(ll)b%mod;}
void sieve(){
    int i,j,m=0;
    np[1]=1;
    mu[1]=1;
    for(i=2;i<=T;i++){
        if(!np[i]){
            m++;
            pr[m]=i;
            mu[i]=-1;
        }
        for(j=1;j<=m;j++){
            if(pr[j]*(ll)i>T)break;
            np[i*pr[j]]=1;
            if(i%pr[j]==0)break;
            mu[i*pr[j]]=-mu[i];
        }
    }
    for(i=1;i<=T;i++){
        if(mu[i]==0)continue;
        for(j=1;i*(ll)j<=T;j++)f[i*j]=ad(f[i*j],mul(mu[i],mul(j-1,j-2)));
    }
    for(int i = 1;i <= 100;i ++) std::cout << f[i] << std::endl;
    for(i=2;i<=T;i++)f[i]=ad(f[i],f[i-1]);
}
map<int,int>res;
map<int,int>::iterator it;
int dj(int n){
    if(n<=T)return f[n];
    it=res.find(n);
    if(it!=res.end())return it->second;
    int i,nex,s=mul(mul(n,n-1),mul(n-2,333333336));
    for(i=2;i<=n;i=nex+1){
        nex=n/(n/i);
        s=de(s,mul(nex-i+1,dj(n/i)));
    }
    return res[n]=s;
}
int main(){
    sieve();
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        res.clear();
        printf("%d\n",(dj(n)+mod)%mod);
    }
}
