#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXM=1000000;
ll a,b,m;
ll phi[MAXM+4];
int tot;
bool check[MAXM+4];
ll prime[MAXM+4];
ll fp(ll x,ll y,ll mod){
    if(y==0)return 1;
    ll temp;
    if(y&1){
        temp=fp(x,y-1,mod);
        (temp*=x)%=mod;
       // if(temp>mod)temp=temp%mod+mod;
        return temp;
    }
    else{
        ll temp=fp(x,y>>1,mod);
        (temp*=temp)%=mod;
       // if(temp>mod)temp=temp%mod+mod;
        return temp;
    }
}

bool islarge(ll a,ll b,ll p) {
    ll ans = 1;
    for(int i = 1;i <= b;i ++) {
        if(ans >= (p + a - 1) / a) return true;
        ans *= a;
    }
    return false;
}

ll dfs(ll a,ll b,ll p) {
    if(b==1) {
        if(a < p) return a;
        return a%p+p;
    }
    if(p == 1) return 1;
    ll mi = dfs(a,b-1,phi[p]);
    if(a == 1) return 1;

    ll ans = fp(a,mi,p);
   // printf("%d %d %d = %d\n",l,r,p,ans);
    return islarge(a,mi,p) ? ans%p+p : ans;
}

int w33ha(){
    scanf("%lld%lld%lld",&a,&b,&m);
    if(b==0)return printf("%lld\n",1LL%m),0;
    ll ans=dfs(a,b,m)%m;
    //cout<<dfs(a,b,m)<<endl;
    printf("%lld\n",ans);
    return 0;
}
void prework(){
    memset(check,0,sizeof(check));
    phi[1]=1;
    tot=0;
    for(int i=2;i<=MAXM;i++){
        if(!check[i]){
            prime[tot++]=i;
            phi[i]=i-1;
        }
        for(int j=0;j<tot;j++){
            if(i*prime[j]>MAXM)break;
            check[i*prime[j]]=1;
            if(i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            else{
                phi[i*prime[j]]=phi[i]*(prime[j]-1);
            }
        }
    }
}
int main(){
    prework();
    int T;scanf("%d",&T);
    while(T--)w33ha();
    return 0;
}
/*
5
2 0 3
3 1 2
3 1 100
3 2 16
5 3 233
*/

