#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int size=100010;
typedef long long LL;
char s[size];
LL mod;

LL ksm(LL a,LL b)
{
	LL ans=1;
	while(b)
	{
		if(b&1) ans=((ans%mod)*(a%mod))%mod;
		a=((a%mod)*(a%mod))%mod;
		b>>=1;
	}
	return ans;
}

int mi[size];

int main()
{
//	freopen("patchouli.in","r",stdin); freopen("patchouli.out","w",stdout);
	scanf("%s%d",s+1,&mod);
	LL num=0;
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		num=(((num%mod)*(26%mod))%mod+s[i]-'A')%mod;
	}
	if(num==0) puts("0 0");
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				LL t=num;
				t-=(s[i]-'A')*ksm(26,n-i)+(s[j]-'A')*ksm(26,n-j);
				t+=(s[j]-'A')*ksm(26,n-i)+(s[i]-'A')*ksm(26,n-j);
				if((t%mod+mod)%mod==0)
				{
					printf("%d %d\n",i,j);
					return 0;
				}
			}
		}
		puts("-1 -1");
	}
	return 0;
}
