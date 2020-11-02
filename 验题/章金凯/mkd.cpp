#include<bits/stdc++.h>
using namespace std;

int n,x;

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.in","w",stdout);
	srand(time(0));
	n=100000;
	printf("%d\n",n);
	for (int i=1;i<=n;i++)
	{
		x=rand()<<15;
		x+=rand();
		x%=1000000000;
		printf("%d ",x);
	}
}
