#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mod = 1e9;


struct matrix {
    int n,m,a[355][355];
    matrix() { n=m=0; memset(a,0,sizeof a); }
}F;

matrix operator *(const matrix &a,const matrix &b) {
    matrix ans;
    ans.n = a.n;
    ans.m = b.m;
    for(int i = 0;i < a.n;i ++) ans.a[i][i] = 0;
    for(int i = 0;i < ans.n;i ++) {
        for(int j = 0;j < ans.m;j ++) {
            for(int k = 0;k < a.m;k ++) {
                (ans.a[i][j] += 1ll*a.a[i][k]*b.a[k][j]%mod) %= mod;
            }
        }
    }
    return ans;
}


int n,f[665],g[665];
LL m;

int main() {
    scanf("%d%lld",&n,&m);
    F.n=F.m=1<<n;
    for(int S = 0;S < (1<<n);S ++) {
        for(int i = 0;i < (1<<n);i ++) g[i] = f[i] = 0;
        f[S] = 1;
        int mask = (1<<n)-1;
        for(int i = 1;i <= n;i ++) {
            for(int s = 0;s < (1<<n);s ++) {
                if(s>>(n-1)&1) {
                    if(i!=1&&!(s&1)) g[((s<<1)^3)&mask]+=f[s];
                    g[(s<<1)&mask] += f[s];
                    g[((s<<1)^1)&mask] += f[s];
                }
                else {
                    g[(s<<1^1)&mask] += f[s];
                }
            }
            for(int s = 0;s < (1<<n);s ++) f[s] = g[s],g[s] = 0;
        }
        for(int s = 0;s < (1<<n);s ++) {
            F.a[s][S] = f[s];
        }
    }
 /*   for(int s = 0;s < (1<<n);s ++,puts(""))
        for(int S = 0;S < (1<<n);S ++) {
            printf("%d ",F.a[s][S]);
        }*/
    matrix ans;
    ans.n = 1<<n;
    ans.m = 1<<n;
    for(int i = 0;i < (1<<n);i ++) ans.a[i][i] = 1;
    while(m) {
        if(m&1) ans = ans * F;
        F = F * F;
        m>>=1;
    }
    LL A = 0;
    //for(int i = 0;i < (1<<n);i ++)
        (A += ans.a[(1<<n)-1][(1<<n)-1]) %= mod;
    printf("%lld\n",A);
}
