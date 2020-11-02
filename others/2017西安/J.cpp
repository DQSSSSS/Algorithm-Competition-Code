#include<bits/stdc++.h>
using namespace std;
char s[6][105];
int used[105];
long long ans;
const int MOD=1e9+7;
void dfs(int u,int tot)
{
	if (u==4)
	{
		ans=(ans+tot) % MOD;
		return;
	}
	for (int i=0;i<100;i++)
	if (s[u][i]=='1' && !used[i])
	{
		used[i]=1;
		if (s[4][i]=='1')
			dfs(u+1,tot-1);
		else dfs(u+1,tot);
		used[i]=0;
	}
}
int main()
{
long long tmp=531192758;
while (scanf("%s",s[0])!=EOF)
{
	for (int i=1;i<5;i++)
		scanf("%s",s[i]);
	int tot=0;
	memset(used,0,sizeof used);
	for (int i=0;i<100;i++)
	if (s[4][i]=='1') tot++;
	//printf("%d\n",tot);
	ans=0;
	dfs(0,tot);
	ans=(ans*tmp)%MOD;
	printf("%lld\n",ans);
}

return 0;
}
