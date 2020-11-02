#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
bool f[101][101],us[1005];
int r,S,M,D,n,x,y,a[1050],s[30][25],m[30][25],d[30][25];
ll ans,A;

bool bao(ll A)
{
    if((A>1000000000000000000ll)||(A<0)) return true;
    return false;
}


ll cf(ll a,ll b)
{
    ll ans = 0;
    while(b)
    {
        if(b & 1)
        {
            ans += a;
            if(bao(ans)) { puts("too many"); exit(0); }
        }
        a += a;
        b >>= 1;
    }
    return ans;
}


bool check()
{
    for (int i=1;i<=S;i++)
    for (int j=1;j<=M;j++)if (!f[i][S+j])
    for (int k=1;k<=D;k++)if ((!f[i][S+M+k])&&(!f[S+j][S+M+k]))
        {ans=1;
         memset(us,0,sizeof(us));
         for (int l=1;l<=s[i][0];l++)if (!us[s[i][l]]){
                ans=cf(ans,a[s[i][l]]);us[s[i][l]]=1;
                if(bao(ans)) return false;
                }
         for (int l=1;l<=m[j][0];l++)if (!us[m[j][l]]){
                ans=cf(ans,a[m[j][l]]);us[m[j][l]]=1;
                if(bao(ans)) return false;
                }
         for (int l=1;l<=d[k][0];l++)if (!us[d[k][l]]){
                ans=cf(ans,a[d[k][l]]);us[d[k][l]]=1;
                if(bao(ans)) return false;
                }
       // printf("%d %d %d %I64d\n",i,j,k,ans);
        A+=ans;
        if(bao(A)) return false;
        }
    return true;
}


int main(){
    scanf("%d%d%d%d%d",&r,&S,&M,&D,&n);
    for (int i=1;i<=r;i++)scanf("%d",&a[i]);
    for (int i=1;i<=S;i++){
    scanf("%d",&s[i][0]);
    for (int j=1;j<=s[i][0];j++)scanf("%d",&s[i][j]);
    }
    for (int i=1;i<=M;i++){
    scanf("%d",&m[i][0]);
    for (int j=1;j<=m[i][0];j++)scanf("%d",&m[i][j]);
    }
    for (int i=1;i<=D;i++){
    scanf("%d",&d[i][0]);
    for (int j=1;j<=d[i][0];j++)scanf("%d",&d[i][j]);
    }
    for (int i=1;i<=n;i++){
    scanf("%d%d",&x,&y);
    f[x][y]=f[y][x]=1;
    }
    if (!check())puts("too many");else
    printf("%I64d\n",A);
   // for(;;);
    return 0;
}
