#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7,M=30,p=1e9+7;
int n,m,l,k,c,ans,cnt,w[N],g[N],d[N],s[N],f[M][N];
inline int read(){
    int num=0; char g=getchar(); while(g<48||57<g) g=getchar();
    while(47<g&&g<58) num=(num<<1)+(num<<3)+g-48,g=getchar(); return num;
}
int main(){
	freopen("J.in","r",stdin); freopen("std.out","w",stdout);
	d[1]=1,s[0]=1,s[1]=2;
	for(int i=2;i<=100000;i++) d[i]=(d[i-1]*2+1)%p,s[i]=s[i-1]*2%p;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++) w[i]=read(); l=1,g[1]=1,k=1,ans=n,cnt=1ll*(d[m]-n+1)*n%p;
		while(l<n){
			g[l+1]=++k; for(int x=1;x<=l;x++) g[l+x+1]=g[x]; l=l*2+1;
		}
		c=k;
		for(int i=1;i<=n;i++){
			if(w[i]<=c){
				int z=(1<<(w[i])),q=(1<<(w[i]-1));
				f[w[i]][(i-q+z)%z]++;
			}
		}
		if(c!=m){
			for(int i=-2*n;i<=n*2;i++){
				int sum=n;
				if(i>=1&&i<=n){
					if(w[i]<=m&&w[i]>c) sum--;
				}
				for(int j=0;j<=c;j++) sum-=f[j][(i%(1<<j)+(1<<j))%(1<<j)];
				ans=min(ans,sum);
			}
		}
		else{
			for(int i=-2*n;i<=0;i++){
				int sum=n;
				if(i+l>=n){
					for(int j=0;j<=c;j++) sum-=f[j][(i%(1<<j)+(1<<j))%(1<<j)];
					ans=min(ans,sum);
				}
			}
		}
		for(int x=1;x<=c;x++)
			for(int i=0;i<(1<<x);i++) f[x][i]=0;
		for(int x=1;x<=n;x++){
			cnt=(cnt-s[m-w[x]]+p)%p;
			if(w[x]<=c){
				int a=(1<<w[x]),b=(1<<(w[x]-1));
				cnt=(cnt+(x+b-1)/a)%p;
				cnt=(cnt+(n-x+b)/a)%p;
			}
		}
		printf("%d %d\n",ans,cnt);
	}
	return 0;
}
