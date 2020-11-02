#include<bits/stdc++.h>
using namespace std;

int f[511][511][8][8],h[511];
vector<int> g[511];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
	{
		string s;
		cin >> s;
		int maxn = 0;
		for(int j = 0;j < 7;j ++)
		{
			a[i][j] = s[i] - '0';
			maxn = max(maxn,a[i][j]);
		}
		for(int j = 0;j < 7;j ++)
			if(a[i][j] == maxn) g[i].push_back(a[i][j]),h[i] |= 1 << j;
	}
	memset(f,63,sizeof(f));
	for(int i = 1;i <= n;i ++)
	{
		if(h[i] & 1)
			f[i][i][0][0] = 0;
		else
			for(int j = 1;j < 7;j ++)
				if(h[i] & (1 << j))
					f[i][i][j][j] = 1;
	}
	for(int i = n;i >= 1;i --)
	{
		for(int j = i + 1;j <= n;j ++)
		{
			for(int k = i + 1;k < j;k ++)
			{
				for(int x = 0;x < 7;x ++)
				{
					for(int y = 0;y < 7;y ++)
					{
						for(int d = 0;d < g[k].size();d ++)
						{
							int z = g[k][d];
							f[i][j][x][y] = min(f[i][j][x][y],f[i][k - 1][x][z] + f[k + 1][j][z][y]);
						}
					}
				}
			}
		}
	}
	return 0;
}
