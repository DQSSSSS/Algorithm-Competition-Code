#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 200010;

int t[SZ];
bool use[SZ];


int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	LL res = 2 * n;
	int ans = 0;
	for(int i = 1;i <= m - 1;i ++)
	{
		int x,y,xx,yy;
		scanf("%d%d%d%d",&x,&y,&xx,&yy);
		if(!use[x]) use[x] = 1,t[xx] ++,res --;
		if(!use[y]) use[y] = 1,t[yy] ++,res --;
		if(xx == yy) ans = max(ans,xx);
	}
	double mx1 = 0,mx2 = 0,mx3 = 0,gl2 = 0,gl3 = 0;	
	int mxnum = 0;
	for(int i = 1;i <= n;i ++)
	{
		if(t[i] == 2) mx1 = max(mx1,1.0 * i);
		if(t[i] == 1)
		{
			mxnum = max(mxnum,i);
		}
		if(t[i] == 0)
		{
			double n =  (res * (res - 1) / 2.0);
			if(i > ans)
				gl3 += 1.0 / n,mx3 += i * 1.0 / n;
		}
	}
	mx2 = mxnum * 1.0 / res; gl2 = 1.0 / res;
	mx2 += (1 - gl2) * ans;
	mx3 += (1 - gl3) * ans;
	printf("%f\n",max(mx1,max(mx2,mx3)));
	return 0;
}
