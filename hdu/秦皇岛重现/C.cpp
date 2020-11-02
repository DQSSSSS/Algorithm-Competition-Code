//#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 5000 + 10;
const int mod = 998244353;
const int INF = 1e9 + 10;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a<'0'||a>'9') { if(a=='-') flag=1; a=getchar(); }
    while(a>='0'&&a<='9') { n=n*10+a-'0'; a=getchar(); }
    if(flag) n=-n;
    return n;
}

inline __attribute__((always_inline)) void add(int &x,const int &y) {
    if(y==0) return ;
    x += y;
    if(x<0) x+=mod;
    else if(x>=mod) x-=mod;
}

struct haha {
    int a[SZ],n;
    int f[SZ][SZ],g[SZ],ans[SZ];
    int pr[SZ];
    int nx[SZ];

    inline __attribute__((always_inline)) void work() {
        int tmp[111] = {};
        for(int i = 1;i <= n;i ++) pr[i] = tmp[a[i]],tmp[a[i]] = i;
        for(int i = 1;i <= 100;i ++) tmp[i]=n+1;
        for(int i = n;i >= 1;i --) nx[i] = tmp[a[i]],tmp[a[i]] = i;

        for(int i = 0;i <= n;i ++) f[0][i] = 1;

        for(int k = 1;k <= n;k ++) {
            //g[0] = f[0]; f[0] = 0;
            //for(int i = 1;i <= n;i ++) g[i]=g[i-1],add(g[i],f[i]),f[i]=0;
            for(int i = k;i <= n;i ++) {
                int l = pr[i],r = i-1,w;
                w = f[k-1][r];
                if(l) add(w,-f[k-1][l-1]);
                f[k][i] = f[k][i-1];
                add(f[k][i],w);
            }
            ans[k] = f[k][n];
           // for(int i = 1;i <= n;i ++) printf("%d ",f[k][i]-f[k][i-1]); puts("");
        }
    }
}a,b;

int n,m;
int sum[SZ][SZ];
int sum2[SZ][SZ];
/*
inline int get_sum(int x1,int y1,int x2,int y2) {
    LL x = 1ll*sum[x2][y2]
        -(x1?sum[x1-1][y2]:0)
        -(y1?sum[x2][y1-1]:0)
        +(x1&&y1?sum[x1-1][y1-1]:0);
    x %= mod; //x += mod; x %= mod;
    return x;
}

inline int get_sum2(int x1,int y1,int x2,int y2) {
    LL x = 1ll*sum2[x1][y1]
        -(x2<=n?sum2[x2+1][y1]:0)
        -(y2<=m?sum2[x1][y2+1]:0)
        +(x2<=n&&y2<=m?sum2[x2+1][y2+1]:0);
    x %= mod; //x += mod; x %= mod;
    return x;
}
*/


inline __attribute__((always_inline)) int get_sum(const int &x1,const int &y1,const int &x2,const int &y2) {
    int A = sum[x2][y2];
    add(A,(x1?-sum[x1-1][y2]:0));
    add(A,(y1?-sum[x2][y1-1]:0));
    add(A,(x1&&y1?sum[x1-1][y1-1]:0));
    return A;
}

inline __attribute__((always_inline)) int get_sum2(const int &x1,const int &y1,const int &x2,const int &y2) {
    int A = sum2[x1][y1];
    add(A,(x2<=n?-sum2[x2+1][y1]:0));
    add(A,(y2<=m?-sum2[x1][y2+1]:0));
    add(A,(x2<=n&&y2<=m?sum2[x2+1][y2+1]:0));
    return A;
}

inline __attribute__((always_inline)) void work() {
    for(int i = 0;i <= n+1;i ++) {
        for(int j = 0;j <= m+1;j ++) {
            sum[i][j]=sum2[i][j]=0;
        }
    }
    for(int i = 0;i <= n;i ++) sum[i][0]=1;
    for(int i = 0;i <= m;i ++) sum[0][i]=1;
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            if(a.a[i] != b.a[j]) sum[i][j] = 0;
            else {
                sum[i][j] = get_sum(a.pr[i],b.pr[j],i-1,j-1);
            //    printf("%d %d: (%d,%d) (%d,%d) %d\n",i,j,a.pr[i],b.pr[j],i-1,j-1,f[i][j]);
            }
            add(sum[i][j],sum[i-1][j]);
            add(sum[i][j],sum[i][j-1]);
            add(sum[i][j],-sum[i-1][j-1]);
            //sum[i][j] = (1ll*sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + f[i][j])%mod;
        }
    }

    for(int i = n+1;i >= 0;i --) sum2[i][m+1]=1;
    for(int i = m+1;i >= 0;i --) sum2[n+1][i]=1;
    for(int i = n;i >= 1;i --) {
        for(int j = m;j >= 1;j --) {
            sum2[i][j] = get_sum2(i+1,j+1,a.nx[i],b.nx[j]);
           // printf("%d %d: (%d,%d) (%d,%d) %d\n",i,j,i+1,j+1,a.nx[i],b.nx[j],g[i][j]);
            add(sum2[i][j],sum2[i+1][j]);
            add(sum2[i][j],sum2[i][j+1]);
            add(sum2[i][j],-sum2[i+1][j+1]);

            //sum2[i][j] = (1ll*sum2[i+1][j] + sum2[i][j+1] - sum2[i+1][j+1] + g[i][j])%mod;
        }
    }
/*
    for(int i = 1;i <= n;i ++,puts(""))
        for(int j = 1;j <= m;j ++)
            printf("%11d",g[i][j]);
*/
   /* for(int i = 1;i <= n+1;i ++,puts(""))
        for(int j = 1;j <= m+1;j ++)
            printf("%11d",sum2[i][j]);*/
}

int main() {
   // freopen("C.in","r",stdin);
    while(~scanf("%d%d",&n,&m)) {
        a.n = n; b.n = m;
        for(int i = 1;i <= n;i ++) a.a[i]=read();//scanf("%d",&a.a[i]);
        for(int i = 1;i <= m;i ++) b.a[i]=read();//scanf("%d",&b.a[i]);
        a.work(); b.work();
        work();
        int ans = 0;
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= m;j ++) {
                if(j < i)
                    add(ans,1ll * a.ans[i] * b.ans[j] % mod);
                if(a.a[i] > b.a[j])
                    add(ans,1ll * get_sum(a.pr[i],b.pr[j],i-1,j-1) * sum2[i+1][j+1] % mod);
            }
        }
      //  ans %= mod; ans += mod; ans %= mod;
        printf("%d\n",ans);
    }
    return 0;
}
