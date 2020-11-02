#include<bits/stdc++.h>
using namespace std;

int n;
long long x,ans;
priority_queue<long long,vector<long long>,greater<long long> > Q;

int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		Q.push(x);
	}
	for (int i=1;i<n;i++)
	{
		long long x=Q.top();Q.pop();
		long long y=Q.top();Q.pop();
		Q.push(x+y);
		ans+=x+y;
	}
	printf("%lld",ans);
}
