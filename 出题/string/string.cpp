#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long LL;
const int SZ = 1000010;

int sa[SZ],Rank[SZ],tmp[SZ],k,n,K;

bool cmp(int x,int y)
{
	if(Rank[x] != Rank[y])	return Rank[x] < Rank[y];
	else
	{
		int a = x + k < n ?
		Rank[x + k] : -1;
		int b = y + k < n ? Rank[y + k] : -1;
		return a < b;
	}
}

void get_sa(char s[])
{
	for(int i = 0;i <= n;i ++)
	{
		sa[i] = i;
		Rank[i] = i == n ? -1: s[i];
	}
	for(k = 1;k <= n;k <<= 1)
	{
		sort(sa,sa + 1 + n,cmp);

		tmp[sa[0]] = 1;
		for(int i = 1;i <= n;i ++)
			tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1],sa[i]);
		for(int i = 0;i <= n;i ++)
			Rank[i] = tmp[i];
	}
}


char s[SZ];

bool smaller(int l,int r,int x)
{
	for(int i = l;i <= r;i ++)
		if(s[i] != s[x + i - l])
			return s[i] < s[x + i - l];
	return true;
}

int cut[SZ][2],t;

bool check(int mid)
{
	int x = sa[mid],r = n - 1;
	t = 1;
	for(int i = n - 1;i >= 0;i --)
	{
		if(!smaller(i,r,x))
		{
			cut[t][0] = i + 1; cut[t][1] = r;
	//		printf("%d %d %d\n",i,r,t);
			r = i,t ++;
		}
	}
	cut[t][0] = 0; cut[t][1] = r;
//	printf("%d %d %d\n\n",t,mid,x);
	return t <= K;
}

void div()
{
	int l = -1,r = n;
	while(r - l > 1)
	{
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid;
	}
	check(r);
//	printf("%d %d\n",l,r);
}

bool smaller(int l,int r,int x,int y)
{
	for(int i = l;i <= r;i ++)
	{
		if(x + i - l > y) return false;
		if(s[i] != s[x + i - l])
			return s[i] < s[x + i - l];
	}
	return true;
}


int main()
{
	///freopen("string.in","r",stdin);
	///freopen("string.out","w",stdout);
	while(~scanf("%d%s",&K,s)) {
		n = strlen(s);

		get_sa(s);
		div();

		int ansl = n + 1,ansr = n + 1;

		for(int i = 1;i <= t;i ++)
		{
			for(int j = cut[i][0];j <= cut[i][1];j ++)
			{
				if(!smaller(j,cut[i][1],ansl,ansr))
				{
					ansl = j; ansr = cut[i][1];
				}
			}
		}
		for(int i = ansl;i <= ansr;i ++)
			printf("%c",s[i]);
		puts("");
	}
	return 0;
}
/*
0
1 a
2 aba
3 ababa
4 ba
5 baba

3
bababbb

*/

