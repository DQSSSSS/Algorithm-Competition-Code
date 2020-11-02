#include<cstdio>
#include<bits/stdc++.h>
#define Mn 400000
using namespace std;
int n,i,j,now,p[Mn];
int main()
{
    srand(time(0));
	freopen("interval10.in","w",stdout);
	n=300000;
	printf("%d\n",n);
	/*for(i=1;i<=37500;i++)
	{
		for(j=1;j<=4;j++)
			printf("%d ",now+j*2-1);
		for(j=1;j<=4;j++)
			printf("%d ",now+j*2);
		now+=8;
	}*/
	for(i=1;i<=n;i++) p[i]=i;
//printf("%d\n",n);
	//random_shuffle(p+1,p+1+n);
	for(i=1;i<=n/2;i++) swap(p[i],p[n-i+1]);
	for(i=1;i<=n;i++)
		printf("%d ",p[i]);
	return 0;
}
