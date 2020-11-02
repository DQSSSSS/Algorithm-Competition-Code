#include<bits/stdc++.h>

using namespace std;

const double eps=1e-7;

int T,n,m,a[10],cas;
vector<int>Djset[66];
double x[6666];

struct Simlex
{
    const static int maxm=30;
    const static int maxn=1088;
	double INF = 1e100;
    double eps=1e-10;
    int n;
    int m;
    double a[maxn][maxn];
    int B[maxm],N[maxn];

    void pivot(int r,int c)
    {
        swap(N[c],B[r]);
        a[r][c]=1/a[r][c];
        for(int j=0;j<=n; ++j) if(j!=c) a[r][j]*=a[r][c];
        for(int i=0; i<=m; ++i)if(i!=r){
            for(int j=0;j<=n; ++j)if(j!=c) a[i][j]-=a[i][c]*a[r][j];
            a[i][c]=-a[i][c]*a[r][c];
        }
    }
    bool feasible(){
        for(;;) {
            int r,c;
            double p = INF;
            for(int i=0; i<m; ++i) if(a[i][n]<p) p=a[r=i][n];
            if(p>-eps) return true;
            p = 0;
            for(int i=0; i<n; ++i) if(a[r][i]<p) p=a[r][c=i];
            if(p > -eps) return false;
           /* p = a[r][n] / a[r][c];
            for(int i=r+1; i<m; ++i) if(a[i][c]>eps){
            	double v=a[i][n]/a[i][c];
                if(v<p) { r=i; p=v;}
            }*/
            pivot(r,c);
        }
    }
    int simplex(int n,int m,double x[maxn],double&ret) {
        this->n=n;
        this->m=m;
        for(int i=0; i<n; ++i) N[i]=i;
        for(int i=0; i<m; ++i) B[i]=n+i;
        if(!feasible()) return 0;
        for(;;) {
        	int r,c;
        	double p=0;
        	for(int i=0; i<n; ++i) if(a[m][i]>p) p=a[m][c=i];
			if(p<eps) {
				for(int i=0; i<n; ++i) if(N[i]<n) x[N[i]]=0;
				for(int i=0; i<m; ++i) if(B[i]<n) x[B[i]]=a[i][n];
				ret=-a[m][n];
				return 1;
			}
			p = INF;
			for(int i=0; i<m; ++i) if(a[i][c]>eps) {
				double v=a[i][n]/a[i][c];
				if(v<p) { r=i; p=v; }
			}
			if(p==INF)
			return -1;
			pivot(r,c);
		}
    }
}solver;

int main() {
	freopen("in.in","r",stdin);freopen("std.out","w",stdout);
    scanf("%d",&T);
    while(T --) {
        memset(solver.a,0,sizeof(solver.a));
        memset(x,0,sizeof(x));
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; ++i) Djset[i].clear();
        for(int i=0; i<n; ++i)
            scanf("%d",a+i);
        for(int mask=1; mask< (1 << n); ++mask) {
            int sum=0;
            for(int i=0; i<n; ++i)
                if(mask>>i&1)
                    sum+=a[i];
            if(sum<=m)
                for(int i=0; i<n; ++i)
                    if(mask>>i&1)
                    	Djset[i].push_back(mask);
        }
        int tot=0;
        for(int i=0; i<n; ++i) {
            for(auto&&x:Djset[i])
                solver.a[tot][x-1]=-1;
            solver.a[tot][(1<<n)-1]=1;
            ++tot;
        }
        solver.a[tot][(1<<n)-1]=1;
        solver.a[tot++][(1<<n)]=1;
        for(int i=0; i<(1<<n)-1; ++i)
            solver.a[tot][i]=1;
        solver.a[tot++][(1<<n)]=1;
        solver.a[tot][(1<<n)-1]=1;
        double ret=0,ans=0;
        solver.simplex((1<<n),tot,x,ret);
        ans=max(ans,ret);
        printf("Case #%d: %.6f\n",++cas,ans);
    }
    return 0;

}
