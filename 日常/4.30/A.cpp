#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const int INF = 1e9 + 10;

int n,m;

char maps[1010][1010];

int get_r_sz(int x) //kongwei
{
	int ans = 0;
	for(int i = 1;i <= 11;i ++)
		if(maps[x][i] == '-') ans ++;
	return ans;
}

int get_1_sz()
{
	int ans = 0;
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= 5;j ++)
			if(maps[i][j] != '.' && maps[i][j] != '-') ans ++;
	return ans;
}

int get_2_sz()
{
	int ans = 0;
	for(int i = 1;i <= n;i ++)
		for(int j = 7;j <= 11;j ++)
			if(maps[i][j] != '.' && maps[i][j] != '-') ans ++;
	return ans;
}

int get_dis(int x)
{
	return min(abs(x - 1),min(abs(x - ((n - 3) / 2 + 2)),abs(n - x)));
}


int getr()
{
	int num2 = get_r_sz(2),numz = get_r_sz((n - 3) / 2 + 3); 
	if(num2 || numz)
	{
		if(num2 >= numz) return 2;
		else return (n - 3) / 2 + 3;
	}
	else
	{
		int tot = 0,a[110];
		memset(a,0,sizeof(a));
		int maxnum = 0,dis = 233;
		for(int i = 1;i <= n;i ++)
		{
			if(maps[i][1] == '.') continue;
			int sz = get_r_sz(i),d = get_dis(i);
	//		cout << i << " "<< d << endl;
			if(sz > maxnum || (sz == maxnum && dis > d))
				maxnum = sz,dis = d;
		}
	//	cout << maxnum << " " << dis << endl;
		for(int i = 1;i <= n;i ++)
		{
			if(maps[i][1] == '.') continue;
			int sz = get_r_sz(i),d = get_dis(i);
			if(sz == maxnum && dis == d) return i;
		}
	}
}

int L[233],R[233];

int getc(int r)
{
	int ln = get_1_sz(),rn = get_2_sz();
	for(int i = 1;i <= 5;i ++)
	{
		int x = L[i],y = R[i];
		if(maps[r][x] == '-' && maps[r][y] == '-')
		{
			if(ln <= rn) return x;
			else return y;
		}
		else if(maps[r][x] == '-') return x;
		else if(maps[r][y] == '-') return y;
	}
}

int main()
{
	L[1] = 5; R[1] = 7;
	L[2] = 3; R[2] = 9;
	L[3] = 1; R[3] = 11;
	L[4] = 6; R[4] = 6;
	L[5] = 2; R[5] = 10;
	cin >> n >> m;
	n += 3;
	for(int i = 1;i <= n;i ++) scanf("%s",maps[i] + 1);
	char c = 'a';
	while(m --)
	{
	//	for(int i = 1;i <= n;i ++) printf("%s\n",maps[i] + 1);
		int x = getr();
		int y = getc(x);
		maps[x][y] = c;
	//	cout << x << " "<< y << endl;
		c ++;
		//system("pause");
	}
	for(int i = 1;i <= n;i ++) printf("%s\n",maps[i] + 1);
	return 0;
}
/**

...........
gke.aic.###
#-#.m--.---
---.###.---
...........
fjb.###.dlh
#--.#-#.--#
#--.--#.#-#
..........

**/
