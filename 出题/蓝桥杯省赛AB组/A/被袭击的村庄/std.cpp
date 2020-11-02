#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;

typedef long long LL;

const int SZ = 1010;

LL sh[SZ][SZ];
int maps[SZ][SZ];
LL nj[SZ][SZ];
int n,m,k;
LL a,b,c;
LL w;

void jssh(int x,int y)
{
	for(int i = x - 1;i <= x + 1;i ++)
	{
		for(int j = y - 1;j <= y + 1;j ++)
		{
			if(i == x && j == y) continue;
			nj[i][j] = max(0ll,nj[i][j] - w);
		}
	}
}

void gj(int x,int y,bool d)
{
	for(int i = x - (k-1)/2;i <= x + (k-1)/2;i ++)
	{
		for(int j = y - (k-1)/2;j <= y + (k-1)/2;j ++)
		if(i > 0 && i <= n && j > 0 && j <= m)
		{
			nj[i][j] = max(0ll,nj[i][j] - sh[i - (x-(k-1)/2) + 1][j - (y-(k-1)/2) + 1]); 
			if(!d) jssh(i,j);
		}
	}
}

int main()
{
	freopen("kancolle.in","r",stdin);
	freopen("kancolle.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%lld%lld%lld",&a,&b,&c);
	scanf("%d%lld",&k,&w);
	for(int i = 1;i <= k;i ++)
	{
		for(int j = 1;j <= k;j ++)
		{
			scanf("%lld",&sh[i][j]);
		}
	} 
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= m;j ++)
		{
			scanf("%d",&maps[i][j]);
			if(maps[i][j] == 1) nj[i][j] = a;
			if(maps[i][j] == 2) nj[i][j] = b;
			if(maps[i][j] == 3) nj[i][j] = c;
		}
	}
	int q;
	scanf("%d",&q);
	while(q --)
	{	
		int opt,x,y;
		scanf("%d%d%d",&opt,&x,&y);
		gj(x,y,opt);
	}	
	int ans1 = 0,ans2 = 0,ans3 = 0;
	LL ans = 0;
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= m;j ++)
		{
			if(maps[i][j] == 1) 
			{
				if(nj[i][j] == 0)
					ans1 ++;
				ans += a - nj[i][j];
			}
			if(maps[i][j] == 2) 
			{
				if(nj[i][j] == 0)
					ans2 ++;
				ans += b - nj[i][j];
			}
			if(maps[i][j] == 3) 
			{
				if(nj[i][j] == 0)
					ans3 ++;
				ans += c - nj[i][j];
			} 
		}
	}
	printf("%d %d %d\n%lld",ans1,ans2,ans3,ans);
	return 0;
}




