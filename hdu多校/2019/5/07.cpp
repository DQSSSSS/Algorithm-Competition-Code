#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=1e5+10;
const int mod=998244353;

int n,m,p1,p2,cnt=0;
LL f[MAXN];
int g[10];

int num[1111],use[1111];

int dfs(int d) {
    if(d == n + 1) {
        if(num[1] != p1 || num[n] != p2) return 0;
        bool f = 0;
        for(int i = 1;i < n;i ++) {
            if(abs(num[i+1]-num[i]) > 2) f = 1;
        }
        if(!f) {
        //    for(int i = 1;i <= n;i ++) printf("%d ",num[i]); puts("");
        }
        return f^1;
    }
    int ans = 0;
    for(int i = 1;i <= n;i ++) {
        if(!use[i]) {
            use[i] = 1;
            num[d] = i;
            ans += dfs(d+1);
            use[i] = 0;
        }
    }
    return ans;
}

int main(){
    f[1]=f[0]=f[2]=f[3]=1;
    for(int i=4;i<=100000;i++){
        f[i]=f[i-1];
        if (i>=3) f[i]+=f[i-3];
        f[i]%=mod;
    }
//    for(int i = 0;i <= 10;i ++) printf("%lld ",f[i]); puts("");
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&p1,&p2);
            LL ans=0;
            if(p2!=n&&p1!=1&&p2==p1+1) ans = 0;
            else {
                m=p2-p1;
                if (p1==1 && p2!=n) {
                    ans=f[m];
                }
                if (p1!=1 && p2==n) {
                    ans=f[m];
                }
                if (p1==1 && p2==n){
                    ans=f[n];
                }
                if(p1!=1 && p2 != n) {
                    ans=f[m-1];
                }
            }
            printf("%lld\n",ans);
    }
}
