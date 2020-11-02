#include <bits/stdc++.h>
using namespace std;
const int MAXN=30;
typedef long double ldb;
const ldb eps=1e-8;
const ldb oo=1e99;

namespace haha
{
	struct LinearProgram{
		int n,m;	
		ldb a[MAXN][MAXN];
		int idn[MAXN],idm[MAXN];
		void display(){
			for(int i=1;i<=n;i++)cout<<"idn["<<i<<"] = "<<idn[i]<<endl;
			for(int j=1;j<=m;j++)cout<<"idm["<<j<<"] = "<<idm[j]<<endl;
			cout<<"Mar is\n";
			for(int i=0;i<=m;i++){
				for(int j=0;j<=n;j++){
					printf("%.4lf ",(double)a[i][j]);
				}
				puts("");
			}
		}
		void pivot(int l,int e){
			swap(idm[l],idn[e]);
			ldb tmp=-a[l][e];a[l][e]=-1;
			for(int i=0;i<=n;i++){
				if(fabs(a[l][i])>eps)a[l][i]/=tmp;
				else a[l][i]=0;
			}
			for(int i=0;i<=m;i++){
				if(i==l||fabs(a[i][e])<eps)continue;
				tmp=a[i][e];a[i][e]=0;
				for(int j=0;j<=n;j++){
					a[i][j]+=tmp*a[l][j];
				}
			}
		}
		void simplex(){
			while(1){
				int l=m+1,e=n+1;
				idn[e]=idm[l]=n+m+1;
				for(int i=1;i<=n;i++)
					if(a[0][i]>eps&&idn[i]<idn[e]){
						e=i;
					}
				if(e==n+1)break;
				ldb tmp=0,limit=oo;
				for(int j=1;j<=m;j++){
					if(a[j][e]<-eps){
						tmp=a[j][0]/(-a[j][e]);
						if(tmp < limit - eps){
							limit=tmp;
							l=j;
						}else if(tmp < limit + eps && idm[j]<idm[l]){
							limit=tmp;
							l=j;
						}
					}
				}
				if(l==m+1){
					puts("Unbounded");
					exit(0);
				}
		//		cout<<"l is "<<l<<" e is "<<e<<endl;
		//		display();
				pivot(l,e);
		//		display();
			}
		}
		void init(){
			for(int i=1;i<=n;i++)
				idn[i]=i;
			for(int j=1;j<=m;j++)
				idm[j]=n+j;
			int l=0;
			ldb limit=0;
			for(int i=1;i<=m;i++){
				if(a[i][0]<limit){
					l=i;
					limit=a[i][0];
				}
			}	
			if(limit+eps>0){
				return;
			}
			static ldb tmp[MAXN];
			for(int i=1;i<=n;i++){
				tmp[i]=a[0][i];
				a[0][i]=0;
			}
			a[0][++n]=-1;
			idn[n]=0;
			for(int i=1;i<=m;i++){
				a[i][n]=1;
			}
			pivot(l,n);
			simplex();
			if(a[0][0]<-eps){
				puts("Infeasible");
				exit(0);
			}
			for(int i=1;i<=m;i++){
				if(idm[i]!=0)continue;
				for(int j=1;j<=n;j++){
					if(a[i][j]>eps){
						pivot(i,j);
						break;
					}
				}
				break;
			}
			int e=0;
			for(int i=1;i<=n;i++)
				if(idn[i]==0)
					e=i;
			swap(idn[e],idn[n]);
			for(int i=0;i<=m;i++)
				swap(a[i][e],a[i][n]);
			n--;
			memset(a[0],0,sizeof a[0]);
			for(int i=1;i<=m;i++){
				if(idm[i]>n)continue;
				for(int j=0;j<=n;j++){
					a[0][j] += tmp[idm[i]] * a[i][j];
				}
			}
			for(int i=1;i<=n;i++){
				if(idn[i]<=n){
					a[0][i] += tmp[idn[i]];
				}
			}
		}
		double solve(){
			init();
			simplex();
			return a[0][0];
		}
	};
	ldb ans[MAXN];
	LinearProgram now;
	
	void work(int n){
		int t;
		cin>>now.n>>now.m>>t;
		for(int i=1;i<=now.n;i++){
			cin>>now.a[0][i];
		}
		for(int i=1;i<=now.m;i++){
			for(int j=1;j<=now.n;j++){
				cin>>now.a[i][j];
				now.a[i][j] = -now.a[i][j];
			}
			cin>>now.a[i][0];
		}
		printf("%.10lf\n",(double)now.solve());
		if(t==1){
			for(int i=1;i<=now.m;i++){
				if(now.idm[i]<=now.n){
					ans[now.idm[i]] = now.a[i][0];
				}
			}
			for(int i=1;i<=now.n;i++)
				printf("%.10lf ",(double)ans[i]);
		}
		return 0;
	}

}

