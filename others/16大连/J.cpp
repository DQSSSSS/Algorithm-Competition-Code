#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=1005;
const double PI=acos(-1);

LL n;
int m;

int main(){
	LL sum=0;
	for(int i=1;i<=200;i++){
		sum+=(i & (-i));
		cout<<i<<' '<<(i&(-i))<<' '<<sum<<endl;
	}
	while(scanf("%lld%d",&n,&m)!=EOF){
		while(m--){
			int a; LL b,c,ans=0;
			scanf("%d",&a);
			if (a==1){
				scanf("%lld%lld",&b,&c);
				for(LL i=c;i>=b;i-=(i & (-i))){
					ans=c-(i-(i& (-i))+1)+1;
				}
			}
			else{
				scanf("%lld",&b);
				for(LL i=b;i<=n;i+=(i& (-i))){
					ans++;
				}
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
