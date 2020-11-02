#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll v[34][34];
int n;
ll ans;
ll calc(int S){
    ll sum=0;
    for(int i=0;i<(n<<1);i++){
        for(int j=i+1;j<(n<<1);j++){
            int p=((S&(1<<i))==0),
                q=((S&(1<<j))==0);
            if(p!=q){
                sum+=v[i][j];
            }
        }
    }
    return sum;
}

int ansS;
void dfs(int x,int ls,int S){
    if(x>n){
        if(ans < calc(S)) {
            ans = calc(S);
            ansS = S;
        }
        return ;
    }
    for(int i=ls+1;i<(n<<1);i++){
        if(S&(1<<i))continue;
        dfs(x+1,i,S|(1<<i));
    }
}
int main(){
    ans=0;
    scanf("%d",&n);
    for(int i=0;i<(n<<1);i++){
        for(int j=0;j<(n<<1);j++){
            scanf("%lld",&v[i][j]);
        }
    }
    dfs(1,-1,0);
    printf("%lld\n",ans);
    for(int i = 0;i < 2*n;i ++)
        printf("%d",ansS>>i&1);
    return 0;
}

