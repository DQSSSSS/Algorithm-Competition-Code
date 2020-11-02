#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a >= '0' && a <= '9') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

struct haha
{
	int l,r;
}p[SZ];

bool cmp(haha a,haha b) { return a.l < b.l; }

int f[2010][2010],a[2010];

int main()
{
	int T = read(),cc = 0;
	while(T --)
	{
		int n = read(),m = read(),K = read();
		for(int i = 1;i <= m;i ++)
		{
			p[i].l = read(),p[i].r = read();
		}
		sort(p + 1,p + 1 + m,cmp);
		for(int i = 0;i <= n;i ++)
			for(int j = 0;j <= K;j ++) 
				f[i][j] = 0;
		for(int i = 0,pos = 1,num = 0;i < n;i ++)
		{
			while(pos <= m && p[pos].l == i + 1) 
				num = max(num,p[pos].r - i),pos ++;
			for(int j = 0;j < K;j ++)
			{
				f[i + num][j + 1] = max(f[i + num][j + 1],f[i][j] + num);
				f[i + 1][j + 1] = max(f[i + 1][j + 1],max(f[i][j + 1],f[i + 1][j]));
				//f[i][j + 1] = max(f[i][j + 1],f[i][j]);
				//f[i + 1][j] = max(f[i + 1][j],f[i][j]);
			}
			if(num) num --;
		}
		printf("Case #%d: %d\n",++ cc,f[n][K]);
	}
	return 0;
}



