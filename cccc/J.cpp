#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
	if(flag) n = -n;
	return n; 
}

struct haha
{
	int id,num;
	int sum;
}a[SZ];

bool cmp(haha a,haha b)
{
	if(a.sum != b.sum) return a.sum > b.sum;
	if(a.num != b.num) return a.num > b.num;
	return a.id < b.id;
}


int main()
{
	int n = read();
	for(int i = 1;i <= n;i ++)
	{
		a[i].id = i;
		int k = read();
		while(k --)
		{
			int id = read(),x = read();
			a[id].num ++;
			a[id].sum += x;
			a[i].sum -= x;
		}
	}
	sort(a + 1,a + 1 + n,cmp);
	for(int i = 1;i <= n;i ++)
		printf("%d %.2f\n",a[i].id,(double)a[i].sum / 100);
	return 0;
}



