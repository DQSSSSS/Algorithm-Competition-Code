#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=2e5+10;
const int mod=1e9+7;

int n,m,v[30];
LL f[3][MAXN],g[3][MAXN];
char ch1[MAXN],ch2[MAXN];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<26;i++) scanf("%d",&v[i]);
    scanf("%s",ch1+1);
    scanf("%s",ch2+1);
    for(int i=0;i<=m;i++) g[0][i]=1;
    for(int i=1;i<=n;i++){
        int a=i%2,b=a^1;
        g[a][0]=0;
        for(int j=1;j<=m;j++){
            if (ch1[i]!=ch2[j]){
                f[a][j]=0;
            } else{
                int r;
                if (i==1) r=j-1;
                else r=max(0,j-1-v[ch1[i-1]-'A']);
                f[a][j]=g[b][r];
            }
            g[a][j]=(g[a][j-1]+f[a][j])%mod;
        }
    }
    LL ans=0;
    for(int j=1;j<=m;j++){
        ans+=f[n%2][j];
        ans%=mod;
    }
    printf("%lld\n",ans);
    return 0;
}

/*
40 4
4 5 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
ABBBBABBBBABBBBABBBBABBBBABBBBABBBBABBBB
ABBA
*/
