#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const int SZ = 2e6 + 10;

LL h[SZ];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
	{
		char s[20];
		int x;
		scanf("%s%d",s,&x);
		if(s[1] == 'o') printf("%lld\n",h[i] = h[i - 1] ^ x);
		else printf("%lld\n",h[i] = h[x]);
	}
	return 0;
}


