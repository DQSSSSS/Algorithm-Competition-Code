#include<bits/stdc++.h>
using namespace std;

const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;

int tot = 0;

struct haha
{
	int a[10];
}ans[SZ];

bool cmp(haha a,haha b)
{
	for(int i = 1;i <= 4;i ++)
		if(a.a[i] != b.a[i]) return a.a[i] < b.a[i];
	return true;
}

int n,m;

bool maps[33][33],a[33][33];

void init()
{
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m;j ++)
			a[i][j] = maps[i][j];	
}

bool check()
{
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m;j ++)
			if(a[i][j] == 0) return false;
	return true;
}

void push(int a,int b,int c,int d)
{
	tot ++;
	ans[tot].a[1] = a;
	ans[tot].a[2] = b;
	ans[tot].a[3] = c;
	ans[tot].a[4] = d;
}

void work1()
{
	for(int i = 1;i <= n;i ++)
	{
		init();
		for(int j = 0;j < i;j ++)
			for(int k = 1;k <= m;k ++)
				if(i - j >= 1 && i + j + 1 <= n)
				{
					int x = a[i - j][k] ^ a[i + j + 1][k];
					a[i - j][k] = a[i + j + 1][k] = x;
				}
		if(check()) push(i,1,i,m);
	}
}

void work2()
{
	for(int i = 1;i <= m;i ++)
	{
		init();
		for(int j = 0;j < i;j ++)
			for(int k = 1;k <= n;k ++)
				if(i - j >= 1 && i + j + 1 <= m)
				{
					int x = a[k][i - j] ^ a[k][i + j + 1];
					//if(i == 10) cout << " " << k << " " << i - j << " " << i + j + 1 << endl;
					a[k][i - j] = a[k][i + j + 1] = x;
				}
		if(check()) push(1,i,n,i);
	}
}

void work3(bool flag)
{
	for(int d = 2;d <= n + m;d ++)
	{
		init();
		for(int x = 1;x <= n;x ++)
			for(int y = 1;y <= m;y ++)
			{
				//cout << x << " " << y << " " << d << endl;
				if(x + y < d && 1 <= d - x && d - x <= n && 1 <= d - y && d - y <= m)
				{
					//cout << x << " " << y << " " << d - x << " " << d - y << endl;
					int dd = (a[x][y] ^ a[d - x][d - y]);
					a[x][y] = a[d - x][d - y] = dd;
				}
			}
		if(check())
		{
			if(d <= n + 1)
			{
				if(!flag) push(d - 1,1,1,d - 1);
				else
				{
					int x = 1,y = d - 1,xx = d - 1,yy = 1;
					push(m - y + 1,x,m - yy + 1,xx);
				}
			}
			else
			{
				if(!flag) push(n,d - n,d - m,m);
				else
				{
					int x = d - m,y = m,xx = n,yy = d - n;
					push(m - y + 1,x,m - yy + 1,xx);
				}
			}
		}
	}
}

void work4()
{
	bool tmp[33][33];
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m;j ++)
			tmp[j][i] = maps[n - i + 1][j];
	swap(n,m);
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= m;j ++)
			maps[i][j] = tmp[i][j];
	work3(1);
}
	

int main()
{
	int T;
	cin >> T;
	while(T --)
	{
		tot = 0;
		cin >> n >> m;
		for(int i = 1;i <= n;i ++)
		{
			char s[33];
			scanf("%s",s + 1);
			for(int j = 1;j <= m;j ++)
				maps[i][j] = s[j] == '.' ? 0 : 1;
		}
		work1(); 
		//puts("fuck");
		work2(); 
		//puts("fuck");
		work3(0);
	//	puts("fuck");
		work4();
		sort(ans + 1,ans + 1 + tot,cmp);
	//	cout << tot << endl;
		cout << ans[1].a[1] << " " << ans[1].a[2] << " " << ans[1].a[3] << " " << ans[1].a[4] << endl;
		//for(int i = 1;i <= tot;i ++)
		//	cout << ans[i].a[1] << " " << ans[i].a[2] << " " 
		//	<< ans[i].a[3] << " " << ans[i].a[4] << endl;
	}
	return 0;
}

/**

5 6
######
##..#.
#..##.
#.###.
####..
2 3
#.#
###

6 6
######
#.#.##
##.#.#
.##.##
#.##.#
.#.###
**/

