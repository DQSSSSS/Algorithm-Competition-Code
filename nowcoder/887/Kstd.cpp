#include<bits/stdc++.h>

using namespace std;
#define rep(i,j,n) for(int i=j;i<=n;i++)

int T,n,Div,Div2;
long long ans;
int p[3500],g1[70010],num[70010],g2[70010],g3[70010],g[70010];
unordered_map<int,int> id;
void pre()
{
    p[0]=1;
    p[1]=2;
    for(int i=3;i*i<=1000000000;i+=2)
    {
        bool pp=true;
        for(int j=1;j<=p[0] && p[j]*p[j]<=i;j++)
            if(i%p[j]==0)
            {
                pp=false;
                break;
            }
        if(pp)
            p[++p[0]]=i;
    }
}
void GetG1(int n)
{
    rep(i,1,Div2)
        g1[i] = num[i] - 1;
    rep(i,1,p[0])
    {
        int P = p[i];
        for(int j = 1; P * P <= num[j]; j++)
        {
            int d = num[j] / P, k = id[d];
            g1[j] -= g1[k] - i + 1;
        }
    }
}
void GetG2(int n)
{
    rep(i,1,Div2)
        g2[i] = (num[i] - 1) / 4, g3[i] = (num[i] + 1) / 4;
    rep(i,2,p[0])
    {
        int P = p[i];
        if(P % 4 == 1)
        for(int j = 1; P * P <= num[j]; j++)
        {
            int d = num[j] / P, k = id[d];
            g2[j] -= g2[k] - g2[id[P - 1]];
            g3[j] -= g3[k] - g3[id[P - 1]];
        }
        else
        for(int j = 1; P * P <= num[j]; j++)
        {
            int d = num[j] / P, k = id[d];
            g2[j] -= g3[k] - g3[id[P - 1]];
            g3[j] -= g2[k] - g2[id[P - 1]];
        }
    }
}
void GetG(int n)
{
    //GetG1(n);
    GetG2(n);
    rep(i,1,Div2)
        g[i]=g3[i]+g2[i]*4+(num[i]>=2);
}
inline int f(int x)
{
    return (x%4 == 1 && x>=5) ? 4 : 1;
}
void Solve(long long t,int i,long long temp,int mx)
{
    int P = p[i];
    //cout<<"? "<<t<<' '<<i<<' '<<mx<<' '<<ans<<endl;
    //if(mx == i - 1)
        ans=ans+max(g[id[n/t]]-g[mx?id[p[mx]]:0],0)*temp;
    //cout<<"! "<<t<<' '<<i<<' '<<mx<<' '<<ans<<endl;
    if(P == 0 || P * P > n) return;
    //Solve(t,i+1,temp,mx);
    rep(j,i,p[0])
    {
        P=p[j];
        if(P*P>n/t) break;
        long long tt=t*P;
        int ftemp=f(P);
        if(tt<=n) Solve(tt,j+1,temp*ftemp,j);
        else break;
        ftemp+=f(P)-1;
        while(tt*P<=n)
        {
            tt*=P;
            ans=ans+temp*ftemp;
            Solve(tt,j+1,temp*ftemp,j);
            ftemp+=f(P)-1;
        }
    }
}
int main()
{
    cin>>T;
    pre();
    while(T--)
    {
        cin>>n;
        Div=sqrt(n);
        rep(i,1,Div) num[i]=n/i;
        if(n/Div == Div)
            {Div2=2*Div-1;for(int i=Div-1;i;i--) num[2*Div-i]=i;}
        else
            {Div2=2*Div;for(int i=Div;i;i--) num[2*Div-i+1]=i;}
        rep(i,1,Div2)
            id[num[i]]=i;
        GetG(n);
        g[0]=id[0]=0;
        /*rep(i,1,Div*2)
            cout<<id[i]<<' '<<g[id[i]]<<endl;*/
        ans=0;
        Solve(1,1,1,0);
        cout<<ans+1<<endl;
    }
}
