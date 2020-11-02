#include<bits/stdc++.h>
using namespace std;

int n,m;
int x[200005],a[200005];
multiset<int> s;

int main(){
	//int T; scanf("%d",&T);
	while(scanf("%d%d",&n,&m)!=EOF){		
		double ans=1.0*n/(n+m);
		printf("%.5f\n",ans);
		/*
		for(int i=1;i<=n;i++) scanf("%d",&x[i]);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			a[i] = m - a[i];
		}
		sort(x+1,x+n+1);
		sort(a+1,a+n+1);
		int ans=0;
		for(int i= n;i >= 1;i --){
			if(x[i] >= a[i]) ans++;
		}
		printf("%d\n",ans);
		
		
		///
		//s.clear();*/
	}
	return 0;
}
